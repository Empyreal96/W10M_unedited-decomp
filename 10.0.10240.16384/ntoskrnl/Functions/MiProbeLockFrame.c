// MiProbeLockFrame 
 
int __fastcall MiProbeLockFrame(int a1)
{
  unsigned int v2; // r2
  int v3; // r0
  __int64 v4; // r2
  int v5; // r5
  int v6; // r4
  unsigned __int8 *v7; // r1
  unsigned int v8; // r2
  unsigned int v9; // r1
  int v10; // r2
  int v11; // r3
  int v12; // r10
  unsigned int v13; // r2
  unsigned int *v14; // r4
  unsigned int v15; // r1
  unsigned int v16; // r0
  int v17; // r4
  unsigned int v18; // r0
  int v19; // r7
  bool v20; // zf
  unsigned int *v21; // r4
  unsigned int v22; // r1
  unsigned int v23; // r2
  int v24; // r7
  int v25; // r10
  int v26; // r9
  int result; // r0
  unsigned __int64 *v28; // r3
  unsigned __int64 v29; // kr00_8
  int v30; // r0
  int v31; // r1
  int v32; // r2
  unsigned int v33; // r1
  unsigned __int8 *v34; // r1
  unsigned int v35; // r2
  int v36; // r3
  unsigned int v37; // r2
  unsigned __int8 *v38; // r1
  unsigned int v39; // r2
  unsigned int v40; // r3
  unsigned int v41; // r2
  unsigned int v42; // r1
  int v43; // r7
  unsigned int *v44; // r2
  unsigned int v45; // r0
  unsigned int v46; // r0
  unsigned int *v47; // r2
  unsigned int v48; // r0
  unsigned int v49; // r0
  _DWORD *v50; // r0
  int v51; // r3
  char v52[4]; // [sp+8h] [bp-28h] BYREF
  int v53; // [sp+Ch] [bp-24h]

  v2 = *(_DWORD *)(a1 + 52);
  if ( v2 > dword_633850 || dword_634C9C && ((*(_DWORD *)(dword_634C9C + 4 * (v2 >> 5)) >> (v2 & 0x1F)) & 1) == 0 )
  {
    if ( *(_DWORD *)(a1 + 40) )
    {
      v50 = MiLocateAddress(*(_DWORD *)a1);
      if ( !v50 || (v51 = v50[7] & 7, v51 != 6) && v51 != 1 )
      {
        result = -1073741819;
        ++dword_6343E0;
        return result;
      }
    }
    result = MiReferenceIoPages(0, *(_DWORD *)(a1 + 52), 1, 0, 0, 0);
    if ( result < 0 )
    {
      ++dword_6343E4;
      return result;
    }
    *(_WORD *)(*(_DWORD *)(a1 + 24) + 6) |= 0x800u;
    return 0;
  }
  v52[0] = 17;
  if ( *(_DWORD *)(a1 + 28) != 4 || (*(_DWORD *)(((*(_DWORD *)a1 >> 20) & 0xFFC) - 1070596096) & 0x402) == 1026 )
  {
    v3 = MmPfnDatabase;
  }
  else
  {
    v5 = MiLockNonPagedPoolPte(((*(_DWORD *)a1 >> 10) & 0x3FFFFC) - 0x40000000, v52);
    v3 = MmPfnDatabase;
    *(_DWORD *)(a1 + 52) = (v5 - MmPfnDatabase) / 24;
    if ( v5 )
    {
      v6 = (unsigned __int8)v52[0];
      v53 = (unsigned __int8)v52[0];
      goto LABEL_10;
    }
  }
  v4 = *(_QWORD *)(a1 + 48);
  v5 = v3 + 24 * HIDWORD(v4);
  if ( (_DWORD)v4 == MmBadPointer )
  {
    v6 = KfRaiseIrql(2);
    v53 = v6;
    v34 = (unsigned __int8 *)(v5 + 15);
    do
      v35 = __ldrex(v34);
    while ( __strex(v35 | 0x80, v34) );
    __dmb(0xBu);
    if ( v35 >> 7 )
      return sub_5452BC();
  }
  else
  {
    v6 = 17;
    v53 = 17;
    v7 = (unsigned __int8 *)(v5 + 15);
    do
      v8 = __ldrex(v7);
    while ( __strex(v8 | 0x80, v7) );
    __dmb(0xBu);
    if ( v8 >> 7 )
    {
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v36 = *(_DWORD *)(v5 + 12);
          __dmb(0xBu);
        }
        while ( (v36 & 0x80000000) != 0 );
        do
          v37 = __ldrex(v7);
        while ( __strex(v37 | 0x80, v7) );
        __dmb(0xBu);
      }
      while ( v37 >> 7 );
    }
  }
