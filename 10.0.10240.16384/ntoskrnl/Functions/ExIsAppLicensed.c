// ExIsAppLicensed 
 
int __fastcall ExIsAppLicensed(int a1)
{
  int result; // r0
  unsigned int v2; // [sp+8h] [bp-18h] BYREF
  _DWORD v3[4]; // [sp+10h] [bp-10h] BYREF

  v3[0] = 0;
  v3[1] = 0;
  result = sub_6E3370(0, a1, 0, 8u, (int)v3, &v2, 0);
  if ( result >= 0 )
    result = sub_81C92C();
  return result;
}
