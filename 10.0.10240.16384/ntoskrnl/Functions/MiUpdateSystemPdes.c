// MiUpdateSystemPdes 
 
unsigned int __fastcall MiUpdateSystemPdes(int a1, int a2, int a3, int a4)
{
  unsigned int v5; // r6
  int v6; // r8
  int v7; // r7
  int v8; // r0
  int v9; // r4
  int v10; // r5
  int v11; // r3
  int v12; // r3
  _DWORD v14[8]; // [sp+0h] [bp-20h] BYREF

  v14[0] = a3;
  v14[1] = a4;
  v5 = (MiGetTopPteAddress(0xC0402000) >> 2) & 0x3FF;
  v6 = *(_DWORD *)(a1 + 24) >> 12;
  v7 = MEMORY[0xC0300C00] & 0xFFF;
  v8 = MiMapPageInHyperSpaceWorker(v6, (int)v14, 0x80000000);
  v9 = *(_DWORD *)(v8 + 4 * v5);
  v10 = v8;
  MiCopyTopLevelMappings(a1, v8);
  MiArmWritePdeOtherProcess(a1, (_DWORD *)(v10 + 4 * v5), v9, v11);
  MiArmWritePdeOtherProcess(a1, (_DWORD *)(v10 + 3072), v7 | (v6 << 12), v12);
  return MiUnmapPageInHyperSpaceWorker(v10, LOBYTE(v14[0]), 0x80000000);
}
