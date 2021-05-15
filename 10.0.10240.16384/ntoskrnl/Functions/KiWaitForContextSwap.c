// KiWaitForContextSwap 
 
int __fastcall KiWaitForContextSwap(int result)
{
  while ( *(_BYTE *)(result + 73) )
  {
    __dmb(0xAu);
    __yield();
  }
  return result;
}
