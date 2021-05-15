// ExpSafeWcslen 
 
int __fastcall ExpSafeWcslen(_WORD *a1, unsigned int a2)
{
  _WORD *v2; // r2
  int result; // r0

  v2 = a1;
  if ( (unsigned int)a1 >= a2 )
    goto LABEL_7;
  do
  {
    if ( !*v2 )
      break;
    ++v2;
  }
  while ( (unsigned int)v2 < a2 );
  if ( (unsigned int)v2 >= a2 )
LABEL_7:
    result = -1;
  else
    result = v2 - a1;
  return result;
}
