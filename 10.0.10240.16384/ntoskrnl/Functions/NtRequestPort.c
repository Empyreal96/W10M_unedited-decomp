// NtRequestPort 
 
int __fastcall NtRequestPort(int a1, int a2)
{
  int v3; // r3
  int v4; // r4
  int v5; // r5
  unsigned int v6; // r2
  int v7; // r0
  unsigned int v8; // r1
  __int16 v9; // r3
  int v11; // [sp+8h] [bp-38h] BYREF
  int v12[12]; // [sp+10h] [bp-30h] BYREF

  v3 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v4 = ObReferenceObjectByHandle(a1, 1, AlpcPortObjectType, v3, &v11);
  if ( v4 >= 0 )
  {
    v5 = v11;
    v12[6] = 0x10000;
    v12[0] = v11;
    v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v6 + 308);
    __mrc(15, 0, 13, 0, 3);
    v7 = AlpcpSendMessage(v12, a2);
    v4 = v7;
    v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v9 = *(_WORD *)(v8 + 0x134) + 1;
    *(_WORD *)(v8 + 308) = v9;
    if ( !v9 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
      KiCheckForKernelApcDelivery(v7);
    ObfDereferenceObject(v5);
  }
  return v4;
}
