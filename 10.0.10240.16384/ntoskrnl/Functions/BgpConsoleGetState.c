// BgpConsoleGetState 
 
int __fastcall BgpConsoleGetState(_DWORD *a1)
{
  BgpFwAcquireLock((unsigned int)a1);
  *a1 = dword_61035C;
  a1[1] = dword_610360;
  a1[2] = dword_610348[0];
  a1[3] = dword_61034C;
  a1[4] = dword_610370;
  a1[5] = dword_610374;
  a1[6] = dword_61037C;
  a1[7] = dword_610380;
  BgpFwReleaseLock();
  return 0;
}
