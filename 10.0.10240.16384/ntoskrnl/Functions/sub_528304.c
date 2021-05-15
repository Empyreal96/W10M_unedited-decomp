// sub_528304 
 
void __fastcall sub_528304(int a1)
{
  int v1; // r5

  KeReleaseQueuedSpinLock(10, a1);
  ObfDereferenceObjectWithTag(v1);
  JUMPOUT(0x4DD788);
}
