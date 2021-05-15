// PiCMUnregisterDeviceInterface 
 
int __fastcall PiCMUnregisterDeviceInterface(unsigned int a1, unsigned int a2, _DWORD *a3, unsigned int a4, int a5, _DWORD *a6)
{
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r4
  int v12; // r4
  int v13; // r5
  int v14; // r3
  int v15; // r2
  int v16; // r3
  int v17; // r0
  unsigned int v18; // r1
  __int16 v19; // r3
  char v21[4]; // [sp+20h] [bp-48h] BYREF
  int v22; // [sp+24h] [bp-44h] BYREF
  int v23; // [sp+28h] [bp-40h] BYREF
  char v24[4]; // [sp+30h] [bp-38h] BYREF
  int v25; // [sp+34h] [bp-34h]
  int v26; // [sp+38h] [bp-30h]
  int v27; // [sp+3Ch] [bp-2Ch]
  int v28; // [sp+44h] [bp-24h]
  int v29; // [sp+48h] [bp-20h]

  v21[0] = 0;
  v22 = 0;
  v23 = 0;
  *a6 = 0;
  v11 = PiCMCaptureObjectInputData(a1, a2, (int)a3, (int)v24);
  if ( v11 >= 0 )
  {
    if ( PiAuDoesClientHaveAccess(2, v8, v9, v10) )
    {
      v13 = v27;
      if ( v27 && !v25 && v26 == 4 && !v28 && a3 && a4 >= 8 )
      {
        v12 = PnpGetObjectProperty(
                PiPnpRtlCtx,
                v27,
                3,
                0,
                0,
                (int)DEVPKEY_DeviceInterface_Enabled,
                (int)&v22,
                (int)v21,
                1,
                (int)&v23,
                0);
        if ( v12 >= 0 )
        {
          if ( v22 == 17 && v23 == 1 )
          {
            v14 = v21[0];
          }
          else
          {
            v14 = 0;
            v21[0] = 0;
          }
          if ( v14 == -1 )
            v12 = -1073740024;
          if ( v12 >= 0 )
          {
            v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v16 = *(__int16 *)(v15 + 0x134) - 1;
            *(_WORD *)(v15 + 308) = v16;
            ExAcquireResourceExclusiveLite((int)&PnpRegistryDeviceResource, 1, v15, v16);
            v12 = CmDeleteDeviceInterface(PiPnpRtlCtx, v13, 0);
            v17 = ExReleaseResourceLite((int)&PnpRegistryDeviceResource);
            v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v19 = *(_WORD *)(v18 + 0x134) + 1;
            *(_WORD *)(v18 + 308) = v19;
            if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
              KiCheckForKernelApcDelivery(v17);
          }
        }
      }
      else
      {
        v12 = -1073741811;
      }
    }
    else
    {
      v12 = -1073741790;
    }
    v11 = PiCMReturnBasicResultData(v12, v29, a3, a4, a6);
  }
  PiCMReleaseObjectInputData((int)v24);
  return v11;
}
