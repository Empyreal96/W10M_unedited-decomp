// RtlLookupFunctionEntry 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall RtlLookupFunctionEntry(unsigned int a1, int *a2, unsigned int *a3)
{
  unsigned int v6; // r8
  unsigned int v7; // r2
  int *v8; // r1
  __int64 v9; // kr00_8
  int v10; // r7
  int v11; // lr
  unsigned int v12; // r3
  unsigned int v13; // r1
  unsigned int *v14; // r4 OVERLAPPED
  unsigned int v15; // r5
  int v16; // r1
  int v17; // r2
  int v18; // r0
  unsigned int v19; // r3
  int v20; // r3
  unsigned int v22; // r2
  int v23; // r3
  unsigned int v24; // r1
  unsigned int v25; // r2
  __int64 v26; // kr18_8
  unsigned int v27; // r2
  unsigned int v28; // r1
  int *v29; // r0
  __int64 v30; // kr28_8
  int v31; // [sp+0h] [bp-30h] BYREF
  int v32; // [sp+4h] [bp-2Ch]
  int v33; // [sp+8h] [bp-28h]
  unsigned int v34; // [sp+Ch] [bp-24h]

  if ( !a3 )
    goto LABEL_13;
  if ( *((_BYTE *)a3 + 7) )
  {
    *((_BYTE *)a3 + 7) = 0;
    v26 = *(_QWORD *)&RtlpUnwindHistoryTable[2 * (unsigned __int8)byte_681BDD + 4];
    if ( HIDWORD(v26) )
    {
      if ( a1 >= *(_DWORD *)HIDWORD(v26) + (int)v26 && a1 < *(_DWORD *)HIDWORD(v26) + 2 * *(_DWORD *)(HIDWORD(v26) + 4) )
        return sub_547E54(RtlpUnwindHistoryTable);
    }
  }
  if ( !*((_BYTE *)a3 + 6) )
    goto LABEL_13;
  if ( a1 < dword_681BE0
    || a1 >= dword_681BE4
    || (v6 = *((unsigned __int8 *)a3 + 5), v7 = v6, v6 >= RtlpUnwindHistoryTable[0]) )
  {
LABEL_11:
    if ( a1 >= a3[2] && a1 < a3[3] )
    {
      v27 = *((unsigned __int8 *)a3 + 4);
      v28 = v27;
      if ( v27 < *a3 )
      {
        v29 = (int *)&a3[2 * v27];
        while ( 1 )
        {
          v30 = *((_QWORD *)v29 + 2);
          if ( a1 >= *(_DWORD *)HIDWORD(v30) + (int)v30
            && a1 < *(_DWORD *)HIDWORD(v30) + 2 * *(_DWORD *)(HIDWORD(v30) + 4) )
          {
            break;
          }
          ++v28;
          v29 += 2;
          if ( v28 >= *a3 )
            goto LABEL_13;
        }
        *((_BYTE *)a3 + 4) = v27 + 1;
        *a2 = v30;
        return HIDWORD(v30);
      }
    }
LABEL_13:
    if ( a1 < dword_616494 || a1 >= dword_616498 + dword_616494 )
    {
      v10 = RtlpxLookupFunctionTable(a1, &v31);
    }
    else
    {
      v31 = dword_616490;
      v32 = dword_616494;
      v33 = dword_616498;
      v34 = *(_DWORD *)algn_61649C;
      v10 = dword_616490;
    }
    if ( !v10 )
      return 0;
    v11 = v32;
    v12 = v34;
    *a2 = v32;
    v13 = v12 >> 3;
    if ( !(v12 >> 3) )
      goto LABEL_44;
    v14 = (unsigned int *)(v10 + 8 * v13 - 8);
    v15 = a1 - v11;
    if ( a1 - v11 < *v14 )
    {
      v16 = v13 - 2;
      v17 = 0;
      while ( v16 >= v17 )
      {
        v18 = (v16 + v17) >> 1;
        v14 = (unsigned int *)(v10 + 8 * v18);
        if ( v15 >= *v14 )
        {
          if ( v15 < v14[2] )
            break;
          v17 = v18 + 1;
        }
        else
        {
          v16 = v18 - 1;
        }
      }
    }
    if ( v15 < *v14
      || ((v19 = v14[1], (v19 & 3) != 0) ? (v20 = (v19 >> 2) & 0x7FF) : (v20 = *(_DWORD *)(v19 + v11) & 0x3FFFF),
          v15 >= *v14 + 2 * v20) )
    {
LABEL_44:
      v14 = 0;
    }
    if ( a3 )
    {
      if ( v14 )
      {
        if ( !*((_BYTE *)a3 + 6) )
        {
          v22 = *a3;
          if ( *a3 < 0xC )
          {
            *a3 = v22 + 1;
            v23 = *a2;
            *(_QWORD *)&a3[2 * v22 + 4] = *(_QWORD *)(&v14 - 1);
            v24 = *v14 + *a2;
            v25 = *v14 + 2 * v14[1];
            if ( v24 < a3[2] )
              a3[2] = v24;
            if ( v25 > a3[3] )
            {
              a3[3] = v25;
              return (int)v14;
            }
          }
        }
      }
    }
    return (int)v14;
  }
  v8 = &RtlpUnwindHistoryTable[2 * v6];
  while ( 1 )
  {
    v9 = *((_QWORD *)v8 + 2);
    if ( a1 >= *(_DWORD *)HIDWORD(v9) + (int)v9 && a1 < *(_DWORD *)HIDWORD(v9) + 2 * *(_DWORD *)(HIDWORD(v9) + 4) )
      break;
    ++v7;
    v8 += 2;
    if ( v7 >= RtlpUnwindHistoryTable[0] )
      goto LABEL_11;
  }
  *((_BYTE *)a3 + 5) = v6 + 1;
  *a2 = v9;
  return HIDWORD(v9);
}
