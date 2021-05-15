// RtlpHpAllocWithExceptionProtection 
 
int __fastcall RtlpHpAllocWithExceptionProtection(int a1, unsigned int a2, int a3)
{
  return RtlpAllocateHeapInternal(a1, a2, a3);
}
