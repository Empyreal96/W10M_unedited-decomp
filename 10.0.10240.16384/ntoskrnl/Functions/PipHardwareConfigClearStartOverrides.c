// PipHardwareConfigClearStartOverrides 
 
int PipHardwareConfigClearStartOverrides()
{
  int result; // r0
  int v1; // [sp+10h] [bp-98h] BYREF
  char v2[144]; // [sp+18h] [bp-90h] BYREF

  result = PnpCtxGetCachedContextBaseKey((_DWORD *)PiPnpRtlCtx, 6, &v1);
  if ( result >= 0 )
  {
    result = RtlStringCchPrintfExW((int)v2, 64, 0, 0, 2048, L"%d");
    if ( result >= 0 )
      result = PnpCtxRegEnumKeyWithCallback(
                 (int *)PiPnpRtlCtx,
                 v1,
                 (int)PipHardwareConfigClearStartOverrideCallback,
                 (int)v2);
  }
  return result;
}
