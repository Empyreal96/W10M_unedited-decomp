// PopDripsWatchdogTakeAction 
 
int __fastcall PopDripsWatchdogTakeAction(int a1, char a2)
{
  int v3; // r5
  int v5; // r4
  int v6; // r5
  unsigned __int16 *v7; // lr
  unsigned __int16 *v8; // r0
  int result; // r0
  int v10; // r8
  int v11; // r9
  int v12; // r0
  int v13; // [sp+18h] [bp-28h] BYREF
  int v14; // [sp+1Ch] [bp-24h] BYREF
  int v15[8]; // [sp+20h] [bp-20h] BYREF

  v3 = *(_DWORD *)(a1 + 4);
  v13 = 0;
  v15[0] = -1;
  PopFxDeviceAccountingWatchdog(10000 * v3, 0, &v13, v15);
  v5 = v13;
  v6 = 0;
  v14 = 0;
  if ( v13 )
  {
    PopFxChildDeviceActive(v13, &v14);
    v6 = v14;
  }
  v7 = 0;
  if ( v5 )
    v7 = (unsigned __int16 *)(*(_DWORD *)(v5 + 28) + 28);
  v8 = 0;
  if ( v6 )
    v8 = (unsigned __int16 *)(v6 + 28);
  result = PopDiagTraceCsDripsWatchdog(
             *(_DWORD *)a1,
             *(_DWORD *)(a1 + 8),
             *(_DWORD *)(a1 + 4),
             *(_BYTE *)(a1 + 20) != 0,
             *(_DWORD *)(a1 + 16),
             v5 != 0,
             a2,
             v7,
             v8);
  if ( !*(_BYTE *)(a1 + 20) || (a2 & 1) != 0 )
  {
    if ( (a2 & 2) != 0 )
      PopDiagTraceCsDripsWatchdogPerfTrack(
        *(_DWORD *)a1,
        *(_DWORD *)(a1 + 8),
        *(_DWORD *)(a1 + 4),
        *(unsigned __int8 *)(a1 + 20),
        *(_DWORD *)(a1 + 16),
        v5 != 0,
        a2);
    v10 = v15[0];
    if ( (a2 & 4) == 0 )
      goto LABEL_20;
    v15[0] = 0;
    v11 = 0;
    if ( v5 )
    {
      v12 = DbgkWerCaptureLiveKernelDump(L"DripsWatchdog", 351, 2, v5, v10, v6, 0, 0, 0);
    }
    else
    {
      if ( !PopDeviceConstraintsEnforced() || KdDebuggerEnabled )
      {
LABEL_18:
        if ( (PoDebug & 2) != 0 )
          DbgPrint("%s: DRIPS watchdog action %u result: 0x%x\n", "PopDripsWatchdogTakeAction", 4, v11);
LABEL_20:
        if ( KdDebuggerEnabled && !KdDebuggerNotPresent )
        {
          if ( (a2 & 8) != 0 )
          {
            if ( *(_DWORD *)(a1 + 12) <= 0x64u )
              __debugbreak();
          }
          else if ( v5 && (a2 & 0x20) != 0 )
          {
            PopFxBugCheck(1561, v5, v10, 0);
          }
        }
        result = VfIsVerifierEnabled();
        if ( result || (result = PopCheckTestsigningEnabled()) != 0 )
        {
          if ( v5 )
          {
            if ( (a2 & 0x20) != 0 )
              PopFxBugCheck(1561, v5, v10, 0);
          }
        }
        return result;
      }
      v12 = DbgkWerCaptureLiveKernelDump(L"DripsWatchdog", 351, 1, a1, *(_DWORD *)a1, 0, 0, 0, v15[0]);
    }
    v11 = v12;
    goto LABEL_18;
  }
  return result;
}
