// MiFillNoReservationCluster 
 
int __fastcall MiFillNoReservationCluster(_DWORD *a1, _DWORD *a2, unsigned int a3)
{
  _DWORD *v5; // r10
  char v6; // r5
  unsigned int v7; // r8
  int v8; // r6
  int v9; // r4
  int v10; // lr
  unsigned __int8 *v11; // r7
  unsigned int v12; // r2
  int v13; // r3
  int v14; // r7
  char v15; // r3
  int v16; // r2
  unsigned int *v17; // r2
  unsigned int v18; // r0
  unsigned __int8 *v19; // r1
  int v20; // r3
  unsigned int v21; // r2
  unsigned int *v22; // r2
  unsigned int v23; // r0
  int v24; // r10
  unsigned int *v25; // r0
  unsigned int v26; // r1
  int v27; // r0
  unsigned int v28; // r2
  unsigned int *v29; // r7
  unsigned __int8 *v30; // r1
  unsigned int v31; // r3
  unsigned int v32; // r2
  unsigned int v33; // r1
  int v34; // r3
  _DWORD *v35; // [sp+0h] [bp-30h]
  int v37; // [sp+8h] [bp-28h]

  if ( a1[168] )
    return sub_53A0A8();
  v5 = a1 + 448;
  v6 = 1;
  v35 = a1 + 448;
  v7 = 0;
  do
  {
    v8 = v5[2];
    if ( v8 == 0xFFFFF )
      break;
    v9 = MmPfnDatabase + 24 * v8;
    v10 = KfRaiseIrql(2);
    v37 = v10;
    v11 = (unsigned __int8 *)(v9 + 15);
    do
      v12 = __ldrex(v11);
    while ( __strex(v12 | 0x80, v11) );
    __dmb(0xBu);
    if ( v12 >> 7 )
    {
      v19 = (unsigned __int8 *)(v9 + 15);
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v20 = *(_DWORD *)(v9 + 12);
          __dmb(0xBu);
        }
        while ( (v20 & 0x80000000) != 0 );
        do
          v21 = __ldrex(v19);
        while ( __strex(v21 | 0x80, v19) );
        __dmb(0xBu);
      }
      while ( v21 >> 7 );
    }
    if ( v8 != v5[2] )
    {
      __dmb(0xBu);
      v22 = (unsigned int *)(v9 + 12);
      do
        v23 = __ldrex(v22);
      while ( __strex(v23 & 0x7FFFFFFF, v22) );
      KfLowerIrql(v10);
      continue;
    }
    v13 = a1[150];
    __dmb(0xBu);
    if ( v13 && (*(_DWORD *)(v9 + 20) & 0x8000000) != 0 )
    {
      v24 = *(_DWORD *)(v9 + 4);
      if ( v24 >= 0 || a1[928] <= 0x80u )
      {
        v5 = v35;
      }
      else
      {
        __dmb(0xBu);
        v25 = (unsigned int *)(v9 + 12);
        do
          v26 = __ldrex(v25);
        while ( __strex(v26 & 0x7FFFFFFF, v25) );
        KfLowerIrql(v10);
        MiReservePageFileSpace(a1, v24 | 0x80000000, 0);
        v27 = KfRaiseIrql(2);
        do
          v28 = __ldrex(v11);
        while ( __strex(v28 | 0x80, v11) );
        __dmb(0xBu);
        v29 = (unsigned int *)(v9 + 12);
        if ( v28 >> 7 )
        {
          v30 = (unsigned __int8 *)(v9 + 15);
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
              v31 = *v29;
              __dmb(0xBu);
            }
            while ( (v31 & 0x80000000) != 0 );
            do
              v32 = __ldrex(v30);
            while ( __strex(v32 | 0x80, v30) );
            __dmb(0xBu);
          }
          while ( v32 >> 7 );
        }
        v5 = v35;
        v37 = v27;
        if ( v8 != v35[2] )
        {
          __dmb(0xBu);
          do
            v33 = __ldrex(v29);
          while ( __strex(v33 & 0x7FFFFFFF, v29) );
          KfLowerIrql(v27);
          continue;
        }
      }
    }
    if ( (v6 & 1) != 0 )
    {
      v14 = 1;
    }
    else
    {
      v14 = MiChargeForWriteInProgressPage(MiSystemPartition);
      if ( !v14 )
      {
        v14 = 0;
        goto LABEL_19;
      }
    }
    if ( (v6 & 4) == 0 )
    {
      MiUnlinkPageFromList(v9, 0);
      *(_DWORD *)(v9 + 12) &= 0xC0000000;
    }
    ++*(_WORD *)(v9 + 16);
    v15 = *(_BYTE *)(v9 + 18) | 8;
    *(_BYTE *)(v9 + 18) = v15;
    if ( (v6 & 8) == 0 )
      *(_BYTE *)(v9 + 18) = v15 & 0xEF;
    if ( (*(_DWORD *)(v9 + 8) & 0x400) == 0 && MiGetPagePrivilege(v9, 1, 0) )
    {
      v34 = *(unsigned __int8 *)(v9 + 18) | 0x20;
      *(_BYTE *)(v9 + 18) = v34;
      MiClearPfnImageVerified(v9, 28, v16, v34);
    }
LABEL_19:
    __dmb(0xBu);
    v17 = (unsigned int *)(v9 + 12);
    do
      v18 = __ldrex(v17);
    while ( __strex(v18 & 0x7FFFFFFF, v17) );
    KfLowerIrql(v37);
    if ( !v14 )
      break;
    *a2++ = v8;
    ++v7;
    v6 &= 0xFEu;
    if ( v14 == 3 && v7 >= 0x10 )
      break;
  }
  while ( v7 < a3 );
  if ( v7 > 1 )
    qsort(&a2[-v7], v7, 4, MiModifiedWriterNoReservationSort);
  return v7;
}
