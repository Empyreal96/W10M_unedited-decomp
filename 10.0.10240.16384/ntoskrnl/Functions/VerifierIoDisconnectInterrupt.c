// VerifierIoDisconnectInterrupt 
 
unsigned int __fastcall VerifierIoDisconnectInterrupt(int a1)
{
  unsigned int v1; // r4
  int v2; // r3
  unsigned int result; // r0

  v1 = 0;
  v2 = ViCtxInitializedIsrStateBlocks;
  __dmb(0xBu);
  if ( v2 )
    v1 = *(_DWORD *)(a1 + 24);
  result = pXdvIoDisconnectInterrupt();
  if ( v1 )
    result = ExFreePoolWithTag(v1);
  return result;
}
