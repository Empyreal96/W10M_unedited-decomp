// CmpReleaseGlobalQuota 
 
unsigned int __fastcall CmpReleaseGlobalQuota(unsigned int a1)
{
  int v1; // r2
  unsigned int result; // r0

  if ( a1 > CmpGlobalQuotaUsed )
    sub_805AB0();
  __dmb(0xBu);
  v1 = -a1;
  do
    result = __ldrex((unsigned int *)&CmpGlobalQuotaUsed);
  while ( __strex(result + v1, (unsigned int *)&CmpGlobalQuotaUsed) );
  __dmb(0xBu);
  return result;
}
