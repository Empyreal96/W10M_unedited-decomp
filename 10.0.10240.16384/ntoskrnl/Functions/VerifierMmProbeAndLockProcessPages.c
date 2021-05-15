// VerifierMmProbeAndLockProcessPages 
 
int __fastcall VerifierMmProbeAndLockProcessPages(int a1, int a2, char a3, int a4)
{
  int v5; // r9
  unsigned int v8; // r0
  int v9; // r5
  int v10; // r2
  int v11; // r1
  int v12; // r3
  int result; // r0
  int vars4; // [sp+24h] [bp+4h]

  v5 = a3;
  v8 = KeGetCurrentIrql(a1);
  if ( v8 > 2 )
    VerifierBugCheckIfAppropriate(196, 113, v8, a1, a2);
  v9 = 2071;
  if ( (unsigned int)VfVerifyMode < 3 )
    v9 = 2067;
  v10 = *(__int16 *)(a1 + 6);
  v11 = v10 & v9;
  v12 = (unsigned __int16)(v10 & v9);
  if ( ((unsigned __int16)v10 & (unsigned __int16)v9) != 0 )
    VerifierBugCheckIfAppropriate(196, 177, a1, v10, v10 & v9);
  if ( VfFaultsInjectResourceFailure(0, v11, v10, v12) == 1 )
    RtlRaiseStatus(-1073741663);
  result = pXdvMmProbeAndLockProcessPages(a1, a2, v5, a4);
  if ( (MmVerifierData & 0x1000) != 0 )
    result = ViTargetAddToCounter(vars4, 96, 100, *(_DWORD *)(a1 + 20));
  return result;
}
