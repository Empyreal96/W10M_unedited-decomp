// RaspGetXExtent 
 
int __fastcall RaspGetXExtent(unsigned int a1, int a2, int *a3, int a4, int a5, int a6)
{
  int v7; // r5
  int v8; // r6
  int v9; // r7
  int v10; // r2
  BOOL v11; // r8
  __int64 v12; // kr00_8
  int v13; // r2
  char *v14; // r4
  int v16; // r5
  int v17; // r1
  int v18; // r2
  int v19; // r3
  int v20; // r3
  int v21; // [sp+18h] [bp-78h] BYREF
  int v22; // [sp+1Ch] [bp-74h] BYREF
  char *v23; // [sp+20h] [bp-70h] BYREF
  int v24; // [sp+24h] [bp-6Ch]
  int *v25; // [sp+28h] [bp-68h]
  int v26; // [sp+30h] [bp-60h]
  int v27; // [sp+34h] [bp-5Ch]
  int v28; // [sp+38h] [bp-58h]
  char v29; // [sp+40h] [bp-50h] BYREF

  v25 = a3;
  v7 = 0;
  v8 = 0;
  v23 = 0;
  v24 = a2;
  v9 = 0;
  v21 = 0;
  v22 = 0;
  v26 = 0;
  v27 = 0;
  v28 = 0;
  v11 = RaspProvidesWorkspace(a6) == 0;
  if ( a1 < 0x20 )
    goto LABEL_4;
  v12 = *(_QWORD *)(v10 + 8);
  RaspGetCacheEntry(&RaspBitmapCache, a1, HIDWORD(v12), *(_DWORD *)(v12 + 20), v12, &v23);
  v14 = v23;
  if ( v23 )
    goto LABEL_3;
  v16 = v24;
  v9 = RaspRasterize(v24, a1, v13, 0, 0, &v21, &v22, (int *)&v23, a6);
  if ( v9 >= 0 )
  {
    if ( v11 )
    {
      v14 = (char *)RaspAllocateMemory(50);
      if ( !v14 )
        return sub_54DB64();
    }
    else
    {
      v14 = &v29;
    }
    v17 = *(_DWORD *)(a6 + 8);
    v18 = *(_DWORD *)(v12 + 20);
    *((_DWORD *)v14 + 6) = *(_DWORD *)(v16 + 12);
    v7 = v21;
    v19 = v22;
    *((_WORD *)v14 + 22) = a1;
    *((_DWORD *)v14 + 5) = v18;
    *((_DWORD *)v14 + 7) = v19;
    v20 = (int)v23;
    *((_DWORD *)v14 + 3) = v12;
    *((_DWORD *)v14 + 2) = v7;
    *((_DWORD *)v14 + 8) = v20;
    *((_DWORD *)v14 + 9) = 4;
    *((_DWORD *)v14 + 10) = 4;
    *(_DWORD *)(v14 + 46) = v17;
    if ( v11 )
      RaspAddCacheEntry(&RaspBitmapCache, v14);
LABEL_3:
    v8 = *((_DWORD *)v14 + 7);
    *(_DWORD *)(a6 + 8) = *(_DWORD *)(v14 + 46);
    goto LABEL_4;
  }
  v7 = v21;
  v8 = v22;
LABEL_4:
  *v25 = v8;
  if ( !v11 || v9 < 0 )
  {
    if ( v7 )
      RaspFreeMemory(v7, a6);
  }
  return v9;
}
