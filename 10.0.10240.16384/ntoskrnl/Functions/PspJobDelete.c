// PspJobDelete 
 
int __fastcall PspJobDelete(int a1)
{
  unsigned int v2; // r5
  int v3; // r3
  int v4; // r0
  int v5; // r2
  int v6; // r3
  int result; // r0
  int v8; // r2
  int *v9; // r1
  int v10; // t1
  int v11; // r6
  int v12; // r2
  int *v13; // r1
  int v14; // t1
  int v15; // r0
  __int16 v16; // r3
  int v17; // r1
  int v18; // r0
  __int16 v19; // r3
  int v20; // r0
  int v21; // r3
  int v22; // r0
  int v23; // r6
  unsigned int v24; // r2
  __int64 v25; // r0
  unsigned int v26; // r1
  int v27; // r0
  __int16 v28; // r3
  int v29; // r0
  unsigned int *v30; // r6
  int v31; // r0
  unsigned int v32; // r2
  __int64 **v33; // r7
  __int64 *v34; // r2
  __int64 v35; // r0
  int v36; // r0
  int v37; // r0
  __int64 v38; // r2
  int v39; // [sp+8h] [bp-78h]
  unsigned int v40; // [sp+Ch] [bp-74h] BYREF
  int v41[2]; // [sp+10h] [bp-70h] BYREF
  _DWORD v42[4]; // [sp+18h] [bp-68h] BYREF
  int v43[8]; // [sp+28h] [bp-58h] BYREF
  char var38[60]; // [sp+48h] [bp-38h] BYREF

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( *(_DWORD *)(a1 + 532) || *(_DWORD *)(a1 + 736) || *(_DWORD *)(a1 + 740) )
  {
    if ( v2 )
      --*(_WORD *)(v2 + 310);
    v3 = *(_DWORD *)(a1 + 576);
    __dmb(0xBu);
    v39 = v3;
    __dmb(0xBu);
    v4 = ExAcquireResourceExclusiveLite(v3 + 32, 1);
    v5 = v39;
    __dmb(0xBu);
    v6 = *(_DWORD *)(a1 + 576);
    __dmb(0xBu);
    if ( v5 != v6 )
      return sub_515108(v4);
    v41[0] = v39;
    __dmb(0xBu);
    v8 = 0;
    v9 = v41;
    while ( 1 )
    {
      v10 = *v9++;
      if ( a1 == v10 )
        break;
      if ( ++v8 )
      {
        ExAcquireResourceExclusiveLite(a1 + 32, 1);
        break;
      }
    }
    if ( *(_DWORD *)(a1 + 532) )
      PspRemoveCpuRateControl(a1);
    v11 = *(_DWORD *)(a1 + 736);
    if ( v11 )
    {
      memset(v43, 0, sizeof(v43));
      v43[5] |= 4u;
      v43[0] = *(_DWORD *)(v11 + 36);
      PspNetRateControlDispatch(v43);
      PspRemoveRateControl(a1, 0);
    }
    if ( *(_DWORD *)(a1 + 740) )
    {
      IoDeleteFlow(a1 + 704);
      PspRemoveRateControl(a1, 1);
    }
    v12 = 0;
    v13 = v41;
    while ( 1 )
    {
      v14 = *v13++;
      if ( a1 == v14 )
        break;
      if ( ++v12 )
      {
        ExReleaseResourceLite(a1 + 32, v13);
        break;
      }
    }
    v15 = ExReleaseResourceLite(v39 + 32, v13);
    if ( v2 )
    {
      v16 = *(_WORD *)(v2 + 310) + 1;
      *(_WORD *)(v2 + 310) = v16;
      if ( !v16 && *(_DWORD *)(v2 + 100) != v2 + 100 )
        KiCheckForKernelApcDelivery(v15);
    }
  }
  v40 = *(_DWORD *)(a1 + 232);
  if ( v40 <= 0xFFFFFFFD )
  {
    v42[0] = a1;
    v42[1] = 2;
    v42[2] = 0;
    if ( v2 )
      --*(_WORD *)(v2 + 310);
    ExAcquireResourceExclusiveLite(a1 + 32, 1);
    PsInvokeWin32Callout(6, v42, 1, &v40);
    v18 = ExReleaseResourceLite(a1 + 32, v17);
    if ( v2 )
    {
      v19 = *(_WORD *)(v2 + 310) + 1;
      *(_WORD *)(v2 + 310) = v19;
      if ( !v19 && *(_DWORD *)(v2 + 100) != v2 + 100 )
        KiCheckForKernelApcDelivery(v18);
    }
  }
  v20 = *(_DWORD *)(a1 + 212);
  *(_DWORD *)(a1 + 176) = 0;
  if ( v20 )
  {
    ObfDereferenceObjectWithTag(v20, 1953261124);
    *(_DWORD *)(a1 + 212) = 0;
  }
  v21 = *(_DWORD *)(a1 + 196);
  if ( v21 )
  {
    SeReleaseSubjectContext(v21 + 4);
    ExFreePoolWithTag(*(_DWORD *)(a1 + 196), 1632269136);
    PsReturnSharedPoolQuota(*(_DWORD *)(a1 + 200), 20, 0);
  }
  --*(_WORD *)(v2 + 310);
  v22 = KeAbPreAcquire(&PspJobListLock, 0, 0);
  v23 = v22;
  do
    v24 = __ldrex((unsigned __int8 *)&PspJobListLock);
  while ( __strex(v24 | 1, (unsigned __int8 *)&PspJobListLock) );
  __dmb(0xBu);
  if ( (v24 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&PspJobListLock, v22, &PspJobListLock);
  if ( v23 )
    *(_BYTE *)(v23 + 14) |= 1u;
  v25 = *(_QWORD *)(a1 + 16);
  if ( *(_DWORD *)(v25 + 4) != a1 + 16 || *(_DWORD *)HIDWORD(v25) != a1 + 16 )
    __fastfail(3u);
  *(_DWORD *)HIDWORD(v25) = v25;
  *(_DWORD *)(v25 + 4) = HIDWORD(v25);
  __dmb(0xBu);
  do
    v26 = __ldrex((unsigned int *)&PspJobListLock);
  while ( __strex(v26 - 1, (unsigned int *)&PspJobListLock) );
  if ( (v26 & 2) != 0 && (v26 & 4) == 0 )
    ExfTryToWakePushLock(&PspJobListLock);
  v27 = KeAbPostRelease(&PspJobListLock);
  v28 = *(_WORD *)(v2 + 310) + 1;
  *(_WORD *)(v2 + 310) = v28;
  if ( !v28 && *(_DWORD *)(v2 + 100) != v2 + 100 )
    KiCheckForKernelApcDelivery(v27);
  PspEmptyPropertySet(a1 + 724);
  v29 = *(_DWORD *)(a1 + 520);
  if ( v29 )
  {
    ExFreePoolWithTag(v29, 1649046352);
    v37 = *(_DWORD *)(a1 + 524);
    *(_DWORD *)(a1 + 520) = 0;
    PsReturnSharedPoolQuota(v37, 136, 0);
  }
  if ( *(_DWORD *)(a1 + 528) )
    IoFreeMiniCompletionPacket();
  if ( (*(_DWORD *)(a1 + 744) & 0x800) != 0 )
    ZwDeleteWnfStateName();
  if ( (*(_DWORD *)(a1 + 744) & 0x40000) != 0 )
  {
    v30 = (unsigned int *)(a1 + 692);
    v31 = KfRaiseIrql(2);
    v40 = v31;
    if ( (dword_682604 & 0x210000) != 0 )
    {
      v31 = KiAcquireSpinLockInstrumented(a1 + 692);
    }
    else
    {
      do
        v32 = __ldrex(v30);
      while ( __strex(1u, v30) );
      __dmb(0xBu);
      if ( v32 )
        v31 = KxWaitForSpinLockAndAcquire(a1 + 692);
    }
    KeQueryInterruptTime(v31);
    v33 = (__int64 **)(a1 + 696);
    while ( *v33 != (__int64 *)v33 )
    {
      v38 = **v33;
      if ( (__int64 **)HIDWORD(v38) != v33 || *(__int64 **)(v38 + 4) != *v33 )
        __fastfail(3u);
      *v33 = (__int64 *)v38;
      *(_DWORD *)(v38 + 4) = v33;
      ExRemoveVirtualizedTimer();
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(a1 + 692);
    }
    else
    {
      __dmb(0xBu);
      *v30 = 0;
    }
    KfLowerIrql(v40);
  }
  PspGetJobLockHierarchyForDeletion(a1, var38);
  PspLockJobsAndProcessExclusive(var38, 0, v2);
  v34 = (__int64 *)(a1 + 556);
  if ( *(_DWORD *)(a1 + 556) != a1 + 556 )
  {
    v35 = *v34;
    if ( *(__int64 **)(*(_DWORD *)v34 + 4) != v34 || *(__int64 **)HIDWORD(v35) != v34 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v35) = v35;
    *(_DWORD *)(v35 + 4) = HIDWORD(v35);
    *(_DWORD *)v34 = v34;
    *(_DWORD *)(a1 + 560) = a1 + 556;
    ObDereferenceObjectDeferDeleteWithTag(*(_DWORD *)(a1 + 572), 1953261124);
    *(_DWORD *)(a1 + 572) = 0;
  }
  PspUnlockJobsAndProcessExclusive(var38, 0, v2);
  ExDeleteResourceLite(a1 + 32);
  if ( *(_DWORD *)(a1 + 588) )
  {
    v36 = *(_DWORD *)(a1 + 592);
    if ( v36 )
    {
      ExFreePoolWithTag(v36, 1649046352);
      *(_DWORD *)(a1 + 592) = 0;
    }
  }
  result = *(_DWORD *)(a1 + 720);
  if ( result )
  {
    result = ObDereferenceObjectDeferDeleteWithTag(result, 1953261124);
    *(_DWORD *)(a1 + 720) = 0;
  }
  return result;
}
