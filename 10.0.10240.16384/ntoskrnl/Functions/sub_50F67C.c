// sub_50F67C 
 
void sub_50F67C()
{
  int v0; // r4
  unsigned __int8 *v1; // r3
  unsigned int v2; // r2

  v1 = (unsigned __int8 *)(v0 + 2);
  do
    v2 = __ldrex(v1);
  while ( __strex(v2 | 0x10, v1) );
  JUMPOUT(0x425394);
}
