// VerifierMmProbeAndLockPages 
 
int __fastcall VerifierMmProbeAndLockPages(int a1, char a2, int a3)
{
  int v4; // r6
  unsigned int v6; // r0
  int v7; // r4
  int v8; // r2
  int v9; // r1
  int v10; // r3
  int result; // r0
  int vars4; // [sp+1Ch] [bp+4h]

  v4 = a2;
  v6 = KeGetCurrentIrql(a1);
  if ( v6 > 2 )
    VerifierBugCheckIfAppropriate(196, 112, v6, a1, v4);
  v7 = 2071;
  if ( (unsigned int)VfVerifyMode < 3 )
    v7 = 2067;
  v8 = *(__int16 *)(a1 + 6);
  v9 = v8 & v7;
  v10 = (unsigned __int16)(v8 & v7);
  if ( ((unsigned __int16)v8 & (unsigned __int16)v7) != 0 )
    VerifierBugCheckIfAppropriate(196, 176, a1, v8, v8 & v7);
  if ( VfFaultsInjectResourceFailure(0, v9, v8, v10) == 1 )
    RtlRaiseStatus(-1073741663);
  result = pXdvMmProbeAndLockPages(a1, v4, a3);
  if ( (MmVerifierData & 0x1000) != 0 )
    result = ViTargetAddToCounter(vars4, 96, 100, *(_DWORD *)(a1 + 20));
  return result;
}
