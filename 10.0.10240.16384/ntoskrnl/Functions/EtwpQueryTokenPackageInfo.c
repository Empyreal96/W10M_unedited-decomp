// EtwpQueryTokenPackageInfo 
 
int __fastcall EtwpQueryTokenPackageInfo(int a1, int a2, _DWORD *a3)
{
  int v6; // r4
  int result; // r0
  int v8; // r5

  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 4) = 0;
  v6 = SeSecurityAttributePresent(a1, &PspSysAppIdClaim);
  result = SeSecurityAttributePresent(a1, &PspPackagedAppClaim);
  v8 = result;
  if ( v6 )
  {
    *a3 |= 1u;
    *(_DWORD *)a2 = 256;
    *(_DWORD *)(a2 + 4) = 130;
    result = RtlQueryPackageIdentity(a1, a2 + 8, a2, a2 + 264, a2 + 4, 0);
    if ( result < 0 )
      return sub_7C36F4();
    if ( v8 )
      *a3 |= 8u;
  }
  if ( !*(_DWORD *)a2 )
  {
    *(_DWORD *)a2 = 2;
    *(_WORD *)(a2 + 8) = 0;
  }
  if ( !*(_DWORD *)(a2 + 4) )
  {
    *(_DWORD *)(a2 + 4) = 2;
    *(_WORD *)(a2 + 264) = 0;
  }
  return result;
}
