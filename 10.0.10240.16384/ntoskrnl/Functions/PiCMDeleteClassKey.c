// PiCMDeleteClassKey 
 
int __fastcall PiCMDeleteClassKey(unsigned int a1, unsigned int a2, _DWORD *a3, unsigned int a4, int a5, _DWORD *a6)
{
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r4
  int v12; // r0
  char v14[4]; // [sp+8h] [bp-30h] BYREF
  int v15; // [sp+Ch] [bp-2Ch]
  int v16; // [sp+10h] [bp-28h]
  int v17; // [sp+14h] [bp-24h]
  int v18; // [sp+1Ch] [bp-1Ch]
  int v19; // [sp+20h] [bp-18h]

  *a6 = 0;
  v11 = PiCMCaptureObjectInputData(a1, a2, (int)a3, (int)v14);
  if ( v11 >= 0 )
  {
    if ( PiAuDoesClientHaveAccess(2, v8, v9, v10) )
    {
      if ( v17 && !v18 && a3 && a4 >= 8 && (v16 == 2 || v16 == 3) && (unsigned int)(v15 - 1) <= 1 )
      {
        if ( v16 == 3 )
          v12 = CmDeleteInterfaceClass(PiPnpRtlCtx, v17, 0);
        else
          v12 = CmDeleteInstallerClass(PiPnpRtlCtx, v17, 0);
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
    v11 = PiCMReturnBasicResultData(v12, v19, a3, a4, a6);
  }
  PiCMReleaseObjectInputData((int)v14);
  return v11;
}
