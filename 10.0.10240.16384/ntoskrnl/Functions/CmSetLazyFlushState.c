// CmSetLazyFlushState 
 
int __fastcall CmSetLazyFlushState(int a1)
{
  char v1; // r3

  if ( a1 )
  {
    CmpDontGrowLogFile = 0;
    CmpDoIdleProcessing = CmpPrevIdleProcessingState;
    if ( CmpEnableLazyFlushTimerInitialized )
    {
      CmpDisableLazyFlush(1);
      KiSetTimerEx((int)CmpEnableLazyFlushTimer, 0, -900000000i64, 0, 0, (int)&CmpEnableLazyFlushDpc);
    }
    CmpEnableLazyFlush(4);
  }
  else
  {
    CmpDontGrowLogFile = 1;
    CmpDisableLazyFlush(4);
    if ( CmpEnableLazyFlushTimerInitialized )
    {
      v1 = CmpHoldLazyFlush;
      __dmb(0xBu);
      if ( (v1 & 1) != 0 )
      {
        if ( KeCancelTimer((int)CmpEnableLazyFlushTimer) )
          CmpEnableLazyFlush(1);
      }
    }
    CmpPrevIdleProcessingState = CmpDoIdleProcessing;
    CmpDoIdleProcessing = 0;
  }
  return a1;
}
