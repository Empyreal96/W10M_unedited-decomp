// sub_7EAC3C 
 
void __fastcall sub_7EAC3C(int a1, int a2, int a3, int a4, unsigned int a5)
{
  _BYTE *v5; // r5
  unsigned int *v6; // r6
  unsigned int v7; // r7
  int v8; // r8
  unsigned int v9; // r4

  if ( AuthzBasepGetClaimAttributesCopyoutBufferSize(v8, &a5) >= 0 )
  {
    v9 = a5;
    if ( a5 )
    {
      if ( v7 >= a5 )
      {
        memset(v5, 0, v7);
        AuthzBasepCopyoutClaimAttributes(v8, v5, v7);
      }
      *v6 = v9;
    }
  }
  JUMPOUT(0x707402);
}
