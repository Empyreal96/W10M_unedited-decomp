// VerifierMmMapLockedPages 
 
int __fastcall VerifierMmMapLockedPages(int a1, char a2)
{
  int v2; // r4
  int v4; // r0
  unsigned int v5; // r1
  unsigned int v6; // r2
  int v7; // r3
  int v8; // r0
  int v9; // r4
  int vars4; // [sp+1Ch] [bp+4h]

  v2 = a2;
  v4 = ViMmMapLockedPagesSanityChecks(a1, a2);
  v7 = *(unsigned __int16 *)(a1 + 6);
  if ( (v7 & 0x2000) == 0 && VfFaultsIsSystemSufficientlyBooted(v4, v5, v6, v7) )
    VerifierBugCheckIfAppropriate(196, 129, a1, *(__int16 *)(a1 + 6), 0);
  v8 = pXdvMmMapLockedPagesSpecifyCache(a1, v2, 1, 0);
  v9 = v8;
  if ( VfPoolTraces )
    ViPoolLogStackTrace(v8, *(_DWORD *)(a1 + 20));
  if ( v9 && (MmVerifierData & 0x1000) != 0 )
    ViTargetAddToCounter(vars4, 104, 108, *(_DWORD *)(a1 + 20));
  return v9;
}
