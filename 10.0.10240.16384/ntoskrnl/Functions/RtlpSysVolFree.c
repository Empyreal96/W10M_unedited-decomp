// RtlpSysVolFree 
 
unsigned int __fastcall RtlpSysVolFree(unsigned int a1)
{
  return ExFreePoolWithTag(a1);
}
