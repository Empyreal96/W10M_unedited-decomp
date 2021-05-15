// PopSetDevicesSystemState 
 
int PopSetDevicesSystemState()
{
  int v0; // r3
  int v2[10]; // [sp+0h] [bp-28h] BYREF

  memset(v2, 0, 28);
  BYTE1(v2[6]) = byte_61EC7D;
  LOBYTE(v2[6]) = byte_61EC62;
  BYTE2(v2[6]) = byte_61EC7C;
  v2[0] = dword_61EC8C;
  v2[1] = dword_61EC88;
  if ( (dword_61EC6C & 8) != 0 )
    v0 = 6;
  else
    v0 = dword_61EC80;
  v2[2] = v0;
  v2[5] = dword_61EC6C;
  v2[3] = dword_61EC84;
  v2[4] = dword_61EC64;
  return PoBroadcastSystemState(v2);
}
