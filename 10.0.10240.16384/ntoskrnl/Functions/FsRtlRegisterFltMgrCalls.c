// FsRtlRegisterFltMgrCalls 
 
unsigned int __fastcall FsRtlRegisterFltMgrCalls(unsigned int result)
{
  unsigned int v1; // r1

  __dmb(0xBu);
  do
    v1 = __ldrex((unsigned int *)&FltMgrCallbacks);
  while ( __strex(result, (unsigned int *)&FltMgrCallbacks) );
  __dmb(0xBu);
  return result;
}
