// PiUEventNotifyDeviceInterfaceChange 
 
int __fastcall PiUEventNotifyDeviceInterfaceChange(int a1)
{
  int v2; // r9
  int v3; // r5
  int v4; // r6
  unsigned int v5; // r2
  unsigned int v6; // r6
  int *v7; // r10
  _DWORD *v8; // r8
  _DWORD **v9; // t1
  _DWORD *v10; // r5
  int v11; // r9
  unsigned __int8 v12; // r5
  unsigned int v13; // r1
  unsigned int v15; // r2
  int v16; // r3
  int v17; // [sp+0h] [bp-30h]
  int v18; // [sp+8h] [bp-28h] BYREF
  void *v19; // [sp+Ch] [bp-24h]

  v2 = 0;
  v17 = 0;
  v18 = 0;
  v19 = 0;
  if ( !memcmp(a1 + 44, (unsigned int)&GUID_DEVICE_INTERFACE_ARRIVAL, 16)
    || !memcmp(a1 + 44, (unsigned int)&GUID_DEVICE_INTERFACE_REMOVAL, 16) )
  {
    v3 = KeAbPreAcquire((unsigned int)&PiUEventClientRegistrationListLock, 0, 0);
    v4 = KfRaiseIrql(1);
    do
      v5 = __ldrex((unsigned __int8 *)&PiUEventClientRegistrationListLock);
    while ( __strex(v5 & 0xFE, (unsigned __int8 *)&PiUEventClientRegistrationListLock) );
    __dmb(0xBu);
    if ( (v5 & 1) == 0 )
      ExpAcquireFastMutexContended((int)&PiUEventClientRegistrationListLock, v3);
    if ( v3 )
      *(_BYTE *)(v3 + 14) |= 1u;
    dword_6308E4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    dword_6308FC = v4;
    v6 = 0;
    v7 = &v18;
    v18 = (int)&PiUEventDevInterfaceClientList + 8 * PiUEventHashGuidIntoBucket((unsigned __int8 *)(a1 + 80));
    v19 = &unk_630968;
    do
    {
      v9 = (_DWORD **)*v7++;
      v8 = v9;
      v10 = *v9;
      while ( v10 != v8 )
      {
        v11 = (int)v10;
        v10 = (_DWORD *)*v10;
        if ( (v6 || !memcmp(a1 + 80, v11 + 12, 16)) && PiUEventApplyAdditionalFilters((_DWORD *)a1, v11) )
        {
          v2 = PiUEventNotifyClient(a1, v11, v15, v16);
          v17 = v2;
        }
        else
        {
          v2 = v17;
        }
      }
      ++v6;
    }
    while ( v6 < 2 );
    dword_6308E4 = 0;
    v12 = dword_6308FC;
    __dmb(0xBu);
    do
      v13 = __ldrex((unsigned int *)&PiUEventClientRegistrationListLock);
    while ( !v13 && __strex(1u, (unsigned int *)&PiUEventClientRegistrationListLock) );
    if ( v13 )
      ExpReleaseFastMutexContended((unsigned int *)&PiUEventClientRegistrationListLock, v13);
    KfLowerIrql(v12);
    KeAbPostRelease((unsigned int)&PiUEventClientRegistrationListLock);
  }
  return v2;
}
