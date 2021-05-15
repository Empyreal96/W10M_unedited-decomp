// MiPfCoalesceAndIssueIOs 
 
int __fastcall MiPfCoalesceAndIssueIOs(int *a1, int a2, int a3)
{
  int **v3; // r5
  int v4; // r9
  int ***v8; // r10
  int ***v9; // lr
  int ****v10; // r4
  int v11; // r5
  int v12; // r4
  unsigned int v14; // r0
  int ***v15; // r5
  __int64 v16; // kr08_8
  unsigned int v17; // r5
  __int64 v18; // kr10_8
  int ***v19; // r0
  __int64 v20; // r2
  int *v21; // r2
  int ***v22; // [sp+0h] [bp-30h]
  int ***v23; // [sp+4h] [bp-2Ch]
  int **v24; // [sp+8h] [bp-28h] BYREF
  int ***v25; // [sp+Ch] [bp-24h]

  v25 = &v24;
  v3 = (int **)&v24;
  v4 = 0;
  v23 = 0;
  v24 = (int **)&v24;
  v8 = 0;
  v9 = 0;
  v22 = 0;
  while ( 1 )
  {
    v10 = (int ****)*a1;
    if ( (int *)*a1 == a1 )
      break;
    v14 = (unsigned int)v10[26];
    if ( v14 >= 0x100000 )
      return sub_5283B0();
    if ( v3 == (int **)&v24 )
    {
      if ( a3 )
        JUMPOUT(0x5283F4);
      v9 = v10[15];
      v8 = v10[14];
      v15 = v10[29];
      v22 = v9;
      v23 = v15;
    }
    else
    {
      v15 = v23;
    }
    v16 = *((_QWORD *)v10 + 7);
    if ( __SPAIR64__((unsigned int)v9, (unsigned int)v8) <= v16
      && v15 == v10[29]
      && (v17 = v16 - (_DWORD)v8 + v14, v16 - __PAIR64__((unsigned int)v9, (unsigned int)v8) <= 0x20000)
      && v17 + v4 <= 0x100000 )
    {
      v18 = *(_QWORD *)v10;
      if ( (*v10)[1] != (int **)v10 || *(int *****)HIDWORD(v18) != v10 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v18) = v18;
      *(_DWORD *)(v18 + 4) = HIDWORD(v18);
      v19 = v25;
      *v10 = &v24;
      v10[1] = v19;
      if ( *v19 != (int **)&v24 )
        __fastfail(3u);
      v9 = (int ***)((__PAIR64__((unsigned int)v9, (unsigned int)v8) + v17) >> 32);
      v8 = (int ***)((char *)v8 + v17);
      *v19 = (int **)v10;
      v22 = v9;
      v25 = (int ***)v10;
      v4 += v17;
      if ( a3 )
        JUMPOUT(0x528400);
      v3 = v24;
    }
    else
    {
      v11 = MiPfIssueCoalesceCandidates((int **)&v24, v4, a2);
      if ( v11 < 0 )
        goto LABEL_5;
      v4 = 0;
      v3 = v24;
      v9 = v22;
    }
  }
  if ( v3 == (int **)&v24 || (v11 = MiPfIssueCoalesceCandidates((int **)&v24, v4, a2), v11 >= 0) )
    v11 = 0;
LABEL_5:
  if ( !a3 )
  {
    while ( 1 )
    {
      v12 = *a1;
      if ( (int *)*a1 == a1 )
        break;
      v20 = *(_QWORD *)v12;
      if ( *(int **)(v12 + 4) != a1 || *(_DWORD *)(v20 + 4) != v12 )
        __fastfail(3u);
      *a1 = v20;
      *(_DWORD *)(v20 + 4) = a1;
      MiIssueHardFaultIo(v12, 0, 0);
      v21 = *(int **)(a2 + 4);
      *(_DWORD *)v12 = a2;
      *(_DWORD *)(v12 + 4) = v21;
      if ( *v21 != a2 )
        __fastfail(3u);
      *v21 = v12;
      *(_DWORD *)(a2 + 4) = v12;
    }
  }
  return v11;
}
