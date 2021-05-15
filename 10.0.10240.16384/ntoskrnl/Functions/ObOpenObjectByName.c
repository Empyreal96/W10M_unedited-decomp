// ObOpenObjectByName 
 
int __fastcall ObOpenObjectByName(int a1, int a2, int a3, int a4, int a5, int a6, _DWORD *a7)
{
  int result; // r0

  *a7 = 0;
  if ( a1 )
    result = sub_7FF478();
  else
    result = -1073741811;
  return result;
}
