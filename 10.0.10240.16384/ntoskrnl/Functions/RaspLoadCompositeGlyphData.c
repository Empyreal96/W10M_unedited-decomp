// RaspLoadCompositeGlyphData 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall RaspLoadCompositeGlyphData(int a1, int a2, _WORD *a3, int *a4, int a5)
{
  int v9; // r0
  _DWORD *v10; // r10
  int v11; // r4
  int v12; // r4
  int v13; // r5
  int v14; // r4
  int v15; // r1 OVERLAPPED
  int v16; // r0
  unsigned __int16 v18; // [sp+18h] [bp-40h] BYREF
  __int16 v19; // [sp+1Ah] [bp-3Eh] BYREF
  unsigned __int16 v20; // [sp+1Ch] [bp-3Ch] BYREF
  int v21; // [sp+20h] [bp-38h] BYREF
  int v22; // [sp+24h] [bp-34h] BYREF
  int v23[2]; // [sp+28h] [bp-30h] BYREF
  __int16 v24; // [sp+30h] [bp-28h] BYREF
  int v25; // [sp+32h] [bp-26h] BYREF
  int v26[8]; // [sp+36h] [bp-22h] BYREF

  v24 = 0;
  v25 = 0;
  v26[0] = 0;
  v21 = 0;
  if ( !a1 )
    return -1073741823;
  v9 = *(_DWORD *)(a1 + 40);
  if ( !v9 )
    return -1073741823;
  v10 = *(_DWORD **)(*(_DWORD *)(a1 + 8) + 8);
  v11 = v9 + a2;
  FioFwReadUshortAtOffset((int)v10, v9 + a2, &v24);
  FioFwReadUshortAtOffset((int)v10, v11 + 2, &v25);
  FioFwReadUshortAtOffset((int)v10, v11 + 4, (_WORD *)&v25 + 1);
  FioFwReadUshortAtOffset((int)v10, v11 + 6, v26);
  v12 = v11 + 8;
  FioFwReadUshortAtOffset((int)v10, v12, (_WORD *)v26 + 1);
  if ( v24 >= 0 )
    return -1073741811;
  v13 = RaspGetCompositeGlyphList(a1, a2, &v20, &v19, &v18, &v22, v23, a5);
  if ( v13 >= 0 )
  {
    v13 = RaspInitializeCompositeGlyphData(v10, v23, &v24, v20, v19, v18, v22 + v12 + 2, a3, &v21, a5);
    if ( v13 >= 0 )
    {
      v16 = v21;
    }
    else
    {
      while ( 1 )
      {
        v14 = v23[0];
        if ( (int *)v23[0] == v23 )
          break;
        *(_QWORD *)&v15 = *(_QWORD *)v23[0];
        if ( *(int **)(v23[0] + 4) != v23 || *(_DWORD *)(v15 + 4) != v23[0] )
          __fastfail(3u);
        v23[0] = v15;
        *(_DWORD *)(v15 + 4) = v23;
        RaspFreeMemory(*(_DWORD *)(v14 + 8), a5);
        RaspFreeMemory(v14, a5);
      }
      v16 = v21;
      if ( v21 )
      {
        RaspFreeMemory(v21, a5);
        v16 = 0;
      }
    }
    *a4 = v16;
  }
  return v13;
}
