// sub_7E7E20 
 
void __fastcall sub_7E7E20(int a1, int a2, int a3)
{
  int *v3; // r4
  unsigned int *v4; // r5
  int v5; // r6
  int v6; // r7
  int v7; // r8
  int v8; // r9
  int v9; // lr

  if ( v4 )
  {
    a2 = 1;
    if ( v4[72] )
      a3 = 1;
    if ( v4[73] )
      v6 = 1;
    if ( *v4 )
      v5 = 1;
  }
  if ( v3 )
  {
    v8 = 1;
    if ( v3[72] )
      a1 = 1;
    if ( v3[73] )
      v9 = 1;
    if ( *v3 )
      v7 = 1;
  }
  if ( a2 != v8
    || a3 != a1
    || v6 != v9
    || v5 != v7
    || a2
    && (a3 && !AuthzBasepCompareSecurityAttributesInformation(v4[72], v3[72])
     || v6 && !AuthzBasepCompareSecurityAttributesInformation(v4[73], v3[73])
     || v5 && !SepCompareSidAndAttributeArrays(v4[1], *v4, v3[1], *v3)) )
  {
    JUMPOUT(0x6F9A60);
  }
  JUMPOUT(0x6F9A5E);
}
