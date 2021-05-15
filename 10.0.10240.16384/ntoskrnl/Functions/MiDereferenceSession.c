// MiDereferenceSession 
 
unsigned int MiDereferenceSession()
{
  int v0; // r4
  unsigned int *v1; // r2
  unsigned int v2; // r1
  unsigned int v3; // r1
  unsigned int *v4; // r2
  unsigned int result; // r0

  v0 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v1 = *(unsigned int **)(v0 + 324);
  __dmb(0xBu);
  do
  {
    v2 = __ldrex(v1);
    v3 = v2 - 1;
  }
  while ( __strex(v3, v1) );
  if ( !v3 )
    MiDereferenceSessionFinal();
  __dmb(0xBu);
  v4 = (unsigned int *)(v0 + 192);
  do
    result = __ldrex(v4);
  while ( __strex(result & 0xFFFEFFFF, v4) );
  __dmb(0xBu);
  return result;
}
