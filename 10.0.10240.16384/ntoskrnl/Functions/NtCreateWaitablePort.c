// NtCreateWaitablePort 
 
int __fastcall NtCreateWaitablePort(_DWORD *a1, _BYTE *a2, int a3, int a4)
{
  unsigned int v4; // r4
  int v5; // r0
  int v6; // r4
  unsigned int v7; // r1
  __int16 v8; // r3

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 308);
  v5 = AlpcpCreateConnectionPort(a1, a2, 0, a4, 1u, 1);
  v6 = v5;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v8 = *(_WORD *)(v7 + 0x134) + 1;
  *(_WORD *)(v7 + 308) = v8;
  if ( !v8 && *(_DWORD *)(v7 + 100) != v7 + 100 && !*(_WORD *)(v7 + 310) )
    KiCheckForKernelApcDelivery(v5);
  return v6;
}
