// sub_54E7EC 
 
void sub_54E7EC()
{
  int v0; // r6
  int v1; // r7
  unsigned int *v2; // r2
  unsigned int v3; // r0

  v2 = (unsigned int *)(v0 + 3844);
  do
    v3 = __ldrex(v2);
  while ( __strex(v3 + v1, v2) );
  JUMPOUT(0x4E6E98);
}
