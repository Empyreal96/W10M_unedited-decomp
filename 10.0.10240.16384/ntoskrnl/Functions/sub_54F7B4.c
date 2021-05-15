// sub_54F7B4 
 
void __fastcall sub_54F7B4(int a1)
{
  int v1; // r5
  unsigned int *v2; // r2
  unsigned int v3; // r0

  if ( a1 != v1 )
  {
    __dmb(0xBu);
    v2 = (unsigned int *)(a1 + 12);
    do
      v3 = __ldrex(v2);
    while ( __strex(v3 & 0x7FFFFFFF, v2) );
  }
  JUMPOUT(0x4EA5AE);
}
