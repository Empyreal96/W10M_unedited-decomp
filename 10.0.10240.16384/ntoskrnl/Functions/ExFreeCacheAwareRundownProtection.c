// ExFreeCacheAwareRundownProtection 
 
int __fastcall ExFreeCacheAwareRundownProtection(int a1)
{
  ExFreePoolWithTag(*(_DWORD *)(a1 + 4), 0);
  return ExFreePoolWithTag(a1, 0);
}
