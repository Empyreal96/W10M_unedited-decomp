// IopIsDescendantNode 
 
int __fastcall IopIsDescendantNode(_DWORD **a1, int a2)
{
  int v2; // r3
  int v3; // r2
  int result; // r0

  if ( a2 )
    v2 = *(_DWORD *)(*(_DWORD *)(a2 + 176) + 20);
  else
    v2 = 0;
  v3 = *(_DWORD *)(v2 + 8);
  if ( v3 )
    result = PipIsDeviceInDeviceObjectList(*a1, *(_DWORD *)(v3 + 16), 0);
  else
    result = sub_7E0568();
  return result;
}
