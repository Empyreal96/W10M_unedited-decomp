// PipProcessRestartPhase2 
 
int __fastcall PipProcessRestartPhase2(_DWORD *a1)
{
  int v2; // r5
  int v3; // r2
  int v4; // r1

  if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x4000000) != 0 )
    Template_qz(
      Microsoft_Windows_Kernel_PnPHandle,
      MEMORY[0x649E54],
      (int)KMPnPEvt_ProcessDeviceRestart_Start,
      a1[6],
      2,
      (unsigned __int16 *)a1[6]);
  v2 = a1[66];
  if ( v2 >= 0 )
  {
    PipSetDevNodeState(a1, 776);
    if ( (a1[114] & 0x20) != 0 )
    {
      PoFxIdleDevice(a1[4]);
      a1[114] &= 0xFFFFFFDF;
    }
    PnpStartedDeviceNodeDependencyCheck((int)a1, v4);
  }
  else
  {
    if ( v2 == -1073741102 )
      v3 = 14;
    else
      v3 = 10;
    PnpRequestDeviceRemoval((int)a1, 0, v3);
    if ( a1[93] )
      IoRequestDeviceEject(a1[4]);
  }
  if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x4000000) != 0 )
    Template_qz(
      Microsoft_Windows_Kernel_PnPHandle,
      MEMORY[0x649E54],
      (int)KMPnPEvt_ProcessDeviceRestart_Stop,
      a1[6],
      2,
      (unsigned __int16 *)a1[6]);
  return v2;
}
