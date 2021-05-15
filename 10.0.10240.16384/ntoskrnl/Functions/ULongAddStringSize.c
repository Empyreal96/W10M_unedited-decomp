// ULongAddStringSize 
 
int __fastcall ULongAddStringSize(unsigned int a1, unsigned __int16 *a2, unsigned int *a3)
{
  unsigned int v5; // r0
  int result; // r0
  unsigned int v7; // r3

  v5 = wcslen(a2);
  result = RtlULongLongToULong(2 * v5, (unsigned __int64)v5 >> 31, a3);
  if ( result >= 0 )
  {
    v7 = *a3 + a1;
    if ( v7 < a1 )
    {
      result = -1073741675;
      v7 = -1;
    }
    else
    {
      result = 0;
    }
    *a3 = v7;
  }
  return result;
}
