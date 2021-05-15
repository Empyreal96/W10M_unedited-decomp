// NtAlpcCreatePort 
 
int __fastcall NtAlpcCreatePort(_DWORD *a1, _BYTE *a2, unsigned int a3)
{
  unsigned int v3; // r4
  int v4; // r0
  int v5; // r4
  unsigned int v6; // r1
  __int16 v7; // r3

  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v3 + 308);
  v4 = AlpcpCreateConnectionPort(a1, a2, a3, 0, 0, 0);
  v5 = v4;
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = *(_WORD *)(v6 + 0x134) + 1;
  *(_WORD *)(v6 + 308) = v7;
  if ( !v7 && *(_DWORD *)(v6 + 100) != v6 + 100 && !*(_WORD *)(v6 + 310) )
    KiCheckForKernelApcDelivery(v4);
  return v5;
}
