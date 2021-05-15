// CcGetFileObjectFromBcb 
 
unsigned int __fastcall CcGetFileObjectFromBcb(int a1)
{
  return *(_DWORD *)(*(_DWORD *)(a1 + 112) + 68) & 0xFFFFFFF8;
}
