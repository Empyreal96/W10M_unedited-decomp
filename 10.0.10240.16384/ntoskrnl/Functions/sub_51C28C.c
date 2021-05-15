// sub_51C28C 
 
void __fastcall sub_51C28C(int a1, unsigned int a2)
{
  unsigned int v2; // r4
  _DWORD *v3; // r5
  int *v4; // r0
  int v5; // t1

  v4 = dword_681D78;
  while ( 1 )
  {
    v5 = *v4++;
    if ( v3[1] | *v3 & ~v5 )
      break;
    ++a2;
    v3 += 2;
    if ( a2 >= v2 )
      JUMPOUT(0x446A50);
  }
  JUMPOUT(0x446A56);
}
