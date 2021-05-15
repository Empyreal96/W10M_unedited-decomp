// _MapCmClassPropertyToRegType 
 
int __fastcall MapCmClassPropertyToRegType(int a1)
{
  if ( a1 == 8 || a1 == 13 )
    return 1;
  if ( a1 > 17 )
  {
    if ( a1 <= 19 )
      return 7;
    if ( a1 == 24 )
      return 3;
    if ( (unsigned int)(a1 - 26) <= 2 )
      return 4;
  }
  return 0;
}
