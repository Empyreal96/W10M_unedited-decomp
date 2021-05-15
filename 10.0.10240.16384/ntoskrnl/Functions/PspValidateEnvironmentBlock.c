// PspValidateEnvironmentBlock 
 
int __fastcall PspValidateEnvironmentBlock(_WORD *a1, int *a2)
{
  int v2; // r4
  int v3; // r7
  unsigned int v4; // r5
  int v5; // r3
  int v6; // t1
  int v7; // r2
  int v8; // r6

  v2 = *a2;
  v3 = 0;
  if ( !*a1 )
  {
    v2 -= 2;
    ++a1;
  }
  if ( !v2 )
    return -1073741811;
  do
  {
    v4 = 0;
    v6 = (unsigned __int16)*a1++;
    v5 = v6;
    v7 = 0;
    v8 = 0;
    v2 -= 2;
    if ( v2 )
    {
      do
      {
        if ( !v5 )
          break;
        if ( v5 == 61 )
        {
          ++v4;
          if ( !v7 )
            v8 = 1;
        }
        v5 = (unsigned __int16)*a1;
        ++v7;
        v2 -= 2;
        ++a1;
      }
      while ( v2 );
      if ( v7 )
        goto LABEL_20;
    }
    if ( v5 )
    {
LABEL_20:
      if ( !v4 || v8 && v4 < 2 )
        return -1073741811;
    }
    else
    {
      if ( v2 )
      {
        *a2 -= v2;
        v2 = 0;
      }
      v3 = 1;
    }
  }
  while ( v2 );
  if ( !v3 )
    return -1073741811;
  return 0;
}
