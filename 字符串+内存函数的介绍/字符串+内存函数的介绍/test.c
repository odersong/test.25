#include<assert.h>
#include<stdio.h>
#include<string.h>
//c语言对字符串的处理是很频繁的，但是c语言本身是没有字符串类型的，字符串通常放在 常量字符串中或者 字符数组中。字符串常量适合用于那些不对他进行修改的字符串函数。

//strlen的三种实现，strlen的返回值是size_t=unsigned int
//1.计数器方法
//2.递归：不创建临时变量，计算字符串长度
//3.指针

//1
//int my_strlen(const char* a)
//{
//	assert(a);
//	int count = 0;
//	while (*a!='\0')//(*a)
//	{
//		count++;
//		a++;
//	}
//	return count;
//}
//int main()
//{
//	char a[] = "abdef";
//	int ret= my_strlen(a);
//	printf("%d\n", ret);
//	return 0;
//}


//2
//int my_strlen(const char* a)
//{
//	if (*a)
//	{
//		a++;
//		return 1 + my_strlen(a);
//	}
//}
//int main()
//{
//	char a[] = "abdef";
//	int ret= my_strlen(a);
//	printf("%d\n", ret);
//	return 0;
//}



//3
//char* my_strlen(const char* a)
//{
//	assert(a);
//	char* p = a;//定义一个指针p保存首地址，如果是保存一级指针要&a
//	assert(p);
//	while (*a)
//	{
//		a++;//a++，到最后一定会多出一个，因为加到的那一个表示\0，不进入循环，但是a已经加过了
//	}
//	return a - p;//地址相加减表示两地之间的元素数
//}
//int main()
//{
//	char a[] = "abdef";
//	int ret= my_strlen(a);
//	printf("%d\n", ret);
//	return 0;
//}


//strlen的返回值是size_t=unsigned int
//int main()
//{
//	if (strlen("abc") - strlen("abcdef") > 0)
//	{
//		printf("hehe\0");//打印hehe，因为strlen的返回值是size_t=unsigned int，没有负数，一定大于0
//	}
//	else
//		printf("haha\0");
//	return 0;
//}


//strcpy  字符串拷贝   他的返回值是char* 类型
//原字符串必须以'\0'结束 ，防止越界访问
//会将原字符串的'\0'拷贝到目标空间
//目标空间足够大，以确保能够存放原字符串
//目标空间必须可变
//学会模拟实现

//int main()
//{
//	char a1[] = "abcdef";
//	char a2[] = "qwer";
//	strcpy_s(a1,sizeof(a1),a2);//sizeof(a1),这个必须要加，防止越界访问
//	printf("%s\n", a1);
//	return 0;
//}


//实现my_strcpy    strcpy是把后面的字符串拷贝到目的地字符串，最终函数返回目的地首元素地址，所以他的返回值是char*
//char* my_strcpy(char* dest, const char* src)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	char* p = dest;
//	while (*dest++ = *src++)//这里仔细看看，仔细理解，后置++先赋值再++
//	{
//		;
//	}
//	return p;
//}
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "bit";
//	printf("%s\n", my_strcpy(arr1, arr2));
//	return 0;
//}



//strcat -字符串追加   返回类型是char*
// 原字符串要有'\0',目的地字符串也要有'\0'  比如下面，a1，a2都有'\0'，再a1'\0'处追加字符串，直到a2'\0'追加过来为止
// 目标空间必须足够大，能容纳原字符串的内容
// 目标空间必须可修改
// 不能追加自己 --注意--给自己追加会把自己的\0弄掉，导致找不大\0
//int main()
//{
//	char a1[8] = "abcd";
//	char a2[] = "efg";
//	strcat(a1, a2);
//	printf("%s\n", a1);
//	return 0;
//}


//实现my_strcat
//char* my_strcat(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* p = dest;
//	//1.找到目的地字符串的\0
//	while (*dest)
//	{
//		dest++;
//	}
//	//2.追加
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return p;
//}
//int main()
//{
//	char a1[20] = "abcde";
//	char a2[] = "fghj";
//	printf("%s\n", my_strcat(a1, a2));
//	return 0;
//}




//strcmp是从地址找到值进行比较，返回值是int
//strcmp-第一个字符串大于第二个字符串，返回大于0的数
//strcmp-第一个字符串小于第二个字符串，返回小于0的数
//strcmp-第一个字符串等于第二个字符串，返回0
// strcmp是一个一个比较，相等比较下一个，不等直接返回
//int main()
//{
//	char* p1[] = "abcde";
//	char* a2[] = "sqrt";
//	if ("abcde" == "sqrt")//这个是错误的，这个比较是吧a的地址和s的地址比较
//	return 0;
//}

