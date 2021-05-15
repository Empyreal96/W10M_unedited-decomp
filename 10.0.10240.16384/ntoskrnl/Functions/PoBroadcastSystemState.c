// PoBroadcastSystemState 
 
int __fastcall PoBroadcastSystemState(int *a1)
{
  int *v1; // r5
  unsigned __int8 *v2; // r4
  int v3; // r8
  int v4; // r3
  int v5; // r2
  char v6; // r3
  int v7; // r2
  int v8; // r9
  int v9; // r6
  unsigned __int8 *v10; // r2
  int i; // r6
  unsigned __int8 *v12; // r1
  int v13; // r0
  int v15; // [sp+8h] [bp-38h] BYREF
  int v16; // [sp+Ch] [bp-34h]
  int *v17; // [sp+10h] [bp-30h] BYREF
  int v18; // [sp+14h] [bp-2Ch]
  int v19; // [sp+18h] [bp-28h]
  int v20; // [sp+1Ch] [bp-24h]

  v1 = a1;
  v2 = (unsigned __int8 *)dword_61E84C;
  v3 = *((unsigned __int8 *)a1 + 25);
  *(_BYTE *)dword_61E84C = *((_BYTE *)a1 + 26);
  v4 = a1[1];
  v2[252] = v3;
  *((_DWORD *)v2 + 1) = v4;
  *((_DWORD *)v2 + 61) = 0;
  *((_DWORD *)v2 + 62) = 0;
  v2[253] = 0;
  v2[254] = 0;
  v2[255] = 0;
  dword_61E844 = 0;
  v5 = (*a1 & 0xF) << 16;
  dword_61E844 = v5;
  if ( v3 )
  {
    dword_61E844 = v5 & 0xFFFF00FF | 0x1100;
  }
  else
  {
    dword_61E844 = v5 ^ ((unsigned __int16)v5 ^ (unsigned __int16)(*((_WORD *)a1 + 4) << 8)) & 0xF00;
    dword_61E844 ^= ((unsigned __int16)dword_61E844 ^ (unsigned __int16)(*((_WORD *)a1 + 2) << 12)) & 0xF000;
  }
  dword_61E848 = a1[4];
  PopCurrentBroadcast = 1;
  if ( (dword_682610 & 0x8000) != 0 )
  {
    v15 = *((_DWORD *)v2 + 1);
    v6 = *((_BYTE *)a1 + 26);
    LOBYTE(v16) = v3;
    BYTE2(v16) = v6;
    BYTE1(v16) = *((_BYTE *)a1 + 24);
    v17 = &v15;
    v18 = 0;
    v19 = 8;
    v20 = 0;
    a1 = EtwTraceKernelEvent((int *)&v17, 1, 0x80008000, 4644, 4200450);
  }
  if ( *((_BYTE *)v1 + 26) == 2 )
    v2[254] = 1;
  if ( *((_BYTE *)v1 + 24) && *((_BYTE *)v1 + 26) == 3 )
    v2[255] = 1;
  if ( (v1[5] & 0x8000000) != 0 )
    dword_61E844 |= 0x200000u;
  if ( !v3 )
  {
    if ( *((int *)v2 + 61) >= 0 )
    {
      PopSetupSleepNotifies(v2);
      PopDiagTraceDevicesSuspend(
        *((unsigned __int8 *)v1 + 26) == 3,
        ((unsigned int)dword_61E844 >> 8) & 0xF,
        (unsigned __int16)dword_61E844 >> 12);
      v7 = v1[4];
      if ( v7 == 4 && (PopShutdownPowerOffPolicy || dword_61EC90) )
        v8 = 3;
      else
        v8 = 0;
      if ( (v7 == 2 || v7 == 3) && *v2 == 2 )
        PopFxActivateDevicesForSx(1u);
      v9 = 4;
      while ( 1 )
      {
        if ( v9 == 1 && *((_BYTE *)v1 + 26) == 2 )
        {
          EmPowerPagingEnabled(0);
          if ( *((_BYTE *)v1 + 24) )
          {
            IoConfigureCrashDump(0, 1);
            if ( (PopShutdownCleanly & 0x10) != 0 )
              ObShutdownSystem(1);
            MmShutdownSystem(1);
          }
          else
          {
            ExAcquireTimeRefreshLock(1);
            v2[256] = 1;
          }
        }
        PopDiagTraceDevicesLevel(v9, 0, *v2, 1);
        v10 = &v2[40 * v9];
        if ( *((_DWORD *)v10 + 9) )
        {
          if ( (v1[5] & 0x80000000) != 0 )
            **((_DWORD **)v2 + 8) = 0;
          PopCurrentLevel = v9;
          PopSleepDeviceList(v2, v10 + 36);
        }
        PopDiagTraceDevicesLevel(v9, 0, *v2, 0);
        if ( *((int *)v2 + 61) < 0 )
          break;
        if ( --v9 < v8 )
          goto LABEL_44;
      }
      v3 = 1;
      if ( *((_DWORD *)v2 + 62)
        && v1[3] == 1
        && (PopMapInternalActionToIrpAction(v1[4], *((_DWORD *)v2 + 1), 0) == 7 || (v1[5] & 0x80000000) == 0) )
      {
        IoNotifyPowerOperationVetoed();
      }
LABEL_44:
      a1 = (int *)PopDiagTraceEventNoPayload((int)POP_ETW_EVENT_DEVICESSUSPEND_END);
    }
    if ( (PopSimulate & 0x20000) != 0 && *((_BYTE *)v1 + 26) == 2 )
    {
      a1 = (int *)DbgPrint("po: POP_WAKE_DEVICE_AFTER_SLEEP enabled.\n");
      v3 = 1;
      *((_DWORD *)v2 + 61) = -1073741823;
    }
  }
  v2[252] = v3;
  if ( v3 )
  {
    *v2 = 2;
    v2[254] = 1;
    *((_DWORD *)v2 + 1) = 1;
    if ( *((_BYTE *)v1 + 26) == 2 )
    {
      PopDiagTraceEventNoPayload((int)POP_ETW_EVENT_DEVICESWAKE);
      a1 = (int *)KeQueryPerformanceCounter(&v15, 0);
      dword_61EF68 = v15;
      dword_61EF6C = v16;
    }
    for ( i = 0; i <= 4; ++i )
    {
      if ( PoResumeFromHibernate && !i )
      {
        if ( byte_61EED0 )
        {
          a1 = (int *)KeQueryPerformanceCounter(&v15, 0);
          dword_61F110 = v15;
          dword_61F114 = v16;
        }
        if ( byte_64A430 )
        {
          BgDisplayFade(a1);
          byte_63760A = 0;
          byte_63761C = 0;
        }
      }
      PopDiagTraceDevicesLevel(i, 1, *v2, 1);
      v12 = &v2[40 * i];
      if ( *((_DWORD *)v12 + 10) < *((_DWORD *)v12 + 9) )
      {
        PopCurrentLevel = i;
        PopWakeDeviceList(v2, v12 + 36);
      }
      a1 = (int *)PopDiagTraceDevicesLevel(i, 1, *v2, 0);
      if ( i == 1 && *((_BYTE *)v1 + 26) == 2 )
      {
        if ( v2[256] )
        {
          v2[256] = 0;
          ExReleaseTimeRefreshLock(a1);
        }
        if ( PoResumeFromHibernate )
          PopBootLoaderSiDataProcess();
        a1 = (int *)EmPowerPagingEnabled(1);
        if ( (PopDebugFlags & 4) != 0 )
        {
          v15 = -50000000;
          v16 = -1;
          KeDelayExecutionThread(0, 0, (unsigned int *)&v15);
          KeBugCheckEx(160, 10, 1, 0, 0);
        }
      }
    }
    if ( *((_BYTE *)v1 + 26) == 2 )
    {
      PopFxIdleDevicesFromSx();
      v13 = KeQueryPerformanceCounter(&v15, 0);
      dword_61EF70 = v15;
      dword_61EF74 = v16;
      PopDiagTraceDevicesWakeEnd(v13);
      PopHandleWakeSources();
      if ( (PopDebugFlags & 8) != 0 )
      {
        v15 = -50000000;
        v16 = -1;
        KeDelayExecutionThread(0, 0, (unsigned int *)&v15);
        KeBugCheckEx(160, 10, 2, 0, 0);
      }
    }
    *v2 = *((_BYTE *)v1 + 26);
    *((_DWORD *)v2 + 1) = v1[1];
  }
  if ( (dword_682610 & 0x8000) != 0 )
  {
    v15 = *((_DWORD *)v2 + 61);
    v17 = &v15;
    v18 = 0;
    v19 = 4;
    v20 = 0;
    EtwTraceKernelEvent((int *)&v17, 1, 0x80008000, 4645, 4200450);
  }
  PopCurrentBroadcast = 0;
  return *((_DWORD *)v2 + 61);
}
