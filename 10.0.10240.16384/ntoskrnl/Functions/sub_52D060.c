// sub_52D060 
 
void __fastcall sub_52D060(int a1)
{
  int v1; // r4

  KiAcquireQueuedSpinLockInstrumented(a1, v1);
  JUMPOUT(0x4772F8);
}