//int main()
//{
//	char a1[] = "abcd";
//	char a2[] = "abcf";
//	int p = (strcmp(a1, a2));
//	printf("%d\n", p);
//	return 0;
//}


//实现my_strcmp
//int my_strcmp(const char* q, const char* e)
//{
//	assert(q && e);
//	while (*q == *e)
//	{
//		if (*q == '\0')
//		{
//			return 0;
//		}
//		q++;
//		e++;
//	}
//	if (*q > *e)
//	{
//		return 1;
//	}
//	else
//	{
//		return -1;
//	}
//}
//int main()
//{
//	char a1[] = "abcd";
//	char a2[] = "abcf";
//	int ret = my_strcmp(a1, a2);
//	printf("%d\n", ret);
//	return 0;
//}

//长度不受限制的字符串函数：strcpy strcmp strcat

//长度受限制的字符串函数：strncpy strncmp strncat

//strncpy
//int main()
//{
//	char a1[] = "abcdefg";
//	char a2[] = "ifghui";
//	strncpy_s(a1,sizeof(a1), a2, 4);//a1："ifgh"
//	printf("%s\n", a1);
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//strncpy_s和strncpy不同，_s打印拷贝过来后加\0,strncpy拷贝过来不加\0
//int main()
//{
//	char a1[20] = "abcdefg";
//	char a2[] = "if";
//	strncpy(a1, a2 , 1);//如果是拷贝4个，那就是把if和两个\0拷贝过去
//	printf("%s\n", a1);
//	return 0;
//}

//int main()
//{
//	char a1[20] = "abcdefg";
//	char a2[] = "if";
//	strncpy_s(a1, sizeof(a1), a2, 1);
//	printf("%s\n", a1);
//	return 0;
//}


//strncat 追加，但是追加字符后都带一个\0，和strcpy不同

//int main()
//{
//	char a1[20] = "abcd";
//	char a2[] = "fgh";
//	strncat(a1, a2, 6);
//	printf("%s\n", a1);
//	return 0;
//}

//int main()
//{
//	char a1[20] = "abcd\0efgpouiu";//\0的意思是到\0出开始追加
//	char a2[] = "fgh";
//	strncat(a1, a2, 6);//这个只追加fgh和一个\0，   a1在内存中可以看到abcdfgh\0pouiu
//                                               //strncat_s在内存中不同，可以看到abcdfgh\0
//	printf("%s\n", a1);
//	return 0;
//}



//strncmp-字符串比较 有n就是比较几个字符
//int main()
//{
//	const char* p1 = "abcde";
//	const char* p2 = "abcfg";
//	int ret = strncmp(p1, p2, 4);
//	printf("%d\n", ret);
//	return 0;
//}



//strstr字符串查找   通过地址比较查找字符串，返回地址char*
//int main()
//{
//	char* p1 = "abceag";
//	char* p2 = "ce";
//	char* ret = strstr(p1, p2);
//	if (ret == NULL)
//	{
//		printf("找不到相同字符串");
//	}
//	else
//	{
//		printf("%s\n", ret);//ceag,因为返回的是地址，打印字符串从首地址开始到\0
//	}
//	return 0;
//}


//my_strstr
//char* my_strstr(const char* p1, const char* p2)
//{
//	assert(p1 && p2);
//	char* pp1 = NULL;
//	char* pp2 = NULL;
//	char* op1 = (char*)p1;
//	if (!*p2)   //!*p2--*p2=='\0'
//	{
//		return (char*)p1;
//	}
//	while (*op1)
//	{
//		char* pp1 = op1;
//		char* pp2 = (char*)p2;
//		while (*pp1 == *pp2 && *pp1 && *pp2)
//		{
//			pp1++;
//			pp2++;
//		}
//		if (!*pp2)
//		{
//			return op1;
//		}
//		op1++;
//		if (!*pp1)
//		{
//			return NULL;
//		}
//	}
//	return NULL;
//}
//int main()
//{
//	const char* p1 = "abcdfghijk";
//	const char* p2 = "df";
//	char* ret = my_strstr(p1, p2);
//	if (ret == NULL)
//	{
//		printf("找不到相同字符串");
//	}
//	else
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}


