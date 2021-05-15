// VerifierIoConnectInterrupt 
 
int __fastcall VerifierIoConnectInterrupt(int a1, int (*a2)(), int a3, int a4, int a5, unsigned __int8 a6, unsigned __int8 a7, int a8, unsigned __int8 a9, int a10, unsigned __int8 a11)
{
  int (*v13)(); // r6
  int v14; // r2
  unsigned int v16; // r5
  int v17; // r0
  int v18; // r4

  v13 = a2;
  v14 = ViCtxInitializedIsrStateBlocks;
  v16 = 0;
  __dmb(0xBu);
  if ( v14 )
  {
    v17 = ViCtxAllocateIsrContext(a2, a3, 0);
    v16 = v17;
    if ( !v17 )
      return -1073741670;
    v13 = ViCtxIsr;
    a3 = v17;
  }
  v18 = pXdvIoConnectInterrupt(a1, v13, a3, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( v18 < 0 && v16 )
    ExFreePoolWithTag(v16);
  return v18;
}
