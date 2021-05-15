// PspNotifyEmptyJobsInJobChain 
 
int __fastcall PspNotifyEmptyJobsInJobChain(int result)
{
  unsigned __int8 *v1; // r3
  unsigned int v2; // r1
  BOOL v3; // r5
  int v4; // r4

  __dmb(0xBu);
  v1 = (unsigned __int8 *)(result + 189);
  do
    v2 = __ldrex(v1);
  while ( __strex(v2 | 8, v1) );
  __dmb(0xBu);
  v3 = (unsigned __int8)(v2 & 8) >> 3 == 0;
  v4 = *(_DWORD *)(result + 288);
  __dmb(0xBu);
  while ( v4 )
  {
    result = PspEvaluateAndNotifyEmptyJob(v4, v3, 1);
    v4 = *(_DWORD *)(v4 + 572);
  }
  return result;
}
