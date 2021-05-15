// RtlpInterlockedFlushSList 
 
int __fastcall RtlpInterlockedFlushSList(unsigned __int64 *a1)
{
  unsigned __int64 v1; // r2

  do
    v1 = __ldrexd(a1);
  while ( __strexd(0i64, a1) == 1 );
  return v1;
}
