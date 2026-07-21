#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int trans();

void print_rectangle(int line, int column) {
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < column; j++) {
			printf("#");
		}
		printf("\n");
		//�˴�ȱ�ٻ���
	}
}

int trans() {
	char c = '2';
	int a = '2' - '0';
	printf("%d\n", a);

	char m = 'a';
	char n = m - 32;
	printf("%c", n);

	return 0;
}

void test(void) {
	printf("test!\n");
	printf("test!\n");
	printf("test!\n");
}

int main() {
	printf("hello world!\n");
	test(); //������Ҫʹ��F11���ܽ��뵽��������

	int a = 10;
	int b = 20;
	int sum = a + b;

	printf("���������һ��int����: ");
	int c;
	scanf("%d", &c);
	if (c > 0) {
		printf("�������������0!\n");
	}
	else if (c < 0) {
		printf("���������С��0!\n");
	}
	else {
		printf("�������������0!\n");
	}

	printf("��������ʼ��ӡһ������,������Ҫ��ӡ���ε�����������: \n");
	int line;
	int column;   
	scanf("%d", &line);
	scanf("%d", &column);
	print_rectangle(line, column);



















	printf("��һ��\n");
	printf("%d\n", sizeof(int));
	printf("%d\n", sizeof(short));
	printf("%d\n", sizeof(long));
	printf("%d\n", sizeof(long long));
	printf("%d\n", sizeof(double));
	printf("%d\n", sizeof(unsigned int));
	printf("--- --- --- ---\n");
	printf("�ڶ���\n");
	trans();
	//ʲô�ǻ�����������ʹ������Щ��������
	//�����������ݹ����ʱ�򣬷�ֹ����������ʹ�þͱ����Ƕ������Ļ���������ӡ��������壻
	
	//���������������Ƚ��ȳ����Ǻ���ȳ���
	//���������������Ƚ��ȳ�

	//scanf����ȡ����׼���뻺���������ݣ�ʹ��%d��%c��ʲô����
	//%d ��ȡ�������������ǰ�ÿհ��ַ���%c ��ȡ���ַ����������ǰ�ÿհ��ַ�

	//scanf�����ķ���ֵ��ʲô���������һ��EOF���Ʒ�����ʱscanf�ķ���ֵ�Ƕ��٣�
	//scanf����ֵ���������ǳɹ���ȡ��ռλ���ĸ�������Windows���а��£���Σ�ctrl+z��������EOF����ʱscanf����-1

	//
	return 0;
}