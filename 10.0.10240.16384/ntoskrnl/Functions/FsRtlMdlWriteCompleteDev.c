// FsRtlMdlWriteCompleteDev 
 
int __fastcall FsRtlMdlWriteCompleteDev(int a1, unsigned int *a2, int a3)
{
  if ( (*(_DWORD *)(a1 + 44) & 0x10) != 0 )
    return 0;
  CcMdlWriteComplete2(a1, a2, a3);
  return 1;
}
