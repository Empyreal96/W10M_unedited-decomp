// PfSnPrefetchCacheCtxInitialize 
 
int __fastcall PfSnPrefetchCacheCtxInitialize(int a1)
{
  memset((_BYTE *)a1, 0, 80);
  *(_DWORD *)a1 = 0;
  *(_DWORD *)(a1 + 4) = 0;
  *(_DWORD *)(a1 + 8) = 0;
  *(_DWORD *)(a1 + 12) = a1 + 12;
  *(_DWORD *)(a1 + 16) = a1 + 12;
  *(_DWORD *)(a1 + 20) = 0;
  return ExInitializeResourceLite(a1 + 24);
}
