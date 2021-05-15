// sub_53AB70 
 
void sub_53AB70()
{
  int v0; // r4
  unsigned int *v1; // r2
  unsigned int v2; // r0

  __dmb(0xBu);
  v1 = (unsigned int *)(v0 + 192);
  do
    v2 = __ldrex(v1);
  while ( __strex(v2 | 0x800000, v1) );
  __dmb(0xBu);
  JUMPOUT(0x49B4E8);
}
