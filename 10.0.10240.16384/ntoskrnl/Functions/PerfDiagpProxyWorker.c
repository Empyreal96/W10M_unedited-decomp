// PerfDiagpProxyWorker 
 
unsigned int __fastcall PerfDiagpProxyWorker(unsigned int result, int a2, int a3, int a4)
{
  int v4; // r4
  unsigned int v5; // r2
  int v6; // r6
  unsigned int v7; // r1
  unsigned int v8; // r0
  unsigned int v9; // r1
  __int16 v10; // r3
  const __int16 *v11; // r0
  int v12; // r0
  _DWORD v13[4]; // [sp+8h] [bp-10h] BYREF

  v13[0] = a4;
  if ( !result )
    return result;
  v4 = *(_DWORD *)(result + 16);
  ExFreePoolWithTag(result);
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v5 + 308);
  v6 = KeAbPreAcquire((unsigned int)&dword_61CB40, 0, 0);
  do
    v7 = __ldrex((unsigned __int8 *)&dword_61CB40);
  while ( __strex(v7 | 1, (unsigned __int8 *)&dword_61CB40) );
  __dmb(0xBu);
  if ( (v7 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&dword_61CB40, v6, (unsigned int)&dword_61CB40);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  if ( !PerfDiagpIsTracingAllowed() )
    goto LABEL_20;
  if ( dword_61CB44 == v4 - 1 )
    goto LABEL_31;
  if ( v4 != 3 )
  {
    if ( v4 != 5 && v4 != 7 )
      goto LABEL_15;
LABEL_31:
    if ( v4 == 1 )
    {
      PerfDiagpInitializeLoggerInfo(0, 0);
      NtTraceControl(
        2,
        (unsigned int)dword_61CB88,
        dword_61CB88[0],
        (int)dword_61CB88,
        dword_61CB88[0],
        (unsigned int)v13);
      v11 = L"Diagnostics\\Performance\\BootCKCLSettings";
      goto LABEL_43;
    }
    if ( v4 == 2 || v4 == 3 )
    {
      v12 = PerfDiagpUpdateCKCLEnableFlags();
      goto LABEL_44;
    }
    if ( v4 != 4 )
    {
      if ( v4 == 5 )
      {
        PerfDiagpInitializeLoggerInfo(0, 0);
        NtTraceControl(
          2,
          (unsigned int)dword_61CB88,
          dword_61CB88[0],
          (int)dword_61CB88,
          dword_61CB88[0],
          (unsigned int)v13);
        v11 = L"Diagnostics\\Performance\\SecondaryLogonCKCLSettings";
        goto LABEL_43;
      }
      if ( v4 != 6 )
      {
        if ( v4 != 7 )
          goto LABEL_45;
        PerfDiagpSaveActiveDCLLogFileName();
        PerfDiagpInitializeLoggerInfo(0, 0);
        NtTraceControl(
          2,
          (unsigned int)dword_61CB88,
          dword_61CB88[0],
          (int)dword_61CB88,
          dword_61CB88[0],
          (unsigned int)v13);
        v11 = L"Diagnostics\\Performance\\ShutdownCKCLSettings";
        goto LABEL_43;
      }
    }
    PerfDiagpInitializeLoggerInfo(0, 0);
    NtTraceControl(
      2,
      (unsigned int)dword_61CB88,
      dword_61CB88[0],
      (int)dword_61CB88,
      dword_61CB88[0],
      (unsigned int)v13);
    v11 = L"WMI\\AutoLogger\\Circular Kernel Context Logger";
LABEL_43:
    v12 = PerfDiagpRestartCKCL(v11);
LABEL_44:
    if ( v12 >= 0 )
      goto LABEL_45;
LABEL_20:
    dword_61CB44 = 8;
    goto LABEL_21;
  }
  if ( dword_61CB44 == 1 )
    goto LABEL_45;
LABEL_15:
  if ( v4 >= dword_61CB44 )
  {
    if ( dword_61CB44 && dword_61CB44 != 8 )
      PerfDiagpRestartCKCL(L"WMI\\AutoLogger\\Circular Kernel Context Logger");
    goto LABEL_20;
  }
  v4 = dword_61CB44;
LABEL_45:
  dword_61CB44 = v4;
LABEL_21:
  __dmb(0xBu);
  do
    v8 = __ldrex(&dword_61CB40);
  while ( __strex(v8 - 1, &dword_61CB40) );
  if ( (v8 & 2) != 0 && (v8 & 4) == 0 )
    ExfTryToWakePushLock(&dword_61CB40);
  result = KeAbPostRelease((unsigned int)&dword_61CB40);
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v10 = *(_WORD *)(v9 + 0x134) + 1;
  *(_WORD *)(v9 + 308) = v10;
  if ( !v10 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
