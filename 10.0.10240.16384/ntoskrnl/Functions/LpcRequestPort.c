// LpcRequestPort 
 
int __fastcall LpcRequestPort(int a1, int a2)
{
  unsigned int v2; // r2
  int v3; // r0
  int v4; // r4
  unsigned int v5; // r1
  __int16 v6; // r3
  int v8[10]; // [sp+0h] [bp-28h] BYREF

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v8[6] = 65538;
  v8[0] = a1;
  v3 = AlpcpSendMessage(v8, a2);
  v4 = v3;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v6 = *(_WORD *)(v5 + 0x134) + 1;
  *(_WORD *)(v5 + 308) = v6;
  if ( !v6 && *(_DWORD *)(v5 + 100) != v5 + 100 && !*(_WORD *)(v5 + 310) )
    KiCheckForKernelApcDelivery(v3);
  return v4;
}
