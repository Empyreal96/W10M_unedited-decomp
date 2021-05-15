// sub_456A04 
 
int __fastcall sub_456A04(unsigned int *a1, int a2)
{
  unsigned int v2; // r7
  int v3; // r6
  unsigned int v4; // r5
  unsigned int v5; // r4

  v2 = *a1;
  __dmb(0xBu);
  do
  {
    v3 = (v2 & 3) + a2;
    v4 = v2;
    __dmb(0xBu);
    do
      v5 = __ldrex(a1);
    while ( v5 == v2 && __strex(v2 & 0xFFFFFFFC | v3, a1) );
    v2 = v5;
    __dmb(0xBu);
  }
  while ( v4 != v5 );
  return v3;
}
