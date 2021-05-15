// MiInitializePartition 
 
// local variable allocation has failed, the output may be wrong!
void MiInitializePartition()
{
  __int16 *v0; // r4 OVERLAPPED
  int v1; // r2
  int v2; // r7
  __int16 *v3; // r6
  _DWORD *v4; // r3
  unsigned int v5; // r0
  int *v6; // r0
  int v7; // r6
  unsigned int v8; // r0
  _DWORD *v9; // r2
  unsigned int i; // r1
  unsigned int v11; // r1
  int v12; // r0
  int v13; // r1
  int v14; // t0
  _DWORD *v15; // r0
  int v16; // r5
  _DWORD *v17; // r5
  char *v18; // r6
  int v19; // r7
  int *v20; // r3
  char *v21; // r5
  int v22; // r6
  int *v23; // r3
  int v24; // r0
  int (__fastcall *v25)(int); // r3
  int v26; // r0

  v0 = MiSystemPartition;
  dword_63F708 = 1;
  MiSystemPartition[0] = 0;
  dword_63F704 = 0;
  dword_640280 = 0;
  KeInitializeEvent((int)&unk_63F778, 0, 0);
  v1 = 0;
  v2 = dword_633818;
  v3 = MiSystemPartition;
  do
  {
    v4 = (_DWORD *)*((_DWORD *)v3 + 256);
    v5 = 0;
    if ( v2 )
    {
      do
      {
        v4[1] = v1;
        v4[2] = 0xFFFFF;
        v4[3] = 0xFFFFF;
        v4[4] = 0;
        *v4 = 0;
        v2 = dword_633818;
        ++v5;
        v4 += 5;
      }
      while ( v5 < dword_633818 );
    }
    ++v1;
    v3 += 2;
  }
  while ( v1 <= 1 );
  MiInitializePfnListHead(&dword_63FB80, 0);
  MiInitializePfnListHead(&dword_63FC00, 1);
  MiInitializePfnListHead(&dword_63FC80, 2);
  v6 = dword_63FD00;
  v7 = 8;
  do
  {
    v6 = MiInitializePfnListHead(v6, 2) + 5;
    --v7;
  }
  while ( v7 );
  dword_640094 = (int)&dword_63FB80;
  dword_640098 = (int)&dword_63FC00;
  dword_64009C = (int)&dword_63FC80;
  MiInitializeLargePageNodeLists((int)MiSystemPartition);
  v8 = dword_633818;
  v9 = (_DWORD *)dword_63FB08;
  for ( i = 0; i < 2 * dword_633818; v9 += 2 )
  {
    *v9 = 0;
    v9[1] = 0;
    v8 = dword_633818;
    ++i;
  }
  v11 = (unsigned int)dword_640508 >> 10;
  if ( !v8 )
    __brkdiv0();
  v14 = v11 / v8;
  v13 = v11 % v8;
  v12 = v14;
  if ( v14 )
  {
    if ( v12 > 16 )
      v12 = 16;
    dword_6403B4 = v12;
    MiInitializePfnListHead(&dword_640680, 3);
    MiInitializePfnListHead(&dword_640700, 4);
    MiInitializePfnListHead(&dword_63FE00, 3);
    v15 = &unk_63FE80;
    v16 = 2;
    do
    {
      v15 = MiInitializePfnListHead(v15, 3) + 5;
      --v16;
    }
    while ( v16 );
    v17 = &unk_63FF00;
    v18 = (char *)&unk_6400D4;
    v19 = 16;
    do
    {
      MiInitializePfnListHead(v17, 3);
      KeInitializeEvent((int)v18, 1, 0);
      v17 += 5;
      v18 += 16;
      --v19;
    }
    while ( v19 );
    MiInitializePfnListHead(&dword_640080, 5);
    dword_6400A0 = (int)&dword_640680;
    dword_6400A4 = (int)&dword_640700;
    dword_6400A8 = (int)&dword_640080;
    v20 = dword_6401D4;
    do
      *v20++ = -65538;
    while ( v20 != &dword_6401E4 );
    KeInitializeEvent((int)&unk_6403A0, 0, 0);
    v21 = (char *)&unk_640284;
    v22 = 2;
    do
    {
      KeInitializeEvent((int)v21, 0, 1);
      v21 += 20;
      --v22;
    }
    while ( v22 );
    dword_63F7A4 = 0;
    KeInitializeEvent((int)&unk_63F7AC, 0, 0);
    v23 = &dword_63F7BC;
    do
      *v23++ = (int)&unk_63F7AC;
    while ( v23 != (int *)&unk_63F7E8 );
    dword_6404C0 = (int)&dword_6404BC;
    dword_6404BC = (int)&dword_6404BC;
    KeInitializeEvent((int)&unk_63F8C4, 1, 0);
    KeInitializeEvent((int)&unk_63F8AC, 1, 0);
    dword_63F8A4 = 18;
    KeInitializeEvent((int)&unk_63F894, 0, 0);
    KeInitializeEvent((int)&unk_63F908, 0, 0);
    KeInitializeGate((int)&unk_63F86C);
    dword_63F868 = (int)&dword_63F864;
    dword_63F864 = (int)&dword_63F864;
    v24 = KeInitializeEvent((int)&unk_63F920, 1, 0);
    dword_63F91C = (int)&dword_63F918;
    dword_63F918 = (int)&dword_63F918;
    dword_640480 = 0;
    MiInitializeNuma(v24);
    dword_63F98C = 0;
    v25 = MiContractWsSwapPageFileWorker;
    *((_QWORD *)v0 + 80) = *(_QWORD *)(&v0 - 1);
    dword_63F978 = 0;
    dword_63F99C = -1;
    KeInitializeEvent((int)&unk_63F9B8, 0, 0);
    KeInitializeEvent((int)&unk_63F9C8, 0, 0);
    unk_63F9D8 = 0;
    unk_63F9DC = 0;
    v26 = MiInitializeSections(MiSystemPartition);
    MiInitializeCombining(v26, &dword_6403D0);
  }
  else
  {
    sub_80FBB4(0, v13, v9);
  }
}
