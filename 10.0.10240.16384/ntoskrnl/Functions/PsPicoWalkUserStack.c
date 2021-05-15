// PsPicoWalkUserStack 
 
int __fastcall PsPicoWalkUserStack(int a1, int a2)
{
  int v4; // r1
  unsigned int v6; // r2
  int v7; // r0
  unsigned int v8; // r1
  __int16 v9; // r3
  _BYTE v10[152]; // [sp-4h] [bp-98h] BYREF

  v4 = PsGetBaseTrapFrame(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  if ( !dword_61D9D8 )
    return 0;
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v6 + 310);
  v7 = memmove((int)v10, v4, 0x88u);
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v9 = *(_WORD *)(v8 + 0x136) + 1;
  *(_WORD *)(v8 + 310) = v9;
  if ( !v9 && *(_DWORD *)(v8 + 100) != v8 + 100 )
    KiCheckForKernelApcDelivery(v7);
  return dword_61D9D8(v10, a1, a2);
}
