// PspInheritQuota 
 
int __fastcall PspInheritQuota(int result, int a2)
{
  int *v2; // r4
  unsigned int *v3; // r2
  unsigned int v4; // r1
  unsigned int *v5; // r2
  unsigned int v6; // r1

  if ( a2 )
  {
    v2 = *(int **)(a2 + 332);
    __dmb(0xBu);
  }
  else
  {
    v2 = PspSystemQuotaBlock;
  }
  __dmb(0xBu);
  v3 = (unsigned int *)(v2 + 256);
  do
    v4 = __ldrex(v3);
  while ( __strex(v4 + 1, v3) );
  __dmb(0xBu);
  v5 = (unsigned int *)(v2 + 257);
  do
    v6 = __ldrex(v5);
  while ( __strex(v6 + 1, v5) );
  __dmb(0xBu);
  *(_DWORD *)(result + 332) = v2;
  return result;
}
