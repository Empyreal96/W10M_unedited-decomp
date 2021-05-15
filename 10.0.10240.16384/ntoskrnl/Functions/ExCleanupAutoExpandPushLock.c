// ExCleanupAutoExpandPushLock 
 
int __fastcall ExCleanupAutoExpandPushLock(int result)
{
  if ( (*(_DWORD *)(result + 4) & 1) != 0 )
    result = sub_52356C();
  return result;
}
