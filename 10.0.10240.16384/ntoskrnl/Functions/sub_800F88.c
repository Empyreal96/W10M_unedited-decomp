// sub_800F88 
 
void sub_800F88()
{
  int v0; // r7

  if ( (v0 & 0xBFFFFF0F) != 0 )
    JUMPOUT(0x73E1BE);
  JUMPOUT(0x73E0C0);
}
