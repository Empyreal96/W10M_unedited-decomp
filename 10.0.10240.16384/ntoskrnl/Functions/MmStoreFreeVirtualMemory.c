// MmStoreFreeVirtualMemory 
 
int __fastcall MmStoreFreeVirtualMemory(unsigned int a1, int a2, int a3, int a4)
{
  int v5; // r7
  __int64 v6; // kr00_8
  int v8; // [sp+0h] [bp-20h]
  int v9; // [sp+8h] [bp-18h] BYREF
  int v10[5]; // [sp+Ch] [bp-14h] BYREF

  v9 = a3;
  v10[0] = a4;
  v5 = MiObtainReferencedVad(a1, v10);
  v6 = *(_QWORD *)(v5 + 12);
  MiUnlockPageTableRange(a1, (HIDWORD(v6) << 12) | 0xFFF);
  LOBYTE(v9) = 0;
  v8 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  MiFreeVadRange(v5, (int)&v9, v6, SHIDWORD(v6));
  return v8;
}
