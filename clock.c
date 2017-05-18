#include <time.h>
#include <stdio.h>

/*计时函数(精度为1ms)
clock_t clock(void);
typedef long clock_t
#define CLOCKS_PER_SEC ((clock_t)1000)
意思是每过千分之一秒(1ms),clock()函数的返回值就会加1
*/

int main(int argc, char const *argv[])
{
	unsigned i = 0-1;
	clock_t start, finish;
	double duration;

	//测试一个事件的持续时间
	printf("%u loops last: ", i);
	start = clock();
	while (i-- != 0)
	{
		;
	}
	finish = clock();
	printf("%lf ms\n", (double)(finish-start));
	duration = (double)(finish-start) / CLOCKS_PER_SEC;  //运算结果表示CLOCKS_PER_SEC为10^6
	printf("%lf s\n", duration);

	// system("pause");		//执行一条shell命令(类似于)
	return 0;
}
