// BgkResumeFinished 
 
int BgkResumeFinished()
{
  int result; // r0
  int v1; // r0

  if ( !dword_64B0A4 )
    return BgkpUnlockBgfxCodeSection(dword_64B0A4);
  v1 = BgFreeContext();
  dword_64B0A4 = 0;
  result = BgkpUnlockBgfxCodeSection(v1);
  byte_64A430 = 0;
  return result;
}
