// sub_523538 
 
void __fastcall sub_523538(unsigned int a1)
{
  int v1; // r4
  unsigned int *v2; // r5
  unsigned int v3; // r2

  *(_DWORD *)(a1 + 4) = v1;
  __dmb(0xBu);
  do
    v3 = __ldrex(v2);
  while ( v3 == v1 && __strex(a1, v2) );
  JUMPOUT(0x45968A);
}
