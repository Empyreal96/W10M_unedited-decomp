// PipHardwareConfigActivateService 
 
int __fastcall PipHardwareConfigActivateService(unsigned __int16 *a1)
{
  int v1; // r4
  int v2; // r5
  int v4; // [sp+8h] [bp-18h] BYREF
  char v5[16]; // [sp+10h] [bp-10h] BYREF

  v4 = 0;
  if ( !a1 )
    return -1073741811;
  RtlInitUnicodeString((unsigned int)v5, a1);
  v1 = PipOpenServiceEnumKeys((int)v5, 0x10000, &v4, 0, 0);
  v2 = v4;
  if ( v1 >= 0 )
  {
    v1 = PnpCtxRegDeleteTree(PiPnpRtlCtx, v4, L"StartOverride");
    if ( v1 == -1073741772 )
      v1 = 0;
  }
  if ( v2 )
    ZwClose();
  return v1;
}
