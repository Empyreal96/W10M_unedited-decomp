// sub_800D80 
 
void sub_800D80()
{
  int v0; // r4
  int v1; // r7
  int v2; // r10

  if ( !v2 && ((v1 & v0) == 0 || v1 == -2 || v1 == -1) )
    VfCheckUserHandle(v1);
  JUMPOUT(0x73C642);
}
