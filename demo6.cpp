/*
C++ ����
�����ǹ̶�ֵ���ڳ���ִ���ڼ䲻��ı䡣��Щ�̶���ֵ���ֽ���������
�����������κεĻ����������ͣ��ɷ�Ϊ�������֡��������֡��ַ����ַ����Ͳ���ֵ
*/

// ��������
/*
��������������ʮ���ơ��˽��ƻ�ʮ�����Ƶĳ�����ǰ׺ָ��������0x �� 0X ��ʾʮ�����ƣ�0 ��ʾ�˽��ƣ�����ǰ׺��Ĭ�ϱ�ʾʮ���ơ�
��������Ҳ���Դ�һ����׺����׺�� U �� L ����ϣ�U ��ʾ�޷���������unsigned����L ��ʾ��������long����
��׺�����Ǵ�д��Ҳ������Сд��U �� L ��˳�����⡣
85         // ʮ����
0213       // �˽���
0x4b       // ʮ������
30         // ����
30u        // �޷�������
30l        // ������
30ul       // �޷��ų�����
*/

// ���㳣��
/*
���㳣�����������֡�С���㡢С�����ֺ�ָ��������ɡ�������ʹ��С����ʽ����ָ����ʽ����ʾ���㳣��
��ʹ��С����ʽ��ʾʱ����������������֡�С������
��ʹ��ָ����ʽ��ʾʱ�� �������С���㡢ָ���������ŵ�ָ������ e �� E �����
3.14159       // �Ϸ���
314159E-5L    // �Ϸ���
510E          // �Ƿ��ģ���������ָ��
210f          // �Ƿ��ģ�û��С����ָ��
.e55          // �Ƿ��ģ�ȱ�����������
*/

// ��������
/*
true ֵ������
false ֵ������
*/

// �ַ�����
/*
�ַ����������ڵ������С���������� L��������дʱ����ͷ�����ʾ����һ�����ַ����������� L'x'������ʱ������洢�� wchar_t ���͵ı����С�
����������һ��խ�ַ����������� 'x'������ʱ�����Դ洢�� char ���͵ļ򵥱�����.

#include <iostream>
using namespace std;

int main()
{
cout << "Hello\tWorld\n\n";
return 0;
}
*/

// �ַ�������
/*
�ַ�������ֵ����������˫���� "" �еġ�һ���ַ��������������ַ��������ַ�����ͨ���ַ���ת�����к�ͨ�õ��ַ�
*/

// ���峣��
/*
�� C++ �У������ּ򵥵Ķ��峣���ķ�ʽ��
ʹ�� #define Ԥ��������
ʹ�� const �ؼ��֡�
*/
// #define Ԥ������  �궨�岻����Ϊ�������ݸ�����,�궨�����ͨ��#undef��ʹ֮ǰ�ĺ궨��ʧЧ
#include <iostream>
using namespace std;

#define LENGTH 10   
#define WIDTH  5
#define NEWLINE '\n'

int main()
{

	int area;

	area = LENGTH * WIDTH;
	cout << "area��ֵ��: " << area;
	cout << NEWLINE;
	return 0;
}

// const �ؼ���: const�޶������Ժ��ǲ����Ըı�ģ������ڶ���ʱ���븳��ʼֵ��Ҫ��Ȼ�Ǵ���ġ�const���������ں����Ĳ����б��г���
/*
#include <iostream>
using namespace std;

int main()
{
const int  LENGTH = 10;
const int  WIDTH  = 5;
const char NEWLINE = '\n';
int area;

area = LENGTH * WIDTH;
cout << area;
cout << NEWLINE;
return 0;
}
*/
// ��ע�⣬�ѳ�������Ϊ��д��ĸ��ʽ����һ���ܺõı��ʵ��