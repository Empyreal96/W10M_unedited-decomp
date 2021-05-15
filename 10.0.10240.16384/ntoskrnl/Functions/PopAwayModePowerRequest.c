// PopAwayModePowerRequest 
 
int __fastcall PopAwayModePowerRequest(int a1)
{
  PopAcquireAwaymodeLock();
  byte_61EC10 = a1 != 0;
  PopReleaseAwaymodeLock();
  return 0;
}
