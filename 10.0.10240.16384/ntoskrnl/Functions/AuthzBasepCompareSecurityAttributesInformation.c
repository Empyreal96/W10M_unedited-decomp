// AuthzBasepCompareSecurityAttributesInformation 
 
int __fastcall AuthzBasepCompareSecurityAttributesInformation(_DWORD *a1, _DWORD *a2)
{
  int v3; // r5
  _DWORD *v4; // r4
  _DWORD *v5; // r6
  _DWORD *v6; // r0

  v3 = 0;
  if ( *a1 == *a2 )
  {
    if ( *a1 )
    {
      v4 = (_DWORD *)a1[1];
      v5 = a1 + 1;
      while ( v4 != v5 )
      {
        v6 = AuthzBasepFindSecurityAttribute((int)a2, (int)(v4 + 4));
        if ( !v6 || !AuthzBasepCompareSecurityAttribute((int)v4, (int)v6) )
          return v3;
        v4 = (_DWORD *)*v4;
      }
    }
    v3 = 1;
  }
  return v3;
}
