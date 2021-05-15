// PipGetRegistrySecurityWithFallback 
 
unsigned int __fastcall PipGetRegistrySecurityWithFallback(int a1, int a2, int a3, int a4, int a5)
{
  unsigned int v7; // r6
  int v8; // r7
  int v9; // r5
  int v10; // r0
  int v11; // r8
  int v12; // r0
  int v13; // r0
  int v15; // r0
  int v16; // [sp+10h] [bp-30h] BYREF
  int v17; // [sp+14h] [bp-2Ch] BYREF
  unsigned int v18; // [sp+18h] [bp-28h] BYREF
  int v19; // [sp+1Ch] [bp-24h]

  v19 = a4;
  v17 = 0;
  v7 = 0;
  v16 = 128;
  v18 = 0;
  v8 = 0;
  v9 = ExAllocatePoolWithTag(1, 128, 1852141648);
  if ( !v9 )
    return 0;
  v10 = CmGetDeviceRegProp(PiPnpRtlCtx, a2, a3, 24, (int)&v17, v9, (int)&v16);
  if ( v10 == -1073741789 )
  {
    ExFreePoolWithTag(v9);
    v9 = ExAllocatePoolWithTag(1, v16, 1852141648);
    if ( !v9 )
      return 0;
    v10 = CmGetDeviceRegProp(PiPnpRtlCtx, a2, a3, 24, (int)&v17, v9, (int)&v16);
  }
  if ( v10 >= 0 && v17 == 3 )
  {
    if ( RtlValidRelativeSecurityDescriptor(v9, v16, 0, 3) )
    {
      v15 = SeCaptureSecurityDescriptor(v9, 0, 1, 1, &v18);
      v7 = v18;
      if ( v15 >= 0 )
        goto LABEL_10;
    }
  }
  if ( a5 )
  {
    v11 = v19;
    v12 = CmGetInstallerClassRegProp(PiPnpRtlCtx, v19, a5, 24, (int)&v17, v9, (int)&v16);
    if ( v12 == -1073741789 )
    {
      ExFreePoolWithTag(v9);
      v9 = ExAllocatePoolWithTag(1, v16, 1852141648);
      if ( !v9 )
        return 0;
      v12 = CmGetInstallerClassRegProp(PiPnpRtlCtx, v11, a5, 24, (int)&v17, v9, (int)&v16);
    }
    if ( v12 >= 0 && v17 == 3 )
    {
      if ( RtlValidRelativeSecurityDescriptor(v9, v16, 0, 3) )
      {
        v13 = SeCaptureSecurityDescriptor(v9, 0, 1, 1, &v18);
        v7 = v18;
        if ( v13 >= 0 )
LABEL_10:
          v8 = 1;
      }
    }
  }
  ExFreePoolWithTag(v9);
  if ( !v8 )
    return 0;
  return v7;
}
