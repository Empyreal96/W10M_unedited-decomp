// MiInitializeImageHeaderPage 
 
int __fastcall MiInitializeImageHeaderPage(int a1, int a2, int a3, int a4)
{
  int v5; // r4
  int result; // r0
  int v7[4]; // [sp+0h] [bp-10h] BYREF

  v7[0] = a4;
  v5 = MiMapPageInHyperSpaceWorker(a1, v7, 0x80000000);
  memset((_BYTE *)(v5 + a2), 0, 4096 - a2);
  result = MiUnmapPageInHyperSpaceWorker(v5, LOBYTE(v7[0]), 0x80000000);
  if ( (a2 & 0x1FF) != 0 )
    result = sub_51AB08(result);
  return result;
}
