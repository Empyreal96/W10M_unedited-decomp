// NtReplyPort 
 
int __fastcall NtReplyPort(int a1, unsigned int a2)
{
  unsigned int v3; // r2
  char v4; // r3
  int v5; // r0
  int v6; // r4
  int v7; // r5
  int v9; // r3
  unsigned int v10; // r1
  __int16 v11; // r3
  int v12; // [sp+8h] [bp-38h] BYREF
  int v13[12]; // [sp+10h] [bp-30h] BYREF

  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v3 + 308);
  v4 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v5 = ObReferenceObjectByHandle(a1, 1, AlpcPortObjectType, v4, (int)&v12, 0);
  v6 = v5;
  if ( v5 >= 0 )
  {
    v7 = v12;
    v13[6] = 0;
    v13[0] = v12;
    if ( (*(_DWORD *)(v12 + 244) & 0x2000) == 0 )
      return sub_81B910();
    v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v6 = AlpcpReplyLegacySynchronousRequest((int)v13, a2, *(char *)(v9 + 346), v9);
    v5 = ObfDereferenceObject(v7);
  }
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = *(_WORD *)(v10 + 0x134) + 1;
  *(_WORD *)(v10 + 308) = v11;
  if ( !v11 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
    KiCheckForKernelApcDelivery(v5);
  return v6;
}
