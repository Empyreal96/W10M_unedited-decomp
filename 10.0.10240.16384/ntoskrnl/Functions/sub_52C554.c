// sub_52C554 
 
void __fastcall sub_52C554(unsigned int *a1)
{
  unsigned int v1; // r1

  __dmb(0xBu);
  do
    v1 = __ldrex(a1);
  while ( __strex(v1 & 0xFFFFFF7F, a1) );
  JUMPOUT(0x471BF4);
}
