// PspAssignProcessToJob 
 
int __fastcall PspAssignProcessToJob(int a1, unsigned int *a2, int a3)
{
  int v5; // r3
  unsigned int *v6; // r2
  unsigned int v7; // r7
  unsigned int v8; // r6
  unsigned int v9; // r5
  char v10; // r6
  int v11; // r0
  unsigned int v12; // r2
  int v13; // r5
  unsigned int v14; // r6
  unsigned __int8 *v15; // r3
  unsigned int v16; // r2
  unsigned int *v17; // r4
  unsigned int v18; // r1
  int v19; // r5
  unsigned int v20; // r5
  int v21; // r4
  unsigned int *v22; // r2
  unsigned int v23; // r4
  unsigned int v24; // r1
  __int16 v25; // r3
  int v26; // r0
  __int16 v27; // r3
  unsigned int *v28; // r0
  unsigned int v29; // r4
  unsigned int v30; // r1
  unsigned int *v32; // r2
  unsigned int v33; // r4
  unsigned int v34; // r1
  int v35; // r0
  __int16 v36; // r3
  int v38[6]; // [sp+1Ch] [bp-50h] BYREF
  _DWORD v39[14]; // [sp+34h] [bp-38h] BYREF

  v39[0] = 0;
  v39[1] = 0;
  v39[2] = 0;
  v39[3] = 0;
  v39[4] = 0;
  v5 = __mrc(15, 0, 13, 0, 3);
  v6 = a2 + 43;
  __pld(a2 + 43);
  v7 = v5 & 0xFFFFFFC0;
  v8 = a2[43] & 0xFFFFFFFE;
  do
    v9 = __ldrex(v6);
  while ( v9 == v8 && __strex(v8 + 2, v6) );
  __dmb(0xBu);
  if ( v9 != v8 && !ExfAcquireRundownProtection(a2 + 43) )
    return sub_7C186C();
  PspGetJobLockHierarchyForAssignment(a1, a2, a3, v39);
  v10 = 11;
  --*(_WORD *)(v7 + 310);
  v11 = KeAbPreAcquire((unsigned int)&PspJobAssignmentLock, 0, 0);
  do
    v12 = __ldrex((unsigned __int8 *)&PspJobAssignmentLock);
  while ( __strex(v12 | 1, (unsigned __int8 *)&PspJobAssignmentLock) );
  __dmb(0xBu);
  if ( (v12 & 1) != 0 )
    JUMPOUT(0x7C1872);
  if ( v11 )
    *(_BYTE *)(v11 + 14) |= 1u;
  PspLockJobsAndProcessExclusive(v39, a2, v7);
  v13 = PspGetJobAssignmentDisposition(a1, a2, v38);
  if ( v13 < 0 )
    JUMPOUT(0x7C1880);
  if ( v38[0] != a3 )
    JUMPOUT(0x7C1884);
  if ( v38[0] != 2 )
  {
    v14 = a2[72];
    __dmb(0xBu);
    if ( v38[0] == 4 && (*(_DWORD *)(v14 + 744) & 0x10) != 0 || PspEstablishJobHierarchy(a1, a2) < 0 )
      goto LABEL_77;
    if ( (*(_DWORD *)(a1 + 744) & 0x1000) != 0 )
    {
      if ( (a2[196] & 0x7FFFFFFF) != 0 )
        JUMPOUT(0x7C1888);
      __dmb(0xBu);
      v15 = (unsigned __int8 *)a2 + 787;
      do
        v16 = __ldrex(v15);
      while ( __strex(v16 | 0x80, v15) );
      __dmb(0xBu);
    }
    v17 = a2 + 42;
    __dmb(0xBu);
    do
      v18 = __ldrex(v17);
    while ( __strex(v18 - 1, v17) );
    if ( (v18 & 2) != 0 )
      JUMPOUT(0x7C18A4);
    KeAbPostRelease((unsigned int)(a2 + 42));
    v19 = PspAddProcessToJobChain(a1, v14, a2, 0);
    PspUnlockJobsAndProcessExclusive(v39, 0, v7);
    if ( v19 < 0 )
      JUMPOUT(0x7C1946);
    if ( (*(_DWORD *)(a1 + 744) & 0x1000000) == 0 )
    {
      v20 = PsReferencePrimaryToken(a2);
      v21 = SeSecurityAttributePresent(v20, &PspSysAppIdClaim);
      ObFastDereferenceObject(a2 + 61, v20);
      if ( !v21 )
      {
        __dmb(0xBu);
        v32 = (unsigned int *)(a1 + 744);
        do
          v33 = __ldrex(v32);
        while ( __strex(v33 | 0x800000, v32) );
        __dmb(0xBu);
      }
      __dmb(0xBu);
      v22 = (unsigned int *)(a1 + 744);
      do
        v23 = __ldrex(v22);
      while ( __strex(v23 | 0x1000000, v22) );
      __dmb(0xBu);
    }
    v13 = PspApplyWorkingSetLimitsToProcess(a2);
    if ( v13 < 0 )
LABEL_77:
      JUMPOUT(0x7C1948);
    if ( !MmAssignProcessToJob(a2, v14) )
      JUMPOUT(0x7C18B6);
    __dmb(0xBu);
    do
      v24 = __ldrex((unsigned int *)&PspJobAssignmentLock);
    while ( __strex(v24 - 1, (unsigned int *)&PspJobAssignmentLock) );
    if ( (v24 & 2) != 0 )
      JUMPOUT(0x7C18BC);
    KeAbPostRelease((unsigned int)&PspJobAssignmentLock);
    v25 = *(_WORD *)(v7 + 310) + 1;
    *(_WORD *)(v7 + 310) = v25;
    if ( !v25 && *(_DWORD *)(v7 + 100) != v7 + 100 )
      JUMPOUT(0x7C18CE);
    v10 = 12;
    --*(_WORD *)(v7 + 308);
    v26 = PspChangeProcessExecutionState(a2);
    v27 = *(_WORD *)(v7 + 308) + 1;
    *(_WORD *)(v7 + 308) = v27;
    if ( !v27 && *(_DWORD *)(v7 + 100) != v7 + 100 && !*(_WORD *)(v7 + 310) )
      KiCheckForKernelApcDelivery(v26);
    if ( a2[71] )
      JUMPOUT(0x7C18D6);
  }
  if ( (v10 & 2) != 0 )
    PspUnlockJobsAndProcessExclusive(v39, a2, v7);
  if ( (v10 & 1) != 0 )
  {
    __dmb(0xBu);
    do
      v34 = __ldrex((unsigned int *)&PspJobAssignmentLock);
    while ( __strex(v34 - 1, (unsigned int *)&PspJobAssignmentLock) );
    if ( (v34 & 2) != 0 && (v34 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)&PspJobAssignmentLock);
    v35 = KeAbPostRelease((unsigned int)&PspJobAssignmentLock);
    v36 = *(_WORD *)(v7 + 310) + 1;
    *(_WORD *)(v7 + 310) = v36;
    if ( !v36 && *(_DWORD *)(v7 + 100) != v7 + 100 )
      KiCheckForKernelApcDelivery(v35);
  }
  if ( (v10 & 8) != 0 )
  {
    v28 = a2 + 43;
    __pld(a2 + 43);
    v29 = a2[43] & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v30 = __ldrex(v28);
    while ( v30 == v29 && __strex(v29 - 2, v28) );
    if ( v30 != v29 )
      ExfReleaseRundownProtection((unsigned __int8 *)v28);
  }
  return v13;
}
