// FsRtlIsPagingFile 
 
BOOL __fastcall FsRtlIsPagingFile(int a1)
{
  int v1; // r3

  v1 = *(_DWORD *)(a1 + 12);
  return v1 && (*(_BYTE *)(v1 + 6) & 8) != 0;
}
