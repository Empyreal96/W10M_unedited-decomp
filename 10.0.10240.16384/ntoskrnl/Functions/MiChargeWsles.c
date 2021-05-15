// MiChargeWsles 
 
int __fastcall MiChargeWsles(int a1, int a2, int a3)
{
  int v3; // r10
  int v6; // r7
  unsigned __int8 *v8; // r3
  unsigned int v9; // r1
  unsigned int v10; // r5
  unsigned int v11; // r8
  int v12; // r0
  unsigned int v13; // r0
  int v14; // r10
  unsigned int v15; // r3
  __int64 v16; // kr00_8
  int v17; // r3
  unsigned int v18; // r3
  __int64 v19; // r2
  unsigned int v20; // r8
  unsigned int v21; // r0
  unsigned int v22; // r1
  unsigned int v23; // r3

  v3 = *(_DWORD *)(a1 + 92);
  if ( !v3 )
    return 1;
  if ( a3 == 1 )
  {
    v6 = 17;
  }
  else
  {
    v6 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
      return sub_5441C8();
    v8 = (unsigned __int8 *)(a1 + 3);
    do
      v9 = __ldrex(v8);
    while ( __strex(v9 | 0x80, v8) );
    __dmb(0xBu);
    if ( v9 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)a1);
    while ( 1 )
    {
      v10 = *(_DWORD *)a1;
      if ( (*(_DWORD *)a1 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v10 & 0x40000000) == 0 )
      {
        do
          v22 = __ldrex((unsigned int *)a1);
        while ( v22 == v10 && __strex(v10 | 0x40000000, (unsigned int *)a1) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v11 = *(_BYTE *)(a1 + 112) & 7;
  if ( v11 < 2 )
  {
    v12 = *(_DWORD *)(a1 + 48);
    if ( v12 )
    {
      if ( v12 + a2 )
        v12 += 4;
      else
        a2 -= 4;
    }
    else
    {
      a2 += 4;
    }
  }
  else
  {
    v12 = MiState[v11 + 1562] + MiState[v11 + 1557];
  }
  if ( a2 <= 0 )
    v12 += a2;
  v13 = MiComputeWslePagesNeeded(*(_DWORD *)(v3 + 252) + *(_DWORD *)(v3 + 36) * v12);
  v14 = v13;
  if ( a2 <= 0 )
  {
    if ( v13 )
    {
      if ( v11 >= 2 && *(_DWORD *)(a1 + 72) - v13 < *(_DWORD *)(a1 + 76) )
        MiRemoveWorkingSetPages(a1);
      v16 = *(_QWORD *)(a1 + 72);
      v17 = v16 - v14;
      if ( (unsigned int)(v16 - v14) < HIDWORD(v16) )
      {
        if ( (unsigned int)v16 < HIDWORD(v16) )
          v14 = 0;
        else
          v14 = v16 - HIDWORD(v16);
      }
      *(_DWORD *)(a1 + 72) = v17;
      if ( v14 )
      {
        MiReturnCommit((int)MiSystemPartition, v14);
        MiReturnResidentAvailable(v14);
        do
          v18 = __ldrex(&dword_634A2C[42]);
        while ( __strex(v18 + v14, &dword_634A2C[42]) );
      }
    }
    goto LABEL_16;
  }
  if ( !v13 )
  {
LABEL_16:
    v15 = *(_BYTE *)(a1 + 112) & 7;
    if ( v15 >= 2 )
      MiState[v15 + 1562] += a2;
    if ( v6 != 17 )
      MiUnlockWorkingSetExclusive(a1, v6);
    return 1;
  }
  v19 = *(_QWORD *)(a1 + 72);
  v20 = v13;
  if ( HIDWORD(v19) > (unsigned int)v19 )
  {
    v23 = HIDWORD(v19) - v19;
    if ( v23 >= v13 )
      goto LABEL_37;
    v20 = v13 - v23;
  }
  if ( !v20 )
  {
LABEL_37:
    *(_DWORD *)(a1 + 72) += v14;
    goto LABEL_16;
  }
  if ( MiChargeCommit((int)MiSystemPartition, v20, 0) )
  {
    if ( MiChargeResident(MiSystemPartition, v20, 0) )
    {
      do
        v21 = __ldrex(&dword_634A2C[41]);
      while ( __strex(v21 + v20, &dword_634A2C[41]) );
      goto LABEL_37;
    }
    MiReturnCommit((int)MiSystemPartition, v20);
  }
  if ( v6 != 17 )
    MiUnlockWorkingSetExclusive(a1, v6);
  return 0;
}
