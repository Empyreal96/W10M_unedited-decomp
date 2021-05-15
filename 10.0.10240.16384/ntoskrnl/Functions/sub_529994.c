// sub_529994 
 
void sub_529994()
{
  unsigned int v0; // r4
  unsigned int *v1; // r5

  if ( v0 > *v1 )
  {
    *v1 = v0;
    __dmb(0xFu);
  }
  JUMPOUT(0x4673AA);
}
