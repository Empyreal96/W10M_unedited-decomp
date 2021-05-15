// PnprAddMemoryResources 
 
int __fastcall PnprAddMemoryResources(int a1, unsigned int *a2)
{
  unsigned int v2; // r5
  unsigned int v3; // r4
  int v4; // r3
  _DWORD *v5; // r7
  int v6; // r6
  int v7; // r3
  int v8; // r2
  int v9; // r2
  _DWORD *v10; // r6
  int v11; // r10
  int v12; // r8
  unsigned __int8 *v13; // r2
  int v14; // r3
  int v15; // t1
  __int64 v16; // kr00_8
  int v17; // r0
  _DWORD *v18; // r9
  __int64 v19; // r0
  unsigned int v20; // r2
  int v21; // r2
  int v22; // r3
  bool v23; // cf
  int v24; // r3
  unsigned int v25; // r0
  int v27; // r3
  int v28; // r2
  int v29; // r2
  unsigned __int8 *v30; // [sp+0h] [bp-38h]
  unsigned int *v31; // [sp+4h] [bp-34h]
  int v32[10]; // [sp+10h] [bp-28h] BYREF

  v2 = *a2;
  v31 = a2;
  v3 = *a2;
  if ( a1 )
    v4 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
  else
    v4 = 0;
  v5 = *(_DWORD **)(v4 + 284);
  if ( !v5 )
  {
    v6 = 0;
    v7 = PnprContext;
    v8 = *(_DWORD *)(PnprContext + 608);
    if ( !v8 )
      v8 = 636;
    *(_DWORD *)(PnprContext + 608) = v8;
    v9 = *(_DWORD *)(v7 + 612);
    if ( !v9 )
      v9 = 6;
    *(_DWORD *)(v7 + 612) = v9;
    goto LABEL_25;
  }
  v10 = v5 + 1;
  v11 = 0;
  if ( !*v5 )
    goto LABEL_24;
  while ( 1 )
  {
    v12 = 0;
    if ( v10[3] )
      break;
LABEL_22:
    v10 = (_DWORD *)((char *)v10 + v12 + 32);
    if ( (unsigned int)++v11 >= *v5 )
    {
      a2 = v31;
LABEL_24:
      v6 = 0;
LABEL_25:
      *a2 = v3;
      if ( v3 != v2 )
      {
        v25 = v2;
        goto LABEL_27;
      }
      return v6;
    }
  }
  v13 = (unsigned __int8 *)(v10 + 4);
  while ( 1 )
  {
    v15 = *v13;
    v13 += 16;
    v14 = v15;
    v30 = v13;
    if ( v15 != 3 && v14 != 7 )
      goto LABEL_21;
    v16 = *(_QWORD *)v3;
    if ( HIDWORD(v16) == (_DWORD)v16 )
      break;
LABEL_20:
    LODWORD(v19) = RtlCmDecodeMemIoResource((int)(v30 - 16), v32);
    v20 = v3 + 16 * *(_DWORD *)(v3 + 4);
    *(_DWORD *)(v20 + 16) = v32[0];
    *(_DWORD *)(v20 + 20) = v32[1];
    *(_QWORD *)(v3 + 16 * *(_DWORD *)(v3 + 4) + 24) = v19;
    v21 = *(_DWORD *)(v3 + 12);
    v22 = *(_DWORD *)(v3 + 8);
    v23 = __CFADD__(v22, (_DWORD)v19);
    *(_DWORD *)(v3 + 8) = v22 + v19;
    v24 = *(_DWORD *)(v3 + 4);
    *(_DWORD *)(v3 + 12) = HIDWORD(v19) + v23 + v21;
    v13 = v30;
    *(_DWORD *)(v3 + 4) = v24 + 1;
LABEL_21:
    if ( (unsigned int)++v12 >= v10[3] )
      goto LABEL_22;
  }
  v17 = ExAllocatePoolWithTag(512, 16 * (HIDWORD(v16) + 5), 1366322768);
  v18 = (_DWORD *)v17;
  if ( v17 )
  {
    memmove(v17, v3, 16 * (HIDWORD(v16) + 1));
    *v18 = HIDWORD(v16) + 4;
    if ( v3 != v2 )
      ExFreePoolWithTag(v3);
    v3 = (unsigned int)v18;
    goto LABEL_20;
  }
  v6 = -1073741670;
  v27 = PnprContext;
  v28 = *(_DWORD *)(PnprContext + 608);
  if ( !v28 )
    v28 = 676;
  *(_DWORD *)(PnprContext + 608) = v28;
  v29 = *(_DWORD *)(v27 + 612);
  if ( !v29 )
    v29 = 10;
  *(_DWORD *)(v27 + 612) = v29;
  *v31 = v2;
  if ( v3 != v2 )
  {
    v25 = v3;
LABEL_27:
    ExFreePoolWithTag(v25);
  }
  return v6;
}
