// PiUEventNotifyDeviceInstancePropertyChange 
 
int __fastcall PiUEventNotifyDeviceInstancePropertyChange(_DWORD *a1)
{
  int v1; // r9
  int v3; // r5
  int v4; // r1
  int v5; // r6
  int v6; // r2
  unsigned int v7; // r6
  int *v8; // r10
  _DWORD *v9; // r7
  _DWORD **v10; // t1
  _DWORD *v11; // r5
  int v12; // r9
  unsigned int v13; // r2
  int v14; // r3
  unsigned __int8 v15; // r5
  unsigned int v16; // r1
  int v18; // [sp+0h] [bp-30h]
  int v19; // [sp+8h] [bp-28h] BYREF
  void *v20; // [sp+Ch] [bp-24h]

  v19 = 0;
  v20 = 0;
  v1 = 0;
  v18 = 0;
  if ( a1[15] == 9 )
  {
    v3 = KeAbPreAcquire((unsigned int)&PiUEventClientRegistrationListLock, 0, 0);
    v5 = KfRaiseIrql(1);
    do
      v6 = __ldrex((unsigned __int8 *)&PiUEventClientRegistrationListLock);
    while ( __strex(v6 & 0xFE, (unsigned __int8 *)&PiUEventClientRegistrationListLock) );
    __dmb(0xBu);
    if ( (v6 & 1) == 0 )
      ExpAcquireFastMutexContended((int)&PiUEventClientRegistrationListLock, v3);
    if ( v3 )
      *(_BYTE *)(v3 + 14) |= 1u;
    dword_6308E4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    dword_6308FC = v5;
    v7 = 0;
    v8 = &v19;
    v19 = (int)&PiUEventDevInstancePropertyClientList
        + 8 * PiUEventHashStringIntoBucket((int)(a1 + 20), v4, v6, dword_6308E4);
    v20 = &unk_630A68;
    do
    {
      v10 = (_DWORD **)*v8++;
      v9 = v10;
      v11 = *v10;
      while ( v11 != v9 )
      {
        v12 = (int)v11;
        v11 = (_DWORD *)*v11;
        if ( (v7 || !wcsicmp((int)(a1 + 20), *(unsigned __int16 **)(*(_DWORD *)(v12 + 12) + 12)))
          && PiUEventApplyAdditionalFilters(a1, v12) )
        {
          v1 = PiUEventNotifyClient((int)a1, v12, v13, v14);
          v18 = v1;
        }
        else
        {
          v1 = v18;
        }
      }
      ++v7;
    }
    while ( v7 < 2 );
    dword_6308E4 = 0;
    v15 = dword_6308FC;
    __dmb(0xBu);
    do
      v16 = __ldrex((unsigned int *)&PiUEventClientRegistrationListLock);
    while ( !v16 && __strex(1u, (unsigned int *)&PiUEventClientRegistrationListLock) );
    if ( v16 )
      ExpReleaseFastMutexContended((unsigned int *)&PiUEventClientRegistrationListLock, v16);
    KfLowerIrql(v15);
    KeAbPostRelease((unsigned int)&PiUEventClientRegistrationListLock);
  }
  return v1;
}
