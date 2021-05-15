// ExDeleteNPagedLookasideList 
 
int __fastcall ExDeleteNPagedLookasideList(unsigned __int64 *a1)
{
  int result; // r0

  ExpRemoveGeneralLookaside((unsigned int *)&ExNPagedLookasideLock, (int)a1);
  result = RtlpInterlockedFlushSList(a1);
  if ( result )
    result = sub_554EC4();
  return result;
}
