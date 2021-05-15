// MiInitializeBootProcess 
 
int __fastcall MiInitializeBootProcess(int a1)
{
  _DWORD *v1; // r8
  _DWORD *v2; // r7
  int v3; // r6
  unsigned int v4; // r0
  int v5; // r2
  int v6; // r1
  _WORD *v7; // r5
  unsigned int v8; // r4
  int v9; // r3
  int v10; // r0
  int v11; // r3
  unsigned int v12; // r2
  char *v13; // r1
  int v14; // r4
  int v15; // r9
  _DWORD *v16; // r8
  _DWORD *v17; // r4
  int *v18; // r5
  int v19; // t1
  int v20; // r10
  int v21; // r0
  _DWORD *v23; // r8
  unsigned int *v24; // r2
  unsigned int v25; // r0
  int **v26; // r0
  _DWORD *v28; // [sp+Ch] [bp-3Ch] BYREF
  _WORD *v29; // [sp+10h] [bp-38h] BYREF
  unsigned __int16 v30; // [sp+14h] [bp-34h]
  unsigned __int16 v31; // [sp+16h] [bp-32h]
  char v32; // [sp+18h] [bp-30h] BYREF
  _DWORD v33[10]; // [sp+20h] [bp-28h] BYREF

  __dmb(0xBu);
  v33[0] = 0;
  v33[1] = 0;
  v33[2] = 0;
  if ( !dword_681290 )
    dword_681290 = 0x100000;
  if ( !dword_68128C )
    dword_68128C = 0x2000;
  if ( !dword_681288 )
    dword_681288 = 0x10000;
  if ( !dword_681284 )
    dword_681284 = 4096;
  v1 = *(_DWORD **)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v28 = v1;
  MiChargeWsles((int)(v1 + 123), 50, 0);
  v1[135] = 50;
  v1[140] = 450;
  v2 = 0;
  LOWORD(v3) = (dword_681128 | MiDetermineUserGlobalPteMask(0)) & 0x1EC | 0xF813;
  MI_INITIALIZE_COLOR_BASE((int)(v1 + 123), 0, (int)&v29);
  MiChargeResident(MiSystemPartition, 2u, 0);
  do
    v4 = __ldrex(&dword_634A2C[62]);
  while ( __strex(v4 + 2, &dword_634A2C[62]) );
  MiChargeCommit((int)MiSystemPartition, 2u, 1);
  MiArmPageDirectorySlist = 0;
  *(_DWORD *)&word_620D24 = 0;
  MiBuildHardwarePageDirectory(
    -1070596096,
    *(_DWORD **)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32));
  v5 = v30;
  v6 = v31;
  v7 = v29;
  v8 = 0;
  do
  {
    v9 = (unsigned __int16)(*v7 + 1);
    *v7 = v9;
    v10 = MiGetPage((int)MiSystemPartition, v6 | v9 & v5, 194);
    if ( v10 == -1 )
      return 0;
    v11 = MmPfnDatabase;
    ++v8;
    *(_DWORD *)(MmPfnDatabase + 24 * v10) = v2;
    v6 = v31;
    v2 = (_DWORD *)(v11 + 24 * v10);
    v5 = v30;
  }
  while ( v8 < 2 );
  v12 = -1070591992;
  v13 = &v32;
  v14 = 2;
  do
  {
    *(_DWORD *)v13 = v12;
    v13 += 4;
    v12 = ((v12 >> 10) & 0x3FFFFC) - 0x40000000;
    --v14;
  }
  while ( v14 );
  v15 = a1;
  v1[62] = v10;
  v16 = v33;
  do
  {
    v17 = v2;
    v2 = (_DWORD *)*v2;
    v19 = *--v16;
    v18 = (int *)v19;
    v20 = ((int)v17 - MmPfnDatabase) / 24;
    MiInitializePfnForOtherProcess(v20, v19, v15, 0);
    *v17 = 0;
    v21 = MiMarkPageActive((int)v17);
    v3 = v3 & 0xFFF | (v20 << 12);
    if ( !v2 )
      v3 |= 1u;
    if ( (unsigned int)v18 >= 0xC0000000 )
      return sub_9697B4(v21);
    *v18 = v3;
    v15 = v20;
  }
  while ( v2 );
  v23 = v28;
  *(_DWORD *)(MmPfnDatabase + 24 * (MEMORY[0xC0300C00] >> 12)) = v28;
  __dmb(0xBu);
  v24 = v23 + 48;
  do
    v25 = __ldrex(v24);
  while ( __strex(v25 | 0x800, v24) );
  __dmb(0xBu);
  KeAcquireInStackQueuedSpinLock((unsigned int *)&dword_634980, (unsigned int)v33);
  v26 = (int **)dword_6337D4;
  v23[155] = &dword_6337D0;
  v23[156] = v26;
  if ( *v26 != &dword_6337D0 )
    __fastfail(3u);
  *v26 = v23 + 155;
  dword_6337D4 = (int)(v23 + 155);
  KeReleaseInStackQueuedSpinLock((int)v33);
  v28 = 0;
  return MmInitializeProcessAddressSpace(v23, 0, 0, &v28);
}
