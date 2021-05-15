// PipForAllChildDeviceNodes 
 
int __fastcall PipForAllChildDeviceNodes(int a1, int a2, int a3)
{
  _DWORD *v3; // r4
  int result; // r0
  _DWORD *v6; // r0

  v3 = *(_DWORD **)(a1 + 4);
  for ( result = 0; v3 && result >= 0; result = PipForAllDeviceNodesCallback(v6, a3) )
  {
    v6 = v3;
    v3 = (_DWORD *)*v3;
  }
  return result;
}
