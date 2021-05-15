// MiChangePageAttribute 
 
int __fastcall MiChangePageAttribute(int a1, int a2, char a3)
{
  char v3; // r4
  unsigned int v6; // r2
  int result; // r0
  int v8; // r7
  unsigned __int8 *v9; // r1
  unsigned int v10; // r2
  int v11; // r9
  unsigned int v12; // r10
  unsigned int *v13; // r2
  unsigned int v14; // r0
  int v15; // r2
  char v16; // r3
  unsigned int v17; // r3
  int v18; // r4
  int v19; // r3
  unsigned int v20; // r2

  v3 = a3;
  if ( (a3 & 1) != 0 )
  {
    v8 = 17;
  }
  else
  {
    v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    if ( dword_63437C == v6 )
      return sub_50A0D0();
    v8 = KfRaiseIrql(2);
    v9 = (unsigned __int8 *)(a1 + 15);
    do
      v10 = __ldrex(v9);
    while ( __strex(v10 | 0x80, v9) );
    __dmb(0xBu);
    if ( v10 >> 7 )
    {
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v19 = *(_DWORD *)(a1 + 12);
          __dmb(0xBu);
        }
        while ( v19 < 0 );
        do
          v20 = __ldrex(v9);
        while ( __strex(v20 | 0x80, v9) );
        __dmb(0xBu);
      }
      while ( v20 >> 7 );
    }
  }
  v11 = *(unsigned __int8 *)(a1 + 18) >> 6;
  result = (unsigned __int64)(715827883i64 * (a1 - MmPfnDatabase)) >> 32;
  v12 = result >> 2;
  if ( dword_634304 )
  {
    result = MiAbortCombineScan(a1);
    v3 = v3 & 0xF9 | 2;
  }
  *(_BYTE *)(a1 + 18) = *(_BYTE *)(a1 + 18) & 0x3F | ((_BYTE)a2 << 6);
  if ( v11 != 3 && (v3 & 4) == 0 )
  {
    if ( (v3 & 2) != 0
      || (v15 = (*(_DWORD *)(a1 + 12) >> 20) & 0xF,
          __dmb(0xFu),
          v16 = KiTbFlushTimeStamp,
          __dmb(0xBu),
          v17 = (v16 - (_BYTE)v15) & 0xF,
          v17 <= 2)
      && ((v15 & 1) != 0 || v17 < 2) )
    {
      ++dword_63381C;
      result = KeFlushTb(3, 2);
    }
    if ( a2 != 1 && v11 == 1 )
    {
      ++dword_633824;
      v18 = KfRaiseIrql(2);
      MI_FLUSH_CACHE_DUE_TO_ATTRIBUTE_CHANGE(v12 + (v12 >> 31), 1, a2);
      result = KfLowerIrql(v18);
    }
  }
  if ( v8 != 17 )
  {
    __dmb(0xBu);
    v13 = (unsigned int *)(a1 + 12);
    do
      v14 = __ldrex(v13);
    while ( __strex(v14 & 0x7FFFFFFF, v13) );
    result = KfLowerIrql(v8);
  }
  return result;
}
