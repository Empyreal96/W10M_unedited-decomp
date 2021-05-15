// MiSwapStackPageNoDpc 
 
int __fastcall MiSwapStackPageNoDpc(char *a1, int a2, int a3)
{
  unsigned int v4; // r10
  unsigned int v6; // r1
  int v7; // r5
  unsigned int v8; // r4
  unsigned int v9; // r2
  int result; // r0
  unsigned __int8 *v11; // r1
  unsigned int v12; // r2
  int v13; // r3
  unsigned int v14; // r2
  unsigned int v15; // r1
  unsigned int *v16; // r2
  unsigned int v17; // r0
  unsigned int *v18; // r2
  unsigned int v19; // r0
  unsigned int v21; // [sp+4h] [bp-24h]

  v4 = *(_DWORD *)(a2 + 4) | 0x80000000;
  v21 = (int)((unsigned __int64)(715827883i64 * (a2 - MmPfnDatabase)) >> 32) >> 2;
  v6 = *(_DWORD *)v4;
  v7 = (a3 - MmPfnDatabase) / 24;
  v8 = *(_DWORD *)v4;
  if ( v4 < 0xC0300000 || v4 > 0xC0300FFF )
    v8 = v6 & 0xFFFFFFEF;
  __dmb(0xBu);
  do
    v9 = __ldrex((unsigned int *)v4);
  while ( v9 == v6 && __strex(v8, (unsigned int *)v4) );
  __dmb(0xBu);
  if ( v9 != v6 )
    return 0;
  KeFlushSingleTb(v4 << 10, 2);
  v11 = (unsigned __int8 *)(a3 + 15);
  do
    v12 = __ldrex(v11);
  while ( __strex(v12 | 0x80, v11) );
  __dmb(0xBu);
  if ( v12 >> 7 )
  {
    do
    {
      do
      {
        __dmb(0xAu);
        __yield();
        v13 = *(_DWORD *)(a3 + 12);
        __dmb(0xBu);
      }
      while ( (v13 & 0x80000000) != 0 );
      do
        v14 = __ldrex(v11);
      while ( __strex(v14 | 0x80, v11) );
      __dmb(0xBu);
    }
    while ( v14 >> 7 );
  }
  MiCopyPfnEntry(a3, (int *)a2);
  MiCopyPage(v7, v21 + (v21 >> 31), a1, 4);
  __dmb(0xBu);
  do
    v15 = __ldrex((unsigned int *)v4);
  while ( v15 == v8 && __strex(v8 & 0xFEF | (v7 << 12) | 0x10, (unsigned int *)v4) );
  __dmb(0xBu);
  if ( v15 != v8 )
  {
    *(_DWORD *)(a3 + 8) = 128;
    *(_BYTE *)(a3 + 18) = *(_BYTE *)(a3 + 18) & 0xF8 | 5;
    *(_DWORD *)(a3 + 20) &= 0xF8FFFFFF;
    __dmb(0xBu);
    v16 = (unsigned int *)(a3 + 12);
    do
      v17 = __ldrex(v16);
    while ( __strex(v17 & 0x7FFFFFFF, v16) );
    return 0;
  }
  __dmb(0xBu);
  v18 = (unsigned int *)(a3 + 12);
  do
    v19 = __ldrex(v18);
  while ( __strex(v19 & 0x7FFFFFFF, v18) );
  result = 1;
  *(_BYTE *)(a2 + 18) = *(_BYTE *)(a2 + 18) & 0xF8 | 5;
  *(_DWORD *)(a2 + 20) &= 0xF8FFFFFF;
  return result;
}
