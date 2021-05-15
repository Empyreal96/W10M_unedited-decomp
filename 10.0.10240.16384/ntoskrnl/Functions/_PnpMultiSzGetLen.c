// _PnpMultiSzGetLen 
 
int __fastcall PnpMultiSzGetLen(unsigned __int16 *a1)
{
  int result; // r0
  int v3; // r3
  unsigned __int16 *v4; // r5

  result = 0;
  if ( a1 )
  {
    v3 = *a1;
    v4 = a1;
    while ( v3 )
    {
      v4 += wcslen(v4) + 1;
      v3 = *v4;
    }
    result = v4 - a1 + 1;
  }
  return result;
}
