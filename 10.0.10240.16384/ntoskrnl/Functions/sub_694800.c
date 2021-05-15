// sub_694800 
 
void __fastcall sub_694800(int a1, int a2)
{
  unsigned int *v2; // r2
  unsigned int v3; // r1

  __dmb(0xBu);
  v2 = (unsigned int *)(a2 + 8);
  do
    v3 = __ldrex(v2);
  while ( __strex(0, v2) );
  __dmb(0xBu);
  JUMPOUT(0x693E96);
}
