// PnprLegacyDeviceDriversPresent 
 
int __fastcall PnprLegacyDeviceDriversPresent(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  unsigned int v6; // [sp+0h] [bp-10h] BYREF
  int v7[3]; // [sp+4h] [bp-Ch] BYREF

  v7[0] = a3;
  v7[1] = a4;
  v6 = 0;
  v4 = 0;
  if ( IoGetLegacyVetoList(&v6, v7) >= 0 && v7[0] )
    v4 = 1;
  if ( v6 )
    ExFreePoolWithTag(v6);
  return v4;
}
