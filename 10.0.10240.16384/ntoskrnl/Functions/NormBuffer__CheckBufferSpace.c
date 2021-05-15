// NormBuffer__CheckBufferSpace 
 
BOOL __fastcall NormBuffer__CheckBufferSpace(int a1)
{
  return *(_DWORD *)(a1 + 20) < *(_DWORD *)(a1 + 16);
}
