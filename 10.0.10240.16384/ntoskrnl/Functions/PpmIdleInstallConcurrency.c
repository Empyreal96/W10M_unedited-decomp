// PpmIdleInstallConcurrency 
 
int __fastcall PpmIdleInstallConcurrency(int a1, int a2, int a3, int a4)
{
  int v6; // r1
  int v8; // [sp+8h] [bp-10h] BYREF
  int v9; // [sp+Ch] [bp-Ch]

  v8 = a3;
  v9 = a4;
  KeQueryPerformanceCounter(&v8, 0);
  PpmIdleUpdateConcurrency(a2, v6, v8, v9, 0, 0);
  *(_DWORD *)(a1 + 3208) = a2;
  return 0;
}
