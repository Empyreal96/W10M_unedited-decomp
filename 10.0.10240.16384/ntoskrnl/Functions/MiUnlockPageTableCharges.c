// MiUnlockPageTableCharges 
 
unsigned int __fastcall MiUnlockPageTableCharges(int a1, int a2, int a3)
{
  int v5; // r6
  int v6; // r9
  unsigned __int8 *v7; // r3
  unsigned int v8; // r1
  unsigned int v9; // r2
  unsigned int *v10; // r2
  unsigned int result; // r0
  unsigned int *v12; // r2
  unsigned __int8 *v13; // r1
  int v14; // r3
  unsigned int v15; // r2
  unsigned int *v16; // r2
  unsigned int v17; // r5
  __int16 *v18; // [sp+8h] [bp-28h]
  int v19; // [sp+Ch] [bp-24h]
  int v20; // [sp+10h] [bp-20h]

  v18 = 0;
  if ( a3 == 1 && !MiIsLowestPageTablePage() )
    sub_545038();
  if ( (*(_DWORD *)(a1 + 12) & 0x3FFFFFFFu) < 0x10000 )
    JUMPOUT(0x54503C);
  v5 = 0;
  v6 = 0;
  v19 = 1;
  if ( a2 != 17 )
    a2 = KfRaiseIrql(2);
  while ( 1 )
  {
    v20 = *(_DWORD *)(a1 + 20) & 0xFFFFF;
    v7 = (unsigned __int8 *)(a1 + 15);
    do
      v8 = __ldrex(v7);
    while ( __strex(v8 | 0x80, v7) );
    __dmb(0xBu);
    if ( v8 >> 7 )
    {
      v13 = (unsigned __int8 *)(a1 + 15);
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v14 = *(_DWORD *)(a1 + 12);
          __dmb(0xBu);
        }
        while ( (v14 & 0x80000000) != 0 );
        do
          v15 = __ldrex(v13);
        while ( __strex(v15 | 0x80, v13) );
        __dmb(0xBu);
      }
      while ( v15 >> 7 );
    }
    v9 = *(_DWORD *)(a1 + 12) & 0xC0000000 | (*(_DWORD *)(a1 + 12) - 0x10000) & 0x3FFFFFFF;
    *(_DWORD *)(a1 + 12) = v9;
    if ( (v9 & 0x3FFFFFFF) >= 0x10000 )
      break;
    if ( !v18 )
      v18 = MiSystemPartition;
    ++v5;
    if ( (v9 & 0x3FFFFFFF) == 0 && MiPfnShareCountIsZero(a1, 0) != 3 )
      ++v6;
    __dmb(0xBu);
    v12 = (unsigned int *)(a1 + 12);
    do
      result = __ldrex(v12);
    while ( __strex(result & 0x7FFFFFFF, v12) );
    if ( !--v19 )
      goto LABEL_13;
    a1 = MmPfnDatabase + 24 * v20;
  }
  __dmb(0xBu);
  v10 = (unsigned int *)(a1 + 12);
  do
    result = __ldrex(v10);
  while ( __strex(result & 0x7FFFFFFF, v10) );
LABEL_13:
  if ( a2 != 17 )
    result = KfLowerIrql(a2);
  if ( v5 )
  {
    if ( v18 == MiSystemPartition )
    {
      MiReturnResidentAvailable(v5);
      do
        result = __ldrex(&dword_634A2C[20]);
      while ( __strex(result + v5, &dword_634A2C[20]) );
    }
    else
    {
      v16 = (unsigned int *)(v18 + 1920);
      do
        v17 = __ldrex(v16);
      while ( __strex(v17 + v5, v16) );
    }
  }
  if ( v6 )
    result = MiReturnCommit((int)v18, v6);
  return result;
}
