// MmGetNumberOfPhysicalPages 
 
int __fastcall MmGetNumberOfPhysicalPages(int a1)
{
  return *(_DWORD *)(*(_DWORD *)(dword_634340 + 4 * a1) + 3592);
}
