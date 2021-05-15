// PopNotifyBrightnessChangesWorker 
 
unsigned int PopNotifyBrightnessChangesWorker()
{
  int v0; // r4
  int v1; // r0
  unsigned __int8 v2; // r5
  unsigned int v3; // r2
  int v5; // r7
  __int64 v6; // r2
  unsigned __int8 v7; // r4
  unsigned int v8; // r1
  int v9; // r4
  int v10; // r7
  unsigned int v11; // r2
  unsigned int v12; // r1

  v0 = KeAbPreAcquire((unsigned int)&PopBrightnessNotifyMutex, 0, 0);
  v1 = KfRaiseIrql(1);
  v2 = v1;
  do
    v3 = __ldrex((unsigned __int8 *)&PopBrightnessNotifyMutex);
  while ( __strex(v3 & 0xFE, (unsigned __int8 *)&PopBrightnessNotifyMutex) );
  __dmb(0xBu);
  if ( (v3 & 1) == 0 )
    return sub_554684();
  if ( v0 )
    *(_BYTE *)(v0 + 14) |= 1u;
  dword_61DEE4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_61DEFC = v1;
  while ( 1 )
  {
    v5 = PopBrightnessChangeWorkList;
    if ( (int *)PopBrightnessChangeWorkList == &PopBrightnessChangeWorkList )
      break;
    v6 = *(_QWORD *)PopBrightnessChangeWorkList;
    if ( *(int **)(PopBrightnessChangeWorkList + 4) != &PopBrightnessChangeWorkList
      || *(_DWORD *)(v6 + 4) != PopBrightnessChangeWorkList )
    {
      __fastfail(3u);
    }
    PopBrightnessChangeWorkList = *(_DWORD *)PopBrightnessChangeWorkList;
    *(_DWORD *)(v6 + 4) = &PopBrightnessChangeWorkList;
    dword_61DEE4 = 0;
    v7 = dword_61DEFC;
    __dmb(0xBu);
    do
      v8 = __ldrex((unsigned int *)&PopBrightnessNotifyMutex);
    while ( !v8 && __strex(1u, (unsigned int *)&PopBrightnessNotifyMutex) );
    if ( v8 )
      ExpReleaseFastMutexContended((unsigned int *)&PopBrightnessNotifyMutex, v8);
    KfLowerIrql(v7);
    KeAbPostRelease((unsigned int)&PopBrightnessNotifyMutex);
    if ( !memcmp((unsigned int)&GUID_DEVICE_POWER_POLICY_VIDEO_BRIGHTNESS, v5 + 8, 16) )
    {
      dword_61EC30 = *(_DWORD *)(v5 + 24);
    }
    else if ( !memcmp((unsigned int)&GUID_DEVICE_POWER_POLICY_VIDEO_DIM_BRIGHTNESS, v5 + 8, 16) )
    {
      dword_61EC34 = *(_DWORD *)(v5 + 24);
    }
    else if ( !memcmp((unsigned int)&GUID_VIDEO_DIM_TIMEOUT, v5 + 8, 16) )
    {
      dword_61EC2C = *(_DWORD *)(v5 + 24);
    }
    else if ( !memcmp((unsigned int)&GUID_VIDEO_ALS_OFFSET, v5 + 8, 16) )
    {
      dword_61EC38 = *(_DWORD *)(v5 + 24);
    }
    else if ( !memcmp((unsigned int)&GUID_VIDEO_ADAPTIVE_DISPLAY_BRIGHTNESS, v5 + 8, 16) )
    {
      dword_61EC3C = *(_DWORD *)(v5 + 24);
    }
    PopBroadcastSessionInfo(*(_DWORD *)(v5 + 8));
    ExFreePoolWithTag(v5, 1869638997);
    v9 = KeAbPreAcquire((unsigned int)&PopBrightnessNotifyMutex, 0, 0);
    v10 = KfRaiseIrql(1);
    do
      v11 = __ldrex((unsigned __int8 *)&PopBrightnessNotifyMutex);
    while ( __strex(v11 & 0xFE, (unsigned __int8 *)&PopBrightnessNotifyMutex) );
    __dmb(0xBu);
    if ( (v11 & 1) == 0 )
      ExpAcquireFastMutexContended((int)&PopBrightnessNotifyMutex, v9);
    if ( v9 )
      *(_BYTE *)(v9 + 14) |= 1u;
    dword_61DEE4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    dword_61DEFC = v10;
    v2 = v10;
  }
  PopBrightnessWorkItemQueued = 0;
  dword_61DEE4 = 0;
  __dmb(0xBu);
  do
    v12 = __ldrex((unsigned int *)&PopBrightnessNotifyMutex);
  while ( !v12 && __strex(1u, (unsigned int *)&PopBrightnessNotifyMutex) );
  if ( v12 )
    ExpReleaseFastMutexContended((unsigned int *)&PopBrightnessNotifyMutex, v12);
  KfLowerIrql(v2);
  return KeAbPostRelease((unsigned int)&PopBrightnessNotifyMutex);
}
