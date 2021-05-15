// PfpScenCtxInitialize 
 
int __fastcall PfpScenCtxInitialize(int a1)
{
  memset((_BYTE *)a1, 0, 80);
  *(_DWORD *)a1 = 0;
  *(_DWORD *)(a1 + 28) = 0;
  *(_DWORD *)(a1 + 4) &= 0xFFFFFFFC;
  return KeInitializeEvent(a1 + 8, 0, 0);
}
