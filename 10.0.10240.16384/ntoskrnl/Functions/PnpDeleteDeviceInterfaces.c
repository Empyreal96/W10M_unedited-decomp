// PnpDeleteDeviceInterfaces 
 
int __fastcall PnpDeleteDeviceInterfaces(unsigned __int16 *a1)
{
  unsigned __int16 *v2; // r4
  int v3; // r2
  int v4; // r3
  int v5; // r5
  int v6; // r3
  unsigned int v7; // r6
  int v9; // r3
  unsigned __int16 *v10; // r6
  int v11; // r0
  unsigned int v12; // r1
  int v13; // r3
  int v14; // [sp+18h] [bp-30h] BYREF
  unsigned int v15; // [sp+1Ch] [bp-2Ch] BYREF
  unsigned __int16 v16; // [sp+20h] [bp-28h] BYREF
  int v17; // [sp+24h] [bp-24h]

  v15 = 0;
  v2 = 0;
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v4 = *(__int16 *)(v3 + 0x134) - 1;
  *(_WORD *)(v3 + 308) = v4;
  ExAcquireResourceExclusiveLite((int)&PnpRegistryDeviceResource, 1, v3, v4);
  v5 = PnpUnicodeStringToWstr((int *)&v15, 0, a1);
  if ( v5 >= 0 )
  {
    v6 = 4096;
    v7 = 0;
    v5 = -1073741789;
    v14 = 4096;
    while ( v7 < 5 )
    {
      if ( v2 )
        return sub_81B5D4();
      v2 = (unsigned __int16 *)ExAllocatePoolWithTag(1, 2 * v6, 538996816);
      if ( !v2 )
      {
        v5 = -1073741670;
        break;
      }
      v5 = CmGetMatchingFilteredDeviceInterfaceList(PiPnpRtlCtx, 0, v15, 0, 0, 0, (int)v2, v14, (int)&v14, 0);
      ++v7;
      if ( v5 != -1073741789 )
        break;
      v6 = v14;
    }
    if ( v5 >= 0 )
    {
      v9 = *v2;
      v10 = v2;
      while ( v9 )
      {
        v5 = RtlInitUnicodeStringEx((int)&v16, v10);
        if ( v5 >= 0 )
          CmDeleteDeviceInterface(PiPnpRtlCtx, v17, 0);
        v10 += ((unsigned int)v16 + 2) >> 1;
        v9 = *v10;
      }
    }
  }
  v11 = ExReleaseResourceLite((int)&PnpRegistryDeviceResource);
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v13 = (__int16)(*(_WORD *)(v12 + 0x134) + 1);
  *(_WORD *)(v12 + 308) = v13;
  if ( !v13 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
    KiCheckForKernelApcDelivery(v11);
  if ( v2 )
    ExFreePoolWithTag((unsigned int)v2);
  PnpUnicodeStringToWstrFree(v15, (int)a1);
  return v5;
}
