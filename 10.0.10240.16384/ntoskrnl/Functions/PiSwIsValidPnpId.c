// PiSwIsValidPnpId 
 
int __fastcall PiSwIsValidPnpId(unsigned __int16 *a1, int a2)
{
  unsigned int i; // r3
  unsigned int v3; // t1

  for ( i = *a1; i; i = v3 )
  {
    if ( i <= 0x20 || i > 0x7F || i == 44 || i == 92 && !a2 )
      return 0;
    v3 = a1[1];
    ++a1;
  }
  return 1;
}
