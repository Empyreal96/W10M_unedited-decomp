// PiDmFreeGenericTableEntry 
 
unsigned int __fastcall PiDmFreeGenericTableEntry(int a1, unsigned int a2)
{
  return ExFreePoolWithTag(a2);
}
