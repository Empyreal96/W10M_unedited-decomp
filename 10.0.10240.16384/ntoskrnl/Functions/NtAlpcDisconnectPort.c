// NtAlpcDisconnectPort 
 
int __fastcall NtAlpcDisconnectPort(int a1, int a2, int a3, int a4)
{
  unsigned int v5; // r2
  char v6; // r3
  int v7; // r4
  unsigned int v8; // r1
  __int16 v9; // r3
  int v11[4]; // [sp+8h] [bp-10h] BYREF

  v11[0] = a3;
  v11[1] = a4;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v5 + 308);
  if ( (a2 & 0xFFFFFFFE) != 0 )
  {
    v7 = -1073741811;
  }
  else
  {
    v6 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
    a1 = ObReferenceObjectByHandle(a1, 1, AlpcPortObjectType, v6, (int)v11, 0);
    v7 = a1;
    if ( a1 >= 0 )
    {
      v7 = AlpcpDisconnectPort(v11[0], a2);
      a1 = ObfDereferenceObject(v11[0]);
    }
  }
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v9 = *(_WORD *)(v8 + 0x134) + 1;
  *(_WORD *)(v8 + 308) = v9;
  if ( !v9 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
    KiCheckForKernelApcDelivery(a1);
  return v7;
}
