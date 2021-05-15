// sub_526354 
 
void sub_526354()
{
  int v0; // r7
  int v1; // r8
  unsigned int *v2; // r2
  unsigned int v3; // r0

  v2 = (unsigned int *)(v1 + 3840);
  do
    v3 = __ldrex(v2);
  while ( __strex(v3 + v0, v2) );
  JUMPOUT(0x461406);
}
