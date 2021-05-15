// ExDeletePagedLookasideList 
 
_DWORD *__fastcall ExDeletePagedLookasideList(int a1)
{
  _DWORD *result; // r0
  _DWORD *v3; // r4

  ExpRemoveGeneralLookaside(&ExPagedLookasideLock, a1);
  result = (_DWORD *)RtlpInterlockedFlushSList((unsigned __int64 *)a1);
  if ( result )
  {
    do
    {
      v3 = (_DWORD *)*result;
      (*(void (**)(void))(a1 + 44))();
      result = v3;
    }
    while ( v3 );
  }
  return result;
}
