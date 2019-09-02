#include "Field.h"
#include <random>
#include <time.h>



Field::Field(unsigned int width, unsigned int height)
{
	mlk::rng random;

	f_height = height;
	f_width = width;

	m_buf1 = new cell*[f_width];
	m_buf2 = new cell*[f_width];
	for (int i = 0; (unsigned)i < f_width; i++) {
		m_buf1[i] = new cell[f_height];
		m_buf2[i] = new cell[f_height];
		for (int j = 0; (unsigned)j < f_height; j++) {
			if (i == 0 || i == f_width - 1 || j == 0 || j == f_height - 1)
				m_buf1[i][j] = m_buf2[i][j] = 0;
			else
				m_buf1[i][j] = m_buf2[i][j] = random.get<bool>();
		}
	}

	m_cur = m_buf1;
	m_draw = m_buf2;

	//int count;
	//auto marr = glfwGetMonitors(&count);
	//for (int i = 0; i < count; i++) {
	//	auto& monitor = *glfwGetVideoMode(marr[i]);
	//	int x, y;
	//	glfwGetMonitorPos(marr[i], &x, &y);
	//	if (monitor.height + y > maxHeight)maxHeight = monitor.height + y;
	//	if (monitor.width + x > maxWidth)maxWidth = monitor.width + x;
	//}
	//payingField.
}


Field::~Field()
{
	for (unsigned int i = 0; i < f_width; i++) {
		delete[] m_buf1[i];
		delete[] m_buf2[i];
	}
	delete[] m_buf1;
	delete[] m_buf2;
}

void Field::Update(){
	for (uint x = 1; x < f_width - 1; x++){
		for (uint y = 1; y < f_height - 1; y++) {
			m_cur[x][y] = CalculateKernel(x, y);
		}
	}
	swap();
}

cell Field::CalculateKernel(uint a_x, uint a_y){
	int x = a_x & ~0x80000000;
	int y = a_y & ~0x80000000;
	unsigned char total = 0;
	for (char xo = -1; xo < 2; ++xo){
		for (char yo = -1; yo < 2; ++yo) {
			total += !(!xo && !yo) && m_draw[x + xo][y + yo];
		}
	}
	//int myArray[2][3]
	//myArray[0]
	/*
	0, 1, 2
	3, 4, 5
	*/
	return (m_draw[x][y] == 0 && total == 0x3) || (m_draw[x][y] == 1 && (total == 0x2 || total == 0x3));
}

void Field::swap() {
	cell** tmp = m_cur;
	m_cur = m_draw;
	m_draw = tmp;
}