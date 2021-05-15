// PiDcFreeGenericTableEntry 
 
unsigned int __fastcall PiDcFreeGenericTableEntry(int a1, unsigned int a2)
{
  return ExFreePoolWithTag(a2);
}
