// sub_53C754 
 
void __fastcall sub_53C754(int a1)
{
  int v1; // r5

  if ( v1 )
    KeReleaseQueuedSpinLock(10, a1);
  JUMPOUT(0x49FE6A);
}
