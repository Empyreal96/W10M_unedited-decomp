// IopAllocateGenericTableEntry 
 
int __fastcall IopAllocateGenericTableEntry(int a1, int a2)
{
  return ExAllocatePoolWithTag(1, a2, 1700032329);
}
