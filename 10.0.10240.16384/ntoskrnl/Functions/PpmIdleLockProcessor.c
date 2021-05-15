// PpmIdleLockProcessor 
 
int __fastcall PpmIdleLockProcessor(unsigned int *a1)
{
  unsigned int *v1; // r5
  int result; // r0
  unsigned int v4; // r6
  unsigned int v5; // r4
  unsigned int v6; // r2

  v1 = a1;
  __pld(a1);
  result = -1073741782;
  v4 = *a1;
  while ( HIBYTE(v4) == 4 || HIBYTE(v4) == 5 )
  {
    v5 = v4;
    __dmb(0xBu);
    do
      v6 = __ldrex(v1);
    while ( v6 == v4
         && __strex((v4 & 0xFFFFFF | 0x5000000) & 0xFF000000 | ((v4 & 0xFFFFFF | 0x5000000) + 1) & 0xFFFFFF, v1) );
    v4 = v6;
    __dmb(0xBu);
    if ( v6 == v5 )
      return 0;
  }
  return result;
}
