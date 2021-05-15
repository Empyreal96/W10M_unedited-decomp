// PiSwPdoAssociationFree 
 
unsigned int __fastcall PiSwPdoAssociationFree(unsigned int a1)
{
  ObfDereferenceObject(*(_DWORD *)(a1 + 8));
  ObfDereferenceObject(*(_DWORD *)(a1 + 12));
  return ExFreePoolWithTag(a1);
}
