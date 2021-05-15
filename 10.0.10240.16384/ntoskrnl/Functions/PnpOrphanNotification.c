// PnpOrphanNotification 
 
unsigned int __fastcall PnpOrphanNotification(int a1)
{
  __int64 v1; // r4
  int v2; // r7
  unsigned int v3; // r2
  __int64 v4; // r2
  int v5; // r0
  unsigned __int8 v6; // r4
  unsigned int v7; // r1

  HIDWORD(v1) = a1;
  LODWORD(v1) = KeAbPreAcquire((unsigned int)&PnpTargetDeviceNotifyLock, 0, 0);
  v2 = KfRaiseIrql(1);
  do
    v3 = __ldrex((unsigned __int8 *)&PnpTargetDeviceNotifyLock);
  while ( __strex(v3 & 0xFE, (unsigned __int8 *)&PnpTargetDeviceNotifyLock) );
  __dmb(0xBu);
  if ( (v3 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&PnpTargetDeviceNotifyLock, v1);
  if ( (_DWORD)v1 )
    *(_BYTE *)(v1 + 14) |= 1u;
  dword_630D24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_630D3C = v2;
  HIDWORD(v1) += 320;
  while ( *(_DWORD *)HIDWORD(v1) != HIDWORD(v1) )
  {
    LODWORD(v1) = *(_DWORD *)HIDWORD(v1);
    v4 = *(_QWORD *)*(_DWORD *)HIDWORD(v1);
    if ( __PAIR64__(HIDWORD(v4), *(_DWORD *)(v4 + 4)) != v1 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v1) = v4;
    *(_DWORD *)(v4 + 4) = HIDWORD(v1);
    v5 = *(_DWORD *)(v1 + 48);
    *(_DWORD *)v1 = v1;
    *(_DWORD *)(v1 + 4) = v1;
    if ( v5 )
    {
      ObfDereferenceObject(v5);
      *(_DWORD *)(v1 + 48) = 0;
    }
  }
  dword_630D24 = 0;
  v6 = dword_630D3C;
  __dmb(0xBu);
  do
    v7 = __ldrex((unsigned int *)&PnpTargetDeviceNotifyLock);
  while ( !v7 && __strex(1u, (unsigned int *)&PnpTargetDeviceNotifyLock) );
  if ( v7 )
    ExpReleaseFastMutexContended((unsigned int *)&PnpTargetDeviceNotifyLock, v7);
  KfLowerIrql(v6);
  return KeAbPostRelease((unsigned int)&PnpTargetDeviceNotifyLock);
}
