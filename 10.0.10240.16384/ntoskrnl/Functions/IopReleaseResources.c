// IopReleaseResources 
 
int IopReleaseResources()
{
  int v0; // r0
  unsigned int v1; // r2

  PnpReleaseResourcesInternal();
  KeAbPreAcquire((unsigned int)&PiResourceListLock, 0, 0);
  v0 = KfRaiseIrql(1);
  do
    v1 = __ldrex((unsigned __int8 *)&PiResourceListLock);
  while ( __strex(v1 & 0xFE, (unsigned __int8 *)&PiResourceListLock) );
  __dmb(0xBu);
  if ( (v1 & 1) != 0 )
    JUMPOUT(0x80D300);
  return sub_80D2F8(v0);
}
