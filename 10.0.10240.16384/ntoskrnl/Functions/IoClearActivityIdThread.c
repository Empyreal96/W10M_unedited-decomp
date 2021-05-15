// IoClearActivityIdThread 
 
int __fastcall IoClearActivityIdThread(int result)
{
  *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x40C) = result;
  return result;
}
