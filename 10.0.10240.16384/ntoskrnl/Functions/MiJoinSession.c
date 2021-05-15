// MiJoinSession 
 
int __fastcall MiJoinSession(unsigned int **a1)
{
  unsigned int *v2; // r4
  unsigned int v3; // r1
  unsigned int v4; // r0
  unsigned int *v5; // r2
  unsigned int v6; // r1

  *a1 = 0;
  v2 = *(unsigned int **)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324);
  if ( !v2 )
    return 1;
  v3 = *v2;
  if ( !*v2 )
    return 0;
  do
    v4 = __ldrex(v2);
  while ( v4 == v3 && __strex(v3 + 1, v2) );
  if ( v4 == v3 )
  {
    v5 = v2 + 3;
    do
      v6 = __ldrex(v5);
    while ( __strex(v6 + 1, v5) );
    __dmb(0xBu);
    *a1 = v2;
    return 1;
  }
  return sub_7BF5A0();
}
