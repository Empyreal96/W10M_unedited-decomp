// CmpClaimGlobalQuota 
 
int __fastcall CmpClaimGlobalQuota(int a1)
{
  unsigned int v2; // r1
  int result; // r0

  CmpUpdateGlobalQuotaAllowed();
  if ( a1 <= 0 || a1 >= CmpGlobalQuotaAllowed - CmpGlobalQuotaUsed )
    return 0;
  __dmb(0xBu);
  do
    v2 = __ldrex((unsigned int *)&CmpGlobalQuotaUsed);
  while ( __strex(v2 + a1, (unsigned int *)&CmpGlobalQuotaUsed) );
  __dmb(0xBu);
  if ( CmpGlobalQuotaUsed <= (unsigned int)CmpGlobalQuotaWarning )
    result = 1;
  else
    result = sub_805AE4();
  return result;
}
