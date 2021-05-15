// FsRtlRegisterMupCalls 
 
unsigned int __fastcall FsRtlRegisterMupCalls(unsigned int result)
{
  unsigned int v1; // r1

  __dmb(0xBu);
  do
    v1 = __ldrex((unsigned int *)&pFsRtlpMupCalls);
  while ( __strex(result, (unsigned int *)&pFsRtlpMupCalls) );
  __dmb(0xBu);
  return result;
}
