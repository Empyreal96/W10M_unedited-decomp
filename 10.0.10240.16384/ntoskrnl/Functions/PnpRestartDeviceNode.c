// PnpRestartDeviceNode 
 
int __fastcall PnpRestartDeviceNode(int a1, int a2)
{
  int v3; // r3
  int v4; // r5
  unsigned int v6; // r0

  PpDevNodeLockTree(4, a2);
  if ( (*(_DWORD *)(a1 + 268) & 0x10) == 0 )
  {
    v4 = -1073741823;
    goto LABEL_4;
  }
  PipClearDevNodeUserFlags(a1, 5);
  PipClearDevNodeFlags(a1, 1081344);
  v3 = *(_DWORD *)(a1 + 456);
  v4 = 0;
  *(_DWORD *)(a1 + 168) = 0;
  *(_DWORD *)(a1 + 456) = v3 & 0xFFFFFC03;
  __dmb(0xBu);
  *(_DWORD *)(a1 + 64) = 0;
  __dmb(0xBu);
  *(_DWORD *)(a1 + 68) = 0;
  if ( *(_DWORD *)(a1 + 172) == 769 )
  {
    *(_DWORD *)(a1 + 420) = -1;
    PipSetDevNodeState((_DWORD *)a1, 769);
LABEL_4:
    PpDevNodeUnlockTree(4);
    return v4;
  }
  v6 = PipClearDevNodeFlags(a1, 2082475264);
  if ( *(_WORD *)(a1 + 28) )
  {
    v6 = ExFreePoolWithTag(*(_DWORD *)(a1 + 32));
    *(_WORD *)(a1 + 30) = 0;
    *(_WORD *)(a1 + 28) = 0;
    *(_DWORD *)(a1 + 32) = 0;
  }
  return sub_7E0CF4(v6);
}
