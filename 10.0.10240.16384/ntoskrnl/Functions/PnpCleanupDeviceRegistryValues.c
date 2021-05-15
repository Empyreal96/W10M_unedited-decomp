// PnpCleanupDeviceRegistryValues 
 
int __fastcall PnpCleanupDeviceRegistryValues(int a1)
{
  int v2; // r4
  int v3; // r7
  int v4; // r2
  unsigned __int8 v6; // r4
  unsigned int v7; // r1
  _DWORD v8[6]; // [sp+0h] [bp-18h] BYREF

  v8[0] = 0;
  v8[1] = a1;
  v2 = KeAbPreAcquire((unsigned int)&PnpDeviceReferenceTableLock, 0, 0);
  v3 = KfRaiseIrql(1);
  do
    v4 = __ldrex((unsigned __int8 *)&PnpDeviceReferenceTableLock);
  while ( __strex(v4 & 0xFE, (unsigned __int8 *)&PnpDeviceReferenceTableLock) );
  __dmb(0xBu);
  if ( (v4 & 1) == 0 )
    return sub_7EF438();
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  dword_630C24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_630C3C = v3;
  RtlDeleteElementGenericTableAvl((int)&PnpDeviceReferenceTable, (int)v8, v4, dword_630C24);
  dword_630C24 = 0;
  v6 = dword_630C3C;
  __dmb(0xBu);
  do
    v7 = __ldrex((unsigned int *)&PnpDeviceReferenceTableLock);
  while ( !v7 && __strex(1u, (unsigned int *)&PnpDeviceReferenceTableLock) );
  if ( v7 )
    ExpReleaseFastMutexContended((unsigned int *)&PnpDeviceReferenceTableLock, v7);
  KfLowerIrql(v6);
  KeAbPostRelease((unsigned int)&PnpDeviceReferenceTableLock);
  return PpDeviceRegistration(a1, 0, 0, 1);
}
