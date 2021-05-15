// sub_7EB1FC 
 
void __fastcall sub_7EB1FC(int a1)
{
  int v1; // r4
  unsigned int *v2; // r2
  unsigned int v3; // r0

  __dmb(0xBu);
  v2 = (unsigned int *)(a1 + 784);
  do
    v3 = __ldrex(v2);
  while ( __strex(v3 | 0x80000000, v2) );
  __dmb(0xBu);
  *(_QWORD *)(v1 + 448) += v3;
  JUMPOUT(0x707DA4);
}
