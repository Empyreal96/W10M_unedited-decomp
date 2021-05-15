// MmCleanProcessAddressSpace 
 
int __fastcall MmCleanProcessAddressSpace(int a1)
{
  unsigned int v1; // r2
  unsigned int v3; // r3
  int result; // r0
  int v5; // r8
  int v6; // r10
  __int16 *v7; // r9
  int v8; // r4
  unsigned int v9; // r1
  unsigned int v10; // r1
  int v11; // r0
  int v12; // r1
  int v13; // r2
  int v14; // r6
  int v15; // r1
  unsigned int v16; // r4
  char v17[48]; // [sp+8h] [bp-30h] BYREF

  v1 = *(_DWORD *)(a1 + 192);
  if ( (v1 & 0x20) == 0 || (*(_BYTE *)(a1 + 607) & 0xC0) != 192 )
  {
    if ( (v1 & 0x20) != 0 || (v3 = (v1 >> 10) & 3, v3 <= 1) )
      JUMPOUT(0x803008);
    if ( v3 == 2 )
      return sub_802F18();
  }
  KeInitializeEvent((int)v17, 0, 0);
  ExFreeSvmAsid();
  v5 = __mrc(15, 0, 13, 0, 3);
  v6 = MiBeginProcessClean(v5 & 0xFFFFFFC0, a1);
  v7 = MiGetThreadPartition();
  while ( 1 )
  {
    LOCK_ADDRESS_SPACE_SHARED(v5 & 0xFFFFFFC0, a1);
    v8 = *(_DWORD *)(a1 + 636);
    if ( !v8 )
      break;
    MiReferenceVad(*(_DWORD *)(a1 + 636));
    UNLOCK_ADDRESS_SPACE_SHARED(v5 & 0xFFFFFFC0, a1);
    MiLockVad(v5 & 0xFFFFFFC0, v8);
    if ( MiVadDeleted(v8) )
      JUMPOUT(0x802FCA);
    if ( (*(_DWORD *)(v8 + 28) & 0x8000) == 0 || (*(_DWORD *)(v8 + 28) & 7) == 1 )
      MiUnmapVad(v8, 0);
    else
      MiDeleteVad(v8, 0);
  }
  MEMORY[0xC0402128] = v17;
  __dmb(0xBu);
  do
  {
    v9 = __ldrex((unsigned int *)0xC0402120);
    v10 = v9 - 1;
  }
  while ( __strex(v10, (unsigned int *)0xC0402120) );
  if ( v10 )
    JUMPOUT(0x802FDA);
  v11 = UNLOCK_ADDRESS_SPACE_SHARED(v5 & 0xFFFFFFC0, a1);
  if ( (*(_BYTE *)(a1 + 607) & 0xC0) == 192 )
    v11 = MiClearCommitReleaseState(a1 + 492);
  MiCleanCfg(v11, v12, v13);
  LOCK_ADDRESS_SPACE(v5 & 0xFFFFFFC0, a1);
  MEMORY[0xC0402128] = 0;
  if ( *(_DWORD *)(a1 + 328) )
    JUMPOUT(0x802FF2);
  MiDeleteVadBitmap(a1);
  v14 = MiCleanWorkingSet(a1);
  UNLOCK_ADDRESS_SPACE(v5 & 0xFFFFFFC0, a1);
  PsReturnProcessQuota(a1, v15, v14);
  if ( v7 != MiSystemPartition )
    JUMPOUT(0x802FFC);
  MiReturnResidentAvailable(v14);
  do
    v16 = __ldrex(&dword_634A04[7]);
  while ( __strex(v16 + v14, &dword_634A04[7]) );
  result = MiUnlinkWorkingSet(a1 + 492, 0);
  if ( (*(_DWORD *)(a1 + 192) & 0x10000) != 0 )
    result = MiDereferenceSession();
  if ( v6 )
    result = MiContractWsSwapPageFile((int)v7);
  return result;
}
