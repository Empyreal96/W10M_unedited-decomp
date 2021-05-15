// SmAcquireReleaseCharges 
 
int __fastcall SmAcquireReleaseCharges(unsigned int a1, char a2, int a3)
{
  int v4; // r1

  v4 = (a2 & 1) != 0;
  if ( (a2 & 2) != 0 )
    v4 |= 2u;
  if ( !a3 )
    return MmChargeResources(a1 >> 12, v4, 0, 1);
  MmReleaseResourceCharge(a1 >> 12);
  return 1;
}
