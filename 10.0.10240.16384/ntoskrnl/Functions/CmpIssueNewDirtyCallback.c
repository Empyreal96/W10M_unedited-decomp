// CmpIssueNewDirtyCallback 
 
int CmpIssueNewDirtyCallback()
{
  char v0; // r3
  int result; // r0

  v0 = CmpHoldLazyFlush;
  __dmb(0xBu);
  if ( (v0 & 8) != 0 )
  {
    if ( CmpCoalescingCallbackActive )
      result = PoIssueCoalescingNotification(CmpCoalescingRegistration, 0);
  }
  return result;
}
