// SmKmFreeMdlForLock 
 
int __fastcall SmKmFreeMdlForLock(int a1)
{
  SmAcquireReleaseCharges(*(_DWORD *)(a1 + 20), 3, 1);
  return ExFreePoolWithTag(a1);
}
