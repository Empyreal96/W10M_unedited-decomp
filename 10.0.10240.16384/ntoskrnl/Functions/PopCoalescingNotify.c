// PopCoalescingNotify 
 
int PopCoalescingNotify()
{
  __int64 v0; // r0

  PopAcquirePolicyLock();
  if ( PopCoalescingState )
  {
    KeCancelTimer((int)&PopCoalescingTimer);
    PopPrintEx(3);
    PopDiagTraceEventNoPayload((int)POP_ETW_IO_COALESCING_FLUSH);
    PoIssueCoalescingNotification(PopCoalescingRegistration, 3);
    LODWORD(v0) = KeQueryInterruptTime();
    PopCoalescingLastFlushTime = v0;
    PopCoalescingSetTimer();
  }
  PopReleasePolicyLock();
  if ( *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x134) )
    __fastfail(0x20u);
  return 0;
}
