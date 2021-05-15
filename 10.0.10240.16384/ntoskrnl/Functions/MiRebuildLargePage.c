// MiRebuildLargePage 
 
int __fastcall MiRebuildLargePage(int a1, int a2, int a3)
{
  unsigned int v3; // r6
  int v4; // r8
  __int16 *v5; // r9
  int v6; // r5
  int v7; // r0
  int v8; // r0
  unsigned int v9; // r8
  int v10; // r8
  int v11; // r4
  unsigned int i; // r5
  int v13; // r0
  unsigned int *v14; // r6
  unsigned __int8 *v15; // r1
  unsigned int v16; // r2
  unsigned int v18; // r2
  char v19; // r3
  char v20; // r3
  unsigned int v21; // r1
  int v22; // r7
  unsigned int *v23; // r5
  unsigned int v24; // r2
  unsigned int v25; // r0
  int v26; // r2
  unsigned int v27; // r0
  int v28; // r4
  unsigned __int8 *v29; // r3
  unsigned int v30; // r1
  unsigned int *v31; // r2
  unsigned int v32; // r0
  unsigned int *v33; // r0
  unsigned int v34; // r1
  unsigned int v35; // r4
  int v36; // r2
  unsigned int v37; // r0
  unsigned int v38; // r3
  int v39; // r2
  unsigned int v40; // r0
  unsigned __int8 *v41; // r1
  int v42; // r3
  unsigned int v43; // r2
  unsigned int *v44; // r2
  unsigned int v45; // r0
  int v46; // [sp+Ch] [bp-4Ch]
  unsigned int v47; // [sp+18h] [bp-40h] BYREF
  int v48; // [sp+1Ch] [bp-3Ch]
  int v49; // [sp+20h] [bp-38h]
  int v50; // [sp+24h] [bp-34h]
  int v51; // [sp+28h] [bp-30h]
  unsigned int v52; // [sp+2Ch] [bp-2Ch]
  __int16 *v53; // [sp+30h] [bp-28h]
  unsigned int *v54; // [sp+34h] [bp-24h]
  int v55; // [sp+38h] [bp-20h]

  v3 = a2;
  v4 = a3;
  v55 = a3;
  v50 = a2;
  v51 = 0;
  v5 = (__int16 *)a1;
  v53 = (__int16 *)a1;
  v48 = 1048574;
  v6 = MiReferencePageRuns(a1, 1);
  v54 = &dword_634A2C[38];
  v49 = v6;
  while ( 1 )
  {
    v7 = MiFindRebuildCandidate(v5, v3, v4);
    v47 = v7;
    if ( v7 == -1 )
      break;
    v8 = MiFindContiguousPages(v5, v7, v7 + 1023, 1024, 0x400u, 1, v3, v46, 1124073472, &v47);
    v9 = v47;
    if ( v8 < 0 )
      goto LABEL_27;
    v51 = 1;
    v10 = v48;
    v52 = MmPfnDatabase + 24 * v47;
    v11 = v52;
    for ( i = 0; i < 0x400; ++i )
    {
      v13 = KfRaiseIrql(2);
      v14 = (unsigned int *)(v11 + 12);
      v15 = (unsigned __int8 *)(v11 + 15);
      do
        v16 = __ldrex(v15);
      while ( __strex(v16 | 0x80, v15) );
      __dmb(0xBu);
      if ( v16 >> 7 )
        return sub_527B14(v13);
      *(_DWORD *)(v11 + 12) &= 0xC0000000;
      *(_BYTE *)(v11 + 19) &= 0xF8u;
      v18 = *(_DWORD *)(v11 + 20) & 0xF7FFFFFF;
      v19 = *(_BYTE *)(v11 + 18);
      *(_DWORD *)(v11 + 20) = v18;
      v20 = v19 & 0xEF;
      *(_BYTE *)(v11 + 18) = v20;
      if ( i )
      {
        *(_BYTE *)(v11 + 18) = v20 & 0xF8 | 1;
        *(_DWORD *)(v11 + 20) = v18 & 0xFFF00000 | v10 & 0xFFFFF;
      }
      __dmb(0xBu);
      do
        v21 = __ldrex(v14);
      while ( __strex(v21 & 0x7FFFFFFF, v14) );
      KfLowerIrql(v13);
      v11 += 24;
    }
    v9 = v47;
    v22 = v52;
    v5 = v53;
    v23 = (unsigned int *)(dword_634C94 + 4 * (v47 >> 15));
    v24 = (v47 >> 10) & 0x1F;
    LOBYTE(v25) = 1;
    if ( v24 + 1 > 0x20 )
    {
      if ( v24 )
      {
        v35 = 32 - v24;
        __dmb(0xBu);
        v36 = ~(((1 << (32 - v24)) - 1) << v24);
        do
          v37 = __ldrex(v23);
        while ( __strex(v37 & v36, v23) );
        __dmb(0xBu);
        v25 = 1 - v35;
        ++v23;
        if ( 1 - v35 >= 0x20 )
        {
          v38 = v25 >> 5;
          do
          {
            v25 -= 32;
            *v23++ = 0;
            --v38;
          }
          while ( v38 );
        }
        if ( !v25 )
          goto LABEL_18;
      }
      __dmb(0xBu);
      v39 = ~((1 << v25) - 1);
      do
        v40 = __ldrex(v23);
      while ( __strex(v40 & v39, v23) );
    }
    else
    {
      __dmb(0xBu);
      v26 = ~(1 << v24);
      do
        v27 = __ldrex(v23);
      while ( __strex(v27 & v26, v23) );
    }
    __dmb(0xBu);
LABEL_18:
    v28 = KfRaiseIrql(2);
    v29 = (unsigned __int8 *)(v22 + 15);
    do
      v30 = __ldrex(v29);
    while ( __strex(v30 | 0x80, v29) );
    __dmb(0xBu);
    if ( v30 >> 7 )
    {
      v41 = (unsigned __int8 *)(v22 + 15);
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v42 = *(_DWORD *)(v22 + 12);
          __dmb(0xBu);
        }
        while ( (v42 & 0x80000000) != 0 );
        do
          v43 = __ldrex(v41);
        while ( __strex(v43 | 0x80, v41) );
        __dmb(0xBu);
      }
      while ( v43 >> 7 );
    }
    *(_DWORD *)(v22 + 20) = *(_DWORD *)(v22 + 20) & 0xFFF00000 | v48 & 0xFFFFF;
    *(_BYTE *)(v22 + 18) = *(_BYTE *)(v22 + 18) & 0xF8 | 1;
    MiInsertLargePageInNodeList(v9, 1024, 1);
    __dmb(0xBu);
    v31 = (unsigned int *)(v22 + 12);
    do
      v32 = __ldrex(v31);
    while ( __strex(v32 & 0x7FFFFFFF, v31) );
    KfLowerIrql(v28);
    MiReturnCommit((int)v5, 1024);
    if ( v5 == MiSystemPartition )
    {
      MiReturnResidentAvailable(1024);
      v33 = v54;
      do
        v34 = __ldrex(v33);
      while ( __strex(v34 + 1024, v33) );
    }
    else
    {
      v44 = (unsigned int *)(v5 + 1920);
      do
        v45 = __ldrex(v44);
      while ( __strex(v45 + 1024, v44) );
    }
    v6 = v49;
    v3 = v50;
LABEL_27:
    if ( !v9 )
      break;
    v4 = v55;
  }
  MiDereferencePageRuns(v6);
  return v51;
}
