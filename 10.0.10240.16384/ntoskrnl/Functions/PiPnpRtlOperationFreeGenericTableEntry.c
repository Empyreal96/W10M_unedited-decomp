// PiPnpRtlOperationFreeGenericTableEntry 
 
unsigned int __fastcall PiPnpRtlOperationFreeGenericTableEntry(int a1, unsigned int a2)
{
  return ExFreePoolWithTag(a2);
}
