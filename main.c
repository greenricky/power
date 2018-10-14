#include <stdio.h>
//base algorithm
double pow_exp_gt_0_base_alg(double base, int exp)
{
	double d_val = 1;
	while(exp-- >0)
		d_val *= base;

	return d_val;
}

//improved algorithm, high performance
double pow_exp_gt_0_improv_alg(double base, int exp)
{
	double d_val = 1;

	while(exp)
	{
		if(exp & 1)
			d_val *= base;

		base *=  base;
		exp = exp >> 1;
	}

	return d_val;
}

double power(double base, int exponent)
{
	double d_val = 1;
	
	if(0 == exponent)
		return 1;
	else if(exponent >0)
	{
		return pow_exp_gt_0_improv_alg(base, exponent);
	}
	else // exp < 0
	{
		if((base < 0.000001) && (base >-0.000001))
			return 0; //assert

		return 1/pow_exp_gt_0_base_alg(base, -exponent);	
	}
}

int main(int argc, char *argv[])
{
	double val = power(2, 3);
	printf("2^3 = %f\n", val);

	val = power(2, -3);
	printf("2^-3 = %f\n", val);
	val = power(0, -3);
	printf("0^-3 = %f\n", val);
	
	val = power(2, 0);
	printf("2^0 = %f\n", val);
	
	val = power(2, 11);
	printf("2^11 = %f\n", val);

	return 0;
}
