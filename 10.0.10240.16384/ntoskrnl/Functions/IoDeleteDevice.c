// IoDeleteDevice 
 
int __fastcall IoDeleteDevice(_DWORD *a1)
{
  int result; // r0
  int v3; // r5
  int v4; // r8
  int v5; // r6
  int v6; // r0
  int v7; // r5
  int v8; // r10
  unsigned int v9; // r2
  int v10; // r10
  unsigned int v11; // r2
  __int64 v12; // r0
  unsigned __int8 v13; // r5
  unsigned int v14; // r1
  int v15; // r2
  int v16; // r3

  if ( (MmVerifierData & 0x90) != 0 )
    return sub_527BFC();
  if ( (a1[7] & 0x800) != 0 )
    IoUnregisterShutdownNotification(a1);
  v3 = a1[6];
  if ( v3 )
  {
    IopRemoveTimerFromTimerList(a1[6]);
    ExFreePoolWithTag(v3, 0);
  }
  if ( (a1[7] & 0x40) != 0 )
    ObMakeTemporaryObject(a1);
  v4 = a1[44];
  PoRegisterDeviceForIdleDetection(a1, 0, 0, 0);
  v5 = *(_DWORD *)(v4 + 12);
  if ( v5 )
  {
    MmLockPagableSectionByHandle(ExPageLockHandle);
    v7 = KeAbPreAcquire((unsigned int)&PopVolumeLock, 0, 0);
    v8 = KfRaiseIrql(1);
    do
      v9 = __ldrex((unsigned __int8 *)&PopVolumeLock);
    while ( __strex(v9 & 0xFE, (unsigned __int8 *)&PopVolumeLock) );
    __dmb(0xBu);
    if ( (v9 & 1) == 0 )
      ExpAcquireFastMutexContended((int)&PopVolumeLock, v7);
    if ( v7 )
      *(_BYTE *)(v7 + 14) |= 1u;
    dword_61EAE4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    dword_61EAFC = v8;
    v10 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented(&PopDopeGlobalLock);
    }
    else
    {
      do
        v11 = __ldrex((unsigned int *)&PopDopeGlobalLock);
      while ( __strex(1u, (unsigned int *)&PopDopeGlobalLock) );
      __dmb(0xBu);
      if ( v11 )
        KxWaitForSpinLockAndAcquire((unsigned int *)&PopDopeGlobalLock);
    }
    if ( *(_DWORD *)(v5 + 52) )
    {
      v12 = *(_QWORD *)(v5 + 52);
      if ( *(_DWORD *)(v12 + 4) != v5 + 52 || *(_DWORD *)HIDWORD(v12) != v5 + 52 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v12) = v12;
      *(_DWORD *)(v12 + 4) = HIDWORD(v12);
      *(_DWORD *)(v5 + 52) = 0;
      *(_DWORD *)(v5 + 56) = 0;
    }
    *(_DWORD *)(v4 + 12) = 0;
    ExFreePoolWithTag(v5, 0);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(&PopDopeGlobalLock);
    }
    else
    {
      __dmb(0xBu);
      PopDopeGlobalLock = 0;
    }
    KfLowerIrql(v10);
    dword_61EAE4 = 0;
    v13 = dword_61EAFC;
    __dmb(0xBu);
    do
      v14 = __ldrex(&PopVolumeLock);
    while ( !v14 && __strex(1u, &PopVolumeLock) );
    if ( v14 )
      ExpReleaseFastMutexContended(&PopVolumeLock, v14);
    KfLowerIrql(v13);
    KeAbPostRelease((unsigned int)&PopVolumeLock);
    MiLockPagableImageSection(ExPageLockHandle, 0, v15, v16);
  }
  PnpFreeInterruptInformation(a1);
  v6 = KeAcquireQueuedSpinLock(10);
  *(_DWORD *)(a1[44] + 16) |= 2u;
  if ( a1[1] )
    result = KeReleaseQueuedSpinLock(10, v6);
  else
    result = IopCompleteUnloadOrDelete(a1, 0, v6);
  return result;
}