LABEL_10:
  if ( (*(_BYTE *)(v5 + 18) & 7u) <= 1 || (v9 = *(unsigned __int16 *)(v5 + 16), !*(_WORD *)(v5 + 16)) )
  {
    __dmb(0xBu);
    v47 = (unsigned int *)(v5 + 12);
    if ( v6 == 17 )
    {
      do
        v48 = __ldrex(v47);
      while ( __strex(v48 & 0x7FFFFFFF, v47) );
    }
    else
    {
      do
        v49 = __ldrex(v47);
      while ( __strex(v49 & 0x7FFFFFFF, v47) );
      KfLowerIrql(v6);
    }
    result = -1073741819;
    ++dword_6343D4;
    return result;
  }
  v10 = *(_DWORD *)(a1 + 24);
  if ( (*(_WORD *)(v10 + 6) & 0x80) != 0
    && (*(_BYTE *)(v5 + 18) & 0x20) != 0
    && (*(_DWORD *)(v5 + 12) & 0x3FFFFFFF) == 0
    && *(_DWORD *)v5
    && (*(_BYTE *)(v5 + 23) & 7) != 1 )
  {
    KeBugCheckEx(26, 399686, v10);
  }
  if ( v9 >= 0x7FFF )
    goto LABEL_96;
  v11 = *(_DWORD *)(v5 + 12) & 0x3FFFFFFF;
  if ( !*(_WORD *)(v5 + 16) )
  {
LABEL_18:
    v12 = 0;
    if ( ((*(_DWORD *)(v5 + 20) & 0x8000000) == 0 || (*(_DWORD *)(v5 + 8) & 0x400) == 0)
      && ((v13 = *(_DWORD *)(v5 + 4) | 0x80000000,
           v13 > (((unsigned int)MmHighestUserAddress >> 10) & 0x3FFFFC) - 0x40000000)
       || v13 < 0xC0000000
       || ((*(unsigned __int8 *)(v5 + 19) >> 5) & 1) == 0)
      || (v12 = 1, MiChargeCommit((int)MiSystemPartition, 1u, 8)) )
    {
      v14 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 4992);
      v15 = *v14;
      if ( *v14 )
      {
        while ( v15 != -1 )
        {
          do
            v16 = __ldrex(v14);
          while ( v16 == v15 && __strex(v15 - 1, v14) );
          if ( v16 == v15 )
          {
            v17 = 1;
            goto LABEL_26;
          }
          v15 = v16;
          if ( !v16 )
            break;
        }
      }
      v17 = MiChargePartitionResidentAvailable((int)MiSystemPartition, 1u, 0);
      if ( v17 )
      {
        do
LABEL_26:
          v18 = __ldrex(&dword_634A2C[85]);
        while ( __strex(v18 + 1, &dword_634A2C[85]) );
      }
      else if ( v12 )
      {
        MiReturnCommit((int)MiSystemPartition, 1);
      }
      if ( v17 )
        goto LABEL_28;
    }
