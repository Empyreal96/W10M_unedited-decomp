// IopFreeGenericTableEntry 
 
unsigned int __fastcall IopFreeGenericTableEntry(int a1, unsigned int a2)
{
  return ExFreePoolWithTag(a2);
}
