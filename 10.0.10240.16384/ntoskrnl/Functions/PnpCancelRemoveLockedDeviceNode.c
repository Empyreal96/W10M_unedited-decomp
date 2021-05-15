// PnpCancelRemoveLockedDeviceNode 
 
int __fastcall PnpCancelRemoveLockedDeviceNode(int result, int a2, int a3)
{
  _DWORD *v3; // r4
  int v4; // r1

  v3 = (_DWORD *)result;
  if ( *(_DWORD *)(result + 172) == 784 )
  {
    IopRemoveDevice(*(_DWORD **)(result + 16), 3, a3);
    PipRestoreDevNodeState(v3);
    result = PnpStartedDeviceNodeDependencyCheck((int)v3, v4);
  }
  return result;
}
