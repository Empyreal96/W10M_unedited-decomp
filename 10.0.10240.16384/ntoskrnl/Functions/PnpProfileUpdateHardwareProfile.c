// PnpProfileUpdateHardwareProfile 
 
int __fastcall PnpProfileUpdateHardwareProfile(int a1)
{
  int v2; // r5
  int v3; // r6
  unsigned int v4; // r2
  int v5; // r3
  int v6; // r0
  unsigned int v7; // r6
  int *v8; // r5
  int *i; // r3
  int v10; // r1
  unsigned __int8 v11; // r7
  unsigned int v12; // r1
  unsigned int v13; // r0
  int v14; // r4
  unsigned __int8 v15; // r5
  unsigned int v16; // r1
  int v18; // [sp+4h] [bp-4Ch]
  int v19; // [sp+8h] [bp-48h]
  int v20; // [sp+10h] [bp-40h] BYREF
  __int16 v21; // [sp+18h] [bp-38h] BYREF
  __int16 v22; // [sp+1Ah] [bp-36h]
  const __int16 *v23; // [sp+1Ch] [bp-34h]
  int v24; // [sp+20h] [bp-30h]
  int v25; // [sp+24h] [bp-2Ch]
  __int16 *v26; // [sp+28h] [bp-28h]
  int v27; // [sp+2Ch] [bp-24h]
  int v28; // [sp+30h] [bp-20h]
  int v29; // [sp+34h] [bp-1Ch]

  v20 = 0;
  v2 = KeAbPreAcquire((unsigned int)&PiProfileDeviceListLock, 0, 0);
  v3 = KfRaiseIrql(1);
  do
    v4 = __ldrex((unsigned __int8 *)&PiProfileDeviceListLock);
  while ( __strex(v4 & 0xFE, (unsigned __int8 *)&PiProfileDeviceListLock) );
  __dmb(0xBu);
  if ( (v4 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&PiProfileDeviceListLock, v2);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  dword_62FB44 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v22 = 124;
  v21 = 122;
  dword_62FB5C = v3;
  v23 = L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\IDConfigDB";
  v24 = 24;
  v25 = 0;
  v26 = &v21;
  v27 = 576;
  v28 = 0;
  v29 = 0;
  if ( ZwOpenKey() >= 0 )
  {
    v22 = 32;
    v21 = 30;
    v23 = L"CurrentDockInfo";
    v19 = 0;
    v24 = 24;
    v27 = 576;
    v25 = 0;
    v26 = &v21;
    v28 = 0;
    v29 = 0;
    if ( ZwOpenKey() >= 0 )
    {
      v22 = 30;
      v21 = 28;
      v23 = L"EjectableDocks";
      v18 = 4;
      ZwSetValueKey();
      ZwClose();
    }
    ZwClose();
  }
  v5 = PiProfileDeviceCount;
  if ( !PiProfileDeviceCount )
    v5 = 1;
  v6 = ExAllocatePoolWithTag(512, 4 * (v5 + 1), 538996816);
  v7 = v6;
  if ( v6 )
  {
    v8 = (int *)v6;
    for ( i = (int *)PiProfileDeviceListHead; i != &PiProfileDeviceListHead; i = (int *)*i )
    {
      v10 = i[2];
      if ( v10 )
        *v8++ = v10;
    }
    dword_62FB44 = 0;
    v11 = dword_62FB5C;
    __dmb(0xBu);
    do
      v12 = __ldrex((unsigned int *)&PiProfileDeviceListLock);
    while ( !v12 && __strex(1u, (unsigned int *)&PiProfileDeviceListLock) );
    if ( v12 )
      ExpReleaseFastMutexContended((unsigned int *)&PiProfileDeviceListLock, v12);
    KfLowerIrql(v11);
    v13 = KeAbPostRelease((unsigned int)&PiProfileDeviceListLock);
    if ( v8 == (int *)v7 )
      *v8++ = 0;
    *v8 = 0;
    v14 = IopExecuteHardwareProfileChange(v13, v7, (int)((int)v8 - v7) >> 2, &v20, a1, v18, v19);
    if ( v20 )
      ZwClose();
    ExFreePoolWithTag(v7);
  }
  else
  {
    dword_62FB44 = 0;
    v15 = dword_62FB5C;
    __dmb(0xBu);
    do
      v16 = __ldrex((unsigned int *)&PiProfileDeviceListLock);
    while ( !v16 && __strex(1u, (unsigned int *)&PiProfileDeviceListLock) );
    if ( v16 )
      ExpReleaseFastMutexContended((unsigned int *)&PiProfileDeviceListLock, v16);
    KfLowerIrql(v15);
    KeAbPostRelease((unsigned int)&PiProfileDeviceListLock);
    v14 = -1073741670;
  }
  return v14;
}
