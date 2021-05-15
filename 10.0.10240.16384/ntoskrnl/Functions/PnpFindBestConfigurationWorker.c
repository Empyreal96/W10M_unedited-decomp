// PnpFindBestConfigurationWorker 
 
int __fastcall PnpFindBestConfigurationWorker(int a1, int a2, __int64 **a3, int a4)
{
  int v5; // r6
  int v6; // r8
  int v7; // r9
  int v8; // r10
  int v10; // r4
  int v12; // r10
  unsigned int v13; // r5
  unsigned int v14; // r9
  int v15; // r4
  __int64 *v16; // r1
  __int64 *v17; // r2
  unsigned int v18; // r2
  int v19; // r1
  int v20; // r0
  int v21; // r3
  int v22; // r5
  int v23; // r9
  int v24; // r3
  int v25[2]; // [sp+0h] [bp-38h] BYREF
  __int64 v26; // [sp+8h] [bp-30h] BYREF
  __int64 v27[5]; // [sp+10h] [bp-28h] BYREF

  HIDWORD(v27[0]) = v27;
  v5 = a2;
  LODWORD(v27[0]) = v27;
  v25[0] = a4;
  v6 = a1;
  LODWORD(v26) = a1;
  *a3 = (__int64 *)a3;
  a3[1] = (__int64 *)a3;
  if ( a2 )
  {
    v7 = a1;
    v8 = a2;
    do
    {
      v10 = *(_DWORD *)(v7 + 24);
      *(_DWORD *)(v10 + 12) = v10 + 24;
      if ( a4 )
        return sub_80DB7C();
      IopAddRemoveReqDescs(*(_DWORD *)(v10 + 24) + 20, *(_DWORD *)(*(_DWORD *)(v10 + 24) + 16), a3, 1, v25[0]);
      v7 += 40;
      --v8;
    }
    while ( v8 );
    v6 = v26;
  }
  KeQuerySystemTime(v25);
  v12 = v25[1];
  v13 = -1;
  v14 = PnpFindBestConfigurationTimeout;
  while ( 1 )
  {
    v15 = IopTestConfiguration(v6, v5, a3);
    if ( v15 >= 0 )
    {
      v16 = a3[1];
      v17 = *a3;
      v27[0] = *(_QWORD *)a3;
      if ( v5 == 1 )
        goto LABEL_10;
      v18 = 0;
      if ( v5 )
      {
        v19 = v6;
        v20 = v5;
        do
        {
          v21 = *(_DWORD *)(v19 + 24);
          v19 += 40;
          v18 += ***(_DWORD ***)(v21 + 12);
          --v20;
        }
        while ( v20 );
      }
      if ( v18 < v13 )
      {
        v13 = v18;
        IopSaveRestoreConfiguration(v6, v5, a3, 1);
      }
    }
    KeQuerySystemTime(&v26);
    if ( _rt_sdiv64(10000i64, v26 - __PAIR64__(v12, v25[0])) >= v14 )
      break;
    if ( !IopSelectNextConfiguration(v6, v5, a3) )
      goto LABEL_25;
  }
  if ( v5 )
  {
    v22 = v6;
    v23 = v5;
    do
    {
      v24 = **(_DWORD **)(*(_DWORD *)(v22 + 24) + 12);
      IopAddRemoveReqDescs(v24 + 20, *(_DWORD *)(v24 + 16), 0, 0, v25[0]);
      v22 += 40;
      --v23;
    }
    while ( v23 );
  }
LABEL_25:
  v16 = (__int64 *)HIDWORD(v27[0]);
  v17 = (__int64 *)v27[0];
LABEL_10:
  if ( v17 == v27 )
  {
    if ( v15 != -1073739512 )
      v15 = -1073741823;
  }
  else
  {
    v15 = 0;
    if ( v5 != 1 )
    {
      *a3 = v17;
      a3[1] = v16;
      IopSaveRestoreConfiguration(v6, v5, a3, 0);
      v15 = IopRetestConfiguration(v6, v5, a3);
    }
  }
  return v15;
}
