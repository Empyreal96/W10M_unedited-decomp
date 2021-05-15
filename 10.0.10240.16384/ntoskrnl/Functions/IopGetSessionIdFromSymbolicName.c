// IopGetSessionIdFromSymbolicName 
 
int __fastcall IopGetSessionIdFromSymbolicName(int a1)
{
  int v1; // r5
  int v2; // r0
  int v3; // r4
  int v4; // r3

  v1 = -1;
  v2 = IopDeviceObjectFromSymbolicName(a1);
  v3 = v2;
  if ( v2 )
  {
    v4 = *(_DWORD *)(*(_DWORD *)(v2 + 176) + 20);
    if ( v4 )
    {
      if ( (*(_DWORD *)(v4 + 268) & 0x20000) == 0 )
      {
        v1 = IopGetSessionIdFromPDO(v2);
        ObfDereferenceObject(v3);
      }
    }
  }
  return v1;
}
