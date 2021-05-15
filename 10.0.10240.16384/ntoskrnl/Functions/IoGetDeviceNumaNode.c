// IoGetDeviceNumaNode 
 
int __fastcall IoGetDeviceNumaNode(int a1, _WORD *a2)
{
  int v3; // r2
  int v4; // r3

  if ( !a1 )
    return -1073741811;
  v3 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
  if ( !v3 || (*(_DWORD *)(v3 + 268) & 0x20000) != 0 )
    return -1073741811;
  v4 = *(_DWORD *)(v3 + 420);
  if ( v4 != -1 && v4 != -2 )
  {
    *a2 = v4;
    return 0;
  }
  if ( !KeQueryHighestNodeNumber() )
  {
    *a2 = 0;
    return 0;
  }
  return -1073741275;
}
