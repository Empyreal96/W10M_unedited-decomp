// PiSwFreeGenericTableEntry 
 
unsigned int __fastcall PiSwFreeGenericTableEntry(int a1, unsigned int a2)
{
  return ExFreePoolWithTag(a2);
}
