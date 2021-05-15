// PipHardwareConfigGetIndex 
 
int __fastcall PipHardwareConfigGetIndex(int a1, int a2)
{
  int v3; // r0
  int v4; // r4
  int v5; // r5
  int v7; // [sp+8h] [bp-18h] BYREF
  int v8[5]; // [sp+Ch] [bp-14h] BYREF

  v7 = 0;
  if ( !a2 )
    return -1073741811;
  v3 = PipHardwareConfigOpenKey(a1, a2, &v7);
  v4 = v3;
  v5 = v7;
  if ( v3 >= 0 )
  {
    v7 = 4;
    v4 = PnpCtxRegQueryValue(v3, v5, L"Id", v8, a2, (unsigned int *)&v7);
  }
  if ( v5 )
    ZwClose();
  return v4;
}
