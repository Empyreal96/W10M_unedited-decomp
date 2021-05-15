// sub_522504 
 
void sub_522504()
{
  if ( (unsigned int)CcNumberActiveWorkerThreads > 1 || (unsigned int)CcActiveExtraWriteBehindThreads > 1 )
  {
    if ( !CcQueueThrottle )
    {
      CcThreadsActiveBeforeThrottle = CcNumberActiveWorkerThreads;
      CcExtraWBThreadsActiveBeforeThrottle = CcActiveExtraWriteBehindThreads;
    }
    CcQueueThrottle = 1;
    JUMPOUT(0x456E28);
  }
  JUMPOUT(0x456E00);
}
