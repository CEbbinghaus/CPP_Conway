# i n c l u d e   " g l _ c o r e _ 4 _ 4 . h "  
 # i n c l u d e   < G L F W / g l f w 3 . h >  
 # i n c l u d e   " R e n d e r e r 2 D . h "  
 # i n c l u d e   " T e x t u r e . h "  
 # i n c l u d e   " F o n t . h "  
 # i n c l u d e   < g l m / e x t . h p p >  
 # i n c l u d e   < s t b _ t r u e t y p e . h >  
  
 n a m e s p a c e   a i e   {  
  
 R e n d e r e r 2 D : : R e n d e r e r 2 D ( )   {  
  
 	 s e t R e n d e r C o l o u r ( 1 , 1 , 1 , 1 ) ;  
 	 s e t U V R e c t ( 0 . 0 f ,   0 . 0 f ,   1 . 0 f ,   1 . 0 f ) ;  
  
 	 m _ c a m e r a X   =   0 ;  
 	 m _ c a m e r a Y   =   0 ;  
 	 m _ c a m e r a S c a l e   =   1 . 0 f ;  
  
 	 u n s i g n e d   i n t   p i x e l s [ 1 ]   =   { 0 x F F F F F F F F } ;  
 	 m _ n u l l T e x t u r e   =   n e w   T e x t u r e ( 1 ,   1 ,   T e x t u r e : : R G B A ,   ( u n s i g n e d   c h a r * ) p i x e l s ) ;  
  
 	 m _ c u r r e n t V e r t e x   =   0 ;  
 	 m _ c u r r e n t I n d e x   =   0 ;  
 	 m _ r e n d e r B e g u n   =   f a l s e ;  
  
 	 m _ v a o   =   - 1 ;  
 	 m _ v b o   =   - 1 ;  
 	 m _ i b o   =   - 1 ;  
  
 	 m _ c u r r e n t T e x t u r e   =   0 ;  
  
 	 f o r   ( i n t   i   =   0 ;   i   <   T E X T U R E _ S T A C K _ S I Z E ;   i + + )   {  
 	 	 m _ t e x t u r e S t a c k [ i ]   =   n u l l p t r ;  
 	 	 m _ f o n t T e x t u r e [ i ]   =   0 ;  
 	 }  
  
 	 c h a r *   v e r t e x S h a d e r   =   " # v e r s i o n   1 5 0 \ n   \  
 	 	 	 	 	 	 i n   v e c 4   p o s i t i o n ;   \  
 	 	 	 	 	 	 i n   v e c 4   c o l o u r ;   \  
 	 	 	 	 	 	 i n   v e c 2   t e x c o o r d ;   \  
 	 	 	 	 	 	 o u t   v e c 4   v C o l o u r ;   \  
 	 	 	 	 	 	 o u t   v e c 2   v T e x C o o r d ;   \  
 	 	 	 	 	 	 o u t   f l o a t   v T e x t u r e I D ;   \  
 	 	 	 	 	 	 u n i f o r m   m a t 4   p r o j e c t i o n M a t r i x ;   \  
 	 	 	 	 	 	 v o i d   m a i n ( )   {   v C o l o u r   =   c o l o u r ;   v T e x C o o r d   =   t e x c o o r d ;   v T e x t u r e I D   =   p o s i t i o n . w ;   \  
 	 	 	 	 	 	 g l _ P o s i t i o n   =   p r o j e c t i o n M a t r i x   *   v e c 4 ( p o s i t i o n . x ,   p o s i t i o n . y ,   p o s i t i o n . z ,   1 . 0 f ) ;   } " ;  
  
 	 c h a r *   f r a g m e n t S h a d e r   =   " # v e r s i o n   1 5 0 \ n   \  
 	 	 	 	 	 	 i n   v e c 4   v C o l o u r ;   \  
 	 	 	 	 	 	 i n   v e c 2   v T e x C o o r d ;   \  
 	 	 	 	 	 	 i n   f l o a t   v T e x t u r e I D ;   \  
 	 	 	 	 	 	 o u t   v e c 4   f r a g C o l o u r ;   \  
 	 	 	 	 	 	 c o n s t   i n t   T E X T U R E _ S T A C K _ S I Z E   =   1 6 ;   \  
 	 	 	 	 	 	 u n i f o r m   s a m p l e r 2 D   t e x t u r e S t a c k [ T E X T U R E _ S T A C K _ S I Z E ] ;   \  
 	 	 	 	 	 	 u n i f o r m   i n t   i s F o n t T e x t u r e [ T E X T U R E _ S T A C K _ S I Z E ] ;   \  
 	 	 	 	 	 	 v o i d   m a i n ( )   {   \  
 	 	 	 	 	 	 	 i n t   i d   =   i n t ( v T e x t u r e I D ) ;   \  
 	 	 	 	 	 	 	 i f   ( i d   <   T E X T U R E _ S T A C K _ S I Z E )   {   \  
 	 	 	 	 	 	 	 	 v e c 4   r g b a   =   t e x t u r e 2 D ( t e x t u r e S t a c k [ i d ] ,   v T e x C o o r d ) ;   \  
 	 	 	 	 	 	 	 	 i f   ( i s F o n t T e x t u r e [ i d ]   = =   1 )   \  
 	 	 	 	 	 	 	 	 	 r g b a   =   r g b a . r r r r ;   \  
 	 	 	 	 	 	 	 	 f r a g C o l o u r   =   r g b a   *   v C o l o u r ;   \  
 	 	 	 	 	 	 	 }   e l s e   f r a g C o l o u r   =   v C o l o u r ;   \  
 	 	 	 	 	 	 i f   ( f r a g C o l o u r . a   <   0 . 0 0 1 f )   d i s c a r d ;   } " ;  
 	  
 	 u n s i g n e d   i n t   v s   =   g l C r e a t e S h a d e r ( G L _ V E R T E X _ S H A D E R ) ;  
 	 u n s i g n e d   i n t   f s   =   g l C r e a t e S h a d e r ( G L _ F R A G M E N T _ S H A D E R ) ;  
  
 	 g l S h a d e r S o u r c e ( v s ,   1 ,   ( c o n s t   c h a r * * ) & v e r t e x S h a d e r ,   0 ) ;  
 	 g l C o m p i l e S h a d e r ( v s ) ;  
  
 	 g l S h a d e r S o u r c e ( f s ,   1 ,   ( c o n s t   c h a r * * ) & f r a g m e n t S h a d e r ,   0 ) ;  
 	 g l C o m p i l e S h a d e r ( f s ) ;  
  
 	 m _ s h a d e r   =   g l C r e a t e P r o g r a m ( ) ;  
 	 g l A t t a c h S h a d e r ( m _ s h a d e r ,   v s ) ;  
 	 g l A t t a c h S h a d e r ( m _ s h a d e r ,   f s ) ;  
 	 g l B i n d A t t r i b L o c a t i o n ( m _ s h a d e r ,   0 ,   " p o s i t i o n " ) ;  
 	 g l B i n d A t t r i b L o c a t i o n ( m _ s h a d e r ,   1 ,   " c o l o u r " ) ;  
 	 g l B i n d A t t r i b L o c a t i o n ( m _ s h a d e r ,   2 ,   " t e x c o o r d " ) ;  
 	 g l L i n k P r o g r a m ( m _ s h a d e r ) ;  
  
 	 i n t   s u c c e s s   =   G L _ F A L S E ;  
 	 g l G e t P r o g r a m i v ( m _ s h a d e r ,   G L _ L I N K _ S T A T U S ,   & s u c c e s s ) ;  
 	 i f   ( s u c c e s s   = =   G L _ F A L S E )   {  
 	 	 i n t   i n f o L o g L e n g t h   =   0 ;  
 	 	 g l G e t P r o g r a m i v ( m _ s h a d e r ,   G L _ I N F O _ L O G _ L E N G T H ,   & i n f o L o g L e n g t h ) ;  
 	 	 c h a r *   i n f o L o g   =   n e w   c h a r [ i n f o L o g L e n g t h ] ;  
  
 	 	 g l G e t P r o g r a m I n f o L o g ( m _ s h a d e r ,   i n f o L o g L e n g t h ,   0 ,   i n f o L o g ) ;  
 	 	 p r i n t f ( " E r r o r :   F a i l e d   t o   l i n k   S p r i t e B a t c h   s h a d e r   p r o g r a m ! \ n % s \ n " ,   i n f o L o g ) ;  
 	 	 d e l e t e [ ]   i n f o L o g ;  
 	 }  
  
 	 g l U s e P r o g r a m ( m _ s h a d e r ) ;  
  
 	 / /   s e t   t e x t u r e   l o c a t i o n s  
 	 c h a r   b u f [ 3 2 ] ;  
 	 f o r   ( i n t   i   =   0 ;   i   <   T E X T U R E _ S T A C K _ S I Z E ;   + + i )   {  
 	 	 s p r i n t f _ s ( b u f ,   " t e x t u r e S t a c k [ % i ] " ,   i ) ;  
 	 	 g l U n i f o r m 1 i ( g l G e t U n i f o r m L o c a t i o n ( m _ s h a d e r ,   b u f ) ,   i ) ;  
 	 }  
  
 	 g l U s e P r o g r a m ( 0 ) ;  
  
 	 g l D e l e t e S h a d e r ( v s ) ;  
 	 g l D e l e t e S h a d e r ( f s ) ;  
 	  
 	 / /   p r e   c a l c u l a t e   t h e   i n d i c e s . . .   t h e y   w i l l   a l w a y s   b e   t h e   s a m e  
 	 i n t   i n d e x   =   0 ;  
 	 f o r   ( i n t   i   =   0 ;   i < ( M A X _ S P R I T E S * 6 ) ; )   {  
 	 	 m _ i n d i c e s [ i + + ]   =   ( i n d e x   +   0 ) ;  
 	 	 m _ i n d i c e s [ i + + ]   =   ( i n d e x   +   1 ) ;  
 	 	 m _ i n d i c e s [ i + + ]   =   ( i n d e x   +   2 ) ;  
  
 	 	 m _ i n d i c e s [ i + + ]   =   ( i n d e x   +   0 ) ;  
 	 	 m _ i n d i c e s [ i + + ]   =   ( i n d e x   +   2 ) ;  
 	 	 m _ i n d i c e s [ i + + ]   =   ( i n d e x   +   3 ) ;  
 	 	 i n d e x   + =   4 ;  
 	 }  
 	  
 	 / /   c r e a t e   t h e   v a o ,   v i o   a n d   v b o  
 	 g l G e n V e r t e x A r r a y s ( 1 ,   & m _ v a o ) ;  
 	 g l B i n d V e r t e x A r r a y ( m _ v a o ) ;  
 	 g l G e n B u f f e r s ( 1 ,   & m _ v b o ) ;  
 	 g l G e n B u f f e r s ( 1 ,   & m _ i b o ) ;  
 	 g l B i n d B u f f e r ( G L _ A R R A Y _ B U F F E R ,   m _ v b o ) ;  
 	 g l B i n d B u f f e r ( G L _ E L E M E N T _ A R R A Y _ B U F F E R ,   m _ i b o ) ;  
 	 g l B u f f e r D a t a ( G L _ E L E M E N T _ A R R A Y _ B U F F E R ,   ( M A X _ S P R I T E S   *   6 )   *   s i z e o f ( u n s i g n e d   s h o r t ) ,   ( v o i d   * ) ( & m _ i n d i c e s [ 0 ] ) ,   G L _ S T A T I C _ D R A W ) ;  
 	 g l B u f f e r D a t a ( G L _ A R R A Y _ B U F F E R ,   ( M A X _ S P R I T E S   *   4 )   *   s i z e o f ( S B V e r t e x ) ,   m _ v e r t i c e s ,   G L _ S T A T I C _ D R A W ) ;  
 	 g l E n a b l e V e r t e x A t t r i b A r r a y ( 0 ) ;  
 	 g l E n a b l e V e r t e x A t t r i b A r r a y ( 1 ) ;  
 	 g l E n a b l e V e r t e x A t t r i b A r r a y ( 2 ) ;  
 	 g l V e r t e x A t t r i b P o i n t e r ( 0 ,   4 ,   G L _ F L O A T ,   G L _ F A L S E ,   s i z e o f ( S B V e r t e x ) ,   ( c h a r   * ) 0 ) ;  
 	 g l V e r t e x A t t r i b P o i n t e r ( 1 ,   4 ,   G L _ F L O A T ,   G L _ F A L S E ,   s i z e o f ( S B V e r t e x ) ,   ( c h a r   * ) 1 6 ) ;  
 	 g l V e r t e x A t t r i b P o i n t e r ( 2 ,   2 ,   G L _ F L O A T ,   G L _ F A L S E ,   s i z e o f ( S B V e r t e x ) ,   ( c h a r   * ) 3 2 ) ;  
 	 g l B i n d V e r t e x A r r a y ( 0 ) ;  
 }  
  
 R e n d e r e r 2 D : : ~ R e n d e r e r 2 D ( )   {  
 	 g l D e l e t e B u f f e r s ( 1 ,   & m _ v b o ) ;  
 	 g l D e l e t e B u f f e r s ( 1 ,   & m _ i b o ) ;  
 	 g l D e l e t e B u f f e r s ( 1 ,   & m _ v a o ) ;  
 	 g l D e l e t e P r o g r a m ( m _ s h a d e r ) ;  
 	 d e l e t e   m _ n u l l T e x t u r e ;  
 }  
  
 v o i d   R e n d e r e r 2 D : : b e g i n ( )   {  
 	 m _ r e n d e r B e g u n   =   t r u e ;  
 	 m _ c u r r e n t I n d e x   =   0 ;  
 	 m _ c u r r e n t V e r t e x   =   0 ;  
 	 m _ c u r r e n t T e x t u r e   =   0 ;  
  
 	 i n t   w i d t h   =   0 ,   h e i g h t   =   0 ;  
 	 a u t o   w i n d o w   =   g l f w G e t C u r r e n t C o n t e x t ( ) ;  
 	 g l f w G e t W i n d o w S i z e ( w i n d o w ,   & w i d t h ,   & h e i g h t ) ;  
 	  
 	 g l U s e P r o g r a m ( m _ s h a d e r ) ;  
  
 	 / /   s c a l e   t h e   w i d t h / h e i g h t   b a s e d   o n   c a m e r a S c a l e  
 	 f l o a t   s c a l e d W i d t h   =   ( f l o a t ) w i d t h   *   m _ c a m e r a S c a l e ;  
 	 f l o a t   s c a l e d H e i g h t   =   ( f l o a t ) h e i g h t   *   m _ c a m e r a S c a l e ;  
  
 	 / /   g e t   t h e   m i d d l e   o f   t h e   w i n d o w   i n   o r d e r   t o   g e t   t h e   s c a l e d   b o u n d s  
 	 f l o a t   m i d X   =   m _ c a m e r a X   +   ( w i d t h     *   0 . 5 f ) ;  
 	 f l o a t   m i d Y   =   m _ c a m e r a Y   +   ( h e i g h t   *   0 . 5 f ) ;  
  
 	 / /   g e t   t h e   b o u n d s   t o   u s e   i n   t h e   p r o j e c t i o n   m a t r i x  
 	 f l o a t   t o p   =   m i d Y   +   ( s c a l e d H e i g h t   *   0 . 5 f ) ;  
 	 f l o a t   r i g h t   =   m i d X   +   ( s c a l e d W i d t h   *   0 . 5 f ) ;  
 	 f l o a t   b o t t o m   =   m i d Y   -   ( s c a l e d H e i g h t   *   0 . 5 f ) ;  
 	 f l o a t   l e f t   =   m i d X   -   ( s c a l e d W i d t h   *   0 . 5 f ) ;  
  
 	 a u t o   p r o j e c t i o n   =   g l m : : o r t h o ( l e f t ,   r i g h t ,   b o t t o m ,   t o p ,   1 . 0 f ,   - 1 0 1 . 0 f ) ;  
 	 g l U n i f o r m M a t r i x 4 f v ( g l G e t U n i f o r m L o c a t i o n ( m _ s h a d e r ,   " p r o j e c t i o n M a t r i x " ) ,   1 ,   f a l s e ,   & p r o j e c t i o n [ 0 ] [ 0 ] ) ;  
  
 	 g l E n a b l e ( G L _ B L E N D ) ;  
 	 g l B l e n d F u n c ( G L _ S R C _ A L P H A ,   G L _ O N E _ M I N U S _ S R C _ A L P H A ) ;  
  
 	 s e t R e n d e r C o l o u r ( 1 , 1 , 1 , 1 ) ;  
 }  
  
 v o i d   R e n d e r e r 2 D : : e n d ( )   {  
 	 i f   ( m _ r e n d e r B e g u n   = =   f a l s e )  
 	 	 r e t u r n ;  
  
 	 f l u s h B a t c h ( ) ;  
  
 	 g l U s e P r o g r a m ( 0 ) ;  
  
 	 m _ r e n d e r B e g u n   =   f a l s e ;  
 }  
  
 v o i d   R e n d e r e r 2 D : : d r a w B o x ( f l o a t   x P o s ,   f l o a t   y P o s ,   f l o a t   w i d t h ,   f l o a t   h e i g h t ,   f l o a t   r o t a t i o n ,   f l o a t   d e p t h )   {  
 	 d r a w S p r i t e ( n u l l p t r ,   x P o s ,   y P o s ,   w i d t h ,   h e i g h t ,   r o t a t i o n ,   d e p t h ) ;  
 }  
  
 v o i d   R e n d e r e r 2 D : : d r a w C i r c l e ( f l o a t   x P o s ,   f l o a t   y P o s ,   f l o a t   r a d i u s ,   f l o a t   d e p t h )   {  
  
 	 i f   ( s h o u l d F l u s h ( 3 3 , 9 6 ) )  
 	 	 f l u s h B a t c h ( ) ;  
 	 u n s i g n e d   i n t   t e x t u r e I D   =   p u s h T e x t u r e ( m _ n u l l T e x t u r e ) ;  
  
 	 i n t   s t a r t I n d e x   =   m _ c u r r e n t V e r t e x ;  
  
 	 / /   c e n t r e   v e r t e x  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 0 ]   =   x P o s ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 1 ]   =   y P o s ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 2 ]   =   d e p t h ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 3 ]   =   ( f l o a t ) t e x t u r e I D ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 0 ]   =   m _ r ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 1 ]   =   m _ g ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 2 ]   =   m _ b ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 3 ]   =   m _ a ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . t e x c o o r d [ 0 ]   =   0 ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . t e x c o o r d [ 1 ]   =   0 ;  
 	 m _ c u r r e n t V e r t e x + + ;  
  
 	 f l o a t   r o t D e l t a   =   g l m : : p i < f l o a t > ( )   *   2   /   3 2 ;  
  
 	 / /   3 2   s e g m e n t   s p h e r e  
 	 f o r   ( i n t   i   =   0 ;   i   <   3 2 ;   + + i )   {  
  
 	 	 i f   ( s h o u l d F l u s h ( ) )  
 	 	 	 f l u s h B a t c h ( ) ;  
  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 0 ]   =   g l m : : s i n ( r o t D e l t a   *   i )   *   r a d i u s   +   x P o s ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 1 ]   =   g l m : : c o s ( r o t D e l t a   *   i )   *   r a d i u s   +   y P o s ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 2 ]   =   d e p t h ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 3 ]   =   ( f l o a t ) t e x t u r e I D ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 0 ]   =   m _ r ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 1 ]   =   m _ g ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 2 ]   =   m _ b ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 3 ]   =   m _ a ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . t e x c o o r d [ 0 ]   =   0 . 5 f ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . t e x c o o r d [ 1 ]   =   0 . 5 f ;  
 	 	 m _ c u r r e n t V e r t e x + + ;  
  
 	 	 i f   ( i   = =   ( 3 2 - 1 ) )   {  
 	 	 	 m _ i n d i c e s [ m _ c u r r e n t I n d e x + + ]   =   s t a r t I n d e x ;  
 	 	 	 m _ i n d i c e s [ m _ c u r r e n t I n d e x + + ]   =   s t a r t I n d e x   +   1 ;  
 	 	 	 m _ i n d i c e s [ m _ c u r r e n t I n d e x + + ]   =   m _ c u r r e n t V e r t e x   -   1 ;  
 	 	 }  
 	 	 e l s e   {  
 	 	 	 m _ i n d i c e s [ m _ c u r r e n t I n d e x + + ]   =   s t a r t I n d e x ;  
 	 	 	 m _ i n d i c e s [ m _ c u r r e n t I n d e x + + ]   =   m _ c u r r e n t V e r t e x ;  
 	 	 	 m _ i n d i c e s [ m _ c u r r e n t I n d e x + + ]   =   m _ c u r r e n t V e r t e x   -   1 ;  
 	 	 }  
 	 }  
 }  
  
 v o i d   R e n d e r e r 2 D : : d r a w S p r i t e ( T e x t u r e   *   t e x t u r e ,  
 	 	 	 	 	 	 	   f l o a t   x P o s ,   f l o a t   y P o s ,    
 	 	 	 	 	 	 	   f l o a t   w i d t h ,   f l o a t   h e i g h t ,    
 	 	 	 	 	 	 	   f l o a t   r o t a t i o n ,   f l o a t   d e p t h ,   f l o a t   x O r i g i n ,   f l o a t   y O r i g i n )   {  
 	 i f   ( t e x t u r e   = =   n u l l p t r )  
 	 	 t e x t u r e   =   m _ n u l l T e x t u r e ;  
  
 	 i f   ( s h o u l d F l u s h ( ) )  
 	 	 f l u s h B a t c h ( ) ;  
 	 u n s i g n e d   i n t   t e x t u r e I D   =   p u s h T e x t u r e ( t e x t u r e ) ;  
  
 	 i f   ( w i d t h   = =   0 . 0 f )  
 	 	 w i d t h   =   ( f l o a t ) t e x t u r e - > g e t W i d t h ( ) ;  
 	 i f   ( h e i g h t   = =   0 . 0 f )  
 	 	 h e i g h t   =   ( f l o a t ) t e x t u r e - > g e t H e i g h t ( ) ;  
  
 	 f l o a t   t l X   =   ( 0 . 0 f   -   x O r i g i n )   *   w i d t h ; 	 	 f l o a t   t l Y   =   ( 0 . 0 f   -   y O r i g i n )   *   h e i g h t ;  
 	 f l o a t   t r X   =   ( 1 . 0 f   -   x O r i g i n )   *   w i d t h ; 	 	 f l o a t   t r Y   =   ( 0 . 0 f   -   y O r i g i n )   *   h e i g h t ;  
 	 f l o a t   b r X   =   ( 1 . 0 f   -   x O r i g i n )   *   w i d t h ; 	 	 f l o a t   b r Y   =   ( 1 . 0 f   -   y O r i g i n )   *   h e i g h t ;  
 	 f l o a t   b l X   =   ( 0 . 0 f   -   x O r i g i n )   *   w i d t h ; 	 	 f l o a t   b l Y   =   ( 1 . 0 f   -   y O r i g i n )   *   h e i g h t ;  
  
 	 i f   ( r o t a t i o n   ! =   0 . 0 f )   {  
 	 	 f l o a t   s i   =   g l m : : s i n ( r o t a t i o n ) ;   f l o a t   c o   =   g l m : : c o s ( r o t a t i o n ) ;  
 	 	 r o t a t e A r o u n d ( t l X ,   t l Y ,   t l X ,   t l Y ,   s i ,   c o ) ;  
 	 	 r o t a t e A r o u n d ( t r X ,   t r Y ,   t r X ,   t r Y ,   s i ,   c o ) ;  
 	 	 r o t a t e A r o u n d ( b r X ,   b r Y ,   b r X ,   b r Y ,   s i ,   c o ) ;  
 	 	 r o t a t e A r o u n d ( b l X ,   b l Y ,   b l X ,   b l Y ,   s i ,   c o ) ;  
 	 }  
  
 	 i n t   i n d e x   =   m _ c u r r e n t V e r t e x ;  
  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 0 ]   =   x P o s   +   t l X ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 1 ]   =   y P o s   +   t l Y ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 2 ]   =   d e p t h ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 3 ]   =   ( f l o a t ) t e x t u r e I D ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 0 ]   =   m _ r ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 1 ]   =   m _ g ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 2 ]   =   m _ b ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 3 ]   =   m _ a ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . t e x c o o r d [ 0 ]   =   m _ u v X ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . t e x c o o r d [ 1 ]   =   m _ u v Y   +   m _ u v H ;  
 	 m _ c u r r e n t V e r t e x + + ;  
  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 0 ]   =   x P o s   +   t r X ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 1 ]   =   y P o s   +   t r Y ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 2 ]   =   d e p t h ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 3 ]   =   ( f l o a t ) t e x t u r e I D ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 0 ]   =   m _ r ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 1 ]   =   m _ g ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 2 ]   =   m _ b ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 3 ]   =   m _ a ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . t e x c o o r d [ 0 ]   =   m _ u v X   +   m _ u v W ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . t e x c o o r d [ 1 ]   =   m _ u v Y   +   m _ u v H ;  
 	 m _ c u r r e n t V e r t e x + + ;  
  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 0 ]   =   x P o s   +   b r X ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 1 ]   =   y P o s   +   b r Y ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 2 ]   =   d e p t h ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 3 ]   =   ( f l o a t ) t e x t u r e I D ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 0 ]   =   m _ r ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 1 ]   =   m _ g ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 2 ]   =   m _ b ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 3 ]   =   m _ a ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . t e x c o o r d [ 0 ]   =   m _ u v X   +   m _ u v W ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . t e x c o o r d [ 1 ]   =   m _ u v Y ;  
 	 m _ c u r r e n t V e r t e x + + ;  
  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 0 ]   =   x P o s   +   b l X ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 1 ]   =   y P o s   +   b l Y ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 2 ]   =   d e p t h ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 3 ]   =   ( f l o a t ) t e x t u r e I D ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 0 ]   =   m _ r ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 1 ]   =   m _ g ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 2 ]   =   m _ b ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 3 ]   =   m _ a ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . t e x c o o r d [ 0 ]   =   m _ u v X ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . t e x c o o r d [ 1 ]   =   m _ u v Y ;  
 	 m _ c u r r e n t V e r t e x + + ;  
  
 	 m _ i n d i c e s [ m _ c u r r e n t I n d e x + + ]   =   ( i n d e x   +   0 ) ;  
 	 m _ i n d i c e s [ m _ c u r r e n t I n d e x + + ]   =   ( i n d e x   +   2 ) ;  
 	 m _ i n d i c e s [ m _ c u r r e n t I n d e x + + ]   =   ( i n d e x   +   3 ) ;  
  
 	 m _ i n d i c e s [ m _ c u r r e n t I n d e x + + ]   =   ( i n d e x   +   0 ) ;  
 	 m _ i n d i c e s [ m _ c u r r e n t I n d e x + + ]   =   ( i n d e x   +   1 ) ;  
 	 m _ i n d i c e s [ m _ c u r r e n t I n d e x + + ]   =   ( i n d e x   +   2 ) ;  
 }  
  
 v o i d   R e n d e r e r 2 D : : d r a w S p r i t e T r a n s f o r m e d 3 x 3 ( T e x t u r e   *   t e x t u r e ,  
 	 	 	 	 	 	 	 	 	 	       f l o a t   *   t r a n s f o r m M a t 3 x 3 ,    
 	 	 	 	 	 	 	 	 	 	       f l o a t   w i d t h ,   f l o a t   h e i g h t ,   f l o a t   d e p t h ,  
 	 	 	 	 	 	 	 	 	 	       f l o a t   x O r i g i n ,   f l o a t   y O r i g i n )   {  
 	 i f   ( t e x t u r e   = =   n u l l p t r )  
 	 	 t e x t u r e   =   m _ n u l l T e x t u r e ;  
  
 	 i f   ( s h o u l d F l u s h ( ) )  
 	 	 f l u s h B a t c h ( ) ;  
  
 	 u n s i g n e d   i n t   t e x t u r e I D   =   p u s h T e x t u r e ( t e x t u r e ) ;  
  
 	 i f   ( w i d t h   = =   0 . 0 f )  
 	 	 w i d t h   =   ( f l o a t ) t e x t u r e - > g e t W i d t h ( ) ;  
 	 i f   ( h e i g h t   = =   0 . 0 f )  
 	 	 h e i g h t   =   ( f l o a t ) t e x t u r e - > g e t H e i g h t ( ) ;  
  
 	 f l o a t   t l X   =   ( 0 . 0 f   -   x O r i g i n )   *   w i d t h ; 	 	 f l o a t   t l Y   =   ( 0 . 0 f   -   y O r i g i n )   *   h e i g h t ;  
 	 f l o a t   t r X   =   ( 1 . 0 f   -   x O r i g i n )   *   w i d t h ; 	 	 f l o a t   t r Y   =   ( 0 . 0 f   -   y O r i g i n )   *   h e i g h t ;  
 	 f l o a t   b r X   =   ( 1 . 0 f   -   x O r i g i n )   *   w i d t h ; 	 	 f l o a t   b r Y   =   ( 1 . 0 f   -   y O r i g i n )   *   h e i g h t ;  
 	 f l o a t   b l X   =   ( 0 . 0 f   -   x O r i g i n )   *   w i d t h ; 	 	 f l o a t   b l Y   =   ( 1 . 0 f   -   y O r i g i n )   *   h e i g h t ;  
  
 	 / /   t r a n s f o r m   t h e   p o i n t s   b y   t h e   m a t r i x  
 	 / /   0   3   6  
 	 / /   1   4   7  
 	 / /   2   5   8  
 	 f l o a t   x ,   y ;  
 	 x   =   t l X ;   y   =   t l Y ;  
 	 t l X   =   x   *   t r a n s f o r m M a t 3 x 3 [ 0 ]   +   y   *   t r a n s f o r m M a t 3 x 3 [ 3 ]   +   t r a n s f o r m M a t 3 x 3 [ 6 ] ;  
 	 t l Y   =   x   *   t r a n s f o r m M a t 3 x 3 [ 1 ]   +   y   *   t r a n s f o r m M a t 3 x 3 [ 4 ]   +   t r a n s f o r m M a t 3 x 3 [ 7 ] ;  
 	 x   =   t r X ;   y   =   t r Y ;  
 	 t r X   =   x   *   t r a n s f o r m M a t 3 x 3 [ 0 ]   +   y   *   t r a n s f o r m M a t 3 x 3 [ 3 ]   +   t r a n s f o r m M a t 3 x 3 [ 6 ] ;  
 	 t r Y   =   x   *   t r a n s f o r m M a t 3 x 3 [ 1 ]   +   y   *   t r a n s f o r m M a t 3 x 3 [ 4 ]   +   t r a n s f o r m M a t 3 x 3 [ 7 ] ;  
 	 x   =   b r X ;   y   =   b r Y ;  
 	 b r X   =   x   *   t r a n s f o r m M a t 3 x 3 [ 0 ]   +   y   *   t r a n s f o r m M a t 3 x 3 [ 3 ]   +   t r a n s f o r m M a t 3 x 3 [ 6 ] ;  
 	 b r Y   =   x   *   t r a n s f o r m M a t 3 x 3 [ 1 ]   +   y   *   t r a n s f o r m M a t 3 x 3 [ 4 ]   +   t r a n s f o r m M a t 3 x 3 [ 7 ] ;  
 	 x   =   b l X ;   y   =   b l Y ;  
 	 b l X   =   x   *   t r a n s f o r m M a t 3 x 3 [ 0 ]   +   y   *   t r a n s f o r m M a t 3 x 3 [ 3 ]   +   t r a n s f o r m M a t 3 x 3 [ 6 ] ;  
 	 b l Y   =   x   *   t r a n s f o r m M a t 3 x 3 [ 1 ]   +   y   *   t r a n s f o r m M a t 3 x 3 [ 4 ]   +   t r a n s f o r m M a t 3 x 3 [ 7 ] ; 	  
  
 	 i n t   i n d e x   =   m _ c u r r e n t V e r t e x ;  
 	  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 0 ]   =   t l X ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 1 ]   =   t l Y ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 2 ]   =   d e p t h ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 3 ]   =   ( f l o a t ) t e x t u r e I D ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 0 ]   =   m _ r ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 1 ]   =   m _ g ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 2 ]   =   m _ b ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 3 ]   =   m _ a ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . t e x c o o r d [ 0 ]   =   m _ u v X ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . t e x c o o r d [ 1 ]   =   m _ u v Y   +   m _ u v H ;  
 	 m _ c u r r e n t V e r t e x + + ;  
  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 0 ]   =   t r X ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 1 ]   =   t r Y ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 2 ]   =   d e p t h ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 3 ]   =   ( f l o a t ) t e x t u r e I D ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 0 ]   =   m _ r ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 1 ]   =   m _ g ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 2 ]   =   m _ b ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 3 ]   =   m _ a ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . t e x c o o r d [ 0 ]   =   m _ u v X   +   m _ u v W ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . t e x c o o r d [ 1 ]   =   m _ u v Y   +   m _ u v H ;  
 	 m _ c u r r e n t V e r t e x + + ;  
  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 0 ]   =   b r X ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 1 ]   =   b r Y ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 2 ]   =   d e p t h ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 3 ]   =   ( f l o a t ) t e x t u r e I D ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 0 ]   =   m _ r ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 1 ]   =   m _ g ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 2 ]   =   m _ b ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 3 ]   =   m _ a ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . t e x c o o r d [ 0 ]   =   m _ u v X   +   m _ u v W ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . t e x c o o r d [ 1 ]   =   m _ u v Y ;  
 	 m _ c u r r e n t V e r t e x + + ;  
  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 0 ]   =   b l X ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 1 ]   =   b l Y ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 2 ]   =   d e p t h ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 3 ]   =   ( f l o a t ) t e x t u r e I D ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 0 ]   =   m _ r ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 1 ]   =   m _ g ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 2 ]   =   m _ b ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 3 ]   =   m _ a ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . t e x c o o r d [ 0 ]   =   m _ u v X ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . t e x c o o r d [ 1 ]   =   m _ u v Y ;  
 	 m _ c u r r e n t V e r t e x + + ;  
  
 	 m _ i n d i c e s [ m _ c u r r e n t I n d e x + + ]   =   ( i n d e x   +   0 ) ;  
 	 m _ i n d i c e s [ m _ c u r r e n t I n d e x + + ]   =   ( i n d e x   +   2 ) ;  
 	 m _ i n d i c e s [ m _ c u r r e n t I n d e x + + ]   =   ( i n d e x   +   3 ) ;  
  
 	 m _ i n d i c e s [ m _ c u r r e n t I n d e x + + ]   =   ( i n d e x   +   0 ) ;  
 	 m _ i n d i c e s [ m _ c u r r e n t I n d e x + + ]   =   ( i n d e x   +   1 ) ;  
 	 m _ i n d i c e s [ m _ c u r r e n t I n d e x + + ]   =   ( i n d e x   +   2 ) ;  
 }  
  
 v o i d   R e n d e r e r 2 D : : d r a w S p r i t e T r a n s f o r m e d 4 x 4 ( T e x t u r e   *   t e x t u r e ,  
 	 	 	 	 	 	 	 	 	 	       f l o a t   *   t r a n s f o r m M a t 4 x 4 ,    
 	 	 	 	 	 	 	 	 	 	       f l o a t   w i d t h ,   f l o a t   h e i g h t ,   f l o a t   d e p t h ,  
 	 	 	 	 	 	 	 	 	 	       f l o a t   x O r i g i n ,   f l o a t   y O r i g i n )   {  
 	 i f   ( t e x t u r e   = =   n u l l p t r )  
 	 	 t e x t u r e   =   m _ n u l l T e x t u r e ;  
  
 	 i f   ( s h o u l d F l u s h ( ) )  
 	 	 f l u s h B a t c h ( ) ;  
 	 u n s i g n e d   i n t   t e x t u r e I D   =   p u s h T e x t u r e ( t e x t u r e ) ;  
  
 	 i f   ( w i d t h   = =   0 . 0 f )  
 	 	 w i d t h   =   ( f l o a t ) t e x t u r e - > g e t W i d t h ( ) ;  
 	 i f   ( h e i g h t   = =   0 . 0 f )  
 	 	 h e i g h t   =   ( f l o a t ) t e x t u r e - > g e t H e i g h t ( ) ;  
  
 	 f l o a t   t l X   =   ( 0 . 0 f   -   x O r i g i n )   *   w i d t h ; 	 	 f l o a t   t l Y   =   ( 0 . 0 f   -   y O r i g i n )   *   h e i g h t ;  
 	 f l o a t   t r X   =   ( 1 . 0 f   -   x O r i g i n )   *   w i d t h ; 	 	 f l o a t   t r Y   =   ( 0 . 0 f   -   y O r i g i n )   *   h e i g h t ;  
 	 f l o a t   b r X   =   ( 1 . 0 f   -   x O r i g i n )   *   w i d t h ; 	 	 f l o a t   b r Y   =   ( 1 . 0 f   -   y O r i g i n )   *   h e i g h t ;  
 	 f l o a t   b l X   =   ( 0 . 0 f   -   x O r i g i n )   *   w i d t h ; 	 	 f l o a t   b l Y   =   ( 1 . 0 f   -   y O r i g i n )   *   h e i g h t ;  
  
 	 / /   t r a n s f o r m   t h e   p o i n t s   b y   t h e   m a t r i x  
 	 / /   0   4   8     1 2  
 	 / /   1   5   9     1 3  
 	 / /   2   6   1 0   1 4  
 	 / /   3   7   1 1   1 5  
 	 f l o a t   x ,   y ;  
 	 x   =   t l X ;   y   =   t l Y ;  
 	 t l X   =   x   *   t r a n s f o r m M a t 4 x 4 [ 0 ]   +   y   *   t r a n s f o r m M a t 4 x 4 [ 4 ]   +   t r a n s f o r m M a t 4 x 4 [ 1 2 ] ;  
 	 t l Y   =   x   *   t r a n s f o r m M a t 4 x 4 [ 1 ]   +   y   *   t r a n s f o r m M a t 4 x 4 [ 5 ]   +   t r a n s f o r m M a t 4 x 4 [ 1 3 ] ;  
 	 x   =   t r X ;   y   =   t r Y ;  
 	 t r X   =   x   *   t r a n s f o r m M a t 4 x 4 [ 0 ]   +   y   *   t r a n s f o r m M a t 4 x 4 [ 4 ]   +   t r a n s f o r m M a t 4 x 4 [ 1 2 ] ;  
 	 t r Y   =   x   *   t r a n s f o r m M a t 4 x 4 [ 1 ]   +   y   *   t r a n s f o r m M a t 4 x 4 [ 5 ]   +   t r a n s f o r m M a t 4 x 4 [ 1 3 ] ;  
 	 x   =   b r X ;   y   =   b r Y ;  
 	 b r X   =   x   *   t r a n s f o r m M a t 4 x 4 [ 0 ]   +   y   *   t r a n s f o r m M a t 4 x 4 [ 4 ]   +   t r a n s f o r m M a t 4 x 4 [ 1 2 ] ;  
 	 b r Y   =   x   *   t r a n s f o r m M a t 4 x 4 [ 1 ]   +   y   *   t r a n s f o r m M a t 4 x 4 [ 5 ]   +   t r a n s f o r m M a t 4 x 4 [ 1 3 ] ;  
 	 x   =   b l X ;   y   =   b l Y ;  
 	 b l X   =   x   *   t r a n s f o r m M a t 4 x 4 [ 0 ]   +   y   *   t r a n s f o r m M a t 4 x 4 [ 4 ]   +   t r a n s f o r m M a t 4 x 4 [ 1 2 ] ;  
 	 b l Y   =   x   *   t r a n s f o r m M a t 4 x 4 [ 1 ]   +   y   *   t r a n s f o r m M a t 4 x 4 [ 5 ]   +   t r a n s f o r m M a t 4 x 4 [ 1 3 ] ;  
  
 	 i n t   i n d e x   =   m _ c u r r e n t V e r t e x ;  
  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 0 ]   =   t l X ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 1 ]   =   t l Y ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 2 ]   =   d e p t h ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 3 ]   =   ( f l o a t ) t e x t u r e I D ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 0 ]   =   m _ r ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 1 ]   =   m _ g ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 2 ]   =   m _ b ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 3 ]   =   m _ a ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . t e x c o o r d [ 0 ]   =   m _ u v X ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . t e x c o o r d [ 1 ]   =   m _ u v Y   +   m _ u v H ;  
 	 m _ c u r r e n t V e r t e x + + ;  
  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 0 ]   =   t r X ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 1 ]   =   t r Y ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 2 ]   =   d e p t h ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 3 ]   =   ( f l o a t ) t e x t u r e I D ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 0 ]   =   m _ r ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 1 ]   =   m _ g ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 2 ]   =   m _ b ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 3 ]   =   m _ a ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . t e x c o o r d [ 0 ]   =   m _ u v X   +   m _ u v W ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . t e x c o o r d [ 1 ]   =   m _ u v Y   +   m _ u v H ;  
 	 m _ c u r r e n t V e r t e x + + ;  
  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 0 ]   =   b r X ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 1 ]   =   b r Y ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 2 ]   =   d e p t h ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 3 ]   =   ( f l o a t ) t e x t u r e I D ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 0 ]   =   m _ r ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 1 ]   =   m _ g ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 2 ]   =   m _ b ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 3 ]   =   m _ a ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . t e x c o o r d [ 0 ]   =   m _ u v X   +   m _ u v W ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . t e x c o o r d [ 1 ]   =   m _ u v Y ;  
 	 m _ c u r r e n t V e r t e x + + ;  
  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 0 ]   =   b l X ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 1 ]   =   b l Y ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 2 ]   =   d e p t h ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 3 ]   =   ( f l o a t ) t e x t u r e I D ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 0 ]   =   m _ r ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 1 ]   =   m _ g ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 2 ]   =   m _ b ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 3 ]   =   m _ a ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . t e x c o o r d [ 0 ]   =   m _ u v X ;  
 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . t e x c o o r d [ 1 ]   =   m _ u v Y ;  
 	 m _ c u r r e n t V e r t e x + + ;  
 	  
 	 m _ i n d i c e s [ m _ c u r r e n t I n d e x + + ]   =   ( i n d e x   +   0 ) ;  
 	 m _ i n d i c e s [ m _ c u r r e n t I n d e x + + ]   =   ( i n d e x   +   2 ) ;  
 	 m _ i n d i c e s [ m _ c u r r e n t I n d e x + + ]   =   ( i n d e x   +   3 ) ;  
  
 	 m _ i n d i c e s [ m _ c u r r e n t I n d e x + + ]   =   ( i n d e x   +   0 ) ;  
 	 m _ i n d i c e s [ m _ c u r r e n t I n d e x + + ]   =   ( i n d e x   +   1 ) ;  
 	 m _ i n d i c e s [ m _ c u r r e n t I n d e x + + ]   =   ( i n d e x   +   2 ) ;  
 }  
  
 v o i d   R e n d e r e r 2 D : : d r a w L i n e ( f l o a t   x 1 ,   f l o a t   y 1 ,   f l o a t   x 2 ,   f l o a t   y 2 ,   f l o a t   t h i c k n e s s ,   f l o a t   d e p t h )   {  
  
 	 f l o a t   x D i f f   =   x 2   -   x 1 ;  
 	 f l o a t   y D i f f   =   y 2   -   y 1 ;  
 	 f l o a t   l e n   =   g l m : : s q r t ( x D i f f   *   x D i f f   +   y D i f f   *   y D i f f ) ;  
 	 f l o a t   x D i r   =   x D i f f   /   l e n ;  
 	 f l o a t   y D i r   =   y D i f f   /   l e n ;  
  
 	 f l o a t   r o t   =   g l m : : a t a n ( y D i r ,   x D i r ) ;  
  
 	 f l o a t   u v X   =   m _ u v X ;  
 	 f l o a t   u v Y   =   m _ u v Y ;  
 	 f l o a t   u v W   =   m _ u v W ;  
 	 f l o a t   u v H   =   m _ u v H ;  
  
 	 s e t U V R e c t ( 0 . 0 f ,   0 . 0 f ,   1 . 0 f ,   1 . 0 f ) ;  
  
 	 d r a w S p r i t e ( m _ n u l l T e x t u r e ,   x 1 ,   y 1 ,   l e n ,   t h i c k n e s s ,   r o t ,   d e p t h ,   0 . 0 f ,   0 . 5 f ) ;  
  
 	 s e t U V R e c t ( u v X ,   u v Y ,   u v W ,   u v H ) ;  
 }  
  
 v o i d   R e n d e r e r 2 D : : d r a w T e x t ( F o n t   *   f o n t ,   c o n s t   c h a r *   t e x t ,   f l o a t   x P o s ,   f l o a t   y P o s ,   f l o a t   d e p t h )   {  
  
 	 i f   ( f o n t   = =   n u l l p t r   | |  
 	 	 f o n t - > m _ g l H a n d l e   = =   0 )  
 	 	 r e t u r n ;  
  
 	 s t b t t _ a l i g n e d _ q u a d   Q   =   { } ;  
  
 	 i f   ( s h o u l d F l u s h ( )   | |   m _ c u r r e n t T e x t u r e   > =   T E X T U R E _ S T A C K _ S I Z E   -   1 )  
 	 	 f l u s h B a t c h ( ) ;  
  
 	 g l A c t i v e T e x t u r e ( G L _ T E X T U R E 0   +   m _ c u r r e n t T e x t u r e + + ) ;  
 	 g l B i n d T e x t u r e ( G L _ T E X T U R E _ 2 D ,   f o n t - > g e t T e x t u r e H a n d l e ( ) ) ;  
 	 g l A c t i v e T e x t u r e ( G L _ T E X T U R E 0 ) ;  
 	 m _ f o n t T e x t u r e [ m _ c u r r e n t T e x t u r e   -   1 ]   =   1 ;  
  
 	 / /   f o n t   r e n d e r s   t o p   t o   b o t t o m ,   s o   w e   n e e d   t o   i n v e r t   i t  
 	 i n t   w   =   0 ,   h   =   0 ;  
 	 g l f w G e t W i n d o w S i z e ( g l f w G e t C u r r e n t C o n t e x t ( ) ,   & w ,   & h ) ;  
  
 	 y P o s   =   h   -   y P o s ;  
  
 	 w h i l e   ( * t e x t   ! =   0 )   {  
  
 	 	 i f   ( s h o u l d F l u s h ( )   | |   m _ c u r r e n t T e x t u r e   > =   T E X T U R E _ S T A C K _ S I Z E   -   1 )   {  
 	 	 	 	 f l u s h B a t c h ( ) ;  
  
 	 	 	 g l A c t i v e T e x t u r e ( G L _ T E X T U R E 0   +   m _ c u r r e n t T e x t u r e + + ) ;  
 	 	 	 g l B i n d T e x t u r e ( G L _ T E X T U R E _ 2 D ,   f o n t - > g e t T e x t u r e H a n d l e ( ) ) ;  
 	 	 	 g l A c t i v e T e x t u r e ( G L _ T E X T U R E 0 ) ;  
 	 	 	 m _ f o n t T e x t u r e [ m _ c u r r e n t T e x t u r e   -   1 ]   =   1 ;  
 	 	 }  
  
 	 	 s t b t t _ G e t B a k e d Q u a d ( ( s t b t t _ b a k e d c h a r * ) f o n t - > m _ g l y p h D a t a ,   f o n t - > m _ t e x t u r e W i d t h ,   f o n t - > m _ t e x t u r e H e i g h t ,   ( u n s i g n e d   c h a r ) * t e x t ,   & x P o s ,   & y P o s ,   & Q ,   1 ) ;  
  
 	 	 i n t   i n d e x   =   m _ c u r r e n t V e r t e x ;  
  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 0 ]   =   Q . x 0 ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 1 ]   =   h   -   Q . y 1 ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 2 ]   =   d e p t h ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 3 ]   =   ( f l o a t ) m _ c u r r e n t T e x t u r e   -   1 ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 0 ]   =   m _ r ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 1 ]   =   m _ g ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 2 ]   =   m _ b ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 3 ]   =   m _ a ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . t e x c o o r d [ 0 ]   =   Q . s 0 ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . t e x c o o r d [ 1 ]   =   Q . t 1 ;  
 	 	 m _ c u r r e n t V e r t e x + + ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 0 ]   =   Q . x 1 ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 1 ]   =   h   -   Q . y 1 ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 2 ]   =   d e p t h ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 3 ]   =   ( f l o a t ) m _ c u r r e n t T e x t u r e   -   1 ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 0 ]   =   m _ r ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 1 ]   =   m _ g ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 2 ]   =   m _ b ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 3 ]   =   m _ a ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . t e x c o o r d [ 0 ]   =   Q . s 1 ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . t e x c o o r d [ 1 ]   =   Q . t 1 ;  
 	 	 m _ c u r r e n t V e r t e x + + ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 0 ]   =   Q . x 1 ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 1 ]   =   h   -   Q . y 0 ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 2 ]   =   d e p t h ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 3 ]   =   ( f l o a t ) m _ c u r r e n t T e x t u r e   -   1 ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 0 ]   =   m _ r ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 1 ]   =   m _ g ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 2 ]   =   m _ b ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 3 ]   =   m _ a ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . t e x c o o r d [ 0 ]   =   Q . s 1 ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . t e x c o o r d [ 1 ]   =   Q . t 0 ;  
 	 	 m _ c u r r e n t V e r t e x + + ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 0 ]   =   Q . x 0 ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 1 ]   =   h   -   Q . y 0 ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 2 ]   =   d e p t h ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . p o s [ 3 ]   =   ( f l o a t ) m _ c u r r e n t T e x t u r e   -   1 ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 0 ]   =   m _ r ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 1 ]   =   m _ g ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 2 ]   =   m _ b ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . c o l o r [ 3 ]   =   m _ a ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . t e x c o o r d [ 0 ]   =   Q . s 0 ;  
 	 	 m _ v e r t i c e s [ m _ c u r r e n t V e r t e x ] . t e x c o o r d [ 1 ]   =   Q . t 0 ;  
 	 	 m _ c u r r e n t V e r t e x + + ;  
 	 	  
 	 	 m _ i n d i c e s [ m _ c u r r e n t I n d e x + + ]   =   ( i n d e x   +   0 ) ;  
 	 	 m _ i n d i c e s [ m _ c u r r e n t I n d e x + + ]   =   ( i n d e x   +   2 ) ;  
 	 	 m _ i n d i c e s [ m _ c u r r e n t I n d e x + + ]   =   ( i n d e x   +   3 ) ;  
  
 	 	 m _ i n d i c e s [ m _ c u r r e n t I n d e x + + ]   =   ( i n d e x   +   0 ) ;  
 	 	 m _ i n d i c e s [ m _ c u r r e n t I n d e x + + ]   =   ( i n d e x   +   1 ) ;  
 	 	 m _ i n d i c e s [ m _ c u r r e n t I n d e x + + ]   =   ( i n d e x   +   2 ) ;  
  
 	 	 t e x t + + ;  
 	 }  
 }  
  
 b o o l   R e n d e r e r 2 D : : s h o u l d F l u s h ( i n t   a d d i t i o n a l V e r t i c e s ,   i n t   a d d i t i o n a l I n d i c e s )   {  
 	 r e t u r n   ( m _ c u r r e n t V e r t e x   +   a d d i t i o n a l V e r t i c e s )   > =   ( M A X _ S P R I T E S   *   4 )   | |    
 	 	 ( m _ c u r r e n t I n d e x   +   a d d i t i o n a l I n d i c e s )   > =   ( M A X _ S P R I T E S   *   6 ) ;  
 }  
  
 v o i d   R e n d e r e r 2 D : : f l u s h B a t c h ( )   {  
  
 	 / /   d o n t   r e n d e r   a n y t h i n g  
 	 i f   ( m _ c u r r e n t V e r t e x   = =   0   | |   m _ c u r r e n t I n d e x   = =   0   | |   m _ r e n d e r B e g u n   = =   f a l s e )  
 	 	 r e t u r n ;   c h a r   b u f [ 3 2 ] ;  
  
 	 f o r   ( i n t   i   =   0 ;   i   <   T E X T U R E _ S T A C K _ S I Z E ;   + + i )   {  
 	 	 s p r i n t f _ s ( b u f ,   " i s F o n t T e x t u r e [ % i ] " ,   i ) ;  
 	 	 g l U n i f o r m 1 i ( g l G e t U n i f o r m L o c a t i o n ( m _ s h a d e r ,   b u f ) ,   m _ f o n t T e x t u r e [ i ] ) ;  
 	 }  
  
 	 i n t   d e p t h F u n c   =   G L _ L E S S ;  
 	 g l G e t I n t e g e r v ( G L _ D E P T H _ F U N C ,   & d e p t h F u n c ) ;  
 	 g l D e p t h F u n c ( G L _ L E Q U A L ) ;  
  
 	 g l B i n d V e r t e x A r r a y ( m _ v a o ) ;  
 	 g l B i n d B u f f e r ( G L _ A R R A Y _ B U F F E R ,   m _ v b o ) ;  
 	 g l B i n d B u f f e r ( G L _ E L E M E N T _ A R R A Y _ B U F F E R ,   m _ i b o ) ;  
  
 	 g l B u f f e r S u b D a t a ( G L _ A R R A Y _ B U F F E R ,   0 ,   m _ c u r r e n t V e r t e x   *   s i z e o f ( S B V e r t e x ) ,   m _ v e r t i c e s ) ;  
 	 g l B u f f e r S u b D a t a ( G L _ E L E M E N T _ A R R A Y _ B U F F E R ,   0 ,   m _ c u r r e n t I n d e x   *   s i z e o f ( u n s i g n e d   s h o r t ) ,   m _ i n d i c e s ) ;  
  
 	 g l D r a w E l e m e n t s ( G L _ T R I A N G L E S ,   m _ c u r r e n t I n d e x ,   G L _ U N S I G N E D _ S H O R T ,   0 ) ;  
  
 	 g l B i n d V e r t e x A r r a y ( 0 ) ;  
  
 	 g l D e p t h F u n c ( d e p t h F u n c ) ;  
  
 	 / /   c l e a r   t h e   a c t i v e   t e x t u r e s  
 	 f o r   ( u n s i g n e d   i n t   i   =   0 ;   i   <   m _ c u r r e n t T e x t u r e ;   i + + )   {  
 	 	 m _ t e x t u r e S t a c k [ i ]   =   n u l l p t r ;  
 	 	 m _ f o n t T e x t u r e [ i ]   =   0 ;  
 	 }  
  
 	 / /   r e s e t   v e r t e x ,   i n d e x   a n d   t e x t u r e   c o u n t  
 	 m _ c u r r e n t I n d e x   =   0 ;  
 	 m _ c u r r e n t V e r t e x   =   0 ;  
 	 m _ c u r r e n t T e x t u r e   =   0 ;  
 }  
  
 u n s i g n e d   i n t   R e n d e r e r 2 D : : p u s h T e x t u r e ( T e x t u r e *   t e x t u r e )   {  
  
 	 / /   c h e c k   i f   t h e   t e x t u r e   i s   a l r e a d y   i n   u s e  
 	 / /   i f   s o ,   r e t u r n   a s   w e   d o n t   n e e d   t o   a d d   i t   t o   o u r   l i s t   o f   a c t i v e   t x t u r e s   a g a i n  
 	 f o r   ( u n s i g n e d   i n t   i   =   0 ;   i   < =   m _ c u r r e n t T e x t u r e ;   i + + )   {  
 	 	 i f   ( m _ t e x t u r e S t a c k [ i ]   = =   t e x t u r e )  
 	 	 	 r e t u r n   i ;  
 	 }  
  
 	 / /   i f   w e ' v e   u s e d   a l l   t h e   t e x t u r e s   w e   c a n ,   t h a n   w e   n e e d   t o   f l u s h   t o   m a k e   r o o m   f o r   a n o t h e r   t e x t u r e   c h a n g e  
 	 i f   ( m _ c u r r e n t T e x t u r e   > =   T E X T U R E _ S T A C K _ S I Z E   -   1 )  
 	 	 f l u s h B a t c h ( ) ;  
  
 	 / /   a d d   t h e   t e x t u r e   t o   o u r   a c t i v e   t e x t u r e   l i s t  
 	 m _ t e x t u r e S t a c k [ m _ c u r r e n t T e x t u r e ]   =   t e x t u r e ;  
  
 	 g l A c t i v e T e x t u r e ( G L _ T E X T U R E 0   +   m _ c u r r e n t T e x t u r e ) ;  
 	 g l B i n d T e x t u r e ( G L _ T E X T U R E _ 2 D ,   t e x t u r e - > g e t H a n d l e ( ) ) ;  
 	 g l A c t i v e T e x t u r e ( G L _ T E X T U R E 0 ) ;  
  
 	 / /   r e t u r n   w h a t   t h e   c u r r e n t   t e x t u r e   w a s   a n d   i n c r e m e n t  
 	 r e t u r n   m _ c u r r e n t T e x t u r e + + ;  
 }  
  
 v o i d   R e n d e r e r 2 D : : s e t R e n d e r C o l o u r ( f l o a t   r ,   f l o a t   g ,   f l o a t   b ,   f l o a t   a )   {  
 	 m _ r   =   r ;  
 	 m _ g   =   g ;  
 	 m _ b   =   b ;  
 	 m _ a   =   a ;  
 }  
  
 v o i d   R e n d e r e r 2 D : : s e t R e n d e r C o l o u r ( u n s i g n e d   i n t   c o l o u r )   {  
 	 m _ r   =   ( ( c o l o u r   &   0 x F F 0 0 0 0 0 0 )   > >   2 4 )   /   2 5 5 . 0 f ;  
 	 m _ g   =   ( ( c o l o u r   &   0 x 0 0 F F 0 0 0 0 )   > >   1 6 )   /   2 5 5 . 0 f ;  
 	 m _ b   =   ( ( c o l o u r   &   0 x 0 0 0 0 F F 0 0 )   > >   8 )   /   2 5 5 . 0 f ;  
 	 m _ a   =   ( ( c o l o u r   &   0 x 0 0 0 0 0 0 F F )   > >   0 )   /   2 5 5 . 0 f ;  
 }  
  
 v o i d   R e n d e r e r 2 D : : s e t U V R e c t ( f l o a t   u v X ,   f l o a t   u v Y ,   f l o a t   u v W ,   f l o a t   u v H )   {  
 	 m _ u v X   =   u v X ;  
 	 m _ u v Y   =   u v Y ;  
 	 m _ u v W   =   u v W ;  
 	 m _ u v H   =   u v H ;  
 }  
  
 v o i d   R e n d e r e r 2 D : : r o t a t e A r o u n d ( f l o a t   i n X ,   f l o a t   i n Y ,   f l o a t &   o u t X ,   f l o a t &   o u t Y ,   f l o a t   s i n ,   f l o a t   c o s )   {  
 	 o u t X   =   i n X   *   c o s   -   i n Y   *   s i n ;  
 	 o u t Y   =   i n X   *   s i n   +   i n Y   *   c o s ;  
 }  
  
 }   / /   n a m e s p a c e   a i e 