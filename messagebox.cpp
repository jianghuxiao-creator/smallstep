#include<windows.h>
//�мǣ�������<windows.h>ʱ����Ҫ����MFC����Afx.h)
int main()
{
int result = MessageBox( NULL , TEXT("���ǶԻ���") , TEXT("���") , MB_ICONINFORMATION|MB_YESNO);
switch(result)/*ע�⣡ʹ��UnicodeӦ��TEXT��Χ�ִ�*/
{
case IDYES:MessageBox(NULL,TEXT("��ѡ����YES"),TEXT("YES"),MB_OK);break;
case IDNO:MessageBox(NULL,TEXT("��ѡ����NO"),TEXT("NO"),MB_OK);break;
}
return 0;
}
