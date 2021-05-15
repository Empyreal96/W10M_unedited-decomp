// CmpDelayDerefKCBWorker 
 
int CmpDelayDerefKCBWorker()
{
  unsigned int v0; // r2

  CmpLockRegistry();
  KeAbPreAcquire((unsigned int)CmpDelayDerefKCBLock, 0, 0);
  KfRaiseIrql(1);
  do
    v0 = __ldrex(CmpDelayDerefKCBLock);
  while ( __strex(v0 & 0xFE, CmpDelayDerefKCBLock) );
  __dmb(0xBu);
  if ( (v0 & 1) != 0 )
    JUMPOUT(0x804FCA);
  return sub_804FC0();
}
