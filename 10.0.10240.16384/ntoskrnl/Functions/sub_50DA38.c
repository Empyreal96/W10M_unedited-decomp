// sub_50DA38 
 
void sub_50DA38()
{
  int v0; // r4
  unsigned int *v1; // r5
  int v2; // r6
  int v3; // r7
  unsigned int v4; // r1

  do
    v4 = __ldrex(v1);
  while ( v4 == v0 && __strex(v0 & ~v3 | (v2 << 20), v1) );
  JUMPOUT(0x498376);
}
