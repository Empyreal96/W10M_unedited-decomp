// VeAllocatePoolWithTagPriority 
 
int VeAllocatePoolWithTagPriority(int a1, unsigned int a2, ...)
{
  int v2; // r6
  int v4; // r5
  int v5; // r9
  int v6; // r4
  unsigned int v7; // r10
  unsigned int v8; // r1
  int v9; // r2
  int v10; // r4
  int v11; // r0
  int v12; // r2
  int v13; // r2
  int *v14; // r6
  int v15; // r0
  int v16; // r2
  unsigned int v17; // r2
  unsigned int v18; // r2
  int v19; // r2
  char *v20; // r3
  int v21; // r9
  unsigned int v22; // r1
  unsigned int v23; // r1
  int *v24; // r2
  unsigned int v25; // r1
  unsigned int v26; // r1
  int v28; // [sp+8h] [bp-28h]
  int v29; // [sp+Ch] [bp-24h]
  int v30; // [sp+10h] [bp-20h]
  int varg_r2; // [sp+40h] [bp+10h] BYREF
  va_list varg_r2a; // [sp+40h] [bp+10h]
  int varg_r3; // [sp+44h] [bp+14h]
  int v34; // [sp+48h] [bp+18h]
  va_list va1; // [sp+4Ch] [bp+1Ch] BYREF

  va_start(va1, a2);
  va_start(varg_r2a, a2);
  varg_r2 = va_arg(va1, _DWORD);
  varg_r3 = va_arg(va1, _DWORD);
  v34 = va_arg(va1, _DWORD);
  v29 = varg_r3;
  v2 = 0;
  v4 = a1;
  v5 = 0;
  v28 = 0;
  if ( (MiFlags & 2) != 0 )
  {
    if ( (a1 & 0x80) != 0 )
    {
      v2 = 1;
      v28 = 1;
      v5 = VfTargetDriversGetVerifierData(v34);
      if ( !v5 )
        return ExAllocatePoolWithTagPriority(v4, a2, varg_r2, varg_r3);
    }
    else
    {
      v4 = a1 | 0x80;
    }
  }
  ExAllocatePoolSanityChecks(v4, a2, (int *)varg_r2a, v34);
  v30 = 0;
  if ( !a2 && (unsigned int)VfVerifyMode <= 1 )
  {
    v30 = 1;
    a2 = 1;
  }
  v7 = a2;
  do
    v8 = __ldrex((unsigned int *)&dword_620D90);
  while ( __strex(v8 + 1, (unsigned int *)&dword_620D90) );
  v9 = varg_r2;
  if ( (v4 & 2) != 0 )
  {
    if ( VfFaultsIsSystemSufficientlyBooted() )
      VerifierBugCheckIfAppropriate(194, 154, v4 & 0xFFFFFF7F);
    goto LABEL_25;
  }
  if ( (MmVerifierData & 4) == 0 )
  {
LABEL_25:
    v10 = v28;
    goto LABEL_26;
  }
  if ( v2 )
  {
    v10 = v28;
  }
  else
  {
    v10 = 1;
    v11 = VfTargetDriversGetVerifierData(v34);
    v9 = varg_r2;
    v5 = v11;
  }
  if ( v5 && VfFaultsInjectPoolAllocationFailure(v9 & 0x7FFFFFFF) )
  {
    if ( VfPoolTraces )
      ViPoolLogStackTrace(0, a2, v12);
    if ( (v4 & 0x10) != 0 )
      RtlRaiseStatus(-1073741670);
    return 0;
  }
LABEL_26:
  if ( (MmVerifierData & 1) != 0 && (v29 & 9) == 0 )
  {
    if ( MmSpecialPoolCatchOverruns == 1 )
      v13 = v29 | 8;
    else
      v13 = v29 | 9;
    v29 = v13;
  }
  v14 = 0;
  if ( (MmVerifierData & 8) != 0 && (v4 & 0x20) == 0 )
  {
    if ( !v10 )
      v5 = VfTargetDriversGetVerifierData(v34);
    if ( v5 && a2 + 4 > a2 )
    {
      v14 = (int *)RtlpInterlockedPopEntrySList((unsigned __int64 *)(v5 + 32));
      if ( v14 || (v14 = (int *)ViGrowPoolAllocation(v5)) != 0 )
      {
        a2 += 4;
        v4 |= 0x40u;
      }
    }
    else
    {
      ++dword_620DB8;
    }
  }
  v15 = ExAllocatePoolWithTagPriority(v4, a2, varg_r2, v29);
  v6 = v15;
  if ( !v15 )
  {
    ++dword_620DA8;
    if ( (MmVerifierData & 0x1000) != 0 )
      ViTargetIncrementCounter(v34, 88);
    if ( VfPoolTraces )
      ViPoolLogStackTrace(0, a2, v16);
    if ( v14 )
      RtlpInterlockedPushEntrySList((unsigned __int64 *)(v5 + 32), v14);
    if ( (v4 & 0x10) != 0 )
      RtlRaiseStatus(-1073741670);
    return 0;
  }
  if ( v30 )
  {
    __dmb(0xBu);
    do
    {
      v17 = __ldrex(&ViBugcheckWorkaroundLogIndex);
      v18 = v17 + 1;
    }
    while ( __strex(v18, &ViBugcheckWorkaroundLogIndex) );
    __dmb(0xBu);
    v19 = 3 * (v18 & 0xF);
    ViBugcheckWorkaroundLog[v19] = 1;
    v20 = (char *)&ViBugcheckWorkaroundLog[v19];
    *((_DWORD *)v20 + 1) = v34;
    *((_DWORD *)v20 + 2) = v15;
  }
  v21 = 0;
  do
  {
    v22 = __ldrex((unsigned int *)&dword_620D94);
    v23 = v22 + 1;
  }
  while ( __strex(v23, (unsigned int *)&dword_620D94) );
  if ( MmIsSpecialPoolAddress(v15, v23, (int)&dword_620D94) == 1 )
  {
    v21 = 1;
    v24 = &dword_620D98;
    do
      v25 = __ldrex((unsigned int *)&dword_620D98);
    while ( __strex(v25 + 1, (unsigned int *)&dword_620D98) );
  }
  else if ( a2 > 0xFF0 )
  {
    v24 = &dword_620D98;
    do
      v26 = __ldrex((unsigned int *)&dword_620D98);
    while ( __strex(v26 + 1, (unsigned int *)&dword_620D98) );
  }
  if ( v14 )
  {
    *v14 = v21 | v6;
    if ( v21 )
      a2 = v7;
    v14[1] = v34;
    v14[2] = a2;
    v14[3] = varg_r2;
    v6 = ViPostPoolAllocation(v14, v4, v24);
  }
  if ( VfPoolTraces )
    ViPoolLogStackTrace(v6, v7, v24);
  if ( v14 && !v21 )
  {
    if ( (v4 & 8) != 0 )
      v7 -= 4;
    VfFillAllocatedMemory(v6, v7, v24);
  }
  return v6;
}
