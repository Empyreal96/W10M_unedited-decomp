// MmDbgCopyMemory 
 
int __fastcall MmDbgCopyMemory(unsigned int a1, unsigned int a2, int a3, unsigned int a4, unsigned int a5)
{
  unsigned int v5; // r5
  int result; // r0
  unsigned int v10; // r4

  v5 = a4;
  if ( a5 != 4 && a5 > 2 )
    return sub_5434AC();
  result = 0;
  if ( a4 )
  {
    do
    {
      v10 = 4096 - (a1 & 0xFFF);
      if ( v10 > v5 )
        v10 = v5;
      result = MiDbgCopyMemory(a1, a2, a3, v10);
      if ( result < 0 )
        break;
      a2 = (__PAIR64__(a2, a1) + v10) >> 32;
      a1 += v10;
      a3 += v10;
      v5 -= v10;
    }
    while ( v5 );
  }
  return result;
}
