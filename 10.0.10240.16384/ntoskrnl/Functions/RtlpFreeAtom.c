// RtlpFreeAtom 
 
unsigned int __fastcall RtlpFreeAtom(int a1)
{
  PsReturnSharedPoolQuota(*(_DWORD *)(a1 - 8), *(_DWORD *)(a1 - 4), 0);
  return ExFreePoolWithTag(a1 - 8);
}
