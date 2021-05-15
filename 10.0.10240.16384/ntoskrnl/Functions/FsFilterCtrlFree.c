// FsFilterCtrlFree 
 
int __fastcall FsFilterCtrlFree(int result)
{
  if ( (*(_DWORD *)(result + 36) & 1) != 0 )
    result = sub_546B14();
  return result;
}
