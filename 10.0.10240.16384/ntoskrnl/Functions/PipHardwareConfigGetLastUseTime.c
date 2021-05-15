// PipHardwareConfigGetLastUseTime 
 
int __fastcall PipHardwareConfigGetLastUseTime(int a1, int a2)
{
  int v3; // r4
  int v4; // r0
  int v5; // r5
  int v7; // [sp+8h] [bp-18h] BYREF
  int v8[5]; // [sp+Ch] [bp-14h] BYREF

  v7 = 0;
  if ( !a2 )
    return -1073741811;
  v4 = PipHardwareConfigOpenKey(a1, a2, &v7);
  v3 = v4;
  v5 = v7;
  if ( v4 >= 0 )
  {
    v7 = 8;
    v3 = PnpCtxRegQueryValue(v4, v5, L"LastUse", v8, a2, (unsigned int *)&v7);
  }
  if ( v5 )
    ZwClose();
  return v3;
}
