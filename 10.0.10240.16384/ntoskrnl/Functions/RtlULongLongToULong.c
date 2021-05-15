// RtlULongLongToULong 
 
int __fastcall RtlULongLongToULong(int a1, int a2, _DWORD *a3)
{
  int result; // r0

  if ( a2 )
  {
    result = -1073741675;
    *a3 = -1;
  }
  else
  {
    *a3 = a1;
    result = 0;
  }
  return result;
}
