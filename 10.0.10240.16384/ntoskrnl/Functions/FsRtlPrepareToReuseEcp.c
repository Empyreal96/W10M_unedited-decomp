// FsRtlPrepareToReuseEcp 
 
int __fastcall FsRtlPrepareToReuseEcp(int result)
{
  *(_DWORD *)(result - 16) &= 0xFFFFFFF7;
  return result;
}
