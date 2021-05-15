// PnpQueryStopDeviceNode 
 
int __fastcall PnpQueryStopDeviceNode(_DWORD *a1, int a2)
{
  int v2; // r5
  int v4; // r1

  v2 = -1073741823;
  if ( a1[43] == 776 && (!a2 || !PiRebalanceOptOut((int)a1)) )
  {
    if ( PnpFindMountableDevice((_DWORD *)a1[4]) )
    {
      PnpLockMountableDevice(a1[4]);
      PipSetDevNodeFlags((int)a1, 0x1000000);
    }
    PoFxActivateDevice(a1[4]);
    v4 = a1[4];
    a1[114] |= 0x20u;
    v2 = IopQueryReconfiguration(5, v4);
    PipSetDevNodeState(a1, 777);
  }
  return v2;
}
