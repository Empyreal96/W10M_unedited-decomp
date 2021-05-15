// HvpViewMapReleaseChargesForPinnedPages 
 
unsigned int *__fastcall HvpViewMapReleaseChargesForPinnedPages(int a1, unsigned int *a2)
{
  unsigned int *result; // r0

  result = MmReleaseResourceCharge(a2, 3, 1);
  *(_DWORD *)(a1 + 16) -= a2;
  return result;
}
