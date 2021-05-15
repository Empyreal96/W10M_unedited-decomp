// KiAsidInitialize 
 
unsigned int *__fastcall KiAsidInitialize(int a1, int a2)
{
  unsigned int v3; // r4
  unsigned int v4; // r2
  unsigned int v5; // r1
  unsigned int *result; // r0
  unsigned int v7; // r2
  unsigned int v8; // r2
  int *v9; // r3
  int v10; // r2
  unsigned int v11; // r2

  if ( !a1 )
  {
    if ( (__mrc(15, 0, 0, 0, 0) & 0xFFF0) == 49296 )
      return (unsigned int *)sub_519488();
    KiAsidLock = 0;
    v9 = KiAsidTable;
    v10 = 256;
    do
    {
      *v9 = 0;
      v9 += 32;
      --v10;
    }
    while ( v10 );
    *(_DWORD *)(a2 + 36) = 255;
    v11 = __mrc(15, 0, 2, 0, 0) & 0xFFFFC000;
    *(_DWORD *)(a2 + 28) = KiTbrConfiguration | v11;
  }
  v3 = *(_DWORD *)(a2 + 28);
  while ( 1 )
  {
    v5 = *(_DWORD *)(a2 + 36);
    result = (unsigned int *)&KiAsidTable[32 * v5];
    do
    {
      v7 = __ldrex(result);
      v8 = v7 + 1;
    }
    while ( __strex(v8, result) );
    if ( (v8 & 0xFFFFC000) == (v3 & 0xFFFFC000) )
      break;
    do
      v4 = __ldrex(result);
    while ( __strex(v4 - 1, result) );
    KiAsidAlloc(a2);
  }
  if ( KiAsidA9Errata )
  {
    __dsb(0xFu);
    __mcr(15, 0, 0xFFu, 13, 0, 1);
    __isb(0xFu);
    __mcr(15, 0, v3, 2, 0, 0);
    __isb(0xFu);
    __dsb(0xFu);
  }
  else
  {
    __mcr(15, 0, 0xFFu, 13, 0, 1);
    __isb(0xFu);
    __mcr(15, 0, v3, 2, 0, 0);
    __isb(0xFu);
  }
  __mcr(15, 0, v5, 13, 0, 1);
  __isb(0xFu);
  __dsb(0xFu);
  __mcr(15, 0, 0, 8, 7, 0);
  __dsb(0xFu);
  __isb(0xFu);
  return result;
}
