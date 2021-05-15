// PipProcessStartPhase1 
 
int __fastcall PipProcessStartPhase1(_DWORD *a1, int a2, int a3, int a4)
{
  int v7; // r5
  _DWORD v8[8]; // [sp+8h] [bp-20h] BYREF

  v8[0] = a3;
  v8[1] = a4;
  if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x4000000) != 0 )
    return sub_7E0BF0();
  if ( a3 && (a1[67] & 0x400000) != 0 )
  {
    v7 = -1073741267;
  }
  else
  {
    IopUncacheInterfaceInformation(a1[4], 1);
    if ( !a1[93]
      || (PpProfileBeginHardwareProfileTransition(0),
          PpProfileIncludeInHardwareProfileTransition(a1, 2),
          v7 = PpProfileQueryHardwareProfileChange(0, 2, v8, 0),
          v7 >= 0) )
    {
      v7 = PnpStartDeviceNode((int)a1, 0, a2);
    }
  }
  if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x4000000) != 0 )
    Template_qz(
      Microsoft_Windows_Kernel_PnPHandle,
      MEMORY[0x649E54],
      (int)KMPnPEvt_ProcessDeviceStart_Stop,
      a1[6],
      1,
      (unsigned __int16 *)a1[6]);
  return v7;
}
