// ExDeleteLookasideListEx 
 
int __fastcall ExDeleteLookasideListEx(int a1)
{
  int *v2; // r0
  int result; // r0

  if ( (*(_DWORD *)(a1 + 28) & 1) != 0 )
    v2 = &ExPagedLookasideLock;
  else
    v2 = &ExNPagedLookasideLock;
  ExpRemoveGeneralLookaside(v2, a1);
  result = RtlpInterlockedFlushSList((unsigned __int64 *)a1);
  if ( result )
    result = sub_524DD4();
  return result;
}
