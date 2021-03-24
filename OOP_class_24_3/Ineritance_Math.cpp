#include <iostream>

using namespace std;

class baseMath
{
public:
	baseMath(){}
	bool isEven(int num)
	{
		if(num %2 == 0)
			return true;
		else
			return false;
	}
	int factorial(int num)
	{
	int result = 1;
	for(int i=1;i<=num; i++)
		{
			result*=i;
		}
	return result;
	}
};

class advancedMath:public baseMath
{
public:
	advancedMath(){}// : baseMath(){}
	double estimateEuler(int num)

	{
		double result = 1.0;
		for(int i=1; i<num;i++)
		{
			result = result + 1.0/(factorial(i));
		}
		return result;
	}

};
int main()
{
	advancedMath a;
	cout << a.estimateEuler(5);
}