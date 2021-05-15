// ArbPruneOrdering 
 
int __fastcall ArbPruneOrdering(unsigned __int16 *a1, unsigned __int64 a2, unsigned __int64 a3)
{
  unsigned int v4; // r4
  int v7; // r0
  unsigned int v8; // r8
  int v9; // r6
  unsigned int v10; // r7
  unsigned __int64 v11; // kr00_8
  unsigned __int64 v12; // r2
  int v13; // r1
  int v14; // r3
  int v15; // r4
  int v16; // r3
  int v17; // r4
  int v18; // r4
  int v19; // r6
  unsigned int v20; // r0
  unsigned int v21; // [sp+0h] [bp-28h]
  unsigned int v22; // [sp+4h] [bp-24h]

  v21 = HIDWORD(a2);
  v4 = a2;
  v22 = a2;
  if ( a3 < a2 )
    return sub_80E84C();
  v7 = ExAllocatePoolWithTag(1, 32 * *a1 + 16, 1281520193);
  v8 = v7;
  if ( !v7 )
    return -1073741670;
  v9 = v7;
  if ( *a1 )
  {
    v10 = *((_DWORD *)a1 + 1);
    if ( v10 < v10 + 16 * *a1 )
    {
      while ( 1 )
      {
        v11 = *(_QWORD *)v10;
        if ( a3 >= *(_QWORD *)v10 && (v12 = *(_QWORD *)(v10 + 8), __PAIR64__(v21, v4) <= v12) )
        {
          if ( __PAIR64__(v21, v4) <= v11 )
          {
            if ( a3 >= v12 )
              goto LABEL_11;
            *(_QWORD *)v9 = a3 + 1;
            *(_DWORD *)(v9 + 8) = *(_DWORD *)(v10 + 8);
            *(_DWORD *)(v9 + 12) = *(_DWORD *)(v10 + 12);
          }
          else
          {
            if ( a3 < v12 )
            {
              *(_QWORD *)v9 = a3 + 1;
              *(_DWORD *)(v9 + 8) = *(_DWORD *)(v10 + 8);
              *(_DWORD *)(v9 + 12) = *(_DWORD *)(v10 + 12);
              *(_DWORD *)(v9 + 16) = *(_DWORD *)v10;
              *(_DWORD *)(v9 + 20) = *(_DWORD *)(v10 + 4);
              *(_QWORD *)(v9 + 24) = __PAIR64__(v21, v4) - 1;
              v9 += 32;
              goto LABEL_11;
            }
            *(_QWORD *)(v9 + 8) = __PAIR64__(v21, v4) - 1;
            *(_QWORD *)v9 = v11;
          }
        }
        else
        {
          v13 = *(_DWORD *)(v10 + 4);
          v14 = *(_DWORD *)(v10 + 8);
          v15 = *(_DWORD *)(v10 + 12);
          *(_DWORD *)v9 = *(_DWORD *)v10;
          *(_DWORD *)(v9 + 4) = v13;
          *(_DWORD *)(v9 + 8) = v14;
          *(_DWORD *)(v9 + 12) = v15;
          v4 = v22;
        }
        v9 += 16;
LABEL_11:
        v10 += 16;
        if ( v10 >= *((_DWORD *)a1 + 1) + 16 * (unsigned int)*a1 )
        {
          v8 = v7;
          break;
        }
      }
    }
  }
  v16 = (int)(v9 - v8) >> 4;
  v17 = (unsigned __int16)v16;
  if ( (_WORD)v16 )
  {
    if ( (unsigned __int16)v16 > (unsigned int)a1[1] )
    {
      v19 = ExAllocatePoolWithTag(1, 16 * (unsigned __int16)v16, 1281520193);
      if ( !v19 )
      {
        v18 = -1073741670;
        ExFreePoolWithTag(v8);
        return v18;
      }
      v20 = *((_DWORD *)a1 + 1);
      if ( v20 )
        ExFreePoolWithTag(v20);
      *((_DWORD *)a1 + 1) = v19;
      a1[1] = v17;
    }
    memmove(*((_DWORD *)a1 + 1), v8, 16 * v17);
  }
  ExFreePoolWithTag(v8);
  *a1 = v17;
  return 0;
}
