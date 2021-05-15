// sub_7C22D0 
 
void __fastcall sub_7C22D0(int a1, unsigned int a2)
{
  unsigned int *v2; // r5
  unsigned int v3; // r4
  unsigned int v4; // r0
  unsigned int v5; // r2

  v2 = (unsigned int *)(a1 + 340);
  v3 = *(_DWORD *)(a1 + 340);
  __dmb(0xBu);
  do
  {
    if ( a2 <= v3 )
      break;
    v4 = v3;
    __dmb(0xBu);
    do
      v5 = __ldrex(v2);
    while ( v5 == v3 && __strex(a2, v2) );
    v3 = v5;
    __dmb(0xBu);
  }
  while ( v5 != v4 );
  JUMPOUT(0x6AAD02);
}
