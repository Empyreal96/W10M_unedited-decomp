// PiPnpRtlSetObjectProperty 
 
int __fastcall PiPnpRtlSetObjectProperty(int a1, unsigned __int16 *a2, int a3, int a4, int a5, unsigned int a6, int a7, int a8, int a9)
{
  unsigned __int16 *v10; // r6
  int v11; // r4
  int v12; // r4
  int v14; // r7
  int (**v15)[5]; // r6
  unsigned int i; // r4
  unsigned int v17; // r1
  unsigned int v18; // t1
  int v19; // r4
  int v20; // r0
  int v21; // r1
  int v22; // r2
  int v23; // r3
  unsigned int v24; // r2
  int v25; // r0
  unsigned int v26; // r1
  int v27; // r3
  int v29; // [sp+1Ch] [bp-2Ch]

  v29 = 0;
  if ( a3 == 3 )
  {
    if ( *(_DWORD *)(a6 + 16) == 256 && !memcmp(a6, (unsigned int)DEVPKEY_Device_InstanceId, 16) )
      return -1073741790;
LABEL_3:
    v10 = a2;
    v11 = a8;
LABEL_4:
    v12 = PnpSetObjectProperty(a1, v10, a3, a4, a5, a6, a7, v11, a9, 0);
    if ( v29 )
    {
      v25 = ExReleaseResourceLite((int)&PnpRegistryDeviceResource);
      v26 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v27 = (__int16)(*(_WORD *)(v26 + 0x134) + 1);
      *(_WORD *)(v26 + 308) = v27;
      if ( !v27 && *(_DWORD *)(v26 + 100) != v26 + 100 && !*(_WORD *)(v26 + 310) )
        KiCheckForKernelApcDelivery(v25);
    }
    return v12;
  }
  if ( a3 == 1 )
  {
    v14 = *(_DWORD *)(a6 + 16);
    v15 = &PiPnpRtlDeviceReadOnlyProps;
    for ( i = 0; i < 9; ++i )
    {
      v18 = (unsigned int)*v15++;
      v17 = v18;
      if ( v14 == *(_DWORD *)(v18 + 16) && !memcmp(a6, v17, 16) )
        return -1073741790;
    }
    v19 = *(_DWORD *)(a6 + 16);
    if ( v19 == 12 && !memcmp(a6, (unsigned int)DEVPKEY_Device_ConfigFlags, 16) )
    {
      v11 = a8;
      if ( !a8 || a9 != 4 )
        JUMPOUT(0x7C8C02);
    }
    else
    {
      if ( v19 == 3 && !memcmp(a6, (unsigned int)DEVPKEY_Device_HardwareIds, 16)
        || v19 == 4 && !memcmp(a6, (unsigned int)DEVPKEY_Device_CompatibleIds, 16) )
      {
        v10 = a2;
        if ( !CmIsRootEnumeratedDevice(a2, v21, v22, v23) )
          return -1073741790;
        v11 = a8;
        goto LABEL_15;
      }
      v11 = a8;
    }
    v10 = a2;
LABEL_15:
    if ( *(_DWORD *)(a6 + 16) == 10 && !memcmp(a6, (unsigned int)DEVPKEY_Device_ClassGuid, 16) )
    {
      v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v24 + 308);
      ExAcquireResourceSharedLite((int)&PnpRegistryDeviceResource, 1);
      v29 = 1;
    }
    goto LABEL_4;
  }
  if ( a3 != 5 )
    goto LABEL_3;
  if ( *(_DWORD *)(a6 + 16) != 105 )
    goto LABEL_3;
  v20 = memcmp(a6, (unsigned int)DEVPKEY_DeviceContainer_ConfigFlags, 16);
  if ( a7 == 7 )
    goto LABEL_3;
  return sub_7C8BFC(v20);
}
