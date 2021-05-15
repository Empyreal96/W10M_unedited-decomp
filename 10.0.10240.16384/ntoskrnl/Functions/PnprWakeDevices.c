// PnprWakeDevices 
 
int __fastcall PnprWakeDevices(int a1)
{
  int v2; // r0

  *(_DWORD *)(PnprContext + 656) = PnprGetMillisecondCounter(0);
  *(_BYTE *)(a1 + 29) = 1;
  v2 = PoBroadcastSystemState(a1 + 4);
  PoClearBroadcast(v2);
  PoEndPartitionReplace(a1 + 36, *(_DWORD *)(a1 + 32));
  PoEndPowerStateTasks(a1 + 36);
  PoUnblockConsoleSwitch(a1 + 36, *(_DWORD *)(a1 + 32));
  *(_DWORD *)(PnprContext + 660) = PnprGetMillisecondCounter(0);
  return 0;
}
