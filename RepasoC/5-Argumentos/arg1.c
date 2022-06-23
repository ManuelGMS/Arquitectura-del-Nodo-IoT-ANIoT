/************* TAREAS
 * Compila el código y ejecútalo. Responde:
 +
 + gcc arg1.c -o main ; ./main
 +
 * 1. ¿Por qué el valor de xc no se modifica tras la llamada a sumC? ¿Dónde se modifca esa información?
 +
 + Como el struct se está pasando por valor la modificación solamente tiene efecto dentro de sumC. 
 +
 * 2. Comenta las dos declaraciones adelantadas de sum() y sumC(). Compila de nuevo, ¿Qué ocurre?
 +
 + Se produce un error ya que al comentarse las cabeceras y procesar en primer lugar el main,
 + cuando este se compila no tiene ninguna referencia de qué y cómo son las funciones sum y sumC.
 +
 ********************/

#include <stdio.h>

/* Tipo estructurado */
struct _complex_ {
	float re;
	float im;
};

/* Declaración adelantada */
int sum(int a, int b);
struct _complex_  sumC(struct _complex_ a, struct _complex_ b);

int main(void) {
	
	int x = 4,y = 5;
	struct _complex_  xc = {.re = 1.0, .im = 2.0};
	struct _complex_  yc = {.re = 3.0, .im = 1.0};
	struct _complex_  zc; 

	zc = sumC(xc,yc);

	int total = sum(x,y); 
	
	printf("Suma de complejos. (%f,%f i) + (%f,%f i) =(%f,%f i)\n",xc.re,xc.im,yc.re,yc.im,zc.re,zc.im);
	printf("Suma de enteros:  x +y = %d + %d = %d \n",x,y, total);
	
	return 0;

}

int sum(int x, int y) {  
	int c;
	c = x + y;
	x = 7;
	y = 3;  
	return c;         
}

struct _complex_  sumC(struct _complex_ a,  struct _complex_ b) {
		struct _complex_ r;
		r.re = a.re + b.re;
		r.im = a.im + b.im;
		// Tratamos de modificar el primer argumento
		a.re = 12.5;
		a.im = 13.4;
		return r;
}
