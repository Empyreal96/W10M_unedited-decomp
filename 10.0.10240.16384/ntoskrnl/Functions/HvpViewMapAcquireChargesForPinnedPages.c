// HvpViewMapAcquireChargesForPinnedPages 
 
int __fastcall HvpViewMapAcquireChargesForPinnedPages(int a1, int a2)
{
  if ( !MmChargeResources(a2, 3, 1, 0) )
    return 0;
  *(_DWORD *)(a1 + 16) += a2;
  return 1;
}
