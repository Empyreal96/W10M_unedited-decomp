// CmCallbackReleaseKeyObjectIDEx 
 
unsigned int __fastcall CmCallbackReleaseKeyObjectIDEx(unsigned int a1)
{
  return ExFreePoolWithTag(a1);
}
