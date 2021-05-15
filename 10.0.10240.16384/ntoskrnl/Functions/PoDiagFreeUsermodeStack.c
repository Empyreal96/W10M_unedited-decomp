// PoDiagFreeUsermodeStack 
 
unsigned int __fastcall PoDiagFreeUsermodeStack(unsigned int a1)
{
  return ExFreePoolWithTag(a1);
}
