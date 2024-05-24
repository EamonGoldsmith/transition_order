#include <stdio.h>

// transition functions
void AtoB_func()
{
	printf("transitioning A to B\n");
}

void BtoC_func()
{
	printf("transitioning B to C\n");
}

void CtoD_func()
{
	printf("transitioning C to D\n");
}

void DtoE_func()
{
	printf("transitioning D to E\n");
}

void BtoA_func()
{
	printf("transitioning B to A\n");
}

void CtoB_func()
{
	printf("transitioning C to B\n");
}

void DtoC_func()
{
	printf("transitioning D to C\n");
}

void EtoD_func()
{
	printf("transitioning E to D\n");
}

// enum of states
enum states {
	A, B, C, D, E
};

typedef void (*func_ptr)();

// two list of function pointers
func_ptr forward[4] = {AtoB_func, BtoC_func, CtoD_func, DtoE_func};
func_ptr backward[4] = {BtoA_func, CtoB_func, DtoC_func, EtoD_func};

// transition from one state to another
void perform_transition(int start, int end)
{
	if (start == end) {
		return;
	}

	if (start > end) {
		// start - 1 because there are 1 more states than transitions
		backward[start - 1]();
		perform_transition(start - 1, end);
	}

	if (start < end) {
		forward[start]();
		perform_transition(start + 1, end);
	}
}

int main()
{
	// go from A to B
	puts("A to B");
	perform_transition(A, B);

	// go from E to C
	puts("E to C");
	perform_transition(E, A);

	return 0;
}



