// sub_5376A8 
 
void sub_5376A8()
{
  int v0; // r6
  unsigned __int16 *v1; // r1
  unsigned int v2; // r5

  __dmb(0xBu);
  v1 = (unsigned __int16 *)(v0 + 344);
  do
    v2 = __ldrex(v1);
  while ( __strex(v2 | 1, v1) );
  __dmb(0xBu);
  JUMPOUT(0x494F40);
}
