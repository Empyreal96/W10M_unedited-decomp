// FsRtlAllocatePoolWithQuotaTag 
 
int __fastcall FsRtlAllocatePoolWithQuotaTag(unsigned int a1, unsigned int a2, int a3)
{
  int result; // r0

  result = ExAllocatePoolWithQuotaTag(a1, a2, a3);
  if ( !result )
    RtlRaiseStatus(-1073741670);
  return result;
}
