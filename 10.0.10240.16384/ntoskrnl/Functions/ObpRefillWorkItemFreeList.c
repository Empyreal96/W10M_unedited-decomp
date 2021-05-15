// ObpRefillWorkItemFreeList 
 
_DWORD *ObpRefillWorkItemFreeList()
{
  int v0; // r4
  _DWORD *result; // r0

  v0 = 100;
  do
  {
    result = (_DWORD *)ExAllocatePoolWithTag(512, 88, 1951556175);
    if ( result )
      result = (_DWORD *)RtlpInterlockedPushEntrySList((unsigned __int64 *)&ObpWorkItemFreeList, result);
    --v0;
  }
  while ( v0 );
  return result;
}
