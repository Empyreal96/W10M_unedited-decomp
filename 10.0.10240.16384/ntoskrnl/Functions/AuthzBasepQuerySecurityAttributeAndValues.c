// AuthzBasepQuerySecurityAttributeAndValues 
 
int __fastcall AuthzBasepQuerySecurityAttributeAndValues(int *a1)
{
  int v2; // r1
  int v3; // r6
  _DWORD *v4; // r5
  bool v5; // cf
  _DWORD *v6; // r0
  _DWORD *v8; // r6
  _DWORD *v9; // r7
  _DWORD *v10; // t1
  int v11; // r2
  int v12; // r3

  v2 = a1[7];
  if ( v2 )
  {
    v11 = *(_DWORD *)a1[8];
    if ( v11 == v2 + 44 )
      return -2147483622;
LABEL_12:
    a1[6] = v11 + 24;
    a1[8] = v11;
    return 0;
  }
  v3 = *a1;
  if ( !*a1 )
    return -1073741275;
  v4 = *(_DWORD **)(v3 + 4);
  if ( v4 == (_DWORD *)(v3 + 4) )
  {
LABEL_8:
    v10 = *(_DWORD **)(v3 + 16);
    v8 = (_DWORD *)(v3 + 16);
    v9 = v10;
    if ( v10 != v8 )
    {
      while ( 1 )
      {
        v4 = v9 - 2;
        if ( (v9[6] & 1) == 0 )
        {
          if ( AuthzBasepEqualUnicodeString((int)(v9 + 2), (int)(a1 + 1)) )
            break;
        }
        v9 = (_DWORD *)*v9;
        if ( v9 == v8 )
          return -1073741275;
      }
LABEL_10:
      if ( v4 )
      {
        v11 = v4[11];
        a1[5] = v4[9];
        *((_WORD *)a1 + 6) = *((_WORD *)v4 + 12);
        v12 = v4[7];
        a1[7] = (int)v4;
        a1[4] = v12;
        goto LABEL_12;
      }
    }
    return -1073741275;
  }
  while ( 1 )
  {
    v5 = (unsigned int)KeGetCurrentIrql() >= 2;
    v6 = v4 + 4;
    if ( v5 )
      return sub_517F1C(v6);
    if ( RtlEqualUnicodeString(v6, a1 + 1, 1) )
      goto LABEL_10;
    v4 = (_DWORD *)*v4;
    if ( v4 == (_DWORD *)(v3 + 4) )
      goto LABEL_8;
  }
}
