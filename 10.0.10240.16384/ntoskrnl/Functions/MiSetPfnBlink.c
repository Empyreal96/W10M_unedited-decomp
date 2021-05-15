// MiSetPfnBlink 
 
int __fastcall MiSetPfnBlink(int result, int a2, int a3)
{
  unsigned int *v4; // r6
  int v5; // r1
  int v6; // r4
  unsigned int v7; // r5
  bool i; // zf
  unsigned int v9; // r1

  if ( a3 == 1 )
    return sub_53BD00();
  v4 = (unsigned int *)(result + 12);
  v5 = *(_DWORD *)(result + 12);
  v6 = a2 & 0xFFFFF;
  do
    v7 = __ldrex(v4);
  while ( v7 == v5 && __strex(v5 & 0xFFF00000 | v6, v4) );
  for ( i = v5 == v7; !i; i = result == v9 )
  {
    result = v7;
    do
      v9 = __ldrex(v4);
    while ( v9 == v7 && __strex(v7 & 0xFFF00000 | v6, v4) );
    v7 = v9;
  }
  return result;
}
