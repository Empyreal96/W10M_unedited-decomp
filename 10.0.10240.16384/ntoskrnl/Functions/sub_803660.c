// sub_803660 
 
void sub_803660()
{
  unsigned int *v0; // r4
  int v1; // r5

  if ( v1 )
    *v0 = *v0 & 0xF800000F | 0x200000;
  JUMPOUT(0x746408);
}
