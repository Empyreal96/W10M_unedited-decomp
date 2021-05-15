// wcsncmp 
 
int __fastcall wcsncmp(_WORD *a1, unsigned __int16 *a2, int a3)
{
  if ( !a3 )
    return 0;
  while ( --a3 && *a1 && (unsigned __int16)*a1 == *a2 )
  {
    ++a1;
    ++a2;
  }
  return (unsigned __int16)*a1 - *a2;
}
