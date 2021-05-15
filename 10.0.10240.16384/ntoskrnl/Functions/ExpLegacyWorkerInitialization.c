// ExpLegacyWorkerInitialization 
 
int ExpLegacyWorkerInitialization()
{
  int result; // r0
  int v1; // r1
  int v2; // r2
  _DWORD *v3; // r2

  if ( (unsigned int)ExpAdditionalCriticalWorkerThreads > 0x64 )
    return sub_50B368();
  v1 = ExpAdditionalDelayedWorkerThreads;
  if ( (unsigned int)ExpAdditionalDelayedWorkerThreads > 0x64 )
  {
    v1 = 100;
    ExpAdditionalDelayedWorkerThreads = 100;
  }
  result = 5;
  if ( (_BYTE)dword_681280 )
    result = 10;
  ExCriticalWorkerThreads = result + ExpAdditionalCriticalWorkerThreads;
  ExDelayedWorkerThreads = v1 + 7;
  v3 = KeNodeBlock;
  if ( KeNodeBlock == &KiNodeInit )
    v3 = 0;
  v2 = v3[96];
  if ( (v2 & 1) != 0 )
    v2 = 0;
  ExWorkerQueue = v2;
  return result;
}
