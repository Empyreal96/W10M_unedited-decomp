// IopDmaScoreRequirement 
 
int __fastcall IopDmaScoreRequirement(int a1)
{
  return *(_DWORD *)(a1 + 12) - *(_DWORD *)(a1 + 8);
}
