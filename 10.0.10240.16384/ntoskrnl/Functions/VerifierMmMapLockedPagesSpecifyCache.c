// VerifierMmMapLockedPagesSpecifyCache 
 
int __fastcall VerifierMmMapLockedPagesSpecifyCache(int a1, char a2, int a3, int a4, int a5, int a6)
{
  int v6; // r7
  int v10; // r0
  unsigned int v11; // r1
  unsigned int v12; // r2
  int v13; // r3
  int v14; // r0
  int v15; // r4
  int vars4; // [sp+2Ch] [bp+4h]

  v6 = a2;
  ViMmMapLockedPagesSanityChecks(a1, a2);
  v10 = VfCheckPagePriority(a6, vars4);
  if ( (*(_WORD *)(a1 + 6) & 0x2000) == 0 && a5 )
  {
    if ( VfFaultsIsSystemSufficientlyBooted(v10, v11, v12, v13) )
      VerifierBugCheckIfAppropriate(196, 130, a1, *(__int16 *)(a1 + 6), a5);
    goto LABEL_5;
  }
  if ( VfFaultsInjectResourceFailure(0, v11, v12, v13) != 1 )
  {
LABEL_5:
    v14 = MmMapLockedPagesSpecifyCache(a1, v6, a3, a4, a5, a6);
    v15 = v14;
    if ( VfPoolTraces )
      ViPoolLogStackTrace(v14, *(_DWORD *)(a1 + 20));
    if ( v15 && (MmVerifierData & 0x1000) != 0 )
      ViTargetAddToCounter(vars4, 104, 108, *(_DWORD *)(a1 + 20));
    return v15;
  }
  if ( v6 )
    RtlRaiseStatus(-1073741670);
  return 0;
}
