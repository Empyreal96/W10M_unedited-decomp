// IoStartNextPacket 
 
int __fastcall IoStartNextPacket(int a1)
{
  int result; // r0

  if ( (*(_DWORD *)(*(_DWORD *)(a1 + 176) + 36) & 0x100) != 0 )
    result = IopStartNextPacketByKeyEx();
  else
    result = IopStartNextPacket();
  return result;
}
