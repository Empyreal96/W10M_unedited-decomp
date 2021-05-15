// MmGetIoSessionState 
 
int __fastcall MmGetIoSessionState(int a1, _DWORD *a2)
{
  int v2; // r2

  v2 = *(_DWORD *)(a1 + 16);
  if ( a2 )
    *a2 = *(_DWORD *)(v2 + 8);
  return *(_DWORD *)(v2 + 8388);
}
