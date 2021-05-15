// PspStartMonitorDeferred 
 
int __fastcall PspStartMonitorDeferred(int a1)
{
  int v1; // r0
  unsigned int v2; // r2

  (*(void (__fastcall **)(_DWORD))(a1 + 32))(0);
  KeAbPreAcquire((unsigned int)&PspSiloListLock, 0, 0);
  v1 = KfRaiseIrql(1);
  do
    v2 = __ldrex((unsigned __int8 *)&PspSiloListLock);
  while ( __strex(v2 & 0xFE, (unsigned __int8 *)&PspSiloListLock) );
  __dmb(0xBu);
  if ( (v2 & 1) != 0 )
    JUMPOUT(0x8109D6);
  return sub_8109CC(v1);
}
