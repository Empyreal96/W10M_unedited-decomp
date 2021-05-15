// IovUtilIsVerifiedDeviceStack 
 
BOOL __fastcall IovUtilIsVerifiedDeviceStack(int a1)
{
  int v1; // r5
  int v2; // r3
  int v3; // r4
  int v4; // r8
  int v5; // r6
  int v6; // r0
  int v7; // r2
  int v8; // r3
  unsigned int v9; // r3

  v1 = a1;
  v2 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 16);
  if ( v2 < 0 )
    return (v2 & 0x40000000) != 0;
  v4 = KeAcquireQueuedSpinLock(10);
  v3 = 0;
  while ( 1 )
  {
    v5 = v1;
    v6 = *(_DWORD *)(v1 + 8);
    v1 = *(_DWORD *)(*(_DWORD *)(v1 + 176) + 24);
    if ( MmIsDriverVerifying(v6) )
      v3 = 1;
    if ( !v1 )
      break;
    if ( (*(_DWORD *)(*(_DWORD *)(v1 + 176) + 16) & 0x80000000) != 0 )
    {
      if ( (*(_DWORD *)(*(_DWORD *)(v1 + 176) + 16) & 0x40000000) != 0 )
        v3 = 1;
      goto LABEL_10;
    }
  }
  do
  {
LABEL_10:
    v7 = *(_DWORD *)(v5 + 176);
    v8 = *(_DWORD *)(v7 + 16);
    if ( v3 )
      v9 = v8 | 0x40000000;
    else
      v9 = v8 & 0xBFFFFFFF;
    *(_DWORD *)(v7 + 16) = v9;
    *(_DWORD *)(v7 + 16) = v9 | 0x80000000;
    v5 = *(_DWORD *)(v5 + 16);
  }
  while ( v5 );
  KeReleaseQueuedSpinLock(10, v4);
  return v3;
}
