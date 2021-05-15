// PiCMDeviceAction 
 
int __fastcall PiCMDeviceAction(unsigned int a1, unsigned int a2, int a3, unsigned int a4, int a5, _DWORD *a6)
{
  int v7; // r0
  int v8; // r2
  int v9; // r4
  unsigned __int16 *v10; // r7
  int v12; // r5
  int v13; // r1
  int v14; // r2
  int v15; // r1
  int v16; // r2
  int v17; // r3
  int v18; // [sp+14h] [bp-54h] BYREF
  int v19; // [sp+18h] [bp-50h]
  int v20; // [sp+1Ch] [bp-4Ch] BYREF
  int v21; // [sp+20h] [bp-48h] BYREF
  char v22[8]; // [sp+28h] [bp-40h] BYREF
  char v23[4]; // [sp+30h] [bp-38h] BYREF
  int v24; // [sp+34h] [bp-34h]
  int v25; // [sp+38h] [bp-30h]
  unsigned __int16 *v26; // [sp+3Ch] [bp-2Ch]
  int v27; // [sp+44h] [bp-24h]
  int v28; // [sp+48h] [bp-20h]

  v19 = a3;
  *a6 = 0;
  v18 = 0;
  v20 = 0;
  v21 = 0;
  v7 = PiCMCaptureObjectInputData(a1, a2, 0, (int)v23);
  v9 = v7;
  if ( v7 < 0 )
    goto LABEL_25;
  v10 = v26;
  if ( !v26 || v25 != 1 || !v19 || a4 < 8 )
    JUMPOUT(0x7DEC6A);
  if ( v27 != 1 )
    return sub_7DEB78();
  v12 = v24;
  if ( v24 <= 0 || v24 >= 7 )
    v9 = -1073741811;
  if ( v9 >= 0 )
  {
    v9 = CmValidateDeviceName(v7, v26, v8, v19);
    if ( v9 >= 0 )
    {
      if ( v12 <= 0 )
      {
LABEL_28:
        v9 = -1073741811;
        goto LABEL_24;
      }
      if ( v12 > 2 )
        JUMPOUT(0x7DEBD8);
      if ( PiAuDoesClientHaveAccess(32) && PiAuDoesClientHavePrivilege(10, v13, v14) )
      {
        if ( !CmIsRootDevice(v10, v15, v16, v17) )
        {
          if ( CmGetDeviceStatus(PiPnpRtlCtx, v10, 0, &v18, &v21, &v20) < 0
            || (v18 & 8) == 0 && ((v18 & 0x400) == 0 || (v9 = PiCMSetProblem(v10, 0, 1), v9 >= 0)) )
          {
            v9 = RtlInitUnicodeStringEx((int)v22, v10);
            if ( v9 >= 0 )
            {
              if ( v12 != 1 )
                JUMPOUT(0x7DEC5E);
              v9 = PiQueueDeviceRequest(v22, 16);
            }
          }
          goto LABEL_24;
        }
        goto LABEL_28;
      }
      v9 = -1073741790;
    }
  }
LABEL_24:
  v9 = PiCMReturnBasicResultData(v9, v28, v19, a4, a6);
LABEL_25:
  PiCMReleaseObjectInputData((int)v23);
  return v9;
}
