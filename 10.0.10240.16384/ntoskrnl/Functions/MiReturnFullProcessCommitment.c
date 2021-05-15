// MiReturnFullProcessCommitment 
 
int __fastcall MiReturnFullProcessCommitment(int a1, int a2)
{
  __int16 *v4; // r0
  int v5; // r1
  int v6; // r2
  int v7; // r3

  v4 = MiGetThreadPartition();
  MiReturnCommit((int)v4, v5);
  return MiReturnFullProcessCharges(a1, a2, v6, v7);
}
