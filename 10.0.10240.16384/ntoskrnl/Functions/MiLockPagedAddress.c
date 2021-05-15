// MiLockPagedAddress 
 
int __fastcall MiLockPagedAddress(unsigned int a1)
{
  unsigned int v1; // r9
  unsigned int v3; // r1
  int v4; // r4
  unsigned int v5; // r3
  int v6; // r4
  unsigned __int8 *v7; // r1
  unsigned int v8; // r2
  int v9; // r8
  unsigned int v10; // r1
  unsigned int *v11; // r2
  unsigned int v12; // r5
  unsigned int v13; // r0
  int v14; // r3
  int v16; // [sp+Ch] [bp-24h]

  __mrc(15, 0, 13, 0, 3);
  v1 = ((a1 >> 10) & 0x3FFFFC) - 0x40000000;
  v16 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_54F8CC();
  do
    v3 = __ldrex((unsigned __int8 *)&dword_634E80 + 3);
  while ( __strex(v3 | 0x80, (unsigned __int8 *)&dword_634E80 + 3) );
  __dmb(0xBu);
  if ( v3 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_634E80);
  while ( 1 )
  {
    v4 = dword_634E80;
    if ( (dword_634E80 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (dword_634E80 & 0x40000000) == 0 )
    {
      do
        v13 = __ldrex((unsigned int *)&dword_634E80);
      while ( v13 == v4 && __strex(v4 | 0x40000000, (unsigned int *)&dword_634E80) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  while ( 1 )
  {
    while ( 1 )
    {
      v5 = *(_DWORD *)v1;
      if ( (*(_DWORD *)v1 & 2) != 0 )
        break;
      MiMakeSystemAddressValidSystemWs(&dword_634E80, a1, v16);
    }
    if ( (v5 & 0x100) == 0 )
      break;
    MiCopyOnWriteEx(v1 << 10, v1, -1, v16, 0);
  }
  v6 = MmPfnDatabase + 24 * (v5 >> 12);
  v7 = (unsigned __int8 *)(v6 + 15);
  do
    v8 = __ldrex(v7);
  while ( __strex(v8 | 0x80, v7) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v8 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
      v14 = *(_DWORD *)(v6 + 12);
      __dmb(0xBu);
    }
    while ( (v14 & 0x80000000) != 0 );
    do
      v8 = __ldrex(v7);
    while ( __strex(v8 | 0x80, v7) );
  }
  if ( MiAddLockedPageCharge(v6, 0) )
  {
    v9 = 1;
    v10 = MiCaptureDirtyBitToPfn(v6);
  }
  else
  {
    v9 = 0;
    v10 = 0;
  }
  __dmb(0xBu);
  v11 = (unsigned int *)(v6 + 12);
  do
    v12 = __ldrex(v11);
  while ( __strex(v12 & 0x7FFFFFFF, v11) );
  if ( v9 )
  {
    if ( v10 )
      MiReleasePageFileInfo((int)MiSystemPartition, v10, 1, 0);
    if ( (*(_DWORD *)v1 & 0x10) == 0 || (*(_DWORD *)v1 & 0x200) != 0 )
      MI_WRITE_VALID_PTE_VOLATILE((unsigned int *)v1, 3);
    if ( (MiFlags & 0x100) == 0 )
      KeFlushSingleTb(a1, 1);
  }
  MiUnlockWorkingSetExclusive((int)&dword_634E80, v16);
  return v9;
}
