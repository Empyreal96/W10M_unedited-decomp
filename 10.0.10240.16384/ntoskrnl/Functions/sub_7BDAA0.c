// sub_7BDAA0 
 
// positive sp value has been detected, the output may be wrong!
int __fastcall sub_7BDAA0(int a1, int a2)
{
  if ( *(_WORD *)(a2 + 310) )
    JUMPOUT(0x6CA278);
  return KiCheckForKernelApcDelivery(a1);
}
