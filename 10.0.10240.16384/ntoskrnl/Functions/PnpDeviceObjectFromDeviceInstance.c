// PnpDeviceObjectFromDeviceInstance 
 
int __fastcall PnpDeviceObjectFromDeviceInstance(int a1)
{
  int v1; // r4
  int v2; // r6
  int v3; // r7
  unsigned int v4; // r2
  int *v5; // r0
  int v6; // r3
  unsigned __int8 v7; // r6
  unsigned int v8; // r1
  _DWORD v10[6]; // [sp+0h] [bp-18h] BYREF

  v10[0] = 0;
  v10[1] = a1;
  v1 = 0;
  v2 = KeAbPreAcquire((unsigned int)&PnpDeviceReferenceTableLock, 0, 0);
  v3 = KfRaiseIrql(1);
  do
    v4 = __ldrex((unsigned __int8 *)&PnpDeviceReferenceTableLock);
  while ( __strex(v4 & 0xFE, (unsigned __int8 *)&PnpDeviceReferenceTableLock) );
  __dmb(0xBu);
  if ( (v4 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&PnpDeviceReferenceTableLock, v2);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  dword_630C24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_630C3C = v3;
  v5 = (int *)RtlLookupElementGenericTableAvl((int)&PnpDeviceReferenceTable, (int)v10);
  if ( v5 )
  {
    v1 = *v5;
    if ( *v5 )
    {
      if ( *(_WORD *)v1 == 3 )
      {
        v6 = *(_DWORD *)(*(_DWORD *)(v1 + 176) + 20);
        if ( !v6 || *(_DWORD *)(v6 + 16) != v1 )
          v1 = 0;
        if ( v1 )
          ObfReferenceObject(v1);
      }
      else
      {
        v1 = 0;
      }
    }
  }
  dword_630C24 = 0;
  v7 = dword_630C3C;
  __dmb(0xBu);
  do
    v8 = __ldrex((unsigned int *)&PnpDeviceReferenceTableLock);
  while ( !v8 && __strex(1u, (unsigned int *)&PnpDeviceReferenceTableLock) );
  if ( v8 )
    ExpReleaseFastMutexContended((unsigned int *)&PnpDeviceReferenceTableLock, v8);
  KfLowerIrql(v7);
  KeAbPostRelease((unsigned int)&PnpDeviceReferenceTableLock);
  return v1;
}
