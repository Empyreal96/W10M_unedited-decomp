// PiCMGetDeviceStatus 
 
int __fastcall PiCMGetDeviceStatus(int a1, int a2, int a3, unsigned int a4, int a5, _DWORD *a6)
{
  int v8; // r4
  int v9; // r0
  int v11; // [sp+10h] [bp-40h] BYREF
  int v12; // [sp+14h] [bp-3Ch] BYREF
  int v13; // [sp+18h] [bp-38h] BYREF
  char v14[4]; // [sp+20h] [bp-30h] BYREF
  int v15; // [sp+24h] [bp-2Ch]
  int v16; // [sp+28h] [bp-28h]
  unsigned __int16 *v17; // [sp+2Ch] [bp-24h]
  int v18; // [sp+34h] [bp-1Ch]
  int v19; // [sp+38h] [bp-18h]

  *a6 = 0;
  v12 = 0;
  v13 = 0;
  v11 = 0;
  v8 = PiCMCaptureObjectInputData(a1, a2, a3, v14);
  if ( v8 >= 0 )
  {
    if ( v17 && !v15 && v16 == 1 && !v18 && a3 && a4 >= 0x14 )
      v9 = CmGetDeviceStatus(PiPnpRtlCtx, v17, 0, &v13, &v12, &v11);
    else
      v9 = -1073741811;
    v8 = PiCMReturnStatusResultData(v9, v13, v12, v11, v19, a3, a4, a6);
  }
  PiCMReleaseObjectInputData((int)v14);
  return v8;
}
