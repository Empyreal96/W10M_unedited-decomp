// PfpRpControlRequestVerify 
 
int __fastcall PfpRpControlRequestVerify(_DWORD *a1)
{
  int *v1; // r1
  int v2; // r2
  int v3; // t1
  unsigned int v4; // r0
  _DWORD *v5; // r1
  int v6; // r2
  int result; // r0

  v1 = a1 + 5;
  v2 = 0;
  if ( a1[2] + a1[1] )
  {
    while ( 1 )
    {
      v3 = *v1;
      v1 += 2;
      if ( !v3 )
        break;
      if ( ++v2 >= (unsigned int)(a1[2] + a1[1]) )
        goto LABEL_4;
    }
    result = 1000;
  }
  else
  {
LABEL_4:
    v4 = a1[4] + a1[3];
    v5 = (_DWORD *)(((unsigned int)v1 + 3) & 0xFFFFFFFC);
    v6 = 0;
    if ( v4 )
    {
      while ( *v5++ )
      {
        if ( ++v6 >= v4 )
          goto LABEL_7;
      }
      result = 2000;
    }
    else
    {
LABEL_7:
      result = 0;
    }
  }
  return result;
}
