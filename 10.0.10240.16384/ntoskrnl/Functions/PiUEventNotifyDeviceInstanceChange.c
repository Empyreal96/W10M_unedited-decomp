// PiUEventNotifyDeviceInstanceChange 
 
int __fastcall PiUEventNotifyDeviceInstanceChange(_DWORD *a1)
{
  int v1; // r3
  int v2; // r9
  int v4; // r5
  int v5; // r1
  int v6; // r6
  int v7; // r2
  unsigned int v8; // r6
  int *v9; // r10
  _DWORD *v10; // r7
  _DWORD **v11; // t1
  _DWORD *v12; // r5
  int v13; // r9
  unsigned int v14; // r2
  int v15; // r3
  unsigned __int8 v16; // r5
  unsigned int v17; // r1
  int v19; // [sp+0h] [bp-30h]
  int v20; // [sp+8h] [bp-28h] BYREF
  void *v21; // [sp+Ch] [bp-24h]

  v20 = 0;
  v21 = 0;
  v1 = a1[15];
  v2 = 0;
  v19 = 0;
  if ( v1 == 4 || v1 == 10 || v1 == 11 )
  {
    v4 = KeAbPreAcquire((unsigned int)&PiUEventClientRegistrationListLock, 0, 0);
    v6 = KfRaiseIrql(1);
    do
      v7 = __ldrex((unsigned __int8 *)&PiUEventClientRegistrationListLock);
    while ( __strex(v7 & 0xFE, (unsigned __int8 *)&PiUEventClientRegistrationListLock) );
    __dmb(0xBu);
    if ( (v7 & 1) == 0 )
      ExpAcquireFastMutexContended((int)&PiUEventClientRegistrationListLock, v4);
    if ( v4 )
      *(_BYTE *)(v4 + 14) |= 1u;
    dword_6308E4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    dword_6308FC = v6;
    v8 = 0;
    v9 = &v20;
    v20 = (int)&PiUEventDevInstanceClientList + 8 * PiUEventHashStringIntoBucket((int)(a1 + 20), v5, v7, dword_6308E4);
    v21 = &unk_6309E8;
    do
    {
      v11 = (_DWORD **)*v9++;
      v10 = v11;
      v12 = *v11;
      while ( v12 != v10 )
      {
        v13 = (int)v12;
        v12 = (_DWORD *)*v12;
        if ( (v8 || !wcsicmp((int)(a1 + 20), *(unsigned __int16 **)(*(_DWORD *)(v13 + 12) + 12)))
          && PiUEventApplyAdditionalFilters(a1, v13) )
        {
          v2 = PiUEventNotifyClient((int)a1, v13, v14, v15);
          v19 = v2;
        }
        else
        {
          v2 = v19;
        }
      }
      ++v8;
    }
    while ( v8 < 2 );
    dword_6308E4 = 0;
    v16 = dword_6308FC;
    __dmb(0xBu);
    do
      v17 = __ldrex((unsigned int *)&PiUEventClientRegistrationListLock);
    while ( !v17 && __strex(1u, (unsigned int *)&PiUEventClientRegistrationListLock) );
    if ( v17 )
      ExpReleaseFastMutexContended((unsigned int *)&PiUEventClientRegistrationListLock, v17);
    KfLowerIrql(v16);
    KeAbPostRelease((unsigned int)&PiUEventClientRegistrationListLock);
  }
  return v2;
}
