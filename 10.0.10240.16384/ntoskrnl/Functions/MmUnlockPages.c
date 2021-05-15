// MmUnlockPages 
 
int __fastcall MmUnlockPages(int a1)
{
  __int16 v1; // r10
  unsigned int *v3; // r9
  int result; // r0
  int v5; // r2
  unsigned int v6; // r5
  int v7; // r7
  unsigned int v8; // r6
  int *i; // r0
  unsigned int v10; // r1
  unsigned int v11; // t1
  int v12; // r0
  int v13; // r4
  int v14; // r5
  int v15; // r1
  int v16; // r6
  unsigned __int8 *v17; // r3
  unsigned int v18; // r1
  int v19; // r2
  int v20; // r4
  int v21; // r3
  int v22; // r2
  int v23; // r7
  unsigned int v24; // r1
  unsigned int v25; // r2
  unsigned int v26; // r0
  int v27; // r6
  unsigned int v28; // r3
  unsigned int *v29; // r4
  int v30; // r1
  unsigned int v31; // r0
  unsigned int v32; // r1
  unsigned int *v33; // r2
  unsigned int v34; // r5
  unsigned int *v35; // r2
  unsigned int v36; // r4
  unsigned __int64 *v37; // r2
  unsigned __int64 v38; // kr00_8
  int v39; // r3
  unsigned int v40; // r2
  unsigned int v41; // r0
  unsigned __int8 *v42; // r1
  int v43; // r3
  unsigned int v44; // r2
  unsigned int v45; // [sp+8h] [bp-60h]
  int v46; // [sp+Ch] [bp-5Ch]
  int v47; // [sp+10h] [bp-58h]
  int v48; // [sp+14h] [bp-54h]
  unsigned int v49; // [sp+18h] [bp-50h]
  __int16 *v50; // [sp+20h] [bp-48h]
  unsigned int *v51; // [sp+24h] [bp-44h]
  int v52; // [sp+40h] [bp-28h]
  unsigned int v53; // [sp+44h] [bp-24h]

  v1 = *(_WORD *)(a1 + 6);
  v52 = *(_DWORD *)(a1 + 8);
  v3 = (unsigned int *)(a1 + 28);
  if ( (v1 & 0x200) != 0 )
    return sub_5450AC();
  v5 = ((unsigned __int16)*(_DWORD *)(a1 + 24) + (unsigned __int16)*(_DWORD *)(a1 + 16)) & 0xFFF;
  v6 = (unsigned int)(*(_DWORD *)(a1 + 20) + v5 + 4095) >> 12;
  v53 = v6;
  if ( (v1 & 1) != 0 )
    MmUnmapLockedPages(*(_DWORD *)(a1 + 12), a1, v5);
  if ( (MmTrackLockedPages & 1) != 0 )
    MiFreeMdlTracker(a1, v6);
  v51 = &v3[v6];
  v46 = 0;
  v48 = 0xFFFFF;
  v7 = 0;
  v8 = 0;
  v47 = 0;
  v45 = 0;
  v49 = KfRaiseIrql(2);
  for ( i = MiState; ; i = MiState )
  {
    v11 = *v3++;
    v10 = v11;
    if ( v11 == -1 )
      break;
    if ( v10 > i[884] || (v12 = i[2183]) != 0 && ((*(_DWORD *)(v12 + 4 * (v10 >> 5)) >> (v10 & 0x1F)) & 1) == 0 )
    {
      MiDereferenceIoPages(0, v10, 1);
      goto LABEL_53;
    }
    v13 = MmPfnDatabase;
    v14 = MmPfnDatabase + 24 * v10;
    if ( (v1 & 0x100) != 0 )
    {
      v15 = *(_DWORD *)(v14 + 20);
      if ( (v15 & 0x7000000) != 0x1000000 )
      {
        v16 = v15 & 0xFFFFF;
        if ( (v15 & 0xFFFFF) != 1048573
          && ((v15 & 0x8000000) != 0 || MiIsLowestPageTablePage(MmPfnDatabase + 24 * v16))
          && v48 != v16 )
        {
          if ( v48 != 0xFFFFF )
            MiUnlockPageTableCharges(v13 + 24 * v48, 17, v46);
          v39 = *(_DWORD *)(v14 + 20);
          v46 = (v39 & 0x8000000) == 0;
          v48 = v39 & 0xFFFFF;
        }
        v8 = v45;
      }
    }
    v50 = 0;
    v17 = (unsigned __int8 *)(v14 + 15);
    do
      v18 = __ldrex(v17);
    while ( __strex(v18 | 0x80, v17) );
    __dmb(0xBu);
    if ( v18 >> 7 )
    {
      v42 = (unsigned __int8 *)(v14 + 15);
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v43 = *(_DWORD *)(v14 + 12);
          __dmb(0xBu);
        }
        while ( (v43 & 0x80000000) != 0 );
        do
          v44 = __ldrex(v42);
        while ( __strex(v44 | 0x80, v42) );
        __dmb(0xBu);
      }
      while ( v44 >> 7 );
    }
    if ( (v1 & 0x80) != 0 )
    {
      if ( (*(_DWORD *)(v14 + 8) & 0x400) == 0 && (*(_BYTE *)(v14 + 18) & 8) == 0 )
      {
        v19 = *(_DWORD *)(v14 + 8);
        if ( (v19 & 0x10) != 0 )
        {
          *(_DWORD *)(v14 + 8) = v19 & 0xFFFFFFEF;
          v8 = v19 & 0xFFFFFFF7;
        }
        else
        {
          v8 = 0;
        }
        v45 = v8;
        if ( v8 )
          v50 = MiSystemPartition;
      }
      *(_BYTE *)(v14 + 18) |= 0x10u;
      if ( (*(_DWORD *)(v14 + 20) & 0x8000000) != 0 && (*(_DWORD *)(v14 + 8) & 0x400) != 0 )
      {
        v37 = (unsigned __int64 *)(*(_DWORD *)(*(_DWORD *)(v14 + 8) & 0xFFFFF800 | (2 * (*(_DWORD *)(v14 + 8) & 0x3FC)))
                                 + 64);
        do
          v38 = __ldrexd(v37);
        while ( __strexd(v38 - 1, v37) );
        if ( v38 == 1 )
          MiQueueControlAreaDelete();
      }
    }
    if ( !*(_WORD *)(v14 + 16) )
      KeBugCheckEx(78, 154, (v14 - MmPfnDatabase) / 24);
    v20 = *(_DWORD *)(v14 + 12);
    v21 = (unsigned __int16)(*(_WORD *)(v14 + 16) - 1);
    *(_WORD *)(v14 + 16) = v21;
    v22 = v20 & 0x3FFFFFFF;
    if ( !v21 )
    {
      v23 = 1;
LABEL_35:
      v24 = (((unsigned int)MmHighestUserAddress >> 10) & 0x3FFFFC) - 0x40000000;
      v25 = *(_DWORD *)(v14 + 4) | 0x80000000;
      if ( v25 <= v24 && v25 >= 0xC0000000 || (v26 = *(unsigned __int8 *)(v14 + 19), ((v26 >> 5) & 1) == 0) )
      {
        if ( (*(_DWORD *)(v14 + 20) & 0x8000000) != 0 && (*(_DWORD *)(v14 + 8) & 0x400) != 0
          || v25 <= v24 && v25 >= 0xC0000000 && ((*(unsigned __int8 *)(v14 + 19) >> 5) & 1) != 0
          || v23 == 1 && (v20 & 0x40000000) != 0 )
        {
          MiReturnCommit((int)MiSystemPartition, 1);
        }
        v27 = 1;
        v28 = (unsigned int)KeGetPcr();
        v29 = (unsigned int *)((v28 & 0xFFFFF000) + 4992);
        v30 = *(_DWORD *)((v28 & 0xFFFFF000) + 0x1380);
        if ( v30 != -1 )
        {
          if ( (unsigned int)(v30 + 1) <= 0x100 )
          {
            while ( 1 )
            {
              do
                v31 = __ldrex(v29);
              while ( v31 == v30 && __strex(v30 + 1, v29) );
              if ( v31 == v30 )
                break;
              v30 = v31;
              if ( v31 == -1 || v31 + 1 > 0x100 )
                goto LABEL_84;
            }
            do
LABEL_45:
              v32 = __ldrex(&dword_634A2C[117]);
            while ( __strex(v32 + 1, &dword_634A2C[117]) );
LABEL_46:
            if ( v23 )
              MiPfnReferenceCountIsZero(v14, (v14 - MmPfnDatabase) / 24);
            v7 = v47;
            v8 = v45;
            goto LABEL_49;
          }
LABEL_84:
          if ( v30 > 192 )
          {
            do
              v40 = __ldrex(v29);
            while ( v40 == v30 && __strex(0xC0u, v29) );
            if ( v40 == v30 )
              v27 = v30 - 191;
          }
        }
        do
          v41 = __ldrex((unsigned int *)&dword_640600);
        while ( __strex(v41 + v27, (unsigned int *)&dword_640600) );
        goto LABEL_45;
      }
      *(_BYTE *)(v14 + 19) = v26 & 0xDF;
      goto LABEL_46;
    }
    if ( v21 == 1 )
    {
      if ( v22 || (*(_BYTE *)(v14 + 18) & 8) != 0 )
        goto LABEL_34;
    }
    else if ( v21 == 2 && v22 && (*(_BYTE *)(v14 + 18) & 8) != 0 )
    {
LABEL_34:
      v23 = 0;
      goto LABEL_35;
    }
LABEL_49:
    __dmb(0xBu);
    v33 = (unsigned int *)(v14 + 12);
    do
      v34 = __ldrex(v33);
    while ( __strex(v34 & 0x7FFFFFFF, v33) );
    if ( v8 )
    {
      MiReleasePageFileInfo((int)v50, v8, 1, 0);
      v8 = 0;
      v45 = 0;
    }
LABEL_53:
    v47 = ++v7;
    if ( (v7 & 0x3F) == 0 && v49 < 2 )
    {
      if ( v3 >= v51 )
        break;
      if ( KeShouldYieldProcessor() )
      {
        KfLowerIrql(v49);
        v49 = KfRaiseIrql(2);
      }
    }
    if ( v3 >= v51 )
      break;
  }
  if ( v48 != 0xFFFFF )
    MiUnlockPageTableCharges(MmPfnDatabase + 24 * v48, 17, v46);
  result = KfLowerIrql(v49);
  if ( v52 )
  {
    result = -v53;
    v35 = (unsigned int *)(v52 + 280);
    do
      v36 = __ldrex(v35);
    while ( __strex(v36 - v53, v35) );
  }
  *(_WORD *)(a1 + 6) &= 0xF6FDu;
  return result;
}
