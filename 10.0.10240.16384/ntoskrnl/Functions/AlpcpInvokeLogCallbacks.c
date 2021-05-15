// AlpcpInvokeLogCallbacks 
 
unsigned int __fastcall AlpcpInvokeLogCallbacks(int a1, int a2)
{
  int v4; // r0
  int v5; // r5
  unsigned int v6; // r2
  void **i; // r5
  unsigned int v8; // r2

  v4 = KeAbPreAcquire((unsigned int)&AlpcpLogLock, 0, 0);
  v5 = v4;
  do
    v6 = __ldrex(&AlpcpLogLock);
  while ( !v6 && __strex(0x11u, &AlpcpLogLock) );
  __dmb(0xBu);
  if ( v6 )
    ExfAcquirePushLockSharedEx(&AlpcpLogLock, v4, (unsigned int)&AlpcpLogLock);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  for ( i = (void **)AlpcpLogCallbackListHead; i != &AlpcpLogCallbackListHead; i = (void **)*i )
    ((void (__fastcall *)(int, int))i[2])(a1, a2);
  __dmb(0xBu);
  do
    v8 = __ldrex(&AlpcpLogLock);
  while ( v8 == 17 && __strex(0, &AlpcpLogLock) );
  if ( v8 != 17 )
    ExfReleasePushLockShared(&AlpcpLogLock);
  return KeAbPostRelease((unsigned int)&AlpcpLogLock);
}
