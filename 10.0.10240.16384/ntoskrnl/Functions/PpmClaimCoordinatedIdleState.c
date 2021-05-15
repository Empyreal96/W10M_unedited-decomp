// PpmClaimCoordinatedIdleState 
 
BOOL __fastcall PpmClaimCoordinatedIdleState(unsigned int *a1)
{
  int v1; // r2
  int v2; // r2
  unsigned int v3; // r1

  v1 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
  __dmb(0xBu);
  v2 = v1 & 0x3FFF | 0x10000000;
  do
    v3 = __ldrex(a1);
  while ( !v3 && __strex(v2, a1) );
  __dmb(0xBu);
  return v3 == 0;
}
