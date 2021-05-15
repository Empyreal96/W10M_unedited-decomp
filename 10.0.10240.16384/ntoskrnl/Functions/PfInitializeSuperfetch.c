// PfInitializeSuperfetch 
 
int PfInitializeSuperfetch()
{
  int v0; // r1
  int v1; // r2
  int v2; // r3
  unsigned int v3; // r1
  unsigned int v5; // r1
  int v6; // r1

  PfpParametersInitialize(&PfGlobals);
  PfpRpInitialize(&dword_6372E0);
  PfpScenCtxInitialize((int)&unk_637290);
  PfpScenCtxStart((int)&unk_637290, v0, v1, v2);
  dword_63734C[0] = 0;
  do
    v3 = __ldrex(dword_63734C);
  while ( !v3 && __strex(1u, dword_63734C) );
  __dmb(0xBu);
  if ( v3 )
    return sub_96E4A4(1);
  __dmb(0xBu);
  do
    v5 = __ldrex(dword_63734C);
  while ( __strex(1u, dword_63734C) );
  __dmb(0xBu);
  dword_637350 = 0;
  dword_637354 = 0;
  dword_63735C = (int)&dword_637358;
  dword_637358 = (int)&dword_637358;
  dword_637360 |= 1u;
  PfSnInitializePrefetcher();
  PfTInitialize(&PfTGlobals, v6, 0);
  PfpParametersStartWatch(&PfGlobals);
  return 0;
}
