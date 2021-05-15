// sub_543520 
 
void sub_543520()
{
  int v0; // r4
  int v1; // r5
  unsigned int *v2; // r2
  unsigned int v3; // r0

  v2 = (unsigned int *)(v0 + 3840);
  do
    v3 = __ldrex(v2);
  while ( __strex(v3 + v1, v2) );
  JUMPOUT(0x4B7842);
}
