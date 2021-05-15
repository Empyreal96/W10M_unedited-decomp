// CmpCancelBootDisabledFlush 
 
void CmpCancelBootDisabledFlush()
{
  char v0; // r3

  if ( CmpEnableLazyFlushTimerInitialized )
  {
    v0 = CmpHoldLazyFlush;
    __dmb(0xBu);
    if ( (v0 & 1) != 0 )
    {
      if ( KeCancelTimer((int)&CmpEnableLazyFlushTimer) )
        CmpEnableLazyFlush(1);
    }
  }
}
