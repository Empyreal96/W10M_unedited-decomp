// FsRtlLookupBaseMcbEntry 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall FsRtlLookupBaseMcbEntry(int a1, int a2, unsigned int a3, int a4, _DWORD *a5, _DWORD *a6, _DWORD *a7, _DWORD *a8, int *a9)
{
  int v10; // r5
  int v11; // r4
  int v12; // r1
  int v14; // r4 OVERLAPPED
  int v15; // r3
  int v16; // r0
  int v17; // r3
  unsigned int v18; // r3
  int v19; // r3
  int v20; // r3 OVERLAPPED
  int v21; // r0
  int v22; // r3
  int v23; // r3

  v10 = 0;
  v11 = *(_DWORD *)(a1 + 4) - 1;
  if ( v11 < 0 )
    return 0;
  while ( 1 )
  {
    v12 = (v11 + v10) / 2;
    if ( v12 && a3 < *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v12 - 8) )
    {
      v11 = v12 - 1;
      goto LABEL_6;
    }
    if ( a3 <= *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v12) - 1 )
      break;
    v10 = v12 + 1;
LABEL_6:
    if ( v10 > v11 )
      return 0;
  }
  v14 = 0;
  if ( a5 )
  {
    v15 = *(_DWORD *)(a1 + 12) + 8 * v12;
    v16 = *(_DWORD *)(v15 + 4);
    if ( v16 == -1 )
    {
      *a5 = -1;
      a5[1] = -1;
    }
    else
    {
      if ( v12 )
        v17 = *(_DWORD *)(v15 - 8);
      else
        v17 = 0;
      v18 = v16 - v17 + a3;
      *(_QWORD *)a5 = *(_QWORD *)(&v14 - 1);
    }
  }
  if ( a6 )
  {
    v19 = *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v12);
    a6[1] = 0;
    *a6 = v19 - a3;
  }
  if ( a7 )
  {
    v20 = *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v12 + 4);
    if ( v20 == -1 )
    {
      *a7 = -1;
      a7[1] = -1;
    }
    else
    {
      *(_QWORD *)a7 = *(_QWORD *)(&v14 - 1);
    }
  }
  if ( a8 )
  {
    if ( v12 )
    {
      v21 = *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v12 - 8);
      v22 = *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v12);
      a8[1] = 0;
      *a8 = v22 - v21;
    }
    else
    {
      v23 = **(_DWORD **)(a1 + 12);
      a8[1] = 0;
      *a8 = v23;
    }
  }
  if ( a9 )
    *a9 = v12;
  return 1;
}
