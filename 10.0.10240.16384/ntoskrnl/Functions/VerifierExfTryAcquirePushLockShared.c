// VerifierExfTryAcquirePushLockShared 
 
int __fastcall VerifierExfTryAcquirePushLockShared(int a1)
{
  if ( (MmVerifierData & 0x800) != 0 )
    ViExCheckAPCsDisabled(234, a1);
  return pXdvExfTryAcquirePushLockShared(a1);
}
