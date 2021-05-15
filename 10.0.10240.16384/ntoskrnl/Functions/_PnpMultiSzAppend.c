// _PnpMultiSzAppend 
 
int __fastcall PnpMultiSzAppend(unsigned __int16 *a1, unsigned int *a2, unsigned __int16 *a3)
{
  unsigned __int16 *v3; // r5
  unsigned int v6; // r4
  unsigned int v8; // r6
  unsigned __int16 *v9; // r4
  unsigned __int16 *v11; // r3

  v3 = a1;
  if ( *a1 )
  {
    v8 = *a2;
    v9 = a1;
    if ( *a2 )
    {
      do
      {
        while ( *v9++ )
          ;
      }
      while ( *v9 && 2 * (v9 - a1) < v8 );
    }
    if ( 2 * (wcslen(a3) + v9 - a1 + 2) <= v8 && RtlStringCbCopyExW(v9, v8, (__int16 *)a3, 0, 0, 2304) >= 0 )
    {
      v11 = &v9[wcslen(a3) + 1];
      *v11 = 0;
      *a2 = 2 * (v11 - v3 + 1);
      return 1;
    }
    return 0;
  }
  v6 = 2 * (wcslen(a3) + 2);
  if ( v6 > *a2 || RtlStringCbCopyExW(v3, *a2, (__int16 *)a3, 0, 0, 2304) < 0 )
    return 0;
  v3[wcslen(v3) + 1] = 0;
  *a2 = v6;
  return 1;
}
