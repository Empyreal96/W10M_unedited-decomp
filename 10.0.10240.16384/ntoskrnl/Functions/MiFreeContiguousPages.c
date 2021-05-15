// MiFreeContiguousPages 
 
int __fastcall MiFreeContiguousPages(int result, int a2, int a3)
{
  __int16 v4; // r7
  int v5; // r5
  unsigned __int8 *v6; // r4
  __int16 *v7; // r9
  int v8; // r6
  unsigned int *v9; // r10
  unsigned __int8 *v10; // r3
  unsigned int v11; // r1
  unsigned int i; // r3
  int v13; // r3
  char v14; // r3
  unsigned int v15; // r1
  unsigned int v16; // r0
  int v17; // r3
  unsigned int v18; // r2
  unsigned int *v19; // r2
  unsigned int v20; // r4
  int v21; // [sp+8h] [bp-20h]

  v4 = a2;
  v5 = MmPfnDatabase + 24 * a2;
  v6 = (unsigned __int8 *)(v5 + 15);
  v7 = (__int16 *)result;
  v8 = 0;
  v9 = (unsigned int *)(v5 + 12);
  do
  {
    if ( (v4 & 0x3FF) == 0 )
      return sub_5143D0(result, &KfRaiseIrql, 1024);
    v21 = KfRaiseIrql(2);
    v10 = (unsigned __int8 *)(v5 + 15);
    do
      v11 = __ldrex(v10);
    while ( __strex(v11 | 0x80, v10) );
    __dmb(0xBu);
    for ( i = v11 >> 7; i; i = v18 >> 7 )
    {
      do
      {
        __dmb(0xAu);
        __yield();
        v17 = *v9;
        __dmb(0xBu);
      }
      while ( v17 < 0 );
      do
        v18 = __ldrex(v6);
      while ( __strex(v18 | 0x80, v6) );
      __dmb(0xBu);
    }
    v13 = (unsigned __int16)(*(_WORD *)(v5 + 16) - 1);
    *(_WORD *)(v5 + 16) = v13;
    if ( v13 == 1 )
      ++v8;
    v14 = *(_BYTE *)(v5 + 18);
    *(_DWORD *)(v5 + 12) |= 0x40000000u;
    if ( (v14 & 7) != 6 )
      KeBugCheckEx(78, 153, (v5 - MmPfnDatabase) / 24);
    if ( !MiUpdateShareCount(v5, -1) )
      MiPfnShareCountIsZero(v5, 0);
    __dmb(0xBu);
    do
      v15 = __ldrex(v9);
    while ( __strex(v15 & 0x7FFFFFFF, v9) );
    result = KfLowerIrql(v21);
    v5 += 24;
    v6 += 24;
    ++v4;
    v9 += 6;
    --a3;
  }
  while ( a3 );
  if ( v8 )
  {
    if ( v7 == MiSystemPartition )
    {
      MiReturnResidentAvailable(v8);
      do
        v16 = __ldrex(&dword_634A2C[38]);
      while ( __strex(v16 + v8, &dword_634A2C[38]) );
    }
    else
    {
      v19 = (unsigned int *)(v7 + 1920);
      do
        v20 = __ldrex(v19);
      while ( __strex(v20 + v8, v19) );
    }
    result = MiReturnCommit(v7, v8);
  }
  return result;
}
