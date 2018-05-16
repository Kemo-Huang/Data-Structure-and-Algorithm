#include <stdio.h>
#include <float.h>

float a = 1.0f;
double b = 1.0;

int main() {
	while (a + 1 != 1){
		a = a / 2.0f;
	}
	while (b + 1 != 1) {
		b = b / 2.0;
	}
	printf("The maximum value of float = %e\n", FLT_EPSILON);
	printf("The value of a is %e\n", a);
	printf("The minimum value of float = %e\n", DBL_EPSILON);
	printf("The value of b is %e\n", b);
}
