// IoOpenDeviceInterfaceRegistryKey 
 
int __fastcall IoOpenDeviceInterfaceRegistryKey(int a1, int a2, int a3)
{
  unsigned __int16 *v4; // r6
  int v7; // r5
  int v8; // r2
  int v9; // r3
  int v10; // r0
  unsigned int v11; // r1
  int v12; // r3
  unsigned __int16 *v14; // [sp+10h] [bp-18h] BYREF

  v4 = 0;
  v14 = 0;
  if ( a1 && *(_DWORD *)(a1 + 4) && *(_WORD *)a1 )
  {
    v7 = PnpUnicodeStringToWstr((int *)&v14, 0, (unsigned __int16 *)a1);
    if ( v7 < 0 )
    {
      v4 = v14;
    }
    else
    {
      v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v9 = *(__int16 *)(v8 + 0x134) - 1;
      *(_WORD *)(v8 + 308) = v9;
      ExAcquireResourceExclusiveLite((int)&PnpRegistryDeviceResource, 1, v8, v9);
      v4 = v14;
      v7 = CmOpenDeviceInterfaceRegKey((int *)PiPnpRtlCtx, v14, 50, (int)&PiPnpRtlCtx, a2, 1, a3, 0);
      v10 = ExReleaseResourceLite((int)&PnpRegistryDeviceResource);
      v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v12 = (__int16)(*(_WORD *)(v11 + 0x134) + 1);
      *(_WORD *)(v11 + 308) = v12;
      if ( !v12 )
        return sub_81A2B8(v10);
    }
  }
  else
  {
    v7 = -1073741811;
  }
  PnpUnicodeStringToWstrFree((unsigned int)v4, a1);
  return v7;
}
