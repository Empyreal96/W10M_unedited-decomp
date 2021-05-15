// PiCMValidateDeviceInstance 
 
int __fastcall PiCMValidateDeviceInstance(unsigned int a1, unsigned int a2, int a3, unsigned int a4, int a5, _DWORD *a6)
{
  int v8; // r4
  unsigned __int16 *v9; // r6
  int v10; // r5
  int v11; // r1
  int v12; // r2
  int v13; // r3
  int v14; // r4
  int v15; // r0
  char v17[4]; // [sp+10h] [bp-68h] BYREF
  int v18; // [sp+14h] [bp-64h] BYREF
  unsigned int v19; // [sp+18h] [bp-60h] BYREF
  int v20; // [sp+1Ch] [bp-5Ch] BYREF
  char v21[4]; // [sp+20h] [bp-58h] BYREF
  int v22; // [sp+24h] [bp-54h] BYREF
  int v23; // [sp+28h] [bp-50h] BYREF
  int v24; // [sp+2Ch] [bp-4Ch] BYREF
  int v25[4]; // [sp+30h] [bp-48h] BYREF
  char v26[4]; // [sp+40h] [bp-38h] BYREF
  int v27; // [sp+44h] [bp-34h]
  int v28; // [sp+48h] [bp-30h]
  unsigned __int16 *v29; // [sp+4Ch] [bp-2Ch]
  int v30; // [sp+54h] [bp-24h]
  int v31; // [sp+58h] [bp-20h]

  v17[0] = 1;
  v18 = 0;
  *a6 = 0;
  v8 = PiCMCaptureObjectInputData(a1, a2, a3, (int)v26);
  if ( v8 >= 0 )
  {
    v9 = v29;
    if ( v29 && (v10 = v27, (unsigned int)(v27 - 1) <= 1) && v28 == 1 && !v30 && a3 && a4 >= 8 )
    {
      v14 = PnpOpenObjectRegKey(PiPnpRtlCtx, (int)v29, 1, 1, 0, (int)&v18, 0, 0);
      if ( v14 >= 0 )
      {
        if ( v10 == 2 )
        {
          v15 = PiAuDoesClientHaveAccess(2);
          if ( v15 )
          {
LABEL_11:
            v19 = 4;
            if ( PnpCtxRegQueryValue(v15, v18, L"Phantom", &v20, (int)v21, &v19) >= 0 )
              return sub_7DED4C();
            goto LABEL_13;
          }
        }
        SeCaptureSubjectContext(v25, v11, v12, v13);
        v14 = PiPnpRtlApplyMandatoryFilters(PiPnpRtlCtx, (int)v9, 1, v18, v25, v17);
        v15 = SeReleaseSubjectContext((int)v25);
        if ( v14 >= 0 )
        {
          if ( !v17[0] )
            goto LABEL_21;
          if ( v10 == 2 )
            goto LABEL_11;
          if ( CmGetDeviceStatus(PiPnpRtlCtx, v9, v18, &v24, &v23, &v22) < 0 )
LABEL_21:
            v14 = -1073741810;
        }
      }
    }
    else
    {
      v14 = -1073741811;
    }
LABEL_13:
    if ( v18 )
      ZwClose();
    v8 = PiCMReturnBasicResultData(v14, v31, a3, a4, a6);
  }
  PiCMReleaseObjectInputData((int)v26);
  return v8;
}
