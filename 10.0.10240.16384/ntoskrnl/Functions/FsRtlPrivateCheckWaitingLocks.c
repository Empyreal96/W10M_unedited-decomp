// FsRtlPrivateCheckWaitingLocks 
 
int __fastcall FsRtlPrivateCheckWaitingLocks(int a1, int a2)
{
  int result; // r0

  if ( *(_DWORD *)(a2 + 12) )
    result = sub_51E3D0();
  return result;
}
