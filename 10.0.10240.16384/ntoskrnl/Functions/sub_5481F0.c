// sub_5481F0 
 
void sub_5481F0()
{
  int v0; // r5
  int v1; // r6
  int v2; // r9
  int v3; // r10
  int v4; // r1

  if ( (v2 & 4) != 0 )
  {
    if ( (v2 & v1) != 0 )
      v4 = 15;
    else
      v4 = *(unsigned __int8 *)(v3 + 7616);
    MiLogKernelStackEvent(v0 - (v4 << 12), v4, 0);
  }
  JUMPOUT(0x4C7464);
}
