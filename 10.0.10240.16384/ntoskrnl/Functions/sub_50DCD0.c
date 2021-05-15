// sub_50DCD0 
 
void __fastcall sub_50DCD0(int a1)
{
  int v1; // r4

  KiAcquireQueuedSpinLockInstrumented(v1, a1);
  JUMPOUT(0x49DF24);
}
