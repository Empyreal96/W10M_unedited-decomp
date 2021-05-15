// VerifierMmUnmapLockedPages 
 
int __fastcall VerifierMmUnmapLockedPages(unsigned int a1, int a2)
{
  unsigned int v4; // r0
  int v5; // r1
  int v6; // r3
  int v7; // r2
  int vars4; // [sp+1Ch] [bp+4h]

  v4 = KeGetCurrentIrql(a1);
  if ( a1 <= MmHighestUserAddress )
  {
    if ( v4 > 1 )
    {
      v5 = 122;
      goto LABEL_6;
    }
  }
  else if ( v4 > 2 )
  {
    v5 = 121;
LABEL_6:
    VerifierBugCheckIfAppropriate(196, v5, v4, a1, a2);
    goto LABEL_7;
  }
LABEL_7:
  if ( (unsigned int)VfVerifyMode >= 3 && a1 > MmHighestUserAddress )
  {
    v6 = *(__int16 *)(a2 + 6);
    if ( (v6 & 1) == 0 )
      VerifierBugCheckIfAppropriate(196, 182, a2, v6, 1);
  }
  v7 = *(_DWORD *)(a2 + 20);
  if ( (MmVerifierData & 0x1000) != 0 )
    ViTargetAddToCounter(vars4, 104, 108, -v7);
  return pXdvMmUnmapLockedPages(a1, a2, v7);
}
