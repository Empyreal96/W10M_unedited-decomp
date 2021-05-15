// PsQueryProcessAttributesByToken 
 
int __fastcall PsQueryProcessAttributesByToken(int result, _BYTE *a2, _BYTE *a3)
{
  int v5; // r5

  v5 = result;
  if ( a2 )
  {
    result = SeSecurityAttributePresent(result, &PspSysAppIdClaim);
    *a2 = result;
  }
  if ( a3 )
  {
    result = SeSecurityAttributePresent(v5, &PspPackagedAppClaim);
    *a3 = result;
  }
  return result;
}
