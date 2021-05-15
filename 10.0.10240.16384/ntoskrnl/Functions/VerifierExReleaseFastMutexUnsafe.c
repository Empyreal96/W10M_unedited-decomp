// VerifierExReleaseFastMutexUnsafe 
 
int __fastcall VerifierExReleaseFastMutexUnsafe(int a1)
{
  int vars4; // [sp+Ch] [bp+4h]

  if ( (MmVerifierData & 0x800) != 0 )
    ViExCheckAPCsDisabled(58, a1);
  VfDeadlockReleaseResource(a1, 4, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, vars4);
  return pXdvExReleaseFastMutexUnsafe(a1);
}
