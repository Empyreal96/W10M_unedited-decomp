// KseGetIoCallbacks 
 
int __fastcall KseGetIoCallbacks(int a1)
{
  return *(_DWORD *)(*(_DWORD *)(a1 + 24) + 28);
}
