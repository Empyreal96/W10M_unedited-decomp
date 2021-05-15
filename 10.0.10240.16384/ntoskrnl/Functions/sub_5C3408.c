// sub_5C3408 
 
int __fastcall sub_5C3408(int a1, unsigned int a2, _DWORD *a3, int *a4)
{
  int v4; // r6
  int result; // r0
  int v8; // r3

  v4 = 72;
  if ( a2 >= 0x48 )
  {
    *a3 = 72;
    KeQuerySystemTime(a3 + 4);
    v8 = a3[11];
    a3[12] = 72;
    a3[11] = v8 | 0x10;
    a3[13] = 1;
    a3[15] = 0;
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
    a3[12] = 72;
    v4 = 56;
  }
  result = 0;
  *a4 = v4;
  return result;
}
