// WmipIsNumber 
 
int __fastcall WmipIsNumber(unsigned __int16 *a1)
{
  unsigned int i; // r3
  unsigned int v2; // t1

  for ( i = *a1; ; i = v2 )
  {
    if ( !i )
      return 1;
    if ( i < 0x30 || i > 0x39 )
      break;
    v2 = a1[1];
    ++a1;
  }
  return 0;
}
