// CmpFree 
 
unsigned int __fastcall CmpFree(unsigned int a1, int a2)
{
  CmpReleaseGlobalQuota(a2);
  return ExFreePoolWithTag(a1);
}
