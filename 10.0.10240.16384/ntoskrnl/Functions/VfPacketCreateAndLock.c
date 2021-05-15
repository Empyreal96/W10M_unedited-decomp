// VfPacketCreateAndLock 
 
int __fastcall VfPacketCreateAndLock(unsigned int a1)
{
  int v2; // r0
  int v3; // r1
  int v4; // r4
  char v5; // r3
  int v6; // r3

  v2 = ExAllocateFromNPagedLookasideList((int)&ViPacketLookaside);
  v4 = v2;
  if ( !v2 )
    return 0;
  *(_DWORD *)(v2 + 36) = 0;
  *(_DWORD *)(v2 + 44) = v2 + 44;
  *(_DWORD *)(v2 + 48) = v2 + 44;
  v5 = *(_BYTE *)(a1 + 34);
  *(_DWORD *)(v2 + 60) = 0;
  *(_DWORD *)(v2 + 64) = 0;
  *(_BYTE *)(v2 + 68) = 0;
  *(_BYTE *)(v2 + 52) = v5;
  *(_DWORD *)(v2 + 72) = 0;
  *(_BYTE *)(v2 + 108) = 0;
  *(_BYTE *)(v2 + 109) = 0;
  *(_BYTE *)(v2 + 110) = 0;
  *(_DWORD *)(v2 + 112) = 0;
  *(_DWORD *)(v2 + 116) = 0;
  *(_DWORD *)(v2 + 140) = 0;
  *(_DWORD *)(v2 + 144) = 0;
  *(_DWORD *)(v2 + 56) = 0;
  *(_DWORD *)(v2 + 120) = 0;
  *(_DWORD *)(v2 + 124) = 0;
  *(_DWORD *)(v2 + 128) = 0;
  *(_DWORD *)(v2 + 132) = 0;
  v6 = MmVerifierData;
  *(_DWORD *)(v2 + 136) = MmVerifierData;
  VfIrpDatabaseEntryInsertAndLock(a1, v3, (unsigned int *)v2, v6);
  return v4;
}
