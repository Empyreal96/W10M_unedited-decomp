// PnprUnlockPagesForReplace 
 
int PnprUnlockPagesForReplace()
{
  MmUnlockPagableImageSection(ExPageLockHandle);
  return ExNotifyCallback(ExCbPowerState, 3, 1);
}
