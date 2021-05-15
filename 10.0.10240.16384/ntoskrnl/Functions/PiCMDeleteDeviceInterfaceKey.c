// PiCMDeleteDeviceInterfaceKey 
 
int __fastcall PiCMDeleteDeviceInterfaceKey(unsigned int a1, unsigned int a2, _DWORD *a3, unsigned int a4, int a5, _DWORD *a6)
{
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r4
  int v12; // r4
  unsigned __int16 *v13; // r5
  int v15[2]; // [sp+10h] [bp-40h] BYREF
  char v16[4]; // [sp+18h] [bp-38h] BYREF
  int v17; // [sp+1Ch] [bp-34h]
  int v18; // [sp+20h] [bp-30h]
  unsigned __int16 *v19; // [sp+24h] [bp-2Ch]
  int v20; // [sp+2Ch] [bp-24h]
  int v21; // [sp+30h] [bp-20h]

  v15[0] = 0;
  *a6 = 0;
  v11 = PiCMCaptureObjectInputData(a1, a2, (int)a3, (int)v16);
  if ( v11 >= 0 )
  {
    if ( PiAuDoesClientHaveAccess(2, v8, v9, v10) )
    {
      v13 = v19;
      if ( v19 && !v17 && v18 == 4 && !v20 && a3 && a4 >= 8 )
      {
        v12 = CmOpenDeviceInterfaceRegKey((int *)PiPnpRtlCtx, v19, 48, (int)v15, 1, 0, (int)v15, 0);
        if ( v12 == -1073741772 )
          v12 = -1073741127;
        if ( v12 >= 0 )
          v12 = CmDeleteDeviceInterfaceRegKey(PiPnpRtlCtx, v13, 50);
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
    if ( v15[0] )
      ZwClose();
    v11 = PiCMReturnBasicResultData(v12, v21, a3, a4, a6);
  }
  PiCMReleaseObjectInputData((int)v16);
  return v11;
}
