// PipFreeBindingId 
 
unsigned int __fastcall PipFreeBindingId(unsigned int a1)
{
  RtlFreeAnsiString((_DWORD *)(a1 + 8));
  return ExFreePoolWithTag(a1);
}
