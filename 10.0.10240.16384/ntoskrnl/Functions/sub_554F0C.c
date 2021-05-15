// sub_554F0C 
 
void sub_554F0C()
{
  int v0; // r5
  unsigned int *v1; // r8
  unsigned int v2; // r0

  __dmb(0xBu);
  do
    v2 = __ldrex(v1);
  while ( __strex(v2 - v0, v1) );
  __dmb(0xBu);
  JUMPOUT(0x4F743C);
}
