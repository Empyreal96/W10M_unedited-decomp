// MiReferenceCfgVad 
 
int __fastcall MiReferenceCfgVad(int a1, unsigned int a2, int a3, int a4)
{
  int v6; // r0
  int v7; // r3
  int v9[4]; // [sp+0h] [bp-10h] BYREF

  v9[0] = a4;
  v6 = MiObtainReferencedVad(a2, v9);
  v7 = *(_DWORD *)(v6 + 16);
  MEMORY[0xC0402154] = v6;
  MEMORY[0xC040214C] = a2;
  MEMORY[0xC0402150] = ((v7 + 1) << 12) - a2;
  return MiUnlockVad(a1, v6);
}
