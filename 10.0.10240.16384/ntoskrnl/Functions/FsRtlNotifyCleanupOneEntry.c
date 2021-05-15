// FsRtlNotifyCleanupOneEntry 
 
int __fastcall FsRtlNotifyCleanupOneEntry(int a1)
{
  *(_WORD *)(a1 + 36) |= 4u;
  if ( *(_DWORD *)(a1 + 24) == a1 + 24 )
    JUMPOUT(0x7E5866);
  return sub_7E585C();
}
