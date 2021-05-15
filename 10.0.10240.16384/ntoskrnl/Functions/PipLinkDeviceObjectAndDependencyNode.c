// PipLinkDeviceObjectAndDependencyNode 
 
int __fastcall PipLinkDeviceObjectAndDependencyNode(int result, int a2)
{
  int v2; // r3

  v2 = *(_DWORD *)(a2 + 44);
  *(_DWORD *)(a2 + 24) = result;
  *(_DWORD *)(a2 + 44) = v2 + 1;
  *(_DWORD *)(*(_DWORD *)(result + 176) + 44) = a2;
  return result;
}
