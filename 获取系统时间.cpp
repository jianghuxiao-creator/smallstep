
#include<iostream>
using namespace std;
#include <time.h>
#include <windows.h> 
int main()
{
    SYSTEMTIME st = {0};
 GetLocalTime(&st);
  cout<< st.wYear << "-" << st.wMonth << "-" <<  st.wDay << "   " <<
  st.wHour << ":"  <<  st.wMinute << ":" << st.wSecond;  
    return 0;
}
