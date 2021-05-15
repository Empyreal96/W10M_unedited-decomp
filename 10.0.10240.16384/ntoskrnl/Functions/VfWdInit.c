// VfWdInit 
 
int VfWdInit()
{
  int result; // r0
  unsigned int v1; // r2

  if ( !VfSafeMode )
  {
    dword_908F14 = (int)&VfWdIrpListHead;
    VfWdIrpListHead = (int)&VfWdIrpListHead;
    VfWdIrpListLock = 0;
    pXdvExInitializeNPagedLookasideList(
      &ViWdIrpLookasideList,
      0,
      VfUtilFreePoolDispatchLevel,
      512,
      20,
      1683449430,
      16,
      VfInitializedWithoutReboot,
      ExInitializeNPagedLookasideListInternal);
    KeInitializeTimerEx(ViWdIrpTimer, 0);
    KeInitializeDpc((int)&ViWdIrpTimerDpc, (int)ViWdIrpTimerDpcRoutine, 0);
    result = VfWdSetCancelTimeout(VfWdIrpTimeoutMsec);
    __dmb(0xBu);
    do
      v1 = __ldrex((unsigned int *)&ViWdInitialized);
    while ( __strex(1u, (unsigned int *)&ViWdInitialized) );
    __dmb(0xBu);
  }
  return result;
}
