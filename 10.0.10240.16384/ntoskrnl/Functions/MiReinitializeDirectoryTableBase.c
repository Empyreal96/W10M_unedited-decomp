// MiReinitializeDirectoryTableBase 
 
unsigned int __fastcall MiReinitializeDirectoryTableBase(int a1, _DWORD *a2, int a3, int a4)
{
  int v7; // r4
  unsigned int result; // r0
  _DWORD v9[6]; // [sp+0h] [bp-18h] BYREF

  v9[0] = a3;
  v9[1] = a4;
  v7 = MiMapPageInHyperSpaceWorker(a3, (int)v9, 0x80000000);
  MiBuildHardwarePageDirectory(v7, *(_DWORD **)(a1 + 32));
  result = MiUnmapPageInHyperSpaceWorker(v7, LOBYTE(v9[0]), 0x80000000);
  *a2 = a3 << 12;
  return result;
}
