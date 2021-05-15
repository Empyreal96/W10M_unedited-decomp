// PpmIdleRemoveConcurrency 
 
int __fastcall PpmIdleRemoveConcurrency(int a1)
{
  int v1; // r5
  int v3; // r1
  int v5[6]; // [sp+8h] [bp-18h] BYREF

  v1 = *(_DWORD *)(a1 + 3208);
  if ( v1 )
  {
    KeQueryPerformanceCounter(v5, 0);
    PpmIdleUpdateConcurrency(v1, v3, v5[0], v5[1], 1, 0);
    *(_DWORD *)(a1 + 3208) = 0;
  }
  return 0;
}
