// PoRegisterPowerSettingCallback 
 
int __fastcall PoRegisterPowerSettingCallback(int a1, _DWORD *a2, int a3, int a4, _DWORD *a5)
{
  int v5; // r9
  BOOL v8; // r8
  int v9; // r4
  int v10; // r5
  unsigned int v11; // r2
  _BYTE *v13; // r0
  _DWORD *v14; // r5
  int v15; // r1
  int v16; // r2
  int v17; // r3
  _DWORD *v18; // r4
  int *v19; // r2
  _DWORD *v20; // r1
  int v21; // r4
  unsigned int v22; // r3
  unsigned __int8 v23; // r5
  unsigned int v24; // r1

  v5 = dword_61EC0C;
  v8 = 0;
  if ( PopStateIsSessionSpecific((unsigned int)a2) )
    return -1073741811;
  v9 = KeAbPreAcquire((unsigned int)&PopSettingLock, 0, 0);
  v10 = KfRaiseIrql(1);
  do
    v11 = __ldrex((unsigned __int8 *)&PopSettingLock);
  while ( __strex(v11 & 0xFE, (unsigned __int8 *)&PopSettingLock) );
  __dmb(0xBu);
  if ( (v11 & 1) == 0 )
    return sub_7F3798();
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  dword_61F324 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_61F33C = v10;
  v13 = (_BYTE *)ExAllocatePoolWithTag(1, 56, 1952797520);
  v14 = v13;
  if ( v13 )
  {
    memset(v13, 0, 56);
    v14[2] = 1952797520;
    v15 = a2[1];
    v16 = a2[2];
    v17 = a2[3];
    v14[5] = *a2;
    v14[6] = v15;
    v14[7] = v16;
    v14[8] = v17;
    v14[10] = a3;
    v14[11] = a4;
    v14[12] = a1;
    v18 = PopFindPowerSettingConfiguration((unsigned int)a2, -1);
    if ( v18 )
    {
      if ( !memcmp((unsigned int)a2, (unsigned int)&GUID_IDLE_BACKGROUND_TASK, 16)
        || !memcmp((unsigned int)a2, (unsigned int)&GUID_BACKGROUND_TASK_NOTIFICATION, 16) )
      {
        v14[9] = v18[v5 + 12];
      }
      v19 = v18 + 2;
      v20 = (_DWORD *)v18[3];
      *v14 = v18 + 2;
      v14[1] = v20;
      if ( (_DWORD *)*v20 != v18 + 2 )
        __fastfail(3u);
    }
    else
    {
      v19 = &PopRegisteredPowerSettingCallbacks;
      v20 = (_DWORD *)dword_61E6DC;
      *v14 = &PopRegisteredPowerSettingCallbacks;
      v14[1] = v20;
      if ( (int *)*v20 != &PopRegisteredPowerSettingCallbacks )
        __fastfail(3u);
    }
    *v20 = v14;
    v21 = 0;
    v22 = PopOsInitPhase;
    v19[1] = (int)v14;
    v8 = v22 >= 3;
    if ( a5 )
      *a5 = v14;
  }
  else
  {
    v21 = -1073741670;
  }
  dword_61F324 = 0;
  v23 = dword_61F33C;
  __dmb(0xBu);
  do
    v24 = __ldrex((unsigned int *)&PopSettingLock);
  while ( !v24 && __strex(1u, (unsigned int *)&PopSettingLock) );
  if ( v24 )
    ExpReleaseFastMutexContended((unsigned int *)&PopSettingLock, v24);
  KfLowerIrql(v23);
  KeAbPostRelease((unsigned int)&PopSettingLock);
  if ( v8 )
    PopSetNotificationWork(32);
  return v21;
}
