// PipProcessStartPhase2 
 
int __fastcall PipProcessStartPhase2(_DWORD *a1)
{
  int v3; // r5
  int v4; // r3
  int v5; // r2

  if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x4000000) != 0 )
    return sub_7CBEE0();
  v3 = a1[66];
  if ( a1[93] )
  {
    if ( v3 < 0 )
      PpProfileCancelHardwareProfileTransition();
    else
      PpProfileCommitTransitioningDock(a1, 2);
  }
  if ( v3 < 0 )
  {
    if ( v3 == -1073741102 )
      v5 = 14;
    else
      v5 = 10;
    PnpRequestDeviceRemoval(a1, 0, v5);
    if ( a1[93] )
      IoRequestDeviceEject(a1[4]);
  }
  else
  {
    IopDoDeferredSetInterfaceState((int)a1);
    if ( !IopBootConfigsReserved )
    {
      v4 = a1[75];
      if ( v4 != -1 )
      {
        if ( v4 == 1 )
          IopAllocateLegacyBootResources(2, a1[76]);
        IopAllocateLegacyBootResources(a1[75], a1[76]);
      }
    }
    PipSetDevNodeState(a1, 775);
  }
  if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x4000000) != 0 )
    Template_qz(
      Microsoft_Windows_Kernel_PnPHandle,
      dword_649E54,
      (int)KMPnPEvt_ProcessDeviceStart_Stop,
      a1[6],
      2,
      (unsigned __int16 *)a1[6]);
  return v3;
}
