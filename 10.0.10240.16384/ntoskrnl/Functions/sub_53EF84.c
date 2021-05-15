// sub_53EF84 
 
void sub_53EF84()
{
  unsigned int *v0; // r5
  unsigned int v1; // r2

  __dmb(0xBu);
  do
    v1 = __ldrex(v0);
  while ( __strex(v1 - 1, v0) );
  JUMPOUT(0x4A7B2C);
}
