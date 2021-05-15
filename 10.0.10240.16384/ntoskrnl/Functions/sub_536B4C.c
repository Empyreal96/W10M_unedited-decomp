// sub_536B4C 
 
void sub_536B4C()
{
  int v0; // r4
  unsigned __int8 *v1; // r3
  unsigned int v2; // r1

  v1 = (unsigned __int8 *)(v0 + 15);
  do
    v2 = __ldrex(v1);
  while ( __strex(v2 | 0x80, v1) );
  __dmb(0xBu);
  if ( v2 >> 7 )
    JUMPOUT(0x493982);
  JUMPOUT(0x4936AA);
}
