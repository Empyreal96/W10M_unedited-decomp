// PopFreeWakeInfo 
 
unsigned int __fastcall PopFreeWakeInfo(unsigned int a1)
{
  PopUnlinkWakeSources(a1);
  return ExFreePoolWithTag(a1);
}
