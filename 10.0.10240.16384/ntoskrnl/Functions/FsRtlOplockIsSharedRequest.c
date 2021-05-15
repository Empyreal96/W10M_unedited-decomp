// FsRtlOplockIsSharedRequest 
 
BOOL __fastcall FsRtlOplockIsSharedRequest(int a1)
{
  int v1; // r2

  v1 = *(_DWORD *)(*(_DWORD *)(a1 + 96) + 16);
  return v1 == 589828 || v1 == 590400 && (*(_DWORD *)(*(_DWORD *)(a1 + 12) + 4) & 4) == 0;
}
