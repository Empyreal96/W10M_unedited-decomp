// FsRtlAllocatePoolWithQuota 
 
int __fastcall FsRtlAllocatePoolWithQuota(unsigned int a1, unsigned int a2)
{
  int result; // r0

  result = ExAllocatePoolWithQuotaTag(a1, a2, 1953649478);
  if ( !result )
    RtlRaiseStatus(-1073741670);
  return result;
}
