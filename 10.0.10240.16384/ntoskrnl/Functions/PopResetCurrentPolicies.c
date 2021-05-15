// PopResetCurrentPolicies 
 
int PopResetCurrentPolicies()
{
  int v0; // r4
  int v2; // [sp+8h] [bp-110h]
  int v3; // [sp+Ch] [bp-10Ch] BYREF
  char v4[8]; // [sp+10h] [bp-108h] BYREF
  int v5; // [sp+18h] [bp-100h]
  char v6[252]; // [sp+1Ch] [bp-FCh] BYREF

  v5 = 0;
  memset(v6, 0, 244);
  v0 = PopOpenPowerKey((int)&v3);
  if ( v0 >= 0 )
  {
    RtlInitUnicodeString((unsigned int)v4, L"SystemPowerPolicy");
    v0 = ZwQueryValueKey();
    if ( v0 < 0 )
      return sub_7F1D80();
    PopApplyPolicy(0, 0, &v6[8], v2 - 12);
    ZwClose();
  }
  return v0;
}
