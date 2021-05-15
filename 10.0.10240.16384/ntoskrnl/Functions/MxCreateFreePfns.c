// MxCreateFreePfns 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall MxCreateFreePfns(int a1)
{
  unsigned int v1; // r5 OVERLAPPED
  unsigned int v2; // r6 OVERLAPPED
  _DWORD *v5; // r7
  int v6; // r4
  int v7; // r3
  int v8; // r6
  unsigned int v9; // r1
  int v10; // r9
  unsigned int v11; // r2
  int v12; // r3
  int v13; // r3
  unsigned int v14; // r9
  unsigned int *v15; // r2
  unsigned int v16; // r0
  int v17; // r0
  int v18; // r0
  unsigned __int8 *v19; // r3
  unsigned int v20; // r1
  int v21; // r3
  unsigned __int8 *v22; // r1
  int v23; // r3
  unsigned int v24; // r2
  unsigned int *v25; // r2
  unsigned int v26; // r0
  _DWORD *v27; // r4
  unsigned int v28; // r5
  int v29; // r0
  unsigned __int8 *v30; // r3
  unsigned int v31; // r1
  unsigned __int8 *v32; // r1
  int v33; // r3
  unsigned int v34; // r2
  int v35; // [sp+8h] [bp-28h]
  int v36; // [sp+Ch] [bp-24h]

  *(_QWORD *)&v1 = *(_QWORD *)(a1 + 12);
  if ( !v1 )
    return sub_96B36C();
  v35 = *(_DWORD *)(a1 + 8) != 24;
  v5 = 0;
  v6 = MmPfnDatabase + 24 * v1;
  if ( v2 )
  {
    while ( 1 )
    {
      v7 = *(_DWORD *)(a1 + 8);
      if ( v7 == 2 || v7 == 24 )
        goto LABEL_8;
      if ( *(_WORD *)(v6 + 16) == 1 )
        break;
      if ( !*(_WORD *)(v6 + 16) )
        goto LABEL_8;
LABEL_10:
      --v2;
      v6 += 24;
      ++v1;
      if ( !v2 )
        goto LABEL_11;
    }
    v9 = *(_DWORD *)(v6 + 4) | 0x80000000;
    v10 = MmPfnDatabase + 24 * (*(_DWORD *)(v6 + 20) & 0xFFFFF);
    if ( v9 < 0xC0000000 || v9 > 0xC03FFFFF )
    {
      *(_DWORD *)v9 = 0;
    }
    else
    {
      __dmb(0xBu);
      *(_DWORD *)v9 = 0;
      if ( v9 + 1070596096 <= 0xFFF )
      {
        v17 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        MiArmWriteConvertedHardwarePde(v17, (_DWORD *)(v17 + 4 * (v9 & 0xFFF)), 0);
      }
    }
    v11 = *(_DWORD *)(v10 + 12) & 0xC0000000 | (*(_DWORD *)(v10 + 12) - 1) & 0x3FFFFFFF;
    *(_DWORD *)(v10 + 12) = v11;
    if ( (v11 & 0x3FFFFFFF) == 1 )
      MiFreeEmptyBootPageTable(v10);
    v12 = *(_DWORD *)(v6 + 12);
    *(_WORD *)(v6 + 16) = 0;
    *(_DWORD *)(v6 + 12) = v12 & 0xC0000000;
LABEL_8:
    if ( (v1 & 0x3FF) == 0
      && ((v13 = *(_DWORD *)(a1 + 8), v13 == 2) || v13 == 24)
      && v2 >= 0x400
      && (v14 = MiRestrictRangeToNode(v1, v2 & 0xFFFFFC00) & 0xFFFFFC00, v14 >= 0x400) )
    {
      v18 = MiPageToNode();
      MiInitializeBlankPfns(v6, v14, v18);
      v36 = KfRaiseIrql(2);
      v19 = (unsigned __int8 *)(v6 + 15);
      do
        v20 = __ldrex(v19);
      while ( __strex(v20 | 0x80, v19) );
      __dmb(0xBu);
      v21 = v20 >> 7;
      if ( v20 >> 7 )
      {
        v22 = (unsigned __int8 *)(v6 + 15);
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v23 = *(_DWORD *)(v6 + 12);
            __dmb(0xBu);
          }
          while ( (v23 & 0x80000000) != 0 );
          do
            v24 = __ldrex(v22);
          while ( __strex(v24 | 0x80, v22) );
          __dmb(0xBu);
          v21 = v24 >> 7;
        }
        while ( v24 >> 7 );
      }
      MiInsertLargePageInNodeList(v1, v14, v35, v21);
      __dmb(0xBu);
      v25 = (unsigned int *)(v6 + 12);
      do
        v26 = __ldrex(v25);
      while ( __strex(v26 & 0x7FFFFFFF, v25) );
      KfLowerIrql(v36);
      v2 = v2 - v14 + 1;
      v6 = v6 + 24 * v14 - 24;
      v1 = v14 + v1 - 1;
    }
    else
    {
      *(_DWORD *)v6 = v5;
      v5 = (_DWORD *)v6;
    }
    goto LABEL_10;
  }
LABEL_11:
  v8 = KfRaiseIrql(2);
  while ( v5 )
  {
    v27 = v5;
    v5 = (_DWORD *)*v5;
    v28 = (int)((unsigned __int64)(715827883i64 * ((int)v27 - MmPfnDatabase)) >> 32) >> 2;
    v29 = MiPageToNode();
    MiInitializeBlankPfns(v27, 1, v29);
    v27[5] &= 0xFFF00000;
    v30 = (unsigned __int8 *)v27 + 15;
    do
      v31 = __ldrex(v30);
    while ( __strex(v31 | 0x80, v30) );
    __dmb(0xBu);
    if ( v31 >> 7 )
    {
      v32 = (unsigned __int8 *)v27 + 15;
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v33 = v27[3];
          __dmb(0xBu);
        }
        while ( (v33 & 0x80000000) != 0 );
        do
          v34 = __ldrex(v32);
        while ( __strex(v34 | 0x80, v32) );
        __dmb(0xBu);
      }
      while ( v34 >> 7 );
    }
    MiInsertPageInFreeOrZeroedList(v28 + (v28 >> 31), 2);
    __dmb(0xBu);
    v15 = v27 + 3;
    do
      v16 = __ldrex(v15);
    while ( __strex(v16 & 0x7FFFFFFF, v15) );
  }
  return KfLowerIrql(v8);
}
