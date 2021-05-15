// strncmp 
 
int __fastcall strncmp(_BYTE *a1, unsigned __int8 *a2, unsigned int a3)
{
  unsigned int v3; // r4
  int v4; // r2
  int v5; // r3

  v3 = 0;
  if ( a3 )
  {
    if ( a3 <= 4 )
      goto LABEL_21;
    do
    {
      a1 += 4;
      a2 += 4;
      if ( !*(a1 - 4) || *(a1 - 4) != *(a2 - 4) )
      {
        v4 = (unsigned __int8)*(a1 - 4);
        v5 = *(a2 - 4);
        return v4 - v5;
      }
      if ( !*(a1 - 3) || *(a1 - 3) != *(a2 - 3) )
      {
        v4 = (unsigned __int8)*(a1 - 3);
        v5 = *(a2 - 3);
        return v4 - v5;
      }
      if ( !*(a1 - 2) || *(a1 - 2) != *(a2 - 2) )
      {
        v4 = (unsigned __int8)*(a1 - 2);
        v5 = *(a2 - 2);
        return v4 - v5;
      }
      if ( !*(a1 - 1) || *(a1 - 1) != *(a2 - 1) )
      {
        v4 = (unsigned __int8)*(a1 - 1);
        v5 = *(a2 - 1);
        return v4 - v5;
      }
      v3 += 4;
    }
    while ( v3 < a3 - 4 );
LABEL_21:
    while ( v3 < a3 )
    {
      if ( !*a1 || *a1 != *a2 )
      {
        v4 = (unsigned __int8)*a1;
        v5 = *a2;
        return v4 - v5;
      }
      ++a1;
      ++v3;
      ++a2;
    }
  }
  return 0;
}
