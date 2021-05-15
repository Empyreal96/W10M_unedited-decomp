// PnprCollectResources 
 
int __fastcall PnprCollectResources(unsigned int *a1, unsigned int *a2, int (__fastcall *a3)(int a1, unsigned __int8 *a2, int a3, int a4), int a4)
{
  _BYTE *v6; // r0
  int v7; // r4
  int v8; // r3
  int v9; // r2
  int v10; // r2
  _BYTE *v11; // r0
  _DWORD *v12; // r3
  int v13; // r0
  int v14; // r0
  int v15; // r1
  int v16; // r0
  int v17; // r1
  int v18; // r3
  int v19; // r2
  int v20; // r2
  unsigned int v21; // r3
  int v22; // r0
  unsigned int v23; // r2
  int v24; // r2
  unsigned __int64 v25; // kr00_8
  int v26; // r2
  unsigned int *v27; // r3
  unsigned int v28; // r0
  unsigned int v29; // r0
  unsigned int v30; // r0
  unsigned int *v32; // [sp+0h] [bp-20h] BYREF
  unsigned int *v33; // [sp+4h] [bp-1Ch]
  int (__fastcall *v34)(int, unsigned __int8 *, int, int); // [sp+8h] [bp-18h] BYREF
  int *v35; // [sp+Ch] [bp-14h]

  v32 = a1;
  v33 = a2;
  v34 = a3;
  v35 = (int *)a4;
  v6 = (_BYTE *)ExAllocatePoolWithTag(512, 32, 1366322768);
  a1[4] = (unsigned int)v6;
  if ( v6 )
  {
    memset(v6, 0, 32);
    *(_DWORD *)(a1[4] + 8) = 4;
    v11 = (_BYTE *)ExAllocatePoolWithTag(512, 32, 1366322768);
    a2[4] = (unsigned int)v11;
    if ( !v11 )
    {
      v7 = -1073741670;
      v8 = PnprContext;
      v9 = *(_DWORD *)(PnprContext + 608);
      if ( !v9 )
        v9 = 1041;
      goto LABEL_4;
    }
    memset(v11, 0, 32);
    *(_DWORD *)(a2[4] + 8) = 4;
    *(_DWORD *)a1[4] = ExAllocatePoolWithTag(512, 4, 1366322768);
    v12 = *(_DWORD **)a1[4];
    if ( !v12 )
    {
      v7 = -1073741670;
      v8 = PnprContext;
      v9 = *(_DWORD *)(PnprContext + 608);
      if ( !v9 )
        v9 = 1061;
      goto LABEL_4;
    }
    *v12 = 0;
    *(_DWORD *)(a1[4] + 4) = 1;
    v13 = ExAllocatePoolWithTag(512, 80, 1366322768);
    a1[5] = v13;
    if ( !v13 )
    {
      v7 = -1073741670;
      v8 = PnprContext;
      v9 = *(_DWORD *)(PnprContext + 608);
      if ( !v9 )
        v9 = 1080;
      goto LABEL_4;
    }
    v14 = ExAllocatePoolWithTag(512, 80, 1366322768);
    a2[5] = v14;
    if ( !v14 )
    {
      v7 = -1073741670;
      v8 = PnprContext;
      v9 = *(_DWORD *)(PnprContext + 608);
      if ( !v9 )
        v9 = 1091;
      goto LABEL_4;
    }
    memset((_BYTE *)a1[5], 0, 80);
    memset((_BYTE *)a2[5], 0, 80);
    *(_DWORD *)a1[5] = 4;
    *(_DWORD *)a2[5] = 4;
    LOBYTE(v32) = 1;
    v33 = a1;
    v34 = PnprAddDeviceResources;
    v35 = (int *)&v32;
    if ( *a1 )
      v16 = *(_DWORD *)(*(_DWORD *)(*a1 + 176) + 20);
    else
      v16 = 0;
    v7 = PipForAllChildDeviceNodes(v16, v15, (int)&v34);
    if ( v7 >= 0 )
    {
      LOBYTE(v32) = 0;
      v21 = *a2;
      v33 = a2;
      if ( v21 )
        v22 = *(_DWORD *)(*(_DWORD *)(v21 + 176) + 20);
      else
        v22 = 0;
      v7 = PipForAllChildDeviceNodes(v22, v17, (int)&v34);
      if ( v7 >= 0 )
      {
        v23 = *(_DWORD *)(a1[4] + 12);
        if ( !v23 && !*(_DWORD *)(a1[5] + 4) )
        {
          v7 = -1073741811;
          v8 = PnprContext;
          v24 = *(_DWORD *)(PnprContext + 608);
          if ( !v24 )
            v24 = 1137;
          *(_DWORD *)(PnprContext + 608) = v24;
          v10 = *(_DWORD *)(v8 + 612);
          if ( !v10 )
            v10 = 5;
          goto LABEL_6;
        }
        v25 = *(_QWORD *)(a2[5] + 8);
        if ( (!v25 || *(_QWORD *)(a1[5] + 8) <= v25) && v23 <= *(_DWORD *)(a2[4] + 12) )
        {
LABEL_47:
          if ( v7 >= 0 )
            return v7;
          goto LABEL_48;
        }
        v7 = -1073741811;
        v18 = PnprContext;
        v26 = *(_DWORD *)(PnprContext + 608);
        if ( !v26 )
          v26 = 1146;
        *(_DWORD *)(PnprContext + 608) = v26;
        v20 = *(_DWORD *)(v18 + 612);
        if ( !v20 )
          v20 = 4;
LABEL_46:
        *(_DWORD *)(v18 + 612) = v20;
        goto LABEL_47;
      }
      v18 = PnprContext;
      v19 = *(_DWORD *)(PnprContext + 608);
      if ( !v19 )
        v19 = 1125;
    }
    else
    {
      v18 = PnprContext;
      v19 = *(_DWORD *)(PnprContext + 608);
      if ( !v19 )
        v19 = 1114;
    }
    *(_DWORD *)(v18 + 608) = v19;
    v20 = *(_DWORD *)(v18 + 612);
    if ( !v20 )
      v20 = 1;
    goto LABEL_46;
  }
  v7 = -1073741670;
  v8 = PnprContext;
  v9 = *(_DWORD *)(PnprContext + 608);
  if ( !v9 )
    v9 = 1028;
LABEL_4:
  *(_DWORD *)(v8 + 608) = v9;
  v10 = *(_DWORD *)(v8 + 612);
  if ( !v10 )
    v10 = 10;
LABEL_6:
  *(_DWORD *)(v8 + 612) = v10;
LABEL_48:
  v27 = (unsigned int *)a1[4];
  if ( v27 )
  {
    if ( *v27 )
      ExFreePoolWithTag(*v27);
    ExFreePoolWithTag(a1[4]);
    a1[4] = 0;
  }
  v28 = a1[5];
  if ( v28 )
  {
    ExFreePoolWithTag(v28);
    a1[5] = 0;
  }
  v29 = a2[4];
  if ( v29 )
  {
    ExFreePoolWithTag(v29);
    a2[4] = 0;
  }
  v30 = a2[5];
  if ( v30 )
  {
    ExFreePoolWithTag(v30);
    a2[5] = 0;
  }
  return v7;
}
