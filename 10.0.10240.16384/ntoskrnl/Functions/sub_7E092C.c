// sub_7E092C 
 
void __fastcall sub_7E092C(unsigned int a1)
{
  unsigned int *v1; // r6
  unsigned int v2; // r1
  unsigned int **v3; // r0
  unsigned int *v4; // r2
  unsigned int v5; // r2

  v2 = a1 + 8;
  v1[15] = a1;
  v3 = *(unsigned int ***)(a1 + 12);
  v4 = v1 + 13;
  v1[13] = v2;
  v1[14] = (unsigned int)v3;
  if ( *v3 != (unsigned int *)v2 )
    __fastfail(3u);
  *v3 = v4;
  *(_DWORD *)(v2 + 4) = v4;
  __dmb(0xBu);
  do
    v5 = __ldrex(v1);
  while ( __strex(v5 + 1, v1) );
  __dmb(0xBu);
  JUMPOUT(0x7770CE);
}
