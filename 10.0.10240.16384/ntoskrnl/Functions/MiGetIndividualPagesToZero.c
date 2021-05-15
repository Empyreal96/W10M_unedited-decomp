// MiGetIndividualPagesToZero 
 
int __fastcall MiGetIndividualPagesToZero(int a1, int *a2, int a3, _DWORD *a4)
{
  _DWORD *v4; // r4
  int v6; // r1
  unsigned int v7; // r5
  int v8; // r6
  int v9; // r3
  int v10; // lr
  unsigned __int8 *v11; // r3
  unsigned int v12; // r1
  int v13; // r8
  int v14; // r4
  _DWORD *v15; // r9
  unsigned int *v16; // r2
  unsigned int v18; // r1
  unsigned int *v19; // r2
  unsigned int v20; // r1
  int v21; // r3
  int v22; // r9
  int v23; // r0
  unsigned int *v24; // r2
  int *v25; // r1
  unsigned int *v26; // r2
  unsigned int v27; // r1
  unsigned int v28; // r4
  unsigned int v29; // r4
  __int64 v30; // r2
  unsigned __int64 v31; // r2
  unsigned int *v32; // r2
  unsigned int v33; // r0
  int v34; // r2
  unsigned int *v35; // lr
  unsigned int v36; // r0
  int v37; // r1
  unsigned int v38; // r4
  unsigned int *v39; // r2
  unsigned int v40; // r0
  unsigned __int8 *v41; // r1
  int v42; // r3
  unsigned int v43; // r2
  unsigned int *v44; // r2
  unsigned int v45; // r0
  unsigned int v46; // r0
  unsigned int v47; // r1
  unsigned int v48; // r1
  unsigned int *v49; // lr
  int v50; // r2
  int v51; // r2
  unsigned int v52; // r0
  int v53; // r4
  int v54; // r2
  unsigned int v55; // r0
  unsigned int v56; // r3
  unsigned int v57; // r0
  int v58; // [sp+8h] [bp-58h]
  int v59; // [sp+Ch] [bp-54h]
  unsigned int v61; // [sp+1Ch] [bp-44h]
  int v62; // [sp+24h] [bp-3Ch]
  int v63; // [sp+28h] [bp-38h]
  int i; // [sp+30h] [bp-30h]
  int v66; // [sp+38h] [bp-28h] BYREF
  unsigned int *v67; // [sp+3Ch] [bp-24h]

  v4 = a4;
  *a4 = 0;
  v63 = *a2;
  v59 = 0;
  v6 = *(_DWORD *)(a1 + 1028);
  for ( i = v6; ; v6 = i )
  {
    v7 = *(_DWORD *)(v6 + 20 * *a2 + 8);
    if ( v7 == 0xFFFFF )
    {
      v8 = v59;
      goto LABEL_4;
    }
    v8 = MmPfnDatabase + 24 * v7;
    v10 = KfRaiseIrql(2);
    v62 = v10;
    v11 = (unsigned __int8 *)(v8 + 15);
    do
      v12 = __ldrex(v11);
    while ( __strex(v12 | 0x80, v11) );
    __dmb(0xBu);
    if ( v12 >> 7 )
    {
      v41 = (unsigned __int8 *)(v8 + 15);
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v42 = *(_DWORD *)(v8 + 12);
          __dmb(0xBu);
        }
        while ( v42 < 0 );
        do
          v43 = __ldrex(v41);
        while ( __strex(v43 | 0x80, v41) );
        __dmb(0xBu);
      }
      while ( v43 >> 7 );
    }
    if ( (*(_BYTE *)(v8 + 18) & 7) != 1 || (*(_DWORD *)(v8 + 20) & 0xFFFFF) == 1048574 )
    {
      __dmb(0xBu);
      v44 = (unsigned int *)(v8 + 12);
      do
        v45 = __ldrex(v44);
      while ( __strex(v45 & 0x7FFFFFFF, v44) );
      KfLowerIrql(v10);
      v4 = a4;
      v8 = v59;
      goto LABEL_5;
    }
    v13 = MmPfnDatabase + 24 * v7;
    v14 = *(_BYTE *)(v13 + 18) & 7;
    v61 = dword_633814 & v7 | (*(_DWORD *)(v13 + 20) >> 28 << byte_6337F5);
    v15 = (_DWORD *)(*(_DWORD *)&MiSystemPartition[2 * v14 + 512] + 20 * v61);
    v16 = v15 + 4;
    v66 = 0;
    v67 = v15 + 4;
    v58 = v14;
    __dmb(0xBu);
    if ( (dword_682604 & 0x210000) != 0 )
      return sub_5332B4();
    do
      v18 = __ldrex(v16);
    while ( __strex((unsigned int)&v66, v16) );
    __dmb(0xBu);
    if ( v18 )
      KxWaitForLockOwnerShip(&v66);
    v19 = *(unsigned int **)&MiSystemPartition[2 * v14 + 1226];
    do
      v20 = __ldrex(v19);
    while ( __strex(v20 - 1, v19) );
    if ( dword_634380 == 1 )
    {
      LOBYTE(v48) = 1;
      v49 = (unsigned int *)(*(_DWORD *)(dword_634388 + 4) + 4 * (v7 >> 5));
      v50 = v7 & 0x1F;
      if ( (unsigned int)(v50 + 1) > 0x20 )
      {
        if ( (v7 & 0x1F) != 0 )
        {
          v53 = 32 - v50;
          __dmb(0xBu);
          v54 = ((1 << (32 - v50)) - 1) << v50;
          do
            v55 = __ldrex(v49);
          while ( __strex(v55 | v54, v49) );
          __dmb(0xBu);
          v48 = 1 - v53;
          ++v49;
          if ( (unsigned int)(1 - v53) >= 0x20 )
          {
            v56 = v48 >> 5;
            do
            {
              v48 -= 32;
              --v56;
              *v49++ = -1;
            }
            while ( v56 );
          }
          v14 = v58;
          if ( !v48 )
            goto LABEL_20;
        }
        __dmb(0xBu);
        do
          v57 = __ldrex(v49);
        while ( __strex(v57 | ((1 << v48) - 1), v49) );
      }
      else
      {
        __dmb(0xBu);
        v51 = 1 << v50;
        do
          v52 = __ldrex(v49);
        while ( __strex(v52 | v51, v49) );
      }
      __dmb(0xBu);
    }
