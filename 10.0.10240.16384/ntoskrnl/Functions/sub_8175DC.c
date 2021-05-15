// sub_8175DC 
 
void sub_8175DC()
{
  unsigned __int8 *v0; // r4
  unsigned int v1; // r3

  __dmb(0xBu);
  do
    v1 = __ldrex(v0);
  while ( __strex(v1 | 2, v0) );
  JUMPOUT(0x7AF9AA);
}
