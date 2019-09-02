/* rng.h 
   @brief REQUIRES C++17
   Wrapper around C++11 random device and engine.
   Can request random value for any integral or floating point type
   through a single get<Type>() or get(T min, T Max)
   
   Usage by default:
     get<bool>() - returns true or false
     get<int/uint/long>() - returns a random int from the range of the int type
     get<float/double/long>() - returns a value of the desired precision 0 to 1 inclusive
   
   Ranged usage:
     get(min, max) - returns a value of the desired precision min to max inclusive 
                   - type deduced by arguments 
                   - bool arguments ignored
   
   Adam Clarke - 2017 10 31

   Edit - 2018 05 25 - Full seeding added. Basic seeding removed 
					   Source https://www.reddit.com/r/cpp/comments/4ec6q1/random_numbers_generation_in_c/
		- 2018 06 29 - Re-seeding from many data types added.
*/

#pragma once
#ifndef RNG_H
#define RNG_H

/* If compiling as engine */
#ifdef _MLK_GL_
	/* MilkCore Helper */
	#include "mlkcore.h"
#else
	/* Standard headers from mlkcore.h */
	#include <random>
	#include <memory>
	#include <string>
	#include <variant>
	#include <vector>
#endif // !_MLK_GL_
#undef _MLK_GL_


/* @namespace MilkGL
*/
namespace mlk
{
    class rng
    {
    private:    

		/* @brief Number of bits in a byte, constant for compile time constexpr resolution
		*/
		static constexpr size_t bits_in_1byte = 8;
		/* @brief Number of bits in a wide char, constant for compile time constexpr resolution
		*/
		static constexpr size_t bits_in_2bytes = 16;
		/* @brief Number of bits in an int / float, constant for compile time constexpr resolution
		*/
		static constexpr size_t bits_in_32bits = 32;

		/* @brief Number of chars in an int / float, constant for compile time constexpr resolution
		*/
		static constexpr size_t chars_in_uint32_t = 4;
		/* @brief Number of wide chars in an int / float, constant for compile time constexpr resolution
		*/
		static constexpr size_t wchars_in_uint32_t = 2;

		/* @breif Constant size given the 64 bit engine.
		@note  Because 2 * 32 == 64
		*/
		static constexpr size_t seed_size = std::mt19937_64::state_size * 2;

        /* @brief 64 bit Mersenne Twister 19937 engine, off the stack 
        */
        std::unique_ptr<std::mt19937_64> m_engine;
		
		/* @brief Storing the seeding bitfield as a vector of ints
		*/
		std::vector<uint32_t> seed_vector;

		/* @brief Varient to hold dynamically typed seed.
		*/
		std::variant<char, 
					 uint8_t,		// unsigned char
					 wchar_t,				 
				     short, 
					 uint16_t,		// unsigned short
			         int, 
					 uint32_t,		// unsigned int
			         long,				 
			         long long, 
					 unsigned long,
					 uint64_t,		// unsigned long long int
			         float, 
					 double, 
					 long double,
			         std::string, 
					 std::vector<uint32_t>> m_seed;

		/* @brief Wrapper for accessing std::vector<uint32_t> from seed
		   @return Reference to vector stored in seed variant
		*/
		std::vector<uint32_t>& seed_as_vector()
		{
			return std::get<std::vector<uint32_t>>(m_seed);
		}

		/* @brief Wrapper for accessing std::vector<uint32_t> from seed
		@return Reference to vector stored in seed variant
		*/
		std::string& seed_as_string()
		{
			return std::get<std::string>(m_seed);
		}

    public:
        /* @brief Constructor builds and initialises the random engine
        */
        rng()
        {
			// Randomi device only required here for seeding.
			std::random_device m_random_device;

			// Construct the engine
			m_engine = std::make_unique<std::mt19937_64>();

			// Storage for seed squence initialization
			seed_vector = std::vector<uint32_t>(seed_size);

			// Populate with random from device
			std::generate(seed_vector.begin(), seed_vector.end(), ref(m_random_device));

			// Alow the seeding function to initialize the engine.
			re_seed(seed_vector);
        }

        /* @brief Access to the engine for external use. 
            eg: shuffle
        */
        std::mt19937_64& get_engine()
        {
            return *m_engine;
        }

        /* @brief Boolean engine specific implementation due to ambiguity of a
            bool get() specialization and not meeting the desired get<bool>() interface
        @tparam T should only compile as boolean
        @tparam Metafunction filters the type to bool for compilation
        @param default params overloaded and unused
        @return true or false across a random 50% distribution
        */
        template<typename T,
                typename std::enable_if < std::conjunction <typename std::is_integral<T>, 
                                                            typename std::is_same<T, bool>>::value >::type* = nullptr >
        T get(T a = false, T b = false)
        {
                auto bool_distribution = std::bernoulli_distribution();
                return bool_distribution(*m_engine);
        }

