// sub_548F84 
 
void sub_548F84()
{
  int v0; // r8
  unsigned int *v1; // r5
  unsigned int v2; // r6
  unsigned int *v3; // r2
  unsigned int v4; // r4
  unsigned int v5; // r1

  v1 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 4276);
  do
    v2 = __ldrex(v1);
  while ( __strex(v2 + 1, v1) );
  v3 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 4280);
  v4 = (unsigned int)(*(_DWORD *)(v0 + 20) + 4095) >> 12;
  do
    v5 = __ldrex(v3);
  while ( __strex(v5 + v4, v3) );
  JUMPOUT(0x4C9978);
}
