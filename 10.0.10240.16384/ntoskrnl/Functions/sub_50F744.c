// sub_50F744 
 
void __fastcall sub_50F744(int a1)
{
  if ( a1 == 3 )
  {
    KeAcquireQueuedSpinLock(5);
    ++CcDbgCoalescingCmdFlushReceived;
    CcScheduleLazyWriteScan(1, 0);
    JUMPOUT(0x42546A);
  }
  JUMPOUT(0x425472);
}
