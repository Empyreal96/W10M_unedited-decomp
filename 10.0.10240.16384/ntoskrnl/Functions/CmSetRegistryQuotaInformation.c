// CmSetRegistryQuotaInformation 
 
int __fastcall CmSetRegistryQuotaInformation(unsigned int *a1)
{
  unsigned int v1; // r0

  v1 = *a1;
  CmpQuotaExplicitlySet = 1;
  if ( v1 > 0x7FFFFFFF )
    v1 = 0x7FFFFFFF;
  if ( v1 < 0x1000000 )
    v1 = 0x1000000;
  CmpGlobalQuota = v1;
  CmpGlobalQuotaWarning = 95 * (v1 / 0x64);
  CmpGlobalQuotaAllowed = v1;
  return 0;
}
