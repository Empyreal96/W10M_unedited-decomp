// StringCbCatW 
 
int __fastcall StringCbCatW(unsigned __int16 *a1, unsigned int a2)
{
  int result; // r0
  unsigned int v4; // r1
  unsigned int v5; // r2
  unsigned __int16 *v6; // r4
  unsigned int v8; // r2

  result = 0;
  v4 = a2 >> 1;
  if ( !v4 )
    result = -2147024809;
  if ( result >= 0 )
  {
    result = 0;
    v5 = v4;
    v6 = a1;
    if ( v4 )
    {
      do
      {
        if ( !*v6++ )
          break;
        --v5;
      }
      while ( v5 );
      if ( v5 )
      {
        v8 = v4 - v5;
        goto LABEL_11;
      }
    }
    result = -2147024809;
  }
  v8 = 0;
LABEL_11:
  if ( result >= 0 )
    result = sub_5B3C20(&a1[v8], v4 - v8, v8, L" ");
  return result;
}
