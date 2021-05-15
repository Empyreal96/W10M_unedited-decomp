// MiSelectImageBase 
 
int __fastcall MiSelectImageBase(int a1, _DWORD **a2, int a3, int a4, unsigned int *a5)
{
  _WORD *v6; // r5
  _DWORD *v8; // lr
  unsigned int v9; // r4
  unsigned int v10; // r2
  _DWORD *v11; // r5
  _DWORD *v12; // r1
  int v13; // r8
  int v14; // r4
  unsigned int v15; // r7
  int v16; // r0
  unsigned int v17; // r4
  unsigned int v18; // r2
  int v19; // r0
  int v20; // r5
  int v22; // r0
  int v23; // r2
  int v24; // r2
  unsigned int v25; // r5
  unsigned int v26; // r1
  int v28[10]; // [sp+8h] [bp-28h] BYREF

  v6 = *a2;
  v28[0] = (int)&dword_632EC8;
  v8 = a2[9];
  v9 = *((_DWORD *)v6 + 13) & 0x9FFFFFFF;
  v28[1] = 0;
  v10 = dword_632EC0;
  *((_DWORD *)v6 + 13) = v9;
  v11 = a2[1];
  v12 = a2[6];
  v13 = (unsigned __int16)(((unsigned int)v11 + 15) >> 4);
  v14 = *(_DWORD *)(a1 + 20);
  v15 = (unsigned int)v12 - v14;
  if ( !a3 )
  {
    if ( (v8[7] & 0x2000) != 0 )
    {
      v18 = RtlFindClearBits((unsigned int *)&dword_632EC8, (unsigned __int16)(((unsigned int)v11 + 15) >> 4), v10);
      if ( v18 != -1 )
      {
        v19 = MiObtainRelocationBits(v28, (unsigned __int16)(((unsigned int)v11 + 15) >> 4), v18, 0);
        v20 = v19;
        if ( v19 != -1 )
        {
          v17 = (30720 - v13 - v19) << 16;
          if ( v17 == v15 )
            return sub_7D5104();
          goto LABEL_9;
        }
      }
    }
    else if ( v14 )
    {
      *a5 = (unsigned int)v12;
      return 0;
    }
    v22 = ExGenRandom(1);
    _rt_udiv64(254i64, (unsigned int)v22);
    v24 = v23 + 1;
    v25 = v13 << 16;
    if ( v15 <= MmHighestUserAddress && v25 <= MmHighestUserAddress )
    {
      v26 = v25 + v15;
      if ( v25 + v15 > v15 && v26 <= MmHighestUserAddress )
      {
        if ( !(*(_DWORD *)(a1 + 20) + (v24 << 16)) )
        {
          v17 = (unsigned int)a2[6];
          goto LABEL_22;
        }
        if ( v15 > v24 << 16 )
        {
          v17 = v15 - (v24 << 16);
LABEL_22:
          v20 = -1;
LABEL_9:
          (*a2)[12] = v20;
          *((_WORD *)*a2 + 26) = v13;
          goto LABEL_10;
        }
        v17 = v15 + (v24 << 16);
        if ( v17 >= v15 && v25 + v17 <= MmHighestUserAddress - 0x10000 && v25 + v17 >= v26 )
          goto LABEL_22;
      }
    }
    return -1073741701;
  }
  if ( a4 == 1 )
  {
    (*a2)[12] = -1;
    *((_WORD *)*a2 + 26) = 0;
    v17 = (unsigned int)a2[6];
    goto LABEL_10;
  }
  v16 = MiSelectSystemImageAddress(a3, v11, v10);
  v17 = v16;
  if ( v16 )
  {
    (*a2)[12] = (unsigned int)(v16 - dword_63389C) >> 16;
    *((_WORD *)*a2 + 26) = v13;
    MiSetControlAreaSystemVa(*a2, a3);
LABEL_10:
    *a5 = v17;
    return 0;
  }
  return -1073741670;
}
