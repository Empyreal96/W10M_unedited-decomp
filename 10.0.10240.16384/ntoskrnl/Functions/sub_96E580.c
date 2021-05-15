// sub_96E580 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall sub_96E580(int a1, int a2, _DWORD *a3)
{
  void (__fastcall __noreturn *v3)(int, int); // r3
  int v4; // r0
  int v6; // r3
  int *v7; // r5
  char *v8; // r4 OVERLAPPED
  int v9; // r6
  int (__fastcall *v10)(int); // [sp-4h] [bp-4h]

  *a3 = 1;
  v6 = PopSleepStudyDeviceAccountingLevel;
  __dmb(0xBu);
  PopFxDeviceAccountingLevel = v6;
  if ( PopSleepStudyDisabled )
  {
    __dmb(0xBu);
    PopFxDeviceAccountingLevel = 0;
  }
  v7 = &PopFxSystemWorkOrders;
  v8 = (char *)&PopFxSystemWatchdogInfo;
  SocSubsystemsList = (int)&SocSubsystemsList;
  dword_61F58C = (int)&SocSubsystemsList;
  v9 = 4;
  do
  {
    v7[5] = 0;
    v7[2] = (int)PopFxPluginWork;
    v7[3] = (int)v7;
    *v7 = 0;
    *((_DWORD *)v8 + 20) = v7;
    KeInitializeTimerEx(v8, 0);
    v8[48] = 19;
    v8[49] = 1;
    v3 = PopFxWorkOrderWatchdog;
    *((_WORD *)v8 + 25) = 0;
    *(_QWORD *)(v8 + 60) = *(_QWORD *)(&v8 - 1);
    *((_DWORD *)v8 + 19) = 0;
    *((_DWORD *)v8 + 14) = 0;
    v7[6] = (int)v8;
    v8 += 88;
    v7 += 7;
    --v9;
  }
  while ( v9 );
  KeInitializeQueue((int)&PopFxSystemWorkQueue, 1);
  PopFxCreateEmergencyWorkerThread();
  v4 = PopPepEntry();
  PopFxPlatformInterface = 0;
  dword_61DB44 = 0;
  dword_61DB48 = 0;
  return v10(v4);
}
