// ExWnfServerSiloTerminated 
 
int __fastcall ExWnfServerSiloTerminated(int a1)
{
  int v1; // r4
  unsigned int v2; // r2
  int v3; // r0
  unsigned int v4; // r1
  __int16 v5; // r3

  v1 = PsAttachSiloToCurrentThread(a1);
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  ExpWnfDeleteScopeInstances(2);
  v3 = ExpWnfDeleteScopeInstances(0);
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = *(_WORD *)(v4 + 0x134) + 1;
  *(_WORD *)(v4 + 308) = v5;
  if ( !v5 && *(_DWORD *)(v4 + 100) != v4 + 100 && !*(_WORD *)(v4 + 310) )
    KiCheckForKernelApcDelivery(v3);
  return PsDetachSiloFromCurrentThread(v1);
}
