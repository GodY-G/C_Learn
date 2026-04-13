#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int trans();

void print_rectangle(int line, int column) {
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < column; j++) {
			printf("#");
		}
		printf("\n");
		//此处缺少换行
	}
}

void test(void) {
	printf("test!\n");
	printf("test!\n");
	printf("test!\n");
}

int main() {
	printf("hello world!\n");
	test(); //这里需要使用F11才能进入到函数里面

	int a = 10;
	int b = 20;
	int sum = a + b;

	printf("请键盘输入一个int整数: ");
	int c;
	scanf("%d", &c);
	if (c > 0) {
		printf("您输入的数大于0!\n");
	}
	else if (c < 0) {
		printf("您输入的数小于0!\n");
	}
	else {
		printf("您输入的数就是0!\n");
	}

	printf("接下来开始打印一个矩形,请输入要打印矩形的行数和列数: \n");
	int line;
	int column;
	scanf("%d", &line);
	scanf("%d", &column);
	print_rectangle(line, column);



















	printf("第一题\n");
	printf("%d\n", sizeof(int));
	printf("%d\n", sizeof(short));
	printf("%d\n", sizeof(long));
	printf("%d\n", sizeof(long long));
	printf("%d\n", sizeof(double));
	printf("%d\n", sizeof(unsigned int));
	printf("--- --- --- ---\n");
	printf("第二题\n");
	trans();
	//什么是缓冲区？我们使用了哪些缓冲区？
	//输入或输出数据过快的时候，防止数据来不及使用就被覆盖而创建的缓冲区；打印机输出缓冲；
	
	//缓冲区的数据是先进先出还是后进先出？
	//缓冲区的数据是先进先出

	//scanf函数取出标准输入缓冲区的数据，使用%d和%c有什么区别？
	//%d 是取出整数，会忽略前置空白字符；%c 是取出字符，不会忽略前置空白字符

	//scanf函数的返回值是什么？如何输入一个EOF控制符，此时scanf的返回值是多少？
	//scanf返回值是整数，是成功读取的占位符的个数；在Windows当中按下（多次）ctrl+z可以输入EOF，此时scanf返回-1

	//
	return 0;
}