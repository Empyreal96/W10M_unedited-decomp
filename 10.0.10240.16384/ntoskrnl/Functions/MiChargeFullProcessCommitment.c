// MiChargeFullProcessCommitment 
 
int __fastcall MiChargeFullProcessCommitment(_DWORD *a1, unsigned int a2)
{
  int v4; // r0
  __int16 *v6; // r0

  if ( a1 != (_DWORD *)PsInitialSystemProcess )
  {
    v4 = a1[83];
    __dmb(0xBu);
    if ( PspChargeQuota(v4, (int)a1, 2, a2) < 0 )
      return sub_800E74();
  }
  if ( !MiChargeProcessCommitment(a1, a2)
    || (a1[47] & 0x10) != 0 && !PspChangeJobMemoryUsageByProcess(16, a2, a1, 0)
    || (v6 = MiGetThreadPartition(), !MiChargeCommit((int)v6, a2, 0)) )
  {
    JUMPOUT(0x800E76);
  }
  return 0;
}
