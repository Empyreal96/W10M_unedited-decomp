// PnpMapDeviceObjectToDeviceInstance 
 
int __fastcall PnpMapDeviceObjectToDeviceInstance(int a1, int a2, int a3, int a4)
{
  int v4; // r5
  int v5; // r6
  unsigned int v6; // r2
  int v8; // r5
  unsigned __int8 v9; // r6
  unsigned int v10; // r1
  _DWORD v11[6]; // [sp+0h] [bp-18h] BYREF

  v11[2] = a4;
  v11[0] = a1;
  v11[1] = a2;
  v4 = KeAbPreAcquire((unsigned int)&PnpDeviceReferenceTableLock, 0, 0);
  v5 = KfRaiseIrql(1);
  do
    v6 = __ldrex((unsigned __int8 *)&PnpDeviceReferenceTableLock);
  while ( __strex(v6 & 0xFE, (unsigned __int8 *)&PnpDeviceReferenceTableLock) );
  __dmb(0xBu);
  if ( (v6 & 1) == 0 )
    return sub_7C95E4();
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  dword_630C24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_630C3C = v5;
  if ( RtlInsertElementGenericTableAvl((int)&PnpDeviceReferenceTable, (int)v11, 8, 0) )
    v8 = 0;
  else
    v8 = -1073741823;
  dword_630C24 = 0;
  v9 = dword_630C3C;
  __dmb(0xBu);
  do
    v10 = __ldrex((unsigned int *)&PnpDeviceReferenceTableLock);
  while ( !v10 && __strex(1u, (unsigned int *)&PnpDeviceReferenceTableLock) );
  if ( v10 )
    ExpReleaseFastMutexContended((unsigned int *)&PnpDeviceReferenceTableLock, v10);
  KfLowerIrql(v9);
  KeAbPostRelease((unsigned int)&PnpDeviceReferenceTableLock);
  return v8;
}