LABEL_96:
    v43 = v53;
    v20 = v53 == 17;
    __dmb(0xBu);
    v44 = (unsigned int *)(v5 + 12);
    if ( v20 )
    {
      do
        v45 = __ldrex(v44);
      while ( __strex(v45 & 0x7FFFFFFF, v44) );
    }
    else
    {
      do
        v46 = __ldrex(v44);
      while ( __strex(v46 & 0x7FFFFFFF, v44) );
      KfLowerIrql(v43);
    }
    result = -1073741663;
    ++dword_6343D8;
    return result;
  }
  if ( v9 == 1 )
  {
    if ( v11 || (*(_BYTE *)(v5 + 18) & 8) != 0 )
      goto LABEL_18;
  }
  else if ( v9 == 2 && v11 && (*(_BYTE *)(v5 + 18) & 8) != 0 )
  {
    goto LABEL_18;
  }
LABEL_28:
  ++*(_WORD *)(v5 + 16);
  v19 = v53;
  v20 = v53 == 17;
  __dmb(0xBu);
  v21 = (unsigned int *)(v5 + 12);
  if ( v20 )
  {
    do
      v22 = __ldrex(v21);
    while ( __strex(v22 & 0x7FFFFFFF, v21) );
  }
  else
  {
    do
      v33 = __ldrex(v21);
    while ( __strex(v33 & 0x7FFFFFFF, v21) );
    KfLowerIrql(v19);
  }
  if ( *(_DWORD *)(a1 + 28) != 1
    || (v23 = *(_DWORD *)(v5 + 20), (v23 & 0x7000000) == 0x1000000)
    || (v24 = v23 & 0xFFFFF, (v23 & 0xFFFFF) == 1048573)
    || (v25 = (v23 >> 27) & 1, v26 = MmPfnDatabase, !v25) && !MiIsLowestPageTablePage(MmPfnDatabase + 24 * v24)
    || *(_DWORD *)(a1 + 56) == v24 )
  {
LABEL_37:
    if ( (*(_WORD *)(*(_DWORD *)(a1 + 24) + 6) & 0x80) != 0
      && (*(_DWORD *)(v5 + 20) & 0x8000000) != 0
      && (*(_DWORD *)(v5 + 8) & 0x400) != 0 )
    {
      v28 = (unsigned __int64 *)(*(_DWORD *)(*(_DWORD *)(v5 + 8) & 0xFFFFF800 | (2 * (*(_DWORD *)(v5 + 8) & 0x3FC))) + 64);
      do
        v29 = __ldrexd(v28);
      while ( __strexd(v29 + 1, v28) );
      return 0;
    }
    return 0;
  }
  if ( v25 )
  {
    v31 = 1;
    v30 = v5;
  }
  else
  {
    v30 = v26 + 24 * v24;
    v31 = 0;
  }
  if ( MiLockPageTablePage(v30, v31) )
  {
    v32 = *(_DWORD *)(a1 + 24);
    *(_DWORD *)(a1 + 56) = *(_DWORD *)(v5 + 20) & 0xFFFFF;
    *(_WORD *)(v32 + 6) |= 0x100u;
    goto LABEL_37;
  }
  v38 = (unsigned __int8 *)(v5 + 15);
  do
    v39 = __ldrex(v38);
  while ( __strex(v39 | 0x80, v38) );
  __dmb(0xBu);
  if ( v39 >> 7 )
  {
    do
    {
      do
      {
        __dmb(0xAu);
        __yield();
        v40 = *v21;
        __dmb(0xBu);
      }
      while ( (v40 & 0x80000000) != 0 );
      do
        v41 = __ldrex(v38);
      while ( __strex(v41 | 0x80, v38) );
      __dmb(0xBu);
    }
    while ( v41 >> 7 );
  }
  MiRemoveLockedPageChargeAndDecRef(v5);
  __dmb(0xBu);
  do
    v42 = __ldrex(v21);
  while ( __strex(v42 & 0x7FFFFFFF, v21) );
  result = -1073741663;
  ++dword_6343DC;
  return result;
}
