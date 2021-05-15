// CcIsWriteBehindThreadpoolAtLowPriority 
 
BOOL CcIsWriteBehindThreadpoolAtLowPriority()
{
  return CcMaxNumberOfWriteBehindThreads < (unsigned int)CcNumberWorkerThreads;
}
