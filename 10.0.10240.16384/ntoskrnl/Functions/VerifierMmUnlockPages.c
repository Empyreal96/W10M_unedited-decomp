// VerifierMmUnlockPages 
 
int __fastcall VerifierMmUnlockPages(int a1)
{
  unsigned int v2; // r0
  int v3; // r4
  int vars4; // [sp+1Ch] [bp+4h]

  v2 = KeGetCurrentIrql(a1);
  if ( v2 > 2 )
    VerifierBugCheckIfAppropriate(196, 120, v2, a1, 0);
  v3 = *(__int16 *)(a1 + 6);
  if ( (v3 & 2) == 0 )
    VerifierBugCheckIfAppropriate(196, 124, a1, *(__int16 *)(a1 + 6), 0);
  if ( (unsigned int)VfVerifyMode >= 3 && (v3 & 4) != 0 )
    VerifierBugCheckIfAppropriate(196, 125, a1, v3, 0);
  if ( (v3 & 0x10) != 0 )
    VerifierBugCheckIfAppropriate(196, 180, a1, v3, 16);
  if ( (v3 & 1) != 0 && (MmVerifierData & 0x1000) != 0 )
    ViTargetAddToCounter(vars4, 104, 108, -*(_DWORD *)(a1 + 20));
  if ( (MmVerifierData & 0x1000) != 0 )
    ViTargetAddToCounter(vars4, 96, 100, -*(_DWORD *)(a1 + 20));
  return pXdvMmUnlockPages(a1);
}
