// sub_7DEFC4 
 
void sub_7DEFC4()
{
  unsigned int *v0; // r8
  unsigned int v1; // r2

  __dmb(0xBu);
  do
    v1 = __ldrex(v0);
  while ( __strex(v1 - 1, v0) );
  __dmb(0xBu);
  JUMPOUT(0x6EE036);
}
