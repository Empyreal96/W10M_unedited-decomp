// PnprMmConstruct 
 
int __fastcall PnprMmConstruct(int a1, int *a2)
{
  int v2; // r7
  int v3; // r4
  int v5; // r8
  int v6; // r9
  __int64 v7; // t1
  int *v8; // r3
  unsigned int v9; // r1
  int v10; // r3
  int v11; // r2
  int v12; // r2
  int v13; // r2
  unsigned int v14; // r0
  int v15; // r2

  v2 = a1;
  v3 = 0;
  v5 = 0;
  if ( *(_DWORD *)(a1 + 4) )
  {
    v6 = a1;
    while ( 1 )
    {
      v7 = *(_QWORD *)(v6 + 16);
      v6 += 16;
      v3 = PnprMmAddRange(a2, (int)a2, v7, SHIDWORD(v7), *(_DWORD *)(v6 + 8));
      if ( v3 < 0 )
        break;
      if ( (unsigned int)++v5 >= *(_DWORD *)(v2 + 4) )
        goto LABEL_5;
    }
    v10 = PnprContext;
    v11 = *(_DWORD *)(PnprContext + 608);
    if ( !v11 )
      v11 = 4487;
    *(_DWORD *)(PnprContext + 608) = v11;
    v12 = *(_DWORD *)(v10 + 612);
    if ( !v12 )
      v12 = 1;
LABEL_19:
    *(_DWORD *)(v10 + 612) = v12;
  }
  else
  {
LABEL_5:
    v8 = (int *)*a2;
    v9 = 0;
    while ( v8 != a2 )
    {
      v13 = v8[3];
      if ( !v13 || (v14 = v8[2], v14 < v9) )
      {
        v3 = -1073741811;
        v10 = PnprContext;
        v15 = *(_DWORD *)(PnprContext + 608);
        if ( !v15 )
          v15 = 4508;
        *(_DWORD *)(PnprContext + 608) = v15;
        v12 = *(_DWORD *)(v10 + 612);
        if ( !v12 )
          v12 = 6;
        goto LABEL_19;
      }
      v8 = (int *)*v8;
      v9 = v14 + v13;
    }
  }
  if ( v3 < 0 )
    PnprMmFree(a2);
  return v3;
}
