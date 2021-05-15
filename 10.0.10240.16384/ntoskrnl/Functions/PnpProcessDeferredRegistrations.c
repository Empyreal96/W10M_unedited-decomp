// PnpProcessDeferredRegistrations 
 
int PnpProcessDeferredRegistrations()
{
  int v0; // r0
  unsigned int v1; // r2

  KeAbPreAcquire((unsigned int)&PnpDeferredRegistrationLock, 0, 0);
  v0 = KfRaiseIrql(1);
  do
    v1 = __ldrex((unsigned __int8 *)&PnpDeferredRegistrationLock);
  while ( __strex(v1 & 0xFE, (unsigned __int8 *)&PnpDeferredRegistrationLock) );
  __dmb(0xBu);
  if ( (v1 & 1) != 0 )
    JUMPOUT(0x7C92B4);
  return sub_7C92AC(v0);
}
