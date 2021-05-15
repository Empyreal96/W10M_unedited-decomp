// PiPnpRtlSetDeviceRegProperty 
 
int __fastcall PiPnpRtlSetDeviceRegProperty(int a1, unsigned __int16 *a2, int a3, int a4, int a5, int a6, int a7)
{
  int v10; // r8
  bool v11; // zf
  int v12; // r4
  unsigned int v13; // r2
  int v14; // r0
  unsigned int v15; // r1
  __int16 v16; // r3

  v10 = 0;
  if ( a4 >= 2 )
  {
    if ( a4 <= 3 )
    {
      v11 = CmIsRootEnumeratedDevice(a2, (int)a2, a3, a4) == 0;
      goto LABEL_8;
    }
    if ( a4 == 9 )
    {
      v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v13 + 308);
      ExAcquireResourceSharedLite((int)&PnpRegistryDeviceResource, 1);
      v10 = 1;
    }
    else
    {
      if ( a4 == 11 )
      {
        if ( !a6 || a7 != 4 )
          return -1073741811;
        goto LABEL_15;
      }
      if ( a4 > 15 )
      {
        if ( a4 <= 17 )
          return -1073741790;
        v11 = a4 == 37;
LABEL_8:
        if ( !v11 )
          goto LABEL_15;
        return -1073741790;
      }
    }
  }
LABEL_15:
  v12 = CmSetDeviceRegProp(a1, (int)a2, 0, a4, a5, a6, a7, 0);
  if ( v10 )
  {
    v14 = ExReleaseResourceLite((int)&PnpRegistryDeviceResource);
    v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v16 = *(_WORD *)(v15 + 0x134) + 1;
    *(_WORD *)(v15 + 308) = v16;
    if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 && !*(_WORD *)(v15 + 310) )
      KiCheckForKernelApcDelivery(v14);
  }
  return v12;
}
