// PiCMDeleteDeviceKey 
 
int __fastcall PiCMDeleteDeviceKey(unsigned int a1, unsigned int a2, _DWORD *a3, unsigned int a4, int a5, _DWORD *a6)
{
  _DWORD *v6; // r5
  int v9; // r1
  int v10; // r2
  int v11; // r3
  int v12; // r4
  int v13; // r4
  int v14; // r6
  __int16 v15; // r5
  int v16; // r0
  int v17; // r7
  int v18; // r5
  int v20; // [sp+Ch] [bp-6Ch] BYREF
  int v21; // [sp+10h] [bp-68h]
  int v22; // [sp+14h] [bp-64h] BYREF
  int v23; // [sp+18h] [bp-60h] BYREF
  char v24[4]; // [sp+20h] [bp-58h] BYREF
  int v25; // [sp+24h] [bp-54h]
  int v26; // [sp+28h] [bp-50h]
  int v27; // [sp+2Ch] [bp-4Ch]
  int v28; // [sp+34h] [bp-44h]
  int v29; // [sp+38h] [bp-40h]
  unsigned __int16 v30[4]; // [sp+40h] [bp-38h] BYREF
  unsigned __int16 v31[24]; // [sp+48h] [bp-30h] BYREF

  v6 = a6;
  *a6 = 0;
  v20 = 0;
  v21 = 0;
  v22 = 0;
  v23 = 0;
  v12 = PiCMCaptureObjectInputData(a1, a2, (int)a3, (int)v24);
  if ( v12 >= 0 )
  {
    if ( PiAuDoesClientHaveAccess(2, v9, v10, v11) )
    {
      v14 = v27;
      if ( v27 && v26 == 1 && a3 && a4 >= 8 )
      {
        v15 = v25;
        v13 = PiCMConvertDeviceKeyType(v25, &v22);
        if ( v13 >= 0 )
        {
          if ( (v15 & 0xFF00) == 512 && v28 == -1 )
          {
            if ( PnpCtxGetCachedContextBaseKey((_DWORD *)PiPnpRtlCtx, 4, &v20) >= 0 )
            {
              v16 = PnpCtxRegOpenKey((int *)PiPnpRtlCtx, v20, (int)L"Control\\IDConfigDB\\Hardware Profiles", 0);
              v17 = 0;
              if ( v16 >= 0 )
              {
                do
                {
                  if ( v13 < 0 )
                    break;
                  v20 = 5;
                  v16 = PnpCtxRegEnumKey(v16, v21, v17, (int)v31, (unsigned int *)&v20);
                  v18 = v16;
                  if ( v16 >= 0 )
                  {
                    v16 = RtlInitUnicodeStringEx((int)v30, v31);
                    v18 = v16;
                    if ( v16 >= 0 )
                    {
                      v16 = RtlUnicodeStringToInteger(v30, 0, &v23);
                      v18 = v16;
                      if ( v16 >= 0 )
                      {
                        v16 = CmDeleteDeviceRegKey(PiPnpRtlCtx, v14, v22, v23);
                        v13 = v16;
                        if ( v16 == -1073741772 )
                          v13 = 0;
                      }
                    }
                  }
                  ++v17;
                }
                while ( v18 >= 0 );
              }
            }
          }
          else
          {
            v13 = CmDeleteDeviceRegKey(PiPnpRtlCtx, v14, v22, v28);
          }
        }
        v6 = a6;
      }
      else
      {
        v13 = -1073741811;
      }
    }
    else
    {
      v13 = -1073741790;
    }
    if ( v21 )
      ZwClose();
    v12 = PiCMReturnBasicResultData(v13, v29, a3, a4, v6);
  }
  PiCMReleaseObjectInputData((int)v24);
  return v12;
}
