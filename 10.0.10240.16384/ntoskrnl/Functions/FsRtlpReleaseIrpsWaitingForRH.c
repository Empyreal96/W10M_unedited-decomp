// FsRtlpReleaseIrpsWaitingForRH 
 
int __fastcall FsRtlpReleaseIrpsWaitingForRH(int result)
{
  if ( *(_DWORD *)(result + 44) != result + 44 )
    result = sub_5295CC();
  return result;
}
