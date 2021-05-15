// sub_5204A4 
 
void __fastcall sub_5204A4(int a1)
{
  int v1; // r4
  unsigned int v2; // r5
  unsigned int *v3; // r2
  unsigned int v4; // r1

  __dmb(0xBu);
  v3 = (unsigned int *)(a1 + 24);
  do
    v4 = __ldrex(v3);
  while ( v4 == v1 && __strex(v2, v3) );
  __dmb(0xBu);
  if ( v1 != v4 )
    JUMPOUT(0x451F58);
  JUMPOUT(0x451F7E);
}
