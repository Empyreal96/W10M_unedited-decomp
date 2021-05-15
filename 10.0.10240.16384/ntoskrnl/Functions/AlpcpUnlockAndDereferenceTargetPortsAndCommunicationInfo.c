// AlpcpUnlockAndDereferenceTargetPortsAndCommunicationInfo 
 
int __fastcall AlpcpUnlockAndDereferenceTargetPortsAndCommunicationInfo(int a1, int a2, int a3)
{
  unsigned int *v5; // r5
  unsigned int v6; // r4
  unsigned int *v8; // r5
  unsigned int v9; // r4
  unsigned int *v10; // r4
  unsigned int v11; // r2

  v5 = (unsigned int *)(a1 - 4);
  __dmb(0xBu);
  do
    v6 = __ldrex(v5);
  while ( v6 == 17 && __strex(0, v5) );
  if ( v6 != 17 )
    return sub_7E96E4();
  KeAbPostRelease(a1 - 4);
  v8 = (unsigned int *)(a2 + 208);
  __dmb(0xBu);
  do
    v9 = __ldrex(v8);
  while ( v9 == 17 && __strex(0, v8) );
  if ( v9 != 17 )
    ExfReleasePushLockShared((_DWORD *)(a2 + 208));
  KeAbPostRelease(a2 + 208);
  if ( a3 != a2 )
  {
    v10 = (unsigned int *)(a3 + 208);
    __dmb(0xBu);
    do
      v11 = __ldrex(v10);
    while ( v11 == 17 && __strex(0, v10) );
    if ( v11 != 17 )
      ExfReleasePushLockShared((_DWORD *)(a3 + 208));
    KeAbPostRelease(a3 + 208);
  }
  ObfDereferenceObject(a2);
  return ObfDereferenceObject(a3);
}
