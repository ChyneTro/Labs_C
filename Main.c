#define PI 3.1415

double abss(double x) 
{
	if (x > 0) return x;
	else return -1 * x;
}


double sina(double x) 
{
	double tmp = x;
	double sum = tmp;
	int n = 0;

	while (abss(tmp) > 0.001) 
	{
		n++;
		tmp = tmp * (-1) * (x * x) / (2 * n) / (2 * n + 1);
		sum += tmp;
	}

	return sum;
}


int test_sin() 
{
	int r = 0;

	r = r || (abss(abss(sina(0)) - 0 >= 0.001));
	r = r || (abss(abss(sina(PI / 2)) - 1 >= 0.001));
	r = r || (abss(abss(sina(PI)) - 0 >= 0.001));
	r = r || (abss(abss(sina(3 * PI / 2)) - 1 >= 0.001));
	r = r || (abss(abss(sina(2 * PI)) - 0 >= 0.001));
	r = r || (abss(abss(sina(-1 * PI / 2)) - 1 >= 0.001));
	r = r || (abss(abss(sina(-1 * PI)) - 0 >= 0.001));
	r = r || (abss(abss(sina(-1 * 3 * PI / 2)) - 1 >= 0.001));
	r = r || (abss(abss(sina(-2 * PI)) - 0 >= 0.001));
	r = r || (abss(abss(sina(PI / 6)) - 0.5 >= 0.001));
	r = r || (abss(abss(sina(7 * PI / 6)) - 0.5 >= 0.001));

	return r;
}


int main()
{
	return test_sin();
}
