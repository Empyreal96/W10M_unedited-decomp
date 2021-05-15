// IopStartNextPacketByKeyEx 
 
int __fastcall IopStartNextPacketByKeyEx(int result, int a2, int a3)
{
  _DWORD *v4; // r7
  unsigned int *v5; // r4
  unsigned int v6; // r5
  signed int v7; // r5
  unsigned int *v8; // r2
  unsigned int v9; // r1
  unsigned int v10; // r1

  v4 = (_DWORD *)result;
  do
  {
    __dmb(0xBu);
    v5 = (unsigned int *)(v4[44] + 28);
    do
    {
      v6 = __ldrex(v5);
      v7 = v6 + 1;
    }
    while ( __strex(v7, v5) );
    __dmb(0xBu);
    if ( v7 <= 1 )
    {
      *(_DWORD *)(v4[44] + 36) &= 0xFFFFFF1F;
      *(_DWORD *)(v4[44] + 32) = 0;
      if ( (a3 & 0x40) != 0 )
      {
        result = IopStartNextPacketByKey(v4, a3 & 0x80, a2);
      }
      else if ( (a3 & 0x20) != 0 )
      {
        result = IopStartNextPacket(v4, a3 & 0x80);
      }
    }
    else
    {
      *(_DWORD *)(v4[44] + 36) |= a3;
      *(_DWORD *)(v4[44] + 32) = a2;
    }
    __dmb(0xBu);
    v8 = (unsigned int *)(v4[44] + 28);
    do
    {
      v9 = __ldrex(v8);
      v10 = v9 - 1;
    }
    while ( __strex(v10, v8) );
    __dmb(0xBu);
    if ( v10 )
      break;
    a2 = *(_DWORD *)(v4[44] + 32);
    a3 = *(_DWORD *)(v4[44] + 36) & 0xE0;
  }
  while ( (*(_DWORD *)(v4[44] + 36) & 0x60) != 0 );
  return result;
}
