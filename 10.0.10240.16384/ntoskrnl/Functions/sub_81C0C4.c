// sub_81C0C4 
 
// local variable allocation has failed, the output may be wrong!
int sub_81C0C4()
{
  _DWORD *v0; // r6
  __int64 v1; // r0
  int v2; // r3
  __int64 v3; // r0
  int *v4; // r9
  int v5; // r3
  int *v6; // r10
  char v7; // lr
  int v8; // r7
  int v9; // r1
  int v10; // r2
  char v11; // r8
  int v12; // r6
  int v13; // r0
  __int64 v14; // kr08_8
  unsigned int v15; // r1
  unsigned int v16; // r5
  int v17; // r4
  unsigned int v18; // t1
  unsigned int v19; // r1
  unsigned int v20; // r5
  int v21; // r4
  __int64 *v22; // r10
  unsigned int v23; // r7
  unsigned int v24; // r3
  char *v25; // r2
  int v26; // r1
  int v27; // r0
  unsigned int v28; // r6
  __int64 v29; // kr20_8
  unsigned int v30; // r1
  unsigned int v31; // r5
  int v32; // r4
  unsigned int v33; // t1
  unsigned int v34; // r1
  unsigned int v35; // r5
  int v36; // r4
  unsigned int v37; // r1 OVERLAPPED
  unsigned int v38; // r6
  int v39; // r7
  int v40; // r10
  __int64 v41; // kr38_8
  unsigned int v42; // r1
  unsigned int v43; // r5
  unsigned int i; // r2 OVERLAPPED
  unsigned int v45; // t1
  unsigned int v46; // r1
  unsigned int v47; // r5
  __int64 v48; // kr50_8
  unsigned int v49; // r7
  unsigned int v50; // r8
  unsigned __int64 v51; // r0
  __int64 v52; // r2
  int v53; // r0
  int v55; // [sp-30h] [bp-30h]
  int v56; // [sp-2Ch] [bp-2Ch]
  int v57; // [sp-28h] [bp-28h]
  int (__fastcall *v58)(int, int, int, int, unsigned int, int); // [sp-4h] [bp-4h]
  int v59; // [sp+0h] [bp+0h]
  int v60; // [sp+4h] [bp+4h]

  LODWORD(v1) = ReadTimeStampCounter();
  v2 = (41929663 * (v1 >> 4)) ^ 0x57E;
  v0[20] = v2;
  v0[21] = 0;
  if ( !v2 )
  {
    v0[20] = 1;
    v0[21] = 0;
  }
  LODWORD(v3) = ReadTimeStampCounter();
  v4 = &KeServiceDescriptorTableShadow;
  v5 = (41929663 * (v3 >> 4)) ^ 0x57E;
  __pld(&KeServiceDescriptorTable);
  v0[22] = v5;
  v0[23] = 0;
  v6 = &KeServiceDescriptorTable;
  v7 = v5 & 0x3F;
  v8 = 32;
  v60 = v0[20];
  v9 = v60;
  v10 = v0[21];
  v11 = 64 - (v5 & 0x3F);
  v12 = 4;
  v59 = v10;
  v13 = v10;
  do
  {
    v14 = *(_QWORD *)v6;
    v6 += 2;
    v16 = (__PAIR64__(v13, v9) - v14) >> 32;
    v15 = v9 - v14;
    v17 = __PAIR64__(v16, v15) << v11 >> 32;
    v9 = (v15 << v11) | (__PAIR64__(v16, v15) >> v7);
    v8 -= 8;
    v13 = v17 | (v16 >> v7);
    --v12;
  }
  while ( v12 );
  for ( ; v8; --v8 )
  {
    v18 = *(unsigned __int8 *)v6;
    v6 = (int *)((char *)v6 + 1);
    v20 = (__PAIR64__(v13, v9) - v18) >> 32;
    v19 = v9 - v18;
    v21 = __PAIR64__(v20, v19) << v11 >> 32;
    v9 = (v19 << v11) | (__PAIR64__(v20, v19) >> v7);
    v13 = v21 | (v20 >> v7);
  }
  v22 = (__int64 *)KeServiceDescriptorTable;
  dword_641C68 = v9;
  unk_641C6C = v13;
  v23 = 4 * dword_682088;
  v24 = KeServiceDescriptorTable + 4 * dword_682088;
  v25 = (char *)KeServiceDescriptorTable;
  if ( KeServiceDescriptorTable < v24 )
  {
    do
    {
      __pld(v25);
      v25 += 128;
    }
    while ( (unsigned int)v25 < v24 );
  }
  v26 = v60;
  v27 = v59;
  if ( v23 >= 8 )
  {
    v28 = v23 >> 3;
    do
    {
      v29 = *v22++;
      v31 = (__PAIR64__(v27, v26) - v29) >> 32;
      v30 = v26 - v29;
      v32 = __PAIR64__(v31, v30) << v11 >> 32;
      v26 = (v30 << v11) | (__PAIR64__(v31, v30) >> v7);
      v23 -= 8;
      v27 = v32 | (v31 >> v7);
      --v28;
    }
    while ( v28 );
  }
  for ( ; v23; --v23 )
  {
    v33 = *(unsigned __int8 *)v22;
    v22 = (__int64 *)((char *)v22 + 1);
    v35 = (__PAIR64__(v27, v26) - v33) >> 32;
    v34 = v26 - v33;
    v36 = __PAIR64__(v35, v34) << v11 >> 32;
    v26 = (v34 << v11) | (__PAIR64__(v35, v34) >> v7);
    v27 = v36 | (v35 >> v7);
  }
  __pld(&KeServiceDescriptorTableShadow);
  dword_641C70 = v26;
  unk_641C74 = v27;
  v38 = v59;
  v37 = v60;
  v39 = 16;
  v40 = 2;
  do
  {
    v41 = *(_QWORD *)v4;
    v4 += 2;
    v43 = (__PAIR64__(v38, v37) - v41) >> 32;
    v42 = v37 - v41;
    v39 -= 8;
    v38 = (__PAIR64__(v43, v42) << v11 >> 32) | (v43 >> v7);
    v37 = (v42 << v11) | (__PAIR64__(v43, v42) >> v7);
    --v40;
  }
  while ( v40 );
  for ( i = v38; v39; v37 = (v46 << v11) | (__PAIR64__(v47, v46) >> v7) )
  {
    v45 = *(unsigned __int8 *)v4;
    v4 = (int *)((char *)v4 + 1);
    v47 = (__PAIR64__(i, v37) - v45) >> 32;
    v46 = v37 - v45;
    i = (v47 >> v7) | (__PAIR64__(v47, v46) << v11 >> 32);
    --v39;
  }
  *(_QWORD *)&dword_641C78 = *(_QWORD *)&v37;
  do
  {
    v48 = MEMORY[0xFFFF93B0];
    while ( 1 )
    {
      v49 = MEMORY[0xFFFF900C];
      __dmb(0xBu);
      v50 = MEMORY[0xFFFF9008];
      __dmb(0xBu);
      if ( v49 == MEMORY[0xFFFF9010] )
        break;
      __dmb(0xAu);
      __yield();
    }
  }
  while ( v48 != MEMORY[0xFFFF93B0] );
  LODWORD(v51) = ReadTimeStampCounter();
  _rt_udiv64(80000000000i64, 41929663 * (v51 >> 4));
  qword_641C60 = v52 - v48 + __PAIR64__(v49, v50) + 288000000000i64;
  v53 = KeInitializeTimer2((int)CmpDelayDerefKCBTimer, (int)CmpDelayDerefKCBTimerRoutine, 0, 8);
  return v58(v53, v55, v56, v57, v38, v60);
}
