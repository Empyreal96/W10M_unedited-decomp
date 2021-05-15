// PnpRegSzToString 
 
int __fastcall PnpRegSzToString(char *a1, unsigned int a2, _DWORD *a3)
{
  unsigned int v3; // r1
  char *i; // r4

  v3 = (unsigned int)&a1[2 * (a2 >> 1)];
  for ( i = a1; (unsigned int)i < v3; i += 2 )
  {
    if ( !*(_WORD *)i )
      break;
  }
  if ( a3 )
    *a3 = i - a1;
  return 1;
}
