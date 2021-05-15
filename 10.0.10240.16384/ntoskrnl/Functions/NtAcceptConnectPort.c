// NtAcceptConnectPort 
 
int __fastcall NtAcceptConnectPort(_DWORD *a1, int a2, _DWORD *a3, unsigned __int8 a4, unsigned int a5, unsigned int a6)
{
  unsigned int v6; // r5
  int v7; // r0
  int v8; // r4
  unsigned int v9; // r1
  __int16 v10; // r3

  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v6 + 308);
  v7 = AlpcpAcceptConnectPort(a1, a2, 0, 0, 0, a2, a3, 0, a4, a5, a6, 1u);
  v8 = v7;
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v10 = *(_WORD *)(v9 + 0x134) + 1;
  *(_WORD *)(v9 + 308) = v10;
  if ( !v10 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
    KiCheckForKernelApcDelivery(v7);
  if ( v8 == -1073740029 )
    v8 = -1073741813;
  return v8;
}
