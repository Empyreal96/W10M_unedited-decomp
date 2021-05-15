// FsRtlOplockBreakToNone 
 
int __fastcall FsRtlOplockBreakToNone(_DWORD *a1)
{
  int result; // r0

  if ( *a1 )
    result = FsRtlOplockBreakToNoneEx();
  else
    result = 0;
  return result;
}
