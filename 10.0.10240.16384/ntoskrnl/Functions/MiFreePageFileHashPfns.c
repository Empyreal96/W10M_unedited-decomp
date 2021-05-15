// MiFreePageFileHashPfns 
 
int __fastcall MiFreePageFileHashPfns(int result)
{
  int v1; // r6
  int v2; // r4
  int v3; // r7
  int v4; // r2
  _DWORD *v5; // r8
  unsigned __int8 *v6; // r3
  unsigned int v7; // r1
  int v8; // r2
  int v9; // r3
  unsigned int *v10; // r2
  unsigned int v11; // r0
  unsigned int v12; // r0
  int v13; // r4
  unsigned int *v14; // r2
  unsigned int v15; // r0
  int v16; // [sp+0h] [bp-38h]
  int v17; // [sp+4h] [bp-34h]
  int v18; // [sp+8h] [bp-30h]
  int v19; // [sp+Ch] [bp-2Ch]
  _DWORD *v20; // [sp+10h] [bp-28h]
  __int16 *v21; // [sp+14h] [bp-24h]

  v1 = *(_DWORD *)(result + 3596);
  v21 = (__int16 *)result;
  v17 = v1;
  v2 = 0;
  __dmb(0xBu);
  if ( v1 )
  {
    v3 = result;
    v16 = result;
    do
    {
      v4 = *(_DWORD *)(v3 + 3600);
      if ( *(_WORD *)(v4 + 52) )
      {
        result = RtlpInterlockedFlushSList((unsigned __int64 *)(v4 + 48));
        v5 = (_DWORD *)result;
        if ( result )
        {
          do
          {
            v20 = (_DWORD *)*v5;
            v18 = ((int)v5 - MmPfnDatabase) / 24;
            v19 = KfRaiseIrql(2);
            v6 = (unsigned __int8 *)v5 + 15;
            do
              v7 = __ldrex(v6);
            while ( __strex(v7 | 0x80, v6) );
            __dmb(0xBu);
            if ( v7 >> 7 )
              return sub_5170C0();
            v8 = MmPfnDatabase + 24 * v18;
            v9 = *(_DWORD *)(v8 + 12);
            *(_WORD *)(v8 + 16) = 0;
            *(_DWORD *)(v8 + 12) = v9 & 0xC0000000;
            MiInsertPageInFreeOrZeroedList();
            __dmb(0xBu);
            v10 = v5 + 3;
            do
              v11 = __ldrex(v10);
            while ( __strex(v11 & 0x7FFFFFFF, v10) );
            result = KfLowerIrql(v19);
            ++v2;
            v5 = v20;
          }
          while ( v20 );
          v3 = v16;
          v1 = v17;
        }
      }
      v3 += 4;
      --v1;
      v16 = v3;
      v17 = v1;
    }
    while ( v1 );
    if ( v2 )
    {
      if ( v21 == MiSystemPartition )
      {
        MiReturnResidentAvailable(v2);
        do
          v12 = __ldrex(&dword_634A2C[26]);
        while ( __strex(v12 + v2, &dword_634A2C[26]) );
      }
      else
      {
        v14 = (unsigned int *)(v21 + 1920);
        do
          v15 = __ldrex(v14);
        while ( __strex(v15 + v2, v14) );
      }
      MiReturnCommit(v21, v2);
      v13 = -v2;
      do
        result = __ldrex((unsigned int *)algn_634F8C);
      while ( __strex(result + v13, (unsigned int *)algn_634F8C) );
    }
  }
  return result;
}
