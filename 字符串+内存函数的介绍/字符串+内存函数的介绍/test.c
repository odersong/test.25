#include<assert.h>
#include<stdio.h>
#include<string.h>
//c���Զ��ַ����Ĵ����Ǻ�Ƶ���ģ�����c���Ա�����û���ַ������͵ģ��ַ���ͨ������ �����ַ����л��� �ַ������С��ַ��������ʺ�������Щ�����������޸ĵ��ַ���������

//strlen������ʵ�֣�strlen�ķ���ֵ��size_t=unsigned int
//1.����������
//2.�ݹ飺��������ʱ�����������ַ�������
//3.ָ��

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
//	char* p = a;//����һ��ָ��p�����׵�ַ������Ǳ���һ��ָ��Ҫ&a
//	assert(p);
//	while (*a)
//	{
//		a++;//a++�������һ������һ������Ϊ�ӵ�����һ����ʾ\0��������ѭ��������a�Ѿ��ӹ���
//	}
//	return a - p;//��ַ��Ӽ���ʾ����֮���Ԫ����
//}
//int main()
//{
//	char a[] = "abdef";
//	int ret= my_strlen(a);
//	printf("%d\n", ret);
//	return 0;
//}


//strlen�ķ���ֵ��size_t=unsigned int
//int main()
//{
//	if (strlen("abc") - strlen("abcdef") > 0)
//	{
//		printf("hehe\0");//��ӡhehe����Ϊstrlen�ķ���ֵ��size_t=unsigned int��û�и�����һ������0
//	}
//	else
//		printf("haha\0");
//	return 0;
//}


//strcpy  �ַ�������   ���ķ���ֵ��char* ����
//ԭ�ַ���������'\0'���� ����ֹԽ�����
//�Ὣԭ�ַ�����'\0'������Ŀ��ռ�
//Ŀ��ռ��㹻����ȷ���ܹ����ԭ�ַ���
//Ŀ��ռ����ɱ�
//ѧ��ģ��ʵ��

//int main()
//{
//	char a1[] = "abcdef";
//	char a2[] = "qwer";
//	strcpy_s(a1,sizeof(a1),a2);//sizeof(a1),�������Ҫ�ӣ���ֹԽ�����
//	printf("%s\n", a1);
//	return 0;
//}


//ʵ��my_strcpy    strcpy�ǰѺ�����ַ���������Ŀ�ĵ��ַ��������պ�������Ŀ�ĵ���Ԫ�ص�ַ���������ķ���ֵ��char*
//char* my_strcpy(char* dest, const char* src)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	char* p = dest;
//	while (*dest++ = *src++)//������ϸ��������ϸ��⣬����++�ȸ�ֵ��++
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



//strcat -�ַ���׷��   ����������char*
// ԭ�ַ���Ҫ��'\0',Ŀ�ĵ��ַ���ҲҪ��'\0'  �������棬a1��a2����'\0'����a1'\0'��׷���ַ�����ֱ��a2'\0'׷�ӹ���Ϊֹ
// Ŀ��ռ�����㹻��������ԭ�ַ���������
// Ŀ��ռ������޸�
// ����׷���Լ� --ע��--���Լ�׷�ӻ���Լ���\0Ū���������Ҳ���\0
//int main()
//{
//	char a1[8] = "abcd";
//	char a2[] = "efg";
//	strcat(a1, a2);
//	printf("%s\n", a1);
//	return 0;
//}


//ʵ��my_strcat
//char* my_strcat(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* p = dest;
//	//1.�ҵ�Ŀ�ĵ��ַ�����\0
//	while (*dest)
//	{
//		dest++;
//	}
//	//2.׷��
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




//strcmp�Ǵӵ�ַ�ҵ�ֵ���бȽϣ�����ֵ��int
//strcmp-��һ���ַ������ڵڶ����ַ��������ش���0����
//strcmp-��һ���ַ���С�ڵڶ����ַ���������С��0����
//strcmp-��һ���ַ������ڵڶ����ַ���������0
// strcmp��һ��һ���Ƚϣ���ȱȽ���һ��������ֱ�ӷ���
//int main()
//{
//	char* p1[] = "abcde";
//	char* a2[] = "sqrt";
//	if ("abcde" == "sqrt")//����Ǵ���ģ�����Ƚ��ǰ�a�ĵ�ַ��s�ĵ�ַ�Ƚ�
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


//ʵ��my_strcmp
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

//���Ȳ������Ƶ��ַ���������strcpy strcmp strcat

//���������Ƶ��ַ���������strncpy strncmp strncat

//strncpy
//int main()
//{
//	char a1[] = "abcdefg";
//	char a2[] = "ifghui";
//	strncpy_s(a1,sizeof(a1), a2, 4);//a1��"ifgh"
//	printf("%s\n", a1);
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//strncpy_s��strncpy��ͬ��_s��ӡ�����������\0,strncpy������������\0
//int main()
//{
//	char a1[20] = "abcdefg";
//	char a2[] = "if";
//	strncpy(a1, a2 , 1);//����ǿ���4�����Ǿ��ǰ�if������\0������ȥ
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


//strncat ׷�ӣ�����׷���ַ��󶼴�һ��\0����strcpy��ͬ

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
//	char a1[20] = "abcd\0efgpouiu";//\0����˼�ǵ�\0����ʼ׷��
//	char a2[] = "fgh";
//	strncat(a1, a2, 6);//���ֻ׷��fgh��һ��\0��   a1���ڴ��п��Կ���abcdfgh\0pouiu
//                                               //strncat_s���ڴ��в�ͬ�����Կ���abcdfgh\0
//	printf("%s\n", a1);
//	return 0;
//}



//strncmp-�ַ����Ƚ� ��n���ǱȽϼ����ַ�
//int main()
//{
//	const char* p1 = "abcde";
//	const char* p2 = "abcfg";
//	int ret = strncmp(p1, p2, 4);
//	printf("%d\n", ret);
//	return 0;
//}



//strstr�ַ�������   ͨ����ַ�Ƚϲ����ַ��������ص�ַchar*
//int main()
//{
//	char* p1 = "abceag";
//	char* p2 = "ce";
//	char* ret = strstr(p1, p2);
//	if (ret == NULL)
//	{
//		printf("�Ҳ�����ͬ�ַ���");
//	}
//	else
//	{
//		printf("%s\n", ret);//ceag,��Ϊ���ص��ǵ�ַ����ӡ�ַ������׵�ַ��ʼ��\0
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
//		printf("�Ҳ�����ͬ�ַ���");
//	}
//	else
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}


