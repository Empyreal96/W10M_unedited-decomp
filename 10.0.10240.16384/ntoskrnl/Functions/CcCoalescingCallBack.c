// CcCoalescingCallBack 
 
int __fastcall CcCoalescingCallBack(int a1)
{
  int v1; // r4

  if ( a1 == 1 )
  {
    v1 = KeAcquireQueuedSpinLock(5);
    ++CcDbgCoalescingCmdOnReceived;
    CcCoalescingState = 1;
    byte_632770 = 0;
    if ( (unsigned int)CcGlobalDirtyPageStatistics >= 0x2000 )
      JUMPOUT(0x50F75A);
    return KeReleaseQueuedSpinLock(5, v1);
  }
  if ( a1 == 2 )
  {
    v1 = KeAcquireQueuedSpinLock(5);
    ++CcDbgCoalescingCmdOffReceived;
    CcCoalescingState = 0;
    CcRescheduleLazyWriteScan(0);
    return KeReleaseQueuedSpinLock(5, v1);
  }
  return sub_50F744();
}
