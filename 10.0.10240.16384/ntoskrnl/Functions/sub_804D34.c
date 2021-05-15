// sub_804D34 
 
void __fastcall sub_804D34(unsigned int a1)
{
  unsigned int *v1; // r5
  unsigned int v2; // r4
  unsigned int v3; // r2

  while ( 1 )
  {
    v2 = a1;
    __dmb(0xBu);
    do
      v3 = __ldrex(v1);
    while ( v3 == a1 && __strex(a1 - 1, v1) );
    a1 = v3;
    __dmb(0xBu);
    if ( v3 == v2 )
      JUMPOUT(0x74E050);
  }
}
