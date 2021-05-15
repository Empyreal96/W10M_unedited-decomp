// VerifierExfAcquirePushLockShared 
 
int __fastcall VerifierExfAcquirePushLockShared(int a1)
{
  if ( (MmVerifierData & 0x800) != 0 )
    ViExCheckAPCsDisabled(234, a1);
  return pXdvExfAcquirePushLockShared(a1);
}
