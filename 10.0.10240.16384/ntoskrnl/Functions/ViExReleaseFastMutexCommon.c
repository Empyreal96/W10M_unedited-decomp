// ViExReleaseFastMutexCommon 
 
int __fastcall ViExReleaseFastMutexCommon(int a1)
{
  char v2; // r0

  if ( (MmVerifierData & 0x800) != 0 )
    v2 = ViExCheckAPCsDisabled(52, a1);
  else
    v2 = KeGetCurrentIrql(a1);
  return VfKeIrqlTransitionReserveLogEntry(v2, *(_DWORD *)(a1 + 28));
}
