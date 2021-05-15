// CcAdjustWriteBehindThreadPool 
 
int __fastcall CcAdjustWriteBehindThreadPool(int result)
{
  if ( result )
  {
    CcMaxNumberOfWriteBehindThreads = 1;
    if ( CcAddExtraWriteBehindThreads )
      result = sub_53D220();
  }
  else
  {
    CcMaxNumberOfWriteBehindThreads = -1;
    if ( (int *)CcRegularWorkQueue != &CcRegularWorkQueue && !CcQueueThrottle )
      result = CcReEngageWorkerThreads(CcNumberWorkerThreads, 0);
  }
  return result;
}
