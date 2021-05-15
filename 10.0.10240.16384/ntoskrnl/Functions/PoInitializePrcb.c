// PoInitializePrcb 
 
int __fastcall PoInitializePrcb(int a1)
{
  int result; // r0

  memset((_BYTE *)(a1 + 2944), 0, 328);
  *(_DWORD *)(a1 + 3120) = PpmWmiDispatch;
  *(_BYTE *)(a1 + 3128) = 1;
  *(_DWORD *)(a1 + 3228) = 100;
  *(_DWORD *)(a1 + 3224) = 100;
  *(_BYTE *)(a1 + 3220) = 100;
  *(_BYTE *)(a1 + 3104) = 2;
  result = KeInitializeDpc(a1 + 3160, (int)PpmPerfAction, a1);
  *(_WORD *)(a1 + 3162) = *(_DWORD *)(a1 + 20) + 32;
  *(_BYTE *)(a1 + 3161) = 3;
  *(_DWORD *)(a1 + 3112) = 0;
  return result;
}
