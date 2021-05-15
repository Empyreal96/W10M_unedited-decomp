// AslEnvVarQuery 
 
int __fastcall AslEnvVarQuery(_WORD *a1, int a2, unsigned int a3, _WORD *a4, unsigned int a5, unsigned int *a6)
{
  unsigned __int16 *v10; // r9
  unsigned int v11; // r0
  unsigned int v12; // r0
  unsigned int v13; // r3
  unsigned int v14; // r4
  int result; // r0
  int v16; // r1
  _WORD *v17; // r8
  unsigned __int16 *v18; // r7
  unsigned int v19; // r4
  int v20; // r3
  int v21; // r4
  _WORD *v22; // r1
  int v23; // r0

  v10 = (unsigned __int16 *)(a2 + 2 * a3);
  v11 = wcslen(L"systemroot");
  if ( a3 < v11 || wcsnicmp(a2, L"systemroot", v11) )
  {
    if ( !a1 )
      return -1073741568;
    while ( 1 )
    {
      if ( !*a1 )
        return -1073741568;
      v17 = a1;
      v18 = (unsigned __int16 *)a2;
      if ( a2 < (unsigned int)v10 )
      {
        do
        {
          if ( !*a1 )
            break;
          v19 = RtlUpcaseUnicodeChar((unsigned __int16)*a1);
          if ( v19 != RtlUpcaseUnicodeChar(*v18) )
            break;
          ++v18;
          ++a1;
        }
        while ( v18 < v10 );
      }
      if ( v18 == v10 && (v20 = (unsigned __int16)*a1, v20 == 61) )
      {
        v21 = 1;
      }
      else
      {
        v21 = 0;
        while ( *a1 && (*a1 != 61 || a1 == v17) )
          ++a1;
        v20 = (unsigned __int16)*a1;
        if ( !*a1 )
          goto LABEL_30;
      }
      v22 = a1;
      if ( v20 )
      {
        v23 = 0;
        do
        {
          if ( (int)(v23 & 0xFFFFFFFE) >= 65534 )
            break;
          ++a1;
          v23 += 2;
        }
        while ( *a1 );
      }
      if ( v21 )
      {
        v16 = (int)(v22 + 1);
        v14 = ((int)a1 - v16) >> 1;
        v13 = a5;
        if ( v14 >= a5 )
          goto LABEL_4;
        goto LABEL_9;
      }
LABEL_30:
      ++a1;
    }
  }
  v12 = wcslen((unsigned __int16 *)0xFFFF9030);
  v13 = a5;
  v14 = v12;
  if ( v12 < a5 )
  {
    v16 = -28624;
LABEL_9:
    *a6 = v14;
    memmove((int)a4, v16, 2 * v14);
    a4[v14] = 0;
    result = 0;
  }
  else
  {
LABEL_4:
    if ( a4 )
    {
      if ( v13 )
        *a4 = 0;
    }
    result = -1073741789;
    *a6 = v14 + 1;
  }
  return result;
}
