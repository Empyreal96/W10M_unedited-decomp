// PopScanIdleList 
 
int PopScanIdleList()
{
  unsigned int v0; // r8
  int v1; // r4
  unsigned int v2; // r2
  int *v3; // r9
  unsigned int *v4; // r4
  unsigned int *v5; // r2
  unsigned int v6; // r1
  int v7; // r3
  unsigned int v8; // r7
  unsigned int v9; // r6
  unsigned int v10; // r0
  unsigned int v11; // r0
  unsigned int v12; // r1
  unsigned int v13; // r3
  int v14; // r5
  int v15; // r4
  int v16; // r1
  unsigned int v17; // r10
  unsigned int v18; // r1
  unsigned int v19; // r0
  unsigned int v20; // t0
  char v21; // r3
  unsigned int v22; // r1
  unsigned int v23; // t0
  int v25; // [sp+0h] [bp-48h]
  int v26; // [sp+8h] [bp-40h] BYREF
  int v27; // [sp+Ch] [bp-3Ch]
  int v28; // [sp+10h] [bp-38h]
  int v29; // [sp+14h] [bp-34h]
  unsigned int v30; // [sp+18h] [bp-30h]
  int v31; // [sp+1Ch] [bp-2Ch]
  unsigned int v32; // [sp+20h] [bp-28h]
  unsigned int v33; // [sp+24h] [bp-24h]
  unsigned int var20[9]; // [sp+28h] [bp-20h] BYREF
  int vars4; // [sp+4Ch] [bp+4h]

  v26 = 0;
  v27 = 0;
  v28 = 0;
  v0 = 0;
  v32 = dword_61EC24;
  v29 = dword_61EC28;
  v30 = *(_DWORD *)(PopPolicy + 212);
  v31 = PopCurrentCoalescingSpindownTimeout;
  v1 = KfRaiseIrql(2);
  var20[0] = v1;
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&PopDopeGlobalLock);
  }
  else
  {
    do
      v2 = __ldrex((unsigned int *)&PopDopeGlobalLock);
    while ( __strex(1u, (unsigned int *)&PopDopeGlobalLock) );
    __dmb(0xBu);
    if ( v2 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&PopDopeGlobalLock);
  }
  if ( byte_64B140 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(&PopDopeGlobalLock, vars4);
    }
    else
    {
      __dmb(0xBu);
      PopDopeGlobalLock = 0;
    }
    KfLowerIrql(v1);
    return 0;
  }
  PopDiagTraceEventNoPayload((int)POP_ETW_EVENT_DEVICE_IDLE_START);
  v3 = (int *)PopIdleDetectList;
  if ( (int *)PopIdleDetectList != &PopIdleDetectList )
  {
    do
    {
      v4 = (unsigned int *)(v3 - 7);
      __dmb(0xBu);
      v5 = (unsigned int *)(v3 - 6);
      do
        v6 = __ldrex(v5);
      while ( __strex(0, v5) );
      v33 = v6;
      __dmb(0xBu);
      *(v3 - 4) += v6;
      if ( v6 || *(v3 - 5) )
        *v4 = 0;
      __dmb(0xBu);
      v7 = PopIdleScanInterval;
      do
        v8 = __ldrex(v4);
      while ( __strex(v8 + v7, v4) );
      __dmb(0xBu);
      if ( !v8 )
        v3[4] = 1;
      if ( v29 == 1 )
        v9 = *(v3 - 3);
      else
        v9 = *(v3 - 2);
      if ( v3[2] == 1 )
      {
        if ( v9 == -1 )
          v9 = v30;
        v11 = PopCoalescingCheck(v31, v9, v8);
        v9 = v11;
        if ( v11 )
          ++v27;
        v12 = v3[9];
        v0 = v32;
        if ( v32 > v11 )
          v0 = v11;
        v10 = v3[8] + PopIdleScanInterval;
        if ( v8 )
        {
          if ( v12 <= PopIdleScanInterval )
            v13 = 0;
          else
            v13 = v12 - PopIdleScanInterval;
        }
        else
        {
          v13 = PopIdleScanInterval + v12;
          if ( PopIdleScanInterval + v12 > v0 )
          {
            v10 = v0;
            v13 = v0;
          }
        }
        v3[8] = v10;
        v3[9] = v13;
      }
      else
      {
        v10 = v8;
      }
      if ( v9 && v10 >= v9 && v3[4] == 1 && (v8 || (PopSimulate & 0x2000000) != 0) )
      {
        if ( v3[2] == 1 )
          PopDiagTraceIoCoalescingDiskIdle(*(v3 - 1));
        v25 = 0;
        if ( PoRequestPowerIrp(*(v3 - 1), 2, v3[3], (int)PopDeviceIdleCompletion) >= 0 )
        {
          v3[4] = v3[3];
          *(v3 - 4) = 0;
          ++dword_64B13C;
        }
      }
      else if ( v3[2] == 1 && !v8 )
      {
        v28 = 1;
      }
      PopDiagTraceDeviceIdleCheck(v3 - 7, v8, v33);
      if ( v3[2] == 1 )
        PopDiagTraceDiskIdleCheck(v3 - 7, v9, v0);
      v3 = (int *)*v3;
    }
    while ( v3 != &PopIdleDetectList );
    v1 = var20[0];
  }
  PopDiagTraceEventNoPayload((int)POP_ETW_EVENT_DEVICE_IDLE_END);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&PopDopeGlobalLock, vars4);
  }
  else
  {
    __dmb(0xBu);
    PopDopeGlobalLock = 0;
  }
  KfLowerIrql(v1);
  v14 = PopIdleBackgroundIgnoreCount;
  if ( PopIdleBackgroundIgnoreCount )
    v14 = --PopIdleBackgroundIgnoreCount;
  v15 = PopBackgroundTaskIgnoreCount;
  if ( PopBackgroundTaskIgnoreCount )
    v15 = --PopBackgroundTaskIgnoreCount;
  if ( !PopIdleScanInterval )
    __brkdiv0();
  v16 = dword_61E808 % (unsigned int)PopIdleScanInterval;
  v17 = dword_61E808 / (unsigned int)PopIdleScanInterval;
  if ( !dword_61E80C )
    goto LABEL_70;
  v18 = PopIdleScanInterval + 179;
  if ( !PopIdleScanInterval )
    __brkdiv0();
  v20 = v18 / PopIdleScanInterval;
  v16 = v18 % PopIdleScanInterval;
  v19 = v20;
  if ( v17 == v20 )
  {
LABEL_70:
    v21 = 1;
    goto LABEL_71;
  }
  if ( v17 < v19 )
  {
    v21 = 0;
LABEL_71:
    PopBackgroundTaskAllowed = v21;
  }
  if ( !v27 || v28 )
  {
    if ( !v14 && !dword_61EC0C )
    {
      PopGetPowerSettingValue((int)&GUID_IDLE_BACKGROUND_TASK, v16, 3, (int)&v26, v25, var20);
      ++v26;
      PopSetPowerSettingValueAcDc(&GUID_IDLE_BACKGROUND_TASK, 4, &v26);
      v22 = PopIdleScanInterval + 59;
      if ( !PopIdleScanInterval )
        __brkdiv0();
      v23 = v22 / PopIdleScanInterval;
      v16 = v22 % PopIdleScanInterval;
      v15 = PopBackgroundTaskIgnoreCount;
      PopIdleBackgroundIgnoreCount = v23;
    }
    if ( !v15 && !dword_61EC0C && PopSIdle >= 50 && PopBackgroundTaskAllowed )
    {
      PopGetPowerSettingValue((int)&GUID_BACKGROUND_TASK_NOTIFICATION, v16, 0, (int)&v26, v25, var20);
      ++v26;
      PopSetPowerSettingValue(&GUID_BACKGROUND_TASK_NOTIFICATION, -1, 0, 4, &v26);
      if ( !PopIdleScanInterval )
        __brkdiv0();
      PopBackgroundTaskAllowed = 0;
      PopBackgroundTaskIgnoreCount = (PopIdleScanInterval + 179) / (unsigned int)PopIdleScanInterval;
    }
  }
  return 0;
}
