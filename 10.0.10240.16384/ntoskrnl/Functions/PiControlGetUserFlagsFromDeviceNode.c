// PiControlGetUserFlagsFromDeviceNode 
 
int __fastcall PiControlGetUserFlagsFromDeviceNode(int a1, int *a2)
{
  int v4; // r4
  int v5; // r1
  int v6; // r2
  int v7; // r3
  int result; // r0
  int v9; // r3
  int v10; // r3

  v4 = 25165824;
  if ( PipAreDriversLoaded(a1) )
    v4 = 25165826;
  if ( PipIsDevNodeDNStarted(a1) )
    v4 |= 8u;
  result = CmIsRootEnumeratedDevice(*(unsigned __int16 **)(a1 + 24), v5, v6, v7);
  if ( result )
    v4 |= 1u;
  if ( (*(_DWORD *)(a1 + 368) & 0x10) != 0 )
    v4 |= 0x4000u;
  v9 = *(_DWORD *)(a1 + 272);
  if ( (v9 & 1) != 0 )
    v4 |= 0x40000u;
  if ( (v9 & 2) != 0 )
    v4 |= 0x40000000u;
  if ( (v9 & 0x40) != 0 )
    v4 |= 0x2000000u;
  if ( (v9 & 4) != 0 )
    v4 |= 0x100u;
  v10 = *(_DWORD *)(a1 + 268);
  if ( (v10 & 0x4000) != 0 )
    v4 |= 0x8000u;
  if ( (v10 & 0x2000) != 0 )
    v4 |= 0x400u;
  if ( (v10 & 0x100000) != 0 )
    v4 |= 0x40u;
  if ( (v10 & 0x1000) != 0 )
    v4 |= 0x1000u;
  if ( (v10 & 0x200000) != 0 )
    v4 |= 0x200u;
  if ( !*(_DWORD *)(a1 + 388) )
    v4 |= 0x2000u;
  *a2 = v4;
  return result;
}
