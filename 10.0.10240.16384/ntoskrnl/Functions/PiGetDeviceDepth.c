// PiGetDeviceDepth 
 
int __fastcall PiGetDeviceDepth(int a1, _DWORD *a2)
{
  int v4; // r5
  int v5; // r0
  int v6; // r3

  v4 = -1073741810;
  *a2 = 0;
  PpDevNodeLockTree(0, (int)a2);
  v5 = PnpDeviceObjectFromDeviceInstance(a1);
  if ( v5 )
  {
    v6 = *(_DWORD *)(*(_DWORD *)(v5 + 176) + 20);
    if ( v6 )
    {
      v4 = 0;
      *a2 = *(_DWORD *)(v6 + 76);
    }
    ObfDereferenceObject(v5);
  }
  PpDevNodeUnlockTree(0);
  return v4;
}
