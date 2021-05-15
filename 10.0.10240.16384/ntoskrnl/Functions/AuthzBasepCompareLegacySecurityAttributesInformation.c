// AuthzBasepCompareLegacySecurityAttributesInformation 
 
int __fastcall AuthzBasepCompareLegacySecurityAttributesInformation(int *a1, int *a2)
{
  int v2; // r7
  int v3; // r6
  int v4; // r5
  _DWORD *v6; // r4
  _DWORD *v7; // r9
  _DWORD *i; // r4
  _DWORD *v9; // r8
  _DWORD *v10; // t1

  v2 = *a1;
  v3 = *a2;
  v4 = 0;
  if ( !*a1 && !v3 )
    return 1;
  v6 = (_DWORD *)a1[1];
  v7 = a1 + 1;
  while ( v6 != v7 )
  {
    if ( AuthzBasepIsCompareRelevantAttribute(v6) )
      return sub_7E7DE0();
    --v2;
    v6 = (_DWORD *)*v6;
  }
  v10 = (_DWORD *)a2[1];
  v9 = a2 + 1;
  for ( i = v10; i != v9; i = (_DWORD *)*i )
  {
    if ( !AuthzBasepIsCompareRelevantAttribute(i) )
      --v3;
  }
  if ( v2 == v3 )
    return 1;
  return v4;
}
