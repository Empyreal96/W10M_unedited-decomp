// AlpcpFreeCompletionList 
 
unsigned int __fastcall AlpcpFreeCompletionList(int a1)
{
  unsigned int v1; // r4
  unsigned int result; // r0

  v1 = *(_DWORD *)(a1 + 212);
  MmUnlockPages(*(_DWORD *)(v1 + 16));
  IoFreeMdl(*(_DWORD *)(v1 + 16));
  AlpcpUnregisterCompletionListDatabase(v1);
  result = ExFreePoolWithTag(v1);
  *(_DWORD *)(a1 + 212) = 0;
  *(_DWORD *)(a1 + 244) &= 0xFFFFBFFF;
  return result;
}
