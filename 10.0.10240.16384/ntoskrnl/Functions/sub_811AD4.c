// sub_811AD4 
 
void __fastcall sub_811AD4(_WORD *a1)
{
  int v1; // r6
  _WORD *v2; // r0

  do
  {
    if ( !*a1 || *a1 == 92 )
      break;
    if ( (unsigned int)++v1 > 2 )
      JUMPOUT(0x7A1E70);
    v2 = wcschr(a1, 92);
    if ( !v2 )
      break;
    a1 = v2 + 1;
  }
  while ( a1 );
  JUMPOUT(0x7A1DC4);
}
