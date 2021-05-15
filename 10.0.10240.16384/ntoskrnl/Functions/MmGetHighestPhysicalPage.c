// MmGetHighestPhysicalPage 
 
int __fastcall MmGetHighestPhysicalPage(int a1)
{
  return *(_DWORD *)(*(_DWORD *)(dword_634340 + 4 * a1) + 3588);
}
