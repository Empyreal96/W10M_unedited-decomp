// KiVoidIcacheRangePoUWithCatch 
 
int __fastcall KiVoidIcacheRangePoUWithCatch(int a1, int a2)
{
  return KiVoidBroadcastIcacheRangePoU(a1, a2 + a1);
}
