// ExFreeToPagedLookasideList 
 
int __fastcall ExFreeToPagedLookasideList(int a1, _DWORD *a2)
{
  unsigned int v2; // r2

  v2 = *(unsigned __int16 *)(a1 + 8);
  ++*(_DWORD *)(a1 + 20);
  if ( *(unsigned __int16 *)(a1 + 4) < v2 )
    return RtlpInterlockedPushEntrySList((unsigned __int64 *)a1, a2);
  ++*(_DWORD *)(a1 + 24);
  return (*(int (__fastcall **)(_DWORD *))(a1 + 44))(a2);
}
