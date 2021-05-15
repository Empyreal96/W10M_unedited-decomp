// sub_527EAC 
 
void __fastcall sub_527EAC(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // r5
  int v8; // r7
  int v9; // r10
  int v10; // r5
  int v11; // r1
  BOOL v12; // r4

  v10 = IopGetDeviceAttachmentBase(v7);
  a7 = v10;
  v12 = PnpIsAnyDeviceInUse(&a7, v11, 0);
  KeReleaseQueuedSpinLock(10, v8);
  if ( !v12 )
    PnpChainDereferenceComplete(v10, v9);
  JUMPOUT(0x4DC98C);
}
