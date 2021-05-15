// FsRtlResetBaseMcb 
 
int __fastcall FsRtlResetBaseMcb(int result)
{
  *(_DWORD *)(result + 4) = 0;
  return result;
}
