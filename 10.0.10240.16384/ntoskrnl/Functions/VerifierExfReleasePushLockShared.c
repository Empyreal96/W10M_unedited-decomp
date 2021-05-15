// VerifierExfReleasePushLockShared 
 
int __fastcall VerifierExfReleasePushLockShared(int a1)
{
  if ( (MmVerifierData & 0x800) != 0 )
    ViExCheckAPCsDisabled(235, a1);
  return pXdvExfReleasePushLockShared(a1);
}
