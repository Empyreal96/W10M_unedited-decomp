// sub_516B78 
 
void sub_516B78()
{
  int v0; // r4
  unsigned int *v1; // r2
  unsigned int v2; // r0

  v1 = (unsigned int *)(v0 + 7656);
  do
    v2 = __ldrex(v1);
  while ( __strex(0, v1) );
  __dmb(0xBu);
  JUMPOUT(0x4362A0);
}
