// PnprLockPagesForReplace 
 
int __fastcall PnprLockPagesForReplace(int a1, int a2, int a3)
{
  MiLockPagableImageSection(ExPageLockHandle, 1, a3, (int)&ExPageLockHandle);
  return ExNotifyCallback(ExCbPowerState, 3, 0);
}
