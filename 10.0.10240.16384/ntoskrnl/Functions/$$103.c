// $$103 
 
int __fastcall __103(int a1, int a2, unsigned int a3)
{
  int v3; // r1
  int v4; // r4
  int v5; // r3
  unsigned int v6; // r5
  int result; // r0

  v3 = a2 - 1;
  v4 = 0;
  if ( v3 < 0 )
    goto LABEL_10;
  do
  {
    v5 = (v3 + v4) >> 1;
    v6 = *(_DWORD *)(a1 + 4 * v5);
    if ( a3 >= v6 )
    {
      if ( a3 <= v6 )
        break;
      v4 = v5 + 1;
    }
    else
    {
      if ( !v5 )
        goto LABEL_10;
      v3 = v5 - 1;
    }
  }
  while ( v3 >= v4 );
  if ( v3 < v4 )
LABEL_10:
    result = 0;
  else
    result = 1;
  return result;
}
