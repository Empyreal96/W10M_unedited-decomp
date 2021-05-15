// PiProfileUpdateDeviceTreeCallback 
 
int __fastcall PiProfileUpdateDeviceTreeCallback(int a1, int a2, int a3, int a4)
{
  int v4; // r2
  int v6; // r3
  int v7; // r1
  int v8; // r3

  v4 = *(_DWORD *)(a1 + 172);
  if ( v4 == 776 )
  {
    if ( !PnpIsDeviceInstanceEnabled(0, (unsigned __int16 *)(a1 + 20), 0, a4) )
      PnpRequestDeviceRemoval(a1, 0, 22);
  }
  else if ( (v4 == 770 || v4 == 786) && (*(_DWORD *)(a1 + 268) & 0x2000) != 0 && *(_DWORD *)(a1 + 276) == 22 )
  {
    PipClearDevNodeProblem(a1, a2, v4, 22);
    if ( PnpIsDeviceInstanceEnabled(0, (unsigned __int16 *)(a1 + 20), 0, v6) )
    {
      PnpRestartDeviceNode(a1, v7);
      IoInvalidateDeviceRelations(*(_DWORD *)(*(_DWORD *)(a1 + 8) + 16), 0);
    }
    else
    {
      PipSetDevNodeProblem(a1, 22, 0, v8);
    }
  }
  return 0;
}
