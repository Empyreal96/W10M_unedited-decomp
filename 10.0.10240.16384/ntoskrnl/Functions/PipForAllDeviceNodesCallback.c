// PipForAllDeviceNodesCallback 
 
int __fastcall PipForAllDeviceNodesCallback(int a1, int a2)
{
  int result; // r0

  result = (*(int (__fastcall **)(int, _DWORD))a2)(a1, *(_DWORD *)(a2 + 4));
  if ( result >= 0 )
  {
    if ( *(_DWORD *)(a1 + 4) )
      result = PipForAllChildDeviceNodes(a1, (int)PipForAllDeviceNodesCallback, a2);
  }
  return result;
}
