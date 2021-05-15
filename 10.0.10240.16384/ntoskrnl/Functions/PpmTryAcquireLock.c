// PpmTryAcquireLock 
 
int PpmTryAcquireLock()
{
  int v0; // r3
  int v1; // r0
  int v2; // r4
  unsigned int v4; // r1
  int v5; // r3

  v0 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v0 & 0xFFFFFFC0) + 0x136);
  v1 = KeWaitForSingleObject(&byte_61E8A4, 0, 0);
  if ( v1 )
  {
    v2 = 0;
    v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v5 = (__int16)(*(_WORD *)(v4 + 0x136) + 1);
    *(_WORD *)(v4 + 310) = v5;
    if ( !v5 && *(_DWORD *)(v4 + 100) != v4 + 100 )
      KiCheckForKernelApcDelivery(v1);
  }
  else
  {
    v2 = 1;
    PpmPerfPolicyLock = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  }
  return v2;
}
