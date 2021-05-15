// ExAllocateFromNPagedLookasideList 
 
int __fastcall ExAllocateFromNPagedLookasideList(int a1)
{
  int result; // r0
  __int64 v3; // kr00_8
  int v4; // r0

  ++*(_DWORD *)(a1 + 12);
  result = RtlpInterlockedPopEntrySList((unsigned __int64 *)a1);
  if ( !result )
  {
    v3 = *(_QWORD *)(a1 + 32);
    v4 = *(_DWORD *)(a1 + 28);
    ++*(_DWORD *)(a1 + 16);
    result = (*(int (__fastcall **)(int, _DWORD, _DWORD))(a1 + 40))(v4, HIDWORD(v3), v3);
  }
  return result;
}
