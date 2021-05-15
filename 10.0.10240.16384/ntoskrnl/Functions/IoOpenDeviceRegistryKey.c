// IoOpenDeviceRegistryKey 
 
int __fastcall IoOpenDeviceRegistryKey(int a1, char a2, int a3, int a4)
{
  int v7; // r4
  int v8; // r4
  unsigned int v9; // r1
  int v10; // r3
  int v11; // r4
  int v12; // r0
  unsigned int v13; // r1
  __int16 v14; // r3

  if ( !a1 )
    return -1073741811;
  v7 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
  if ( !v7 || (*(_DWORD *)(v7 + 268) & 0x20000) != 0 )
    return -1073741811;
  if ( (a2 & 1) != 0 )
  {
    v8 = 17;
    goto LABEL_6;
  }
  if ( (a2 & 2) == 0 )
    return -1073741811;
  v8 = 18;
LABEL_6:
  if ( (a2 & 4) != 0 )
    v8 |= 0x200u;
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v10 = *(__int16 *)(v9 + 0x134) - 1;
  *(_WORD *)(v9 + 308) = v10;
  ExAcquireResourceExclusiveLite((int)&PnpRegistryDeviceResource, 1, a3, v10);
  v11 = CmOpenDeviceRegKey(PiPnpRtlCtx, *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 176) + 20) + 24), v8, 0, a3, 1u, a4, 0);
  v12 = ExReleaseResourceLite((int)&PnpRegistryDeviceResource);
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v14 = *(_WORD *)(v13 + 0x134) + 1;
  *(_WORD *)(v13 + 308) = v14;
  if ( !v14 )
    return sub_7E8780(v12);
  return v11;
}
