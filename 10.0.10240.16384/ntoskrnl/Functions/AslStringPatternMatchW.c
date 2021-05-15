// AslStringPatternMatchW 
 
int __fastcall AslStringPatternMatchW(_WORD *a1, _WORD *a2)
{
  unsigned int v4; // r7
  unsigned int v6; // r4

  while ( 1 )
  {
    v4 = (unsigned __int16)*a1;
    if ( !*a1 )
      return sub_817914();
    if ( v4 != 63 )
    {
      if ( v4 == 42 )
        JUMPOUT(0x81791C);
      v6 = RtlUpcaseUnicodeChar((unsigned __int16)*a2);
      if ( RtlUpcaseUnicodeChar(v4) != v6 )
        break;
    }
    ++a1;
    if ( !*a2 )
      break;
    ++a2;
  }
  return 0;
}
