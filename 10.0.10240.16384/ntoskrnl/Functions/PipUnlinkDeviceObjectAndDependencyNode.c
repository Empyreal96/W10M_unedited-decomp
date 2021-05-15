// PipUnlinkDeviceObjectAndDependencyNode 
 
int __fastcall PipUnlinkDeviceObjectAndDependencyNode(int a1, int a2)
{
  *(_DWORD *)(*(_DWORD *)(a1 + 176) + 44) = 0;
  *(_DWORD *)(a2 + 24) = 0;
  return PipDereferenceDependencyNode(a2);
}
