// sub_5C345C 
 
int __fastcall sub_5C345C(int a1, unsigned int a2, _DWORD *a3, int *a4)
{
  int v4; // r6
  int result; // r0

  v4 = 102;
  if ( a2 >= 0x66 )
  {
    *a3 = 102;
    KeQuerySystemTime(a3 + 4);
    a3[15] = 38;
    a3[14] = 64;
  }
  else
  {
    if ( a2 < 0x38 )
    {
      result = -1073741789;
      *a4 = 0;
      return result;
    }
    a3[11] = 32;
    a3[12] = 102;
    v4 = 56;
  }
  result = 0;
  *a4 = v4;
  return result;
}
