// PoPowerOffMonitor 
 
int PoPowerOffMonitor()
{
  int v0; // r4
  int v2; // [sp+0h] [bp-28h] BYREF
  int v3[8]; // [sp+8h] [bp-20h] BYREF

  memset(v3, 0, 24);
  LOBYTE(v3[0]) = 0;
  v3[1] = 0;
  v3[2] = 1;
  v2 = PoBlockConsoleSwitch(v3);
  PoStartPowerStateTasks(v3);
  v3[4] = 12;
  v0 = PopDispatchStateCallout(v3, &v2);
  PoEndPowerStateTasks(v3);
  PoUnblockConsoleSwitch(v3, v2);
  return v0;
}
