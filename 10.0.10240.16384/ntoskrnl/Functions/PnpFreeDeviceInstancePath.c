// PnpFreeDeviceInstancePath 
 
unsigned int __fastcall PnpFreeDeviceInstancePath(int a1)
{
  int v2; // r5
  int v3; // r0
  unsigned int v4; // r2
  unsigned int v6; // r0
  unsigned __int8 v7; // r5
  unsigned int v8; // r1

  v2 = KeAbPreAcquire((unsigned int)&PnpDeviceReferenceTableLock, 0, 0);
  v3 = KfRaiseIrql(1);
  do
    v4 = __ldrex((unsigned __int8 *)&PnpDeviceReferenceTableLock);
  while ( __strex(v4 & 0xFE, (unsigned __int8 *)&PnpDeviceReferenceTableLock) );
  __dmb(0xBu);
  if ( (v4 & 1) == 0 )
    return sub_7EF414(v3);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  dword_630C24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_630C3C = v3;
  v6 = *(_DWORD *)(a1 + 24);
  if ( v6 )
    ExFreePoolWithTag(v6);
  *(_WORD *)(a1 + 22) = 0;
  *(_WORD *)(a1 + 20) = 0;
  *(_DWORD *)(a1 + 24) = 0;
  dword_630C24 = 0;
  v7 = dword_630C3C;
  __dmb(0xBu);
  do
    v8 = __ldrex((unsigned int *)&PnpDeviceReferenceTableLock);
  while ( !v8 && __strex(1u, (unsigned int *)&PnpDeviceReferenceTableLock) );
  if ( v8 )
    ExpReleaseFastMutexContended((unsigned int *)&PnpDeviceReferenceTableLock, v8);
  KfLowerIrql(v7);
  return KeAbPostRelease((unsigned int)&PnpDeviceReferenceTableLock);
}
