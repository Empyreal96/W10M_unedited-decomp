// PiCMGetDeviceDepth 
 
int __fastcall PiCMGetDeviceDepth(unsigned int a1, unsigned int a2, int a3, unsigned int a4, int a5, _DWORD *a6)
{
  int v7; // r7
  int v9; // r2
  int v10; // r4
  unsigned __int16 *v11; // r4
  int v12; // r0
  int v14; // [sp+8h] [bp-40h] BYREF
  char v15[8]; // [sp+10h] [bp-38h] BYREF
  char v16[4]; // [sp+18h] [bp-30h] BYREF
  int v17; // [sp+1Ch] [bp-2Ch]
  int v18; // [sp+20h] [bp-28h]
  unsigned __int16 *v19; // [sp+24h] [bp-24h]
  int v20; // [sp+2Ch] [bp-1Ch]
  int v21; // [sp+30h] [bp-18h]

  *a6 = 0;
  v7 = 0;
  v14 = 0;
  v10 = PiCMCaptureObjectInputData(a1, a2, a3, (int)v16);
  if ( v10 >= 0 )
  {
    v11 = v19;
    if ( v19 && !v17 && v18 == 1 && !v20 && a3 && a4 >= 0xC )
    {
      v12 = CmValidateDeviceName(0, v19, v9, 0);
      if ( v12 >= 0 )
      {
        v12 = RtlInitUnicodeStringEx((int)v15, v11);
        if ( v12 >= 0 )
        {
          v12 = PiGetDeviceDepth(v15, &v14);
          v7 = v14;
        }
      }
    }
    else
    {
      v12 = -1073741811;
    }
    v10 = PiCMReturnDepthResultData(v12, v7, v21, a3, a4, a6);
  }
  PiCMReleaseObjectInputData((int)v16);
  return v10;
}
