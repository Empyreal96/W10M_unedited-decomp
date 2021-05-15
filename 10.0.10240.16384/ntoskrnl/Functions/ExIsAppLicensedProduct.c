// ExIsAppLicensedProduct 
 
int __fastcall ExIsAppLicensedProduct(int a1)
{
  int result; // r0
  unsigned int v3; // [sp+8h] [bp-38h] BYREF
  int v4; // [sp+10h] [bp-30h] BYREF
  char v5[32]; // [sp+14h] [bp-2Ch] BYREF

  v4 = 0;
  memset(v5, 0, sizeof(v5));
  result = sub_6E3370(1, a1, 0, 0x24u, (int)&v4, &v3, 0);
  if ( result >= 0 )
    result = sub_81C700();
  return result;
}
