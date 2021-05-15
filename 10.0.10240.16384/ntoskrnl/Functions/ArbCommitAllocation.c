// ArbCommitAllocation 
 
int __fastcall ArbCommitAllocation(int a1)
{
  __int64 v2; // r2
  int result; // r0

  RtlFreeRangeList(*(_DWORD **)(a1 + 20));
  v2 = *(_QWORD *)(a1 + 20);
  result = 0;
  *(_DWORD *)(a1 + 20) = HIDWORD(v2);
  *(_DWORD *)(a1 + 24) = v2;
  return result;
}
