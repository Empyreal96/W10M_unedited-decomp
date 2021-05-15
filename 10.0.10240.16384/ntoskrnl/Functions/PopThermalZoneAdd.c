// PopThermalZoneAdd 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PopThermalZoneAdd(int a1)
{
  int v2; // r2
  int v3; // r3
  int (*v4)(); // r3
  __int64 v5; // r0
  int v7; // r0

  KeInitializeTimerEx((_DWORD *)(a1 + 80), 0);
  KeInitializeDpc(a1 + 128, (int)PopThermalZoneDpc, a1);
  *(_BYTE *)(a1 + 32) = 6;
  *(_BYTE *)(a1 + 35) = 2;
  *(_BYTE *)(a1 + 37) = -1;
  *(_BYTE *)(a1 + 38) = -1;
  v2 = *(_DWORD *)(a1 + 28);
  *(_DWORD *)(a1 + 44) = 1000;
  *(_DWORD *)(a1 + 48) = 100;
  *(_DWORD *)(a1 + 52) = 100;
  *(_DWORD *)(v2 + 24) = -1073741667;
  *(_DWORD *)(a1 + 268) = 100;
  v3 = PopThermalZoneNextId;
  *(_DWORD *)(a1 + 360) = PopThermalZoneNextId;
  PopThermalZoneNextId = v3 + 1;
  KeInitializeEvent(a1 + 328, 0, 0);
  KeInitializeEvent(a1 + 344, 0, 0);
  v4 = PopThermalWorker;
  *(_QWORD *)(a1 + 312) = *(_QWORD *)(&a1 - 1);
  *(_DWORD *)(a1 + 304) = 0;
  LODWORD(v5) = KeQueryInterruptTime();
  *(_QWORD *)(a1 + 376) = v5;
  *(_DWORD *)(a1 + 320) = 0;
  *(_DWORD *)(a1 + 324) = 0;
  *(_DWORD *)(a1 + 320) = 0;
  if ( ++PopThermalZoneCount == 1 )
  {
    v7 = PopAcquirePolicyLock();
    if ( byte_61EA4D != 1 )
    {
      byte_61EA4D = 1;
      PopResetCurrentPolicies(v7);
    }
    PopReleasePolicyLock();
  }
  PopThermalUpdateTelemetryClientCount(1);
  return ExQueueWorkItem((_DWORD *)(a1 + 304), 1);
}
