// PnpDisableDevice 
 
int __fastcall PnpDisableDevice(int a1, int a2)
{
  int v2; // r2
  int v5; // r3

  v2 = *(_DWORD *)(a1 + 172);
  if ( v2 >= 769 )
  {
    if ( v2 <= 770 )
    {
LABEL_7:
      IopRemoveDevice(*(_DWORD **)(a1 + 16), 2, v2);
      IopReleaseDeviceResources((_DWORD *)a1, 1);
      goto LABEL_8;
    }
    if ( v2 <= 776 || v2 <= 781 )
    {
      if ( PiIrpQueryRemoveDevice(*(_DWORD **)(a1 + 16), 0) < 0 )
      {
        IopRemoveDevice(*(_DWORD **)(a1 + 16), 3, v2);
        goto LABEL_8;
      }
      goto LABEL_7;
    }
  }
LABEL_8:
  v5 = *(_DWORD *)(a1 + 268);
  if ( (v5 & 0x6000) != 0 )
    PipClearDevNodeProblem(a1, a2, v2, v5);
  return PipSetDevNodeProblem(a1, a2, 0, v5);
}
