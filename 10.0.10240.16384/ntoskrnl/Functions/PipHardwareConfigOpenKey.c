// PipHardwareConfigOpenKey 
 
int __fastcall PipHardwareConfigOpenKey(int a1, int a2, _DWORD *a3)
{
  int v4; // r4
  unsigned __int16 v6[268]; // [sp+10h] [bp-218h] BYREF

  if ( !a3 )
    return -1073741811;
  v4 = RtlStringCchCopyExW(v6, 260, L"System\\HardwareConfig\\");
  if ( v4 >= 0 )
  {
    v4 = RtlStringCchCatExW(v6, 0x104u, L"Current");
    if ( v4 >= 0 )
    {
      v4 = PnpCtxRegOpenKey((int *)PiPnpRtlCtx, -2147483646, (int)v6, 0);
      if ( v4 >= 0 )
        *a3 = 0;
    }
  }
  return v4;
}
