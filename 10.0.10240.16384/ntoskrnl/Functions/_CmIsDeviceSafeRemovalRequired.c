// _CmIsDeviceSafeRemovalRequired 
 
int __fastcall CmIsDeviceSafeRemovalRequired(int a1, unsigned __int16 *a2, int a3)
{
  BOOL v6; // r4
  char v7; // r6
  char v8; // r3
  int v9; // r5
  unsigned __int16 *i; // r2
  char v11; // r3
  char v13[4]; // [sp+20h] [bp-368h] BYREF
  int v14; // [sp+24h] [bp-364h] BYREF
  int v15; // [sp+28h] [bp-360h] BYREF
  int v16; // [sp+2Ch] [bp-35Ch] BYREF
  int v17; // [sp+30h] [bp-358h] BYREF
  unsigned int v18; // [sp+34h] [bp-354h] BYREF
  char v19[4]; // [sp+38h] [bp-350h] BYREF
  int v20; // [sp+3Ch] [bp-34Ch] BYREF
  int v21; // [sp+40h] [bp-348h] BYREF
  _WORD v22[200]; // [sp+48h] [bp-340h] BYREF
  unsigned __int16 v23[216]; // [sp+1D8h] [bp-1B0h] BYREF

  v16 = 0;
  v17 = 0;
  v21 = 0;
  v6 = 0;
  if ( CmGetDeviceStatus(a1, a2, a3, &v16, &v17, &v21) >= 0 )
  {
    v14 = 4;
    v7 = v16;
    if ( CmGetDeviceRegProp(a1, (int)a2, a3, 16, (int)v19, (int)&v15, (int)&v14) >= 0 )
    {
      v8 = v15;
    }
    else
    {
      v8 = 0;
      v15 = 0;
    }
    v9 = v8 & 4;
    if ( (v7 & 8) != 0 || (v8 & 2) != 0 )
    {
      v6 = (v8 & 0x80) == 0;
      v14 = 1;
      if ( !PnpGetObjectProperty(
              a1,
              (int)a2,
              1,
              a3,
              0,
              (int)DEVPKEY_Device_SafeRemovalRequiredOverride,
              (int)&v20,
              (int)v13,
              1,
              (int)&v14,
              0)
        && v20 == 17
        && v14 == 1 )
      {
        v6 = v13[0] != 0;
      }
      if ( !v9 && v6 )
      {
        v6 = 0;
        for ( i = a2; RtlStringCchCopyExW(v23, 200, i, 0, 0, 2048) >= 0; i = v22 )
        {
          v18 = 200;
          if ( CmGetDeviceParent(a1, v23, v22, &v18) >= 0 )
          {
            v14 = 4;
            if ( CmGetDeviceRegProp(a1, (int)v22, 0, 16, (int)v19, (int)&v15, (int)&v14) >= 0 )
            {
              v11 = v15;
            }
            else
            {
              v11 = 0;
              v15 = 0;
            }
            v9 = v11 & 4;
            if ( (v11 & 4) == 0 )
              continue;
          }
          return v9;
        }
      }
    }
  }
  return v6;
}
