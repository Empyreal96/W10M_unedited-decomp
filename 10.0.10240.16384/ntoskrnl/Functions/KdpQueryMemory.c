// KdpQueryMemory 
 
int __fastcall KdpQueryMemory(_DWORD *a1)
{
  int v2; // r5
  unsigned int v3; // r0
  int v4; // r3

  v2 = 0;
  if ( a1[8] )
  {
    v2 = -1073741811;
  }
  else
  {
    v3 = a1[4];
    if ( v3 >= MmHighestUserAddress )
    {
      if ( MmIsSessionAddress(v3) )
        v4 = 1;
      else
        v4 = 2;
      a1[8] = v4;
    }
    else
    {
      a1[8] = 0;
    }
    a1[9] = 7;
  }
  a1[2] = v2;
  a1[6] = 0;
  a1[7] = 0;
  return KdSendPacket_0();
}
