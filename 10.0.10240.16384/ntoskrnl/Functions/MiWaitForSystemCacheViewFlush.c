// MiWaitForSystemCacheViewFlush 
 
int __fastcall MiWaitForSystemCacheViewFlush(int result)
{
  while ( (*(_DWORD *)(result + 12) & 0xFFFFF000) != 0 )
  {
    __dmb(0xAu);
    __yield();
  }
  return result;
}
