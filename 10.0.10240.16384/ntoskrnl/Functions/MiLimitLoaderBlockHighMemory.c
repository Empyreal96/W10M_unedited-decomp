// MiLimitLoaderBlockHighMemory 
 
int __fastcall MiLimitLoaderBlockHighMemory(int a1, unsigned int a2)
{
  int result; // r0
  _DWORD *i; // r4
  _DWORD *v4; // t1
  int v5; // r2

  v4 = *(_DWORD **)(a1 + 24);
  result = a1 + 24;
  for ( i = v4; i != (_DWORD *)result; i = (_DWORD *)*i )
  {
    v5 = i[2];
    if ( v5 != 6 && v5 != 32 && v5 != 31 && v5 != 30 && v5 != 23 && v5 != 3 && v5 != 22 && i[4] + i[3] > a2 )
      return sub_96D664();
  }
  return result;
}
