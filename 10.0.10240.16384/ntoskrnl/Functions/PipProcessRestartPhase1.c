// PipProcessRestartPhase1 
 
int __fastcall PipProcessRestartPhase1(int *a1, int a2, int a3)
{
  int v6; // r5

  if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x4000000) != 0 )
    Template_qz(
      Microsoft_Windows_Kernel_PnPHandle,
      MEMORY[0x649E54],
      (int)KMPnPEvt_ProcessDeviceRestart_Start,
      a1[6],
      1,
      (unsigned __int16 *)a1[6]);
  if ( a3 && (a1[67] & 0x400000) != 0 )
  {
    v6 = -1073741267;
  }
  else
  {
    v6 = PnpStartDeviceNode((int)a1, 1, a2);
    if ( (a1[67] & 0x1000000) != 0 )
    {
      PnpUnlockMountableDevice(a1[4]);
      PipClearDevNodeFlags((int)a1, 0x1000000);
    }
  }
  if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x4000000) != 0 )
    Template_qz(
      Microsoft_Windows_Kernel_PnPHandle,
      MEMORY[0x649E54],
      (int)KMPnPEvt_ProcessDeviceRestart_Stop,
      a1[6],
      1,
      (unsigned __int16 *)a1[6]);
  return v6;
}
