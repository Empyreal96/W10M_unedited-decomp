// StringListElementSubstringMatch 
 
int __fastcall StringListElementSubstringMatch(unsigned __int16 *a1, int a2, unsigned __int16 *a3, int a4, int a5)
{
  int v5; // r6
  int v6; // r5
  int v11; // r3
  unsigned __int16 *v12; // r4

  v5 = 0;
  v6 = 0;
  switch ( a5 )
  {
    case 0x2000:
      v6 = 9;
      break;
    case 0x3000:
      v6 = 10;
      break;
    case 0x4000:
      v6 = 11;
      break;
  }
  while ( *a3 )
  {
    v11 = *a1;
    v12 = a1;
    while ( v11 )
    {
      if ( SubstringMatch(v12, a3, a4, v6) )
      {
        v5 = 1;
        break;
      }
      v12 += wcslen(v12) + 1;
      v11 = *v12;
    }
    if ( a2 == 18 || a2 == 8210 && v5 )
      break;
    a3 += wcslen(a3) + 1;
  }
  return v5;
}