LABEL_20:
    --*v15;
    if ( v15[2] == v7 )
    {
      v21 = *(_DWORD *)v13;
      v15[2] = *(_DWORD *)v13;
      if ( v21 == 0xFFFFF )
      {
        v15[3] = 0xFFFFF;
      }
      else
      {
        v35 = (unsigned int *)(MmPfnDatabase + 24 * v21 + 12);
        v36 = *v35;
        v37 = *v35 | 0xFFFFF;
        do
          v38 = __ldrex(v35);
        while ( v38 == v36 && __strex(v37, v35) );
        if ( v36 == v38 )
        {
          v14 = v58;
        }
        else
        {
          do
          {
            v46 = v38;
            do
              v47 = __ldrex(v35);
            while ( v47 == v38 && __strex(v38 | 0xFFFFF, v35) );
            v38 = v47;
          }
          while ( v46 != v47 );
          v14 = v58;
        }
      }
    }
    else
    {
      *(_DWORD *)(MmPfnDatabase + 24 * (*(_DWORD *)(v13 + 12) & 0xFFFFF)) = *(_DWORD *)v13;
      if ( *(_DWORD *)v13 == 0xFFFFF )
        v15[3] = *(_DWORD *)(v13 + 12) & 0xFFFFF;
      else
        MiSetPfnBlink(MmPfnDatabase + 24 * *(_DWORD *)v13, *(_DWORD *)(v13 + 12) & 0xFFFFF, 0);
    }
    *(_BYTE *)(v13 + 18) = *(_BYTE *)(v13 + 18) & 0xF8 | 5;
    v22 = (unsigned __int8)byte_634378;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseQueuedSpinLockInstrumented(&v66);
      goto LABEL_29;
    }
    v23 = v66;
    if ( v66 )
      goto LABEL_53;
    v24 = v67;
    __dmb(0xBu);
    do
      v25 = (int *)__ldrex(v24);
    while ( v25 == &v66 && __strex(0, v24) );
    if ( v25 != &v66 )
    {
      v23 = KxWaitForLockChainValid(&v66);
LABEL_53:
      v66 = 0;
      __dmb(0xBu);
      v39 = (unsigned int *)(v23 + 4);
      do
        v40 = __ldrex(v39);
      while ( __strex(v40 ^ 1, v39) );
    }
LABEL_29:
    v26 = (unsigned int *)(dword_63F718 + 4 * (v14 + 26 * (v61 >> byte_6337F5) + 14));
    do
      v27 = __ldrex(v26);
    while ( __strex(v27 - 1, v26) );
    do
    {
      v28 = __ldrex((unsigned int *)&dword_640580);
      v29 = v28 - 1;
    }
    while ( __strex(v29, (unsigned int *)&dword_640580) );
    if ( v29 == dword_6402AC || v29 == dword_6402B0 )
      MiUpdateAvailableEvents(MiSystemPartition);
    if ( v29 <= 0x400 && (!dword_6404B8 || !*(_BYTE *)(dword_6404B8 + 44)) )
      MiObtainFreePages(MiSystemPartition);
    HIDWORD(v30) = *(_DWORD *)(v13 + 12);
    v31 = v30 & 0xFFF0000000000000ui64;
    *(_DWORD *)v13 = 0;
    *(_QWORD *)(v13 + 8) = v31;
    if ( v58 == 1 || v22 == 1 )
      *(_DWORD *)(v13 + 8) = 128;
    if ( (*(_BYTE *)(v8 + 18) & 7) != 5 || *(_WORD *)(v8 + 16) )
      KeBugCheck2(
        78,
        141,
        v7,
        *(unsigned __int16 *)(v8 + 16) | (*(unsigned __int16 *)(v8 + 18) << 16),
        *(_DWORD *)(v8 + 4),
        v31);
    *(_DWORD *)v8 = v59;
    __dmb(0xBu);
    v32 = (unsigned int *)(v8 + 12);
    do
      v33 = __ldrex(v32);
    while ( __strex(v33 & 0x7FFFFFFF, v32) );
    KfLowerIrql(v62);
    v34 = *(unsigned __int8 *)(v8 + 18) >> 6;
    if ( v34 )
    {
      if ( v34 != 2 || (MiFlags & 0x4000) == 0 )
        goto LABEL_43;
LABEL_96:
      MiChangePageAttribute(v8, 1, 0);
      goto LABEL_43;
    }
    if ( (MiFlags & 0x2000) != 0 )
      goto LABEL_96;
LABEL_43:
    v4 = a4;
    v59 = v8;
    ++*a4;
LABEL_4:
    v9 = *a2 & ~dword_6337E0 | (*a2 + 1) & dword_6337E0;
    *a2 = v9;
    if ( v9 == v63 )
      return v8;
LABEL_5:
    if ( *v4 == a3 )
      break;
  }
  return v8;
}
