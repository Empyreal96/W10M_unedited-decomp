// FsRtlAcknowledgeEcp 
 
int __fastcall FsRtlAcknowledgeEcp(int result)
{
  *(_DWORD *)(result - 16) |= 8u;
  return result;
}
