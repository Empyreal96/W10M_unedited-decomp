// sub_903BD0 
 
void sub_903BD0()
{
  unsigned int *v0; // r4
  int v1; // r5
  unsigned int v2; // r7
  unsigned int v3; // r8

  if ( *v0 >= v3 && *v0 <= v2 )
    KdpDeleteBreakpoint(v1 + 1);
  JUMPOUT(0x902ED8);
}
