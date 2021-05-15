// MiUnsecureVirtualMemoryAgainstWrites 
 
int __fastcall MiUnsecureVirtualMemoryAgainstWrites(_DWORD *a1, unsigned int a2, unsigned int a3)
{
  int v4; // [sp+10h] [bp-10h] BYREF
  int v5[3]; // [sp+14h] [bp-Ch] BYREF

  v4 = 0;
  return MiSetProtectionOnSection(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), a1, a2, a3, 4u, 0, v5, &v4);
}
