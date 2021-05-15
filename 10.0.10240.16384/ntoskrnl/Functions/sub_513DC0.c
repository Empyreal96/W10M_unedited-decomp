// sub_513DC0 
 
void __fastcall sub_513DC0(int a1)
{
  int v1; // r4

  KiTryToAcquireQueuedSpinLockInstrumented(v1, a1);
  JUMPOUT(0x43019A);
}
