// PiDqFreeGenericTableEntry 
 
unsigned int __fastcall PiDqFreeGenericTableEntry(int a1, unsigned int a2)
{
  return ExFreePoolWithTag(a2);
}
