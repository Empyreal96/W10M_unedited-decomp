// WdipSemDisableScenario 
 
int __fastcall WdipSemDisableScenario(int a1, int a2, int a3)
{
  int v6; // r6
  unsigned int v7; // r4
  int v8; // r0
  int v9; // r1
  int v10; // r7
  unsigned int v11; // r4
  int v12; // r4
  int v13; // r1
  unsigned int v14; // r0
  int v15; // r0
  unsigned int v16; // r2
  int v17; // r0
  unsigned int v18; // r1
  __int16 v19; // r3
  unsigned int v20; // r2
  int v21; // r0
  int v22; // r6
  unsigned int v23; // r2
  int v24; // r1
  unsigned int v25; // r0
  unsigned int v26; // r2
  int v27; // r0
  unsigned int v28; // r1
  __int16 v29; // r3
  int v31; // [sp+8h] [bp-20h]

  v31 = 0;
  v6 = 0;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 308);
  v8 = KeAbPreAcquire((unsigned int)&WdipSemPushLock, 0, 0);
  v10 = v8;
  do
    v11 = __ldrex((unsigned int *)&WdipSemPushLock);
  while ( !v11 && __strex(0x11u, (unsigned int *)&WdipSemPushLock) );
  __dmb(0xBu);
  if ( v11 )
    v8 = ExfAcquirePushLockSharedEx(&WdipSemPushLock, v8, (unsigned int)&WdipSemPushLock);
  if ( v10 )
    *(_BYTE *)(v10 + 14) |= 1u;
  if ( !a1 || !a3 )
  {
    v12 = -1073741811;
LABEL_10:
    if ( EtwEventEnabled(WdipSemRegHandle, MEMORY[0x61CB14], (int)WDI_SEM_EVENT_SCENARIO_END_FAILED) )
      WdipSemWriteSemFailureEvent(WDI_SEM_EVENT_SCENARIO_END_FAILED, a1, a2, a3);
    if ( v6 )
      WdipSemActivateInstance(v6);
    goto LABEL_14;
  }
  if ( !WdipSemEnabled )
  {
LABEL_18:
    v12 = -1073741823;
    goto LABEL_10;
  }
  v12 = WdipSemGetLoggerIds(v8, v9, 1, (unsigned __int8)WdipSemEnabled);
  if ( v12 >= 0 )
  {
    v15 = WdipSemMarkInstanceForDeletion(a3);
    v6 = v15;
    if ( !v15 )
      goto LABEL_18;
    v12 = WdipSemValidateEndEvent(a1, a2, *(_DWORD *)(v15 + 24));
    if ( v12 < 0 )
      goto LABEL_10;
    WdipSemDisableContextProviders(v6, 0);
  }
  else
  {
    v31 = 1;
  }
  if ( v12 < 0 )
    goto LABEL_10;
  if ( EtwEventEnabled(WdipSemRegHandle, MEMORY[0x61CB14], (int)WDI_SEM_EVENT_SCENARIO_END) )
    WdipSemWriteSemActionsEvent(WDI_SEM_EVENT_SCENARIO_END, v6);
  WdipSemDeleteTransitionalInstance(v6);
LABEL_14:
  __pld(&WdipSemPushLock);
  v13 = WdipSemPushLock;
  if ( (WdipSemPushLock & 0xFFFFFFF0) <= 0x10 )
    v14 = 0;
  else
    v14 = WdipSemPushLock - 16;
  if ( (WdipSemPushLock & 2) != 0 )
    goto LABEL_34;
  __dmb(0xBu);
  do
    v16 = __ldrex((unsigned int *)&WdipSemPushLock);
  while ( v16 == v13 && __strex(v14, (unsigned int *)&WdipSemPushLock) );
  if ( v16 != v13 )
LABEL_34:
    ExfReleasePushLock(&WdipSemPushLock, v13);
  v17 = KeAbPostRelease((unsigned int)&WdipSemPushLock);
  v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v19 = *(_WORD *)(v18 + 0x134) + 1;
  *(_WORD *)(v18 + 308) = v19;
  if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
    KiCheckForKernelApcDelivery(v17);
  if ( v31 )
  {
    v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v20 + 308);
    v21 = KeAbPreAcquire((unsigned int)&WdipSemPushLock, 0, 0);
    v22 = v21;
    do
      v23 = __ldrex((unsigned __int8 *)&WdipSemPushLock);
    while ( __strex(v23 | 1, (unsigned __int8 *)&WdipSemPushLock) );
    __dmb(0xBu);
    if ( (v23 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(&WdipSemPushLock, v21, (unsigned int)&WdipSemPushLock);
    if ( v22 )
      *(_BYTE *)(v22 + 14) |= 1u;
    if ( WdipSemEnabled )
      WdipSemShutdown();
    __pld(&WdipSemPushLock);
    v24 = WdipSemPushLock;
    v25 = WdipSemPushLock - 16;
    if ( (WdipSemPushLock & 0xFFFFFFF0) <= 0x10 )
      v25 = 0;
    if ( (WdipSemPushLock & 2) != 0 )
      goto LABEL_55;
    __dmb(0xBu);
    do
      v26 = __ldrex((unsigned int *)&WdipSemPushLock);
    while ( v26 == v24 && __strex(v25, (unsigned int *)&WdipSemPushLock) );
    if ( v26 != v24 )
LABEL_55:
      ExfReleasePushLock(&WdipSemPushLock, v24);
    v27 = KeAbPostRelease((unsigned int)&WdipSemPushLock);
    v28 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v29 = *(_WORD *)(v28 + 0x134) + 1;
    *(_WORD *)(v28 + 308) = v29;
    if ( !v29 && *(_DWORD *)(v28 + 100) != v28 + 100 && !*(_WORD *)(v28 + 310) )
      KiCheckForKernelApcDelivery(v27);
  }
  return v12;
}
