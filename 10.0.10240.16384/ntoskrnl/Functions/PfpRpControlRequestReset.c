// PfpRpControlRequestReset 
 
int __fastcall PfpRpControlRequestReset(int a1)
{
  int *v2; // r0
  unsigned int *v3; // r2
  unsigned int v4; // r4

  PfpRpCHashEmpty(a1, (unsigned int *)(a1 + 56), (unsigned __int8 *)(a1 + 72));
  v2 = 0;
  while ( 1 )
  {
    v2 = PsGetNextProcess((int)v2);
    if ( !v2 )
      break;
    __dmb(0xBu);
    v3 = (unsigned int *)(v2 + 48);
    do
      v4 = __ldrex(v3);
    while ( __strex(v4 & 0xFFFFBFFF, v3) );
    __dmb(0xBu);
  }
  PfpRpCHashEmpty(a1, (unsigned int *)(a1 + 32), (unsigned __int8 *)(a1 + 52));
  *(_DWORD *)(a1 + 48) = 0;
  return 0;
}
