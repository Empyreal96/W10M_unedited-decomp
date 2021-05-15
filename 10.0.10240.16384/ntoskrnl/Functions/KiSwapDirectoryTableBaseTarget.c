// KiSwapDirectoryTableBaseTarget 
 
int __fastcall KiSwapDirectoryTableBaseTarget(int a1, int a2, unsigned int *a3, unsigned int *a4)
{
  unsigned int v7; // r4
  unsigned int v8; // r4
  unsigned int v9; // r7
  int result; // r0
  unsigned int v11; // r2
  unsigned int v12; // r2
  unsigned int v13; // r1
  unsigned int v14; // r3
  int v15; // r2
  unsigned int v16; // r2
  int v17; // r0
  int v18; // r3

  __dmb(0xBu);
  do
  {
    v7 = __ldrex(a4);
    v8 = v7 - 1;
  }
  while ( __strex(v8, a4) );
  __dmb(0xBu);
  v9 = ~v8 & 0x80000000;
  if ( (v8 & 0x7FFFFFFF) != 0 )
  {
    while ( (*a4 & 0x80000000) != v9 )
    {
      __dmb(0xAu);
      __yield();
    }
    __dmb(0xBu);
  }
  else
  {
    v17 = a4[1] | v9;
    __dmb(0xBu);
    *a4 = v17;
  }
  result = MmStealTopLevelPage(*(_DWORD *)(a2 + 20));
  if ( result )
    *(_BYTE *)(a2 + 1) = 1;
  __dmb(0xBu);
  do
  {
    v11 = __ldrex(a4);
    v12 = v11 - 1;
  }
  while ( __strex(v12, a4) );
  __dmb(0xBu);
  v13 = ~v12 & 0x80000000;
  if ( (v12 & 0x7FFFFFFF) != 0 )
  {
    while ( (*a4 & 0x80000000) != v13 )
    {
      __dmb(0xAu);
      __yield();
    }
    __dmb(0xBu);
  }
  else
  {
    v18 = a4[1] | v13;
    __dmb(0xBu);
    *a4 = v18;
  }
  __dsb(0xFu);
  __mcr(15, 0, 0xC0300000, 8, 7, 3);
  v14 = -1073741824;
  v15 = 4;
  do
  {
    __mcr(15, 0, v14, 8, 7, 3);
    v14 += 0x100000;
    --v15;
  }
  while ( v15 );
  __dsb(0xFu);
  __isb(0xFu);
  __dmb(0xBu);
  do
    v16 = __ldrex(a3);
  while ( __strex(v16 - 1, a3) );
  __dmb(0xBu);
  return result;
}
