// RtlQueryPackageIdentity 
 
int __fastcall RtlQueryPackageIdentity(int a1, int a2, int a3, int a4, int a5, _BYTE *a6)
{
  int result; // r0

  result = RtlQueryPackageClaims(a1, a2, a3);
  if ( result >= 0 )
  {
    if ( a6 )
      *a6 = 0;
  }
  return result;
}
