// NtAlpcAcceptConnectPort 
 
int __fastcall NtAlpcAcceptConnectPort(int a1)
{
  unsigned int v1; // r4
  int v2; // r0
  int v3; // r4
  unsigned int v4; // r1
  __int16 v5; // r3

  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v1 + 308);
  v2 = AlpcpAcceptConnectPort(a1);
  v3 = v2;
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = *(_WORD *)(v4 + 0x134) + 1;
  *(_WORD *)(v4 + 308) = v5;
  if ( !v5 && *(_DWORD *)(v4 + 100) != v4 + 100 && !*(_WORD *)(v4 + 310) )
    KiCheckForKernelApcDelivery(v2);
  return v3;
}
