// RtlFindFirstRunClear 
 
unsigned int __fastcall RtlFindFirstRunClear(unsigned int *a1, unsigned int *a2)
{
  return RtlFindNextForwardRunClearCapped(a1, 0, 0xFFFFFFFF, a2);
}
