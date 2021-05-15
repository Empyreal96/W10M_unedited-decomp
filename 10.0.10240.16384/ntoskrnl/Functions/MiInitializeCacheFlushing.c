// MiInitializeCacheFlushing 
 
int MiInitializeCacheFlushing()
{
  int result; // r0
  int v1; // r8
  unsigned int v2; // r9
  int v3; // r4
  int v4; // r0
  int v5; // r3
  __int64 v6; // r0
  __int64 v7; // r6
  __int64 v8; // r0
  __int64 v9; // r4
  unsigned int v10; // kr08_4
  unsigned int v11; // r3
  unsigned int v12; // r6
  _BYTE *v13; // r7
  int v14; // r9
  unsigned int v15; // r8
  __int64 v16; // r0
  __int64 v17; // r4
  int v18; // r2
  __int64 v19; // r0
  unsigned int v20; // kr10_4
  unsigned __int64 v21; // r2
  __int64 v22; // r0
  int v23; // [sp+0h] [bp-30h]
  unsigned int v24; // [sp+4h] [bp-2Ch]
  unsigned int v25; // [sp+4h] [bp-2Ch]
  int v26; // [sp+8h] [bp-28h]
  unsigned int v27; // [sp+8h] [bp-28h]
  unsigned int v28; // [sp+Ch] [bp-24h]
  int v29; // [sp+10h] [bp-20h]

  result = MiGetPage((int)MiSystemPartition, 0, 0);
  v1 = result;
  if ( result != -1 )
  {
    v24 = 0;
    v2 = 0;
    v28 = 0;
    v3 = MmPfnDatabase + 24 * result;
    v23 = v3;
    MiFinalizePageAttribute(v3, 1, 0);
    v4 = KfRaiseIrql(2);
    v5 = 4;
    v26 = 4;
    v29 = v4;
    while ( 1 )
    {
      MiZeroPhysicalPage(v1, 1, 0, v5);
      *(_BYTE *)(v3 + 18) &= 0x3Fu;
      LODWORD(v6) = ReadTimeStampCounter();
      v7 = v6;
      __dmb(0xFu);
      MI_FLUSH_CACHE_DUE_TO_ATTRIBUTE_CHANGE(v1, 1, 0);
      __dmb(0xFu);
      LODWORD(v8) = ReadTimeStampCounter();
      v9 = v8;
      *(_BYTE *)(v23 + 18) = *(_BYTE *)(v23 + 18) & 0x3F | 0x40;
      ++dword_63381C;
      KeFlushTb(3, 2);
      v10 = v24 + v9 - v7;
      v2 = (__PAIR64__(v2, v24) + v9 - v7) >> 32;
      v24 = v10;
      v5 = --v26;
      if ( !v26 )
        break;
      v3 = v23;
    }
    v25 = __SPAIR64__(v2, v10) >> 2;
    v27 = v2;
    if ( __PAIR64__(v2, v10) >> 2 )
    {
      v11 = dword_633800;
      if ( !dword_633800 )
        v11 = 256;
      v12 = v11 >> 2;
      v13 = (_BYTE *)ExAllocatePoolWithTag(512, 3 * (v11 >> 2), 538996045);
      if ( v13 )
      {
        v14 = 2;
        v15 = 0;
        do
        {
          memset(v13, 0, 3 * v12);
          LODWORD(v16) = ReadTimeStampCounter();
          v17 = v16;
          __dmb(0xFu);
          KeInvalidateAllCaches(v16, SHIDWORD(v16), v18, ++dword_633820);
          __dmb(0xFu);
          LODWORD(v19) = ReadTimeStampCounter();
          __dmb(0xFu);
          v20 = v28 + v19 - v17;
          v15 = (__PAIR64__(v15, v28) + v19 - v17) >> 32;
          --v14;
          v28 = v20;
        }
        while ( v14 );
        ExFreePoolWithTag((unsigned int)v13);
        HIDWORD(v21) = v15;
        LODWORD(v22) = v25;
        if ( !__PAIR64__(v27 >> 2, v25) )
          __brkdiv0();
        LODWORD(v21) = 2 * (__SPAIR64__(v15, v20) >> 1);
        HIDWORD(v22) = v27 >> 2;
        dword_633828 = _rt_udiv64(v22, v21);
      }
    }
    KfLowerIrql(v29);
    result = MiReleaseFreshPage(v23);
  }
  return result;
}
