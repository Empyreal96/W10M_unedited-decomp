// KdpDeleteBreakpointRange 
 
int KdpDeleteBreakpointRange()
{
  int *v0; // r4
  unsigned int i; // r5

  v0 = &KdpBreakpointTable;
  for ( i = 0; i < 0x20; ++i )
  {
    if ( (v0[6] & 1) != 0 )
      return sub_903BD0();
    v0 += 8;
  }
  return 0;
}
