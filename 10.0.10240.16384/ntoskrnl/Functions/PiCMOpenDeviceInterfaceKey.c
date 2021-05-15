// PiCMOpenDeviceInterfaceKey 
 
int __fastcall PiCMOpenDeviceInterfaceKey(int a1, int a2, int a3, unsigned int a4, int a5, _DWORD *a6)
{
  int v8; // r8
  int v9; // r5
  unsigned __int16 *v10; // r5
  int v11; // r4
  int v12; // r6
  int v13; // r1
  int v15; // [sp+10h] [bp-50h] BYREF
  int v16; // [sp+14h] [bp-4Ch] BYREF
  int v17; // [sp+18h] [bp-48h] BYREF
  char v18[4]; // [sp+20h] [bp-40h] BYREF
  int v19; // [sp+24h] [bp-3Ch]
  int v20; // [sp+28h] [bp-38h]
  unsigned __int16 *v21; // [sp+2Ch] [bp-34h]
  int v22; // [sp+34h] [bp-2Ch]
  int v23; // [sp+38h] [bp-28h]
  int v24; // [sp+3Ch] [bp-24h]
  int v25; // [sp+40h] [bp-20h]

  *a6 = 0;
  v16 = 0;
  v17 = 0;
  v15 = 0;
  v8 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v9 = PiCMCaptureRegistryInputData(a1, a2, a3, v18);
  if ( v9 >= 0 )
  {
    v10 = v21;
    if ( v21 && !v19 && v20 == 4 && !v24 && a3 && a4 >= 0x10 )
    {
      v11 = CmOpenDeviceInterfaceRegKey((int *)PiPnpRtlCtx, v21, 48, 1, 1, 0, (int)&v17, 0);
      if ( v11 == -1073741772 )
        v11 = -1073741127;
      if ( v11 >= 0 )
      {
        v12 = v22;
        v11 = CmOpenDeviceInterfaceRegKey((int *)PiPnpRtlCtx, v10, 50, (int)&v15, v22, v23 == 1, (int)&v15, 0);
        if ( v11 >= 0 )
          v11 = PiCMDuplicateRegistryHandle(v15, v13, v12, v8, &v16);
      }
    }
    else
    {
      v11 = -1073741811;
    }
    v9 = PiCMReturnHandleResultData(v11, v16, v25, a3, a4, a6);
    if ( v17 )
      ZwClose();
    if ( v15 )
      ZwClose();
    if ( v9 < 0 || v11 < 0 )
      return sub_7E79DC();
  }
  PiCMReleaseObjectInputData(v18);
  return v9;
}
