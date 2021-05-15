// VerifierExfTryToWakePushLock 
 
int __fastcall VerifierExfTryToWakePushLock(int a1)
{
  if ( (MmVerifierData & 0x800) != 0 )
    ViExCheckAPCsDisabled(235, a1);
  return pXdvExfTryToWakePushLock(a1);
}