        /* @brief Integer engine implementation
        @tparam T should only compile as integral type (non-boolean)
        @tparam Metafunction filters OUT the bool type for integer compilation
        @param default type's minimum
        @param default type's maximum
        @return a random integral from the range inclusive of args
        */
        template<typename T,
                typename std::enable_if < std::conjunction < typename std::is_integral<T> ,
                                                             std::negation <typename std::is_same<T, bool>>>::value>::type* = nullptr >
        T get(T a_min = std::numeric_limits<T>::min(),
            T a_max = std::numeric_limits<T>::max())
        {
            auto int_distribution = std::uniform_int_distribution<T>{a_min, a_max};
            return int_distribution(*m_engine);
        }
        
        /* @brief Floating point engine implementation
        @tparam T should only compile as floating type
        @tparam Metafunction captures floating point requests
        @param default type's 0 value or given minimum
        @param default type's 1 value or given maximum
        @return a random floating point from the range inclusive of args
        */
        template<typename T, 
                typename std::enable_if<std::is_floating_point<T>::value>::type* = nullptr >
        T get(T a_min = T(0),
            T a_max = std::nextafter(T(1),std::numeric_limits<T>::max()))
        {
            auto real_distribution = std::uniform_real_distribution<T>{a_min, a_max};
            return real_distribution(*m_engine);
        }


		/* @brief See the engine with given data.
		@note If data does not cover a full initialization, it will be tiled across the seed_sequence
		*/
		template <typename T>
		void re_seed(const T& a_seed)
		{
			// Copy the seed locally
			m_seed = T(a_seed);

			// Check to see if it is already of  std::vector<uint32_t> form
			if constexpr (std::is_same<T, std::vector<uint32_t>>::value)
			{
				// If it a complete sequence, simply copy
				if (seed_as_vector().size() == seed_size)
				{
					seed_vector = seed_as_vector();
				}
				else // Else fill the seed vector from the argument
				{
					size_t variant_seed_size = seed_as_vector().size();
					for (size_t index = 0; index < seed_size; ++index)
					{
						seed_vector.at(index) = seed_as_vector().at(index % variant_seed_size);
					}
				}
			}
			else if constexpr (std::is_same<T, std::string>::value)
			{
				// bitfield for populating the vector
				uint32_t bitfield = 0;
				// string length for char wrapping
				size_t variant_seed_size = seed_as_string().size();

				// Populate the entire seed_vector
				for (size_t index = 0; index < seed_size; ++index)
				{
					// Reset and Load the bitfield with chars.
					bitfield = 0;
					// 4 chars in an int.
					for (int char_index = 0; char_index < chars_in_uint32_t; ++char_index)
					{
						bitfield = bitfield << bits_in_1byte;
						bitfield |= seed_as_string().at((index * bits_in_1byte + char_index) % variant_seed_size);
					}
					seed_vector.at(index) = bitfield;
				}
			}
			else // remaining valid data types are 1, 2, 4, or 8 bytes.
			{
				// 64bits of seeed buffer
				uint32_t ying = 0;
				uint32_t yang = 0;
				
				// Pad and repeat the single char across 64 bits
				if constexpr (sizeof(T) == sizeof(char))
				{
					// For 4 chars worth of memory...
					for (size_t count = 0; count < chars_in_uint32_t; ++count)
					{
						// Shift...
						ying <<= (bits_in_1byte);
						// Edit.
						ying |= std::get<T>(m_seed);
					}
					// Duplicate.
					yang = ying;
				}
				// Pad and repeat the single wide char across 64 bits
				else if constexpr (sizeof(T) == sizeof(wchar_t))
				{
					// For 2 wide chars worth of memory...
					for (size_t count = 0; count < wchars_in_uint32_t; ++count)
					{
						// Shift...
						ying <<= sizeof(wchar_t);
						// Edit.
						ying |= std::get<T>(m_seed);
					}
					// Duplicate.
					yang = ying;
				}
				// Data is vector data size. Treat memory as bitfield.
				else if constexpr (sizeof(T) == sizeof(uint32_t))
				{
					// Hard cast as binary stored in a uint.
					ying = (0 | reinterpret_cast<uint32_t&>(std::get<T>(m_seed)));
					// Duplicate.
					yang = ying;
				}
				// Data is twice vector data size. Treat memory as bitfield
				// across two uints of memory
				else if constexpr (sizeof(T) == sizeof(uint64_t))
				{
					// Hard cast as binary stored in a long uint.
					uint64_t data = reinterpret_cast<uint64_t&>(std::get<T>(m_seed));
					// Write first 32 bits.
					ying = (0 | uint32_t(data));
					// Shift 32 bits
					data = data >> bits_in_32bits;
					// Write final 32 bits.
					yang = (0 | uint32_t(data));
				}
				else
				{
					// Somehow it has compiled and still failed to seed.
					static_assert(RNG_ENGINE_RESEEDING_FAILURE_INVALID_SEED, "RNG_ENGINE_RESEEDING_FAILURE_INVALID_SEED");
				}

				// Emplace object in vec till vec full.
				for (size_t index = 0; index < seed_vector.size(); ++index)
				{
					seed_vector.at(index) = (index % 2) ? yang : ying;
				}
			}

			// Create the seed
			std::seed_seq m_seed_sequence(seed_vector.begin(), seed_vector.end());
			// Fully seed the engine
			m_engine->seed(m_seed_sequence);
		}

    };
}
#endif // !RNG_H