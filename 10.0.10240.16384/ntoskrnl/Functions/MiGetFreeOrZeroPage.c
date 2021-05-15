// MiGetFreeOrZeroPage 
 
int __fastcall MiGetFreeOrZeroPage(int a1, unsigned int a2, int a3)
{
  int v6; // r9
  int v7; // r10
  int v8; // r0
  _DWORD *v9; // r8
  __int64 v11; // kr00_8
  unsigned int v12; // r4
  int v13; // r0
  int v14; // r0
  int *v15; // r8
  _DWORD *v16; // r1
  int v17; // lr
  int v18; // r3
  int v19; // r8
  int v20; // r1
  int v21; // r3
  __int16 i; // r0
  _DWORD *v23; // r4
  int v24; // r1
  int v25; // lr
  int v26; // r4
  int v27; // r2
  int v28; // r0
  int v29; // r8
  int v30; // r3
  int v31; // r0
  int v32; // r4
  int v33; // lr
  unsigned __int8 *v34; // r3
  unsigned int v35; // r1
  unsigned int *v36; // r2
  unsigned int v37; // r0
  unsigned int v38; // r2
  int v39; // r0
  _DWORD *v40; // r0
  unsigned int v41; // r2
  _DWORD *v42; // r0
  _DWORD *v43; // r0
  int v44; // r0
  _DWORD *v45; // r0
  int v46; // r0
  unsigned __int8 *v47; // r3
  unsigned int v48; // r1
  unsigned int *v49; // r2
  unsigned int v50; // r0
  unsigned __int8 *v51; // r1
  int v52; // r3
  unsigned int v53; // r2
  unsigned __int8 *v54; // r1
  int v55; // r3
  unsigned int v56; // r2
  char v57[4]; // [sp+0h] [bp-48h] BYREF
  int v58; // [sp+4h] [bp-44h]
  unsigned int v59; // [sp+8h] [bp-40h]
  int v60; // [sp+Ch] [bp-3Ch]
  int v61; // [sp+10h] [bp-38h]
  int v62; // [sp+14h] [bp-34h]
  int v63; // [sp+18h] [bp-30h]
  int v64; // [sp+1Ch] [bp-2Ch]
  _DWORD *v65; // [sp+20h] [bp-28h]
  int v66; // [sp+24h] [bp-24h]

  v6 = 0;
  v7 = a3 & 2;
  if ( (a3 & 2) == 0 )
  {
    v13 = *(_DWORD *)(a1 + 1036) + 8 * a2;
    if ( *(_WORD *)(v13 + 4) )
    {
      v42 = (_DWORD *)RtlpInterlockedPopEntrySList((unsigned __int64 *)v13);
      if ( v42 )
      {
        v12 = ((int)v42 - MmPfnDatabase) / 24;
        v42[2] = 128;
        *v42 = 0;
        if ( v12 != -1 )
          return v12;
      }
    }
    v14 = *(_DWORD *)(a1 + 1032) + 8 * a2;
    if ( *(_WORD *)(v14 + 4) )
    {
      v40 = (_DWORD *)RtlpInterlockedPopEntrySList((unsigned __int64 *)v14);
      v65 = v40;
      if ( v40 )
      {
        v41 = (int)((unsigned __int64)(715827883i64 * ((int)v40 - MmPfnDatabase)) >> 32) >> 2;
        v40[2] = 0;
        v15 = MiState;
        v12 = v41 + (v41 >> 31);
        if ( (MiFlags & 0x80) != 0
          && v12 < 0x200000
          && (*(_BYTE *)(MmPfnDatabase + 24 * v12 + 19) & 0x40) == 0
          && (MmPageValidationFrequency & ++dword_634414) == 0 )
        {
          if ( *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x1384) )
          {
            v64 = MiMapPageInHyperSpaceWorker(v12, v57, 0x80000000);
            if ( RtlCompareMemoryUlong(v64, 4096, 0) != 4096 )
              MiPageNotZero(v64, v12);
            MiUnmapPageInHyperSpaceWorker(v64, (unsigned __int8)v57[0], 0x80000000);
            v40 = v65;
          }
        }
        *v40 = 0;
        if ( v12 != -1 )
          return v12;
      }
      else
      {
        v15 = MiState;
        v12 = -1;
      }
    }
    else
    {
      v15 = MiState;
      v12 = -1;
    }
    goto LABEL_17;
  }
  v8 = *(_DWORD *)(a1 + 1032) + 8 * a2;
  if ( *(_WORD *)(v8 + 4) )
  {
    v9 = (_DWORD *)RtlpInterlockedPopEntrySList((unsigned __int64 *)v8);
    if ( !v9 )
      return sub_535F00();
    v11 = 715827883i64 * ((int)v9 - MmPfnDatabase);
    v9[2] = 0;
    v12 = (SHIDWORD(v11) >> 2) + (HIDWORD(v11) >> 31);
    if ( (MiFlags & 0x80) != 0
      && v12 < 0x200000
      && (*(_BYTE *)(MmPfnDatabase + 24 * v12 + 19) & 0x40) == 0
      && (MmPageValidationFrequency & ++dword_634414) == 0 )
    {
      if ( *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x1384) )
      {
        v64 = MiMapPageInHyperSpaceWorker(v12, v57, 0x80000000);
        if ( RtlCompareMemoryUlong(v64, 4096, 0) != 4096 )
          MiPageNotZero(v64, v12);
        MiUnmapPageInHyperSpaceWorker(v64, (unsigned __int8)v57[0], 0x80000000);
      }
    }
    *v9 = 0;
    if ( v12 != -1 )
      return v12;
  }
  else
  {
    v12 = -1;
  }
  v15 = MiState;
  v16 = (_DWORD *)(*(_DWORD *)(a1 + 1024) + 20 * a2);
  v17 = *(_DWORD *)(a1 + 3252);
  if ( v16[4] || (a3 & 1) != 0 )
    goto LABEL_65;
  if ( *v16 >= (unsigned int)(v17 + 64) )
  {
    v12 = -2;
  }
  else if ( *(_DWORD *)(*(_DWORD *)(a1 + 1028) + 20 * a2) >= (unsigned int)(v17 + 64) )
  {
    goto LABEL_65;
  }
  v6 = 1;
  if ( *(_DWORD *)(a1 + 3712) < (unsigned int)(v17 + 1024) )
  {
    v6 = 0;
LABEL_65:
    v44 = *(_DWORD *)(a1 + 1036) + 8 * a2;
    if ( *(_WORD *)(v44 + 4) )
    {
      v45 = (_DWORD *)RtlpInterlockedPopEntrySList((unsigned __int64 *)v44);
      if ( v45 )
      {
        v12 = ((int)v45 - MmPfnDatabase) / 24;
        *v45 = 0;
        v45[2] = 128;
        if ( v12 != -1 )
          return v12;
      }
      else
      {
        v12 = -1;
      }
    }
    else
    {
      v12 = -1;
    }
  }
LABEL_17:
  v18 = *(_DWORD *)(a1 + 24);
  v59 = a2 >> *((_BYTE *)v15 + 3445);
  v19 = v18 + 104 * v59;
  v66 = v19;
LABEL_18:
  if ( v12 == -2 )
    goto LABEL_42;
  v20 = 0;
  v21 = 0;
  for ( i = a3; ; i |= 2u )
  {
    v23 = (_DWORD *)(v19 + 4 * v21);
    v20 += v23[14];
    if ( (i & 0x400) != 0 )
      v20 += (v23[10] + v23[12]) << 10;
    if ( (i & 2) != 0 )
      break;
    v21 = 1;
  }
  if ( v20 )
    goto LABEL_42;
  if ( (a3 & 1) == 0 )
  {
    v24 = *(_DWORD *)(a1 + 24) + 104 * v59;
    v65 = (_DWORD *)v24;
    if ( v7 )
    {
      v25 = 0;
      v26 = 1;
    }
    else
    {
      v25 = 1;
      v26 = 0;
    }
    v27 = 0;
    v28 = 0;
    v58 = 0;
    v64 = v26;
    v61 = 0;
    v62 = v25;
    v60 = 0;
    v29 = v25;
    while ( 1 )
    {
      if ( v27 )
      {
        v28 = *(unsigned __int8 *)v27;
        v60 = v28;
      }
      if ( *(_DWORD *)(v24 + 8 * (v29 + v28 + 1)) != v24 + 8 * (v29 + v28 + 1) )
      {
        v63 = MiUnlinkNodeLargePage(a1, v59, v28, v25);
        if ( v63 )
        {
          v46 = KfRaiseIrql(2);
          v32 = v63;
          v33 = v46;
          v47 = (unsigned __int8 *)(v63 + 15);
          do
            v48 = __ldrex(v47);
          while ( __strex(v48 | 0x80, v47) );
          __dmb(0xBu);
          if ( v48 >> 7 )
          {
            v51 = (unsigned __int8 *)(v32 + 15);
            do
            {
              do
              {
                __dmb(0xAu);
                __yield();
                v52 = *(_DWORD *)(v32 + 12);
                __dmb(0xBu);
              }
              while ( (v52 & 0x80000000) != 0 );
              do
                v53 = __ldrex(v51);
              while ( __strex(v53 | 0x80, v51) );
              __dmb(0xBu);
            }
            while ( v53 >> 7 );
          }
          *(_BYTE *)(v32 + 18) ^= (*(_BYTE *)(v32 + 18) ^ v62) & 7;
          __dmb(0xBu);
          v49 = (unsigned int *)(v32 + 12);
          do
            v50 = __ldrex(v49);
          while ( __strex(v50 & 0x7FFFFFFF, v49) );
LABEL_41:
          KfLowerIrql(v33);
          MiInsertLargePageInFreeOrZeroList(v32, *(_BYTE *)(v32 + 18) & 7);
          v19 = v66;
LABEL_42:
          if ( (a3 & 4) == 0 )
          {
            v38 = *(_DWORD *)(a1 + 3712);
            if ( v38 < 0x80
              && ((*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3C4) & 2) == 0 || v38 < 2)
              && ((__int16 *)a1 == MiSystemPartition || v38 < 2) )
            {
              goto LABEL_48;
            }
          }
          v12 = MiRemoveAnyPage(a1, a2, a3);
          if ( v12 == -1 )
          {
            if ( (a3 & 1) == 0 )
              goto LABEL_18;
LABEL_48:
            v12 = -1;
            if ( v6 != 1 )
              goto LABEL_51;
            v39 = *(_DWORD *)(a1 + 1036) + 8 * a2;
            if ( !*(_WORD *)(v39 + 4) )
            {
              v12 = -1;
              goto LABEL_51;
            }
            v43 = (_DWORD *)RtlpInterlockedPopEntrySList((unsigned __int64 *)v39);
            if ( !v43 )
            {
              v12 = -1;
              goto LABEL_51;
            }
            v12 = ((int)v43 - MmPfnDatabase) / 24;
            v43[2] = 128;
            *v43 = 0;
            if ( v12 == -1 )
            {
LABEL_51:
              if ( v7 )
                goto LABEL_52;
            }
          }
          return v12;
        }
        v24 = (int)v65;
        v28 = v60;
      }
      if ( *(_DWORD *)(v24 + 8 * (v26 + v28 + 1)) != v24 + 8 * (v26 + v28 + 1) )
      {
        v63 = MiUnlinkNodeLargePage(a1, v59, v28, v64);
        if ( v63 )
        {
          v31 = KfRaiseIrql(2);
          v32 = v63;
          v33 = v31;
          v34 = (unsigned __int8 *)(v63 + 15);
          do
            v35 = __ldrex(v34);
          while ( __strex(v35 | 0x80, v34) );
          __dmb(0xBu);
          if ( v35 >> 7 )
          {
            v54 = (unsigned __int8 *)(v32 + 15);
            do
            {
              do
              {
                __dmb(0xAu);
                __yield();
                v55 = *(_DWORD *)(v32 + 12);
                __dmb(0xBu);
              }
              while ( (v55 & 0x80000000) != 0 );
              do
                v56 = __ldrex(v54);
              while ( __strex(v56 | 0x80, v54) );
              __dmb(0xBu);
            }
            while ( v56 >> 7 );
          }
          *(_BYTE *)(v32 + 18) ^= (*(_BYTE *)(v32 + 18) ^ v64) & 7;
          __dmb(0xBu);
          v36 = (unsigned int *)(v32 + 12);
          do
            v37 = __ldrex(v36);
          while ( __strex(v37 & 0x7FFFFFFF, v36) );
          goto LABEL_41;
        }
        v24 = (int)v65;
        v28 = v60;
      }
      v27 = v61;
      v30 = v58;
      if ( v61 )
      {
        v27 = v61 + 1;
        v61 = v27;
        if ( v27 )
        {
          v30 = v58 - 1;
          v26 -= 2;
          v29 -= 2;
        }
        else
        {
          v27 = -1;
          v61 = -1;
        }
      }
      v26 += 2;
      v58 = v30 + 1;
      v29 += 2;
      if ( v30 + 1 > 1 )
        goto LABEL_48;
      v25 = v62;
    }
  }
  if ( v7 )
LABEL_52:
    v12 = MiGetFreeOrZeroPage(a1, a2, a3 & 0xFFFFFFFD);
  else
    v12 = -1;
  return v12;
}
