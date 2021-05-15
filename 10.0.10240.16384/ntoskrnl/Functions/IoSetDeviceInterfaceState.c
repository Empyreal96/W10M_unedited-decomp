// IoSetDeviceInterfaceState 
 
int __fastcall IoSetDeviceInterfaceState(int a1, int a2)
{
  int v4; // r2
  int v5; // r3
  int v6; // r4
  unsigned int v7; // r0
  __int16 v8; // r3

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = *(__int16 *)(v4 + 0x134) - 1;
  *(_WORD *)(v4 + 308) = v5;
  ExAcquireResourceExclusiveLite((int)&PnpRegistryDeviceResource, 1, v4, v5);
  v6 = IopProcessSetInterfaceState(a1, a2, 1);
  ExReleaseResourceLite((int)&PnpRegistryDeviceResource);
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v8 = *(_WORD *)(v7 + 0x134) + 1;
  *(_WORD *)(v7 + 308) = v8;
  if ( !v8 && *(_DWORD *)(v7 + 100) != v7 + 100 )
    return sub_7C8CFC();
  if ( v6 < 0 && !a2 )
    v6 = 0;
  return v6;
}
