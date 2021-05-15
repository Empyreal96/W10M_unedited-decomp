// KxSwapProcess 
 
unsigned int __fastcall KxSwapProcess(int a1, int a2)
{
  unsigned int v3; // r6
  unsigned int result; // r0
  unsigned int v5; // r4
  unsigned int *v7; // lr
  unsigned int v8; // r2
  unsigned int v9; // r2
  unsigned int v10; // r2
  unsigned int v11; // r2
  unsigned int v12; // r2
  unsigned int *v13; // r2
  unsigned int v14; // r1

  v3 = *(_DWORD *)(a1 + 28);
  result = *(_DWORD *)(a1 + 36);
  v5 = v3 & 0xFFFFC000;
  v7 = (unsigned int *)&KiAsidTable[32 * result];
  do
  {
    v8 = __ldrex(v7);
    v9 = v8 + 1;
  }
  while ( __strex(v9, v7) );
  if ( (v9 & 0xFFFFC000) != v5 )
  {
    do
    {
      do
        v10 = __ldrex(v7);
      while ( __strex(v10 - 1, v7) );
      KiAsidAlloc(a1);
      result = *(_DWORD *)(a1 + 36);
      v7 = (unsigned int *)&KiAsidTable[32 * result];
      do
      {
        v11 = __ldrex(v7);
        v12 = v11 + 1;
      }
      while ( __strex(v12, v7) );
    }
    while ( (v12 & 0xFFFFC000) != v5 );
  }
  if ( KiAsidA9Errata )
    return sub_50CDF8();
  __mcr(15, 0, 0xFFu, 13, 0, 1);
  __isb(0xFu);
  __mcr(15, 0, v3, 2, 0, 0);
  __isb(0xFu);
  __mcr(15, 0, result, 13, 0, 1);
  __isb(0xFu);
  v13 = (unsigned int *)&KiAsidTable[32 * *(_DWORD *)(a2 + 36)];
  do
    v14 = __ldrex(v13);
  while ( __strex(v14 - 1, v13) );
  return result;
}
