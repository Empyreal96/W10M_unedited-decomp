// PiCMSetRegistryProperty 
 
int __fastcall PiCMSetRegistryProperty(unsigned int a1, unsigned int a2, _DWORD *a3, unsigned int a4, int a5, _DWORD *a6)
{
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r4
  int v12; // r4
  int v13; // r0
  int v14; // r4
  unsigned __int16 *v15; // r5
  int v17[2]; // [sp+10h] [bp-48h] BYREF
  char v18[4]; // [sp+18h] [bp-40h] BYREF
  int v19; // [sp+1Ch] [bp-3Ch]
  int v20; // [sp+20h] [bp-38h]
  unsigned __int16 *v21; // [sp+24h] [bp-34h]
  int v22; // [sp+2Ch] [bp-2Ch]
  int v23; // [sp+30h] [bp-28h]
  int v24; // [sp+34h] [bp-24h]
  int v25; // [sp+38h] [bp-20h]
  int v26; // [sp+3Ch] [bp-1Ch]

  *a6 = 0;
  v17[0] = 0;
  v11 = PiCMCaptureRegistryPropertyInputData(a1, a2, (int)a3, (int)v18);
  if ( v11 >= 0 )
  {
    v12 = v22;
    if ( v22 == 13 )
      v13 = 64;
    else
      v13 = 2;
    if ( PiAuDoesClientHaveAccess(v13, v8, v9, v10) )
    {
      v15 = v21;
      if ( v21 && !v19 && a3 && a4 >= 8 )
      {
        v14 = PiCMConvertRegistryProperty(v12, v17);
        if ( v14 >= 0 )
        {
          if ( v20 == 1 )
          {
            v14 = PiPnpRtlSetDeviceRegProperty(PiPnpRtlCtx, v15, (int)&PiPnpRtlCtx, v17[0], v23, v24, v25);
            if ( v14 >= 0 && RtlInitUnicodeStringEx((int)v17, v15) >= 0 )
              PnpSetDeviceInstancePropertyChangeEventFromDeviceInstance((unsigned __int16 *)v17);
          }
          else if ( v20 == 2 )
          {
            v14 = CmSetInstallerClassRegProp(PiPnpRtlCtx, v15, 0, v17[0], v23, v24, v25);
          }
          else
          {
            v14 = -1073741811;
          }
          if ( v14 == -1073741790 )
            v14 = -1073741264;
        }
      }
      else
      {
        v14 = -1073741811;
      }
    }
    else
    {
      v14 = -1073741790;
    }
    v11 = PiCMReturnBasicResultData(v14, v26, a3, a4, a6);
  }
  PiCMReleaseRegistryPropertyInputData((int)v18);
  return v11;
}
