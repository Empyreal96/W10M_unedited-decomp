// sub_51F02C 
 
void __fastcall sub_51F02C(int a1)
{
  unsigned int *v1; // r2
  unsigned int v2; // r0

  __dmb(0xBu);
  v1 = (unsigned int *)(a1 + 12);
  do
    v2 = __ldrex(v1);
  while ( __strex(v2 & 0x7FFFFFFF, v1) );
  JUMPOUT(0x44E85C);
}
