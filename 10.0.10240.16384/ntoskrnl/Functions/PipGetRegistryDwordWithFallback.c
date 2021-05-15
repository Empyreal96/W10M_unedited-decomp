// PipGetRegistryDwordWithFallback 
 
int __fastcall PipGetRegistryDwordWithFallback(int a1, int a2, int a3, int a4, int a5, _DWORD *a6)
{
  int v8; // r5
  int v10; // [sp+10h] [bp-20h] BYREF
  int v11; // [sp+14h] [bp-1Ch] BYREF
  int v12[6]; // [sp+18h] [bp-18h] BYREF

  v11 = 0;
  v12[0] = 0;
  v10 = 4;
  v8 = 0;
  if ( CmGetDeviceRegProp(PiPnpRtlCtx, a2, a3, a1, (int)&v11, (int)v12, (int)&v10) >= 0 && v11 == 4 && v10 == 4
    || a5
    && (v10 = 4, CmGetInstallerClassRegProp(PiPnpRtlCtx, a4, a5, a1, &v11, v12, &v10) >= 0)
    && v11 == 4
    && v10 == 4 )
  {
    v8 = 1;
    *a6 = v12[0];
  }
  return v8;
}
