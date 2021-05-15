// HvpEnlistFreeCell 
 
// local variable allocation has failed, the output may be wrong!
unsigned int *__fastcall HvpEnlistFreeCell(int a1, int a2, unsigned int a3, int a4, char a5)
{
  unsigned int v7; // r6
  unsigned int *result; // r0
  unsigned int *v11; // r4
  _DWORD *v12; // r0
  int v13; // r9
  unsigned int v14; // r0
  _DWORD *v15; // r7
  int v16; // r6
  int v17; // r10
  _DWORD *v18; // r4
  int v19; // r8
  unsigned int v20; // r0
  int v21; // r0
  _DWORD *i; // r8
  int v23; // r0
  int v24; // r0
  int v25; // r8
  int *v26; // r2 OVERLAPPED
  int v27; // r1 OVERLAPPED
  int v28; // r7
  int *v29; // r0
  int v30; // r3
  int v31; // r2
  unsigned int v32; // r3
  _DWORD *v33; // r0
  bool v34; // zf
  _DWORD *v35; // r0
  _DWORD *v36; // r0
  unsigned int v37; // r0
  unsigned __int8 v38; // [sp+8h] [bp-48h] BYREF
  unsigned __int8 v39; // [sp+9h] [bp-47h] BYREF
  char v40[2]; // [sp+Ah] [bp-46h] BYREF
  _DWORD *v41; // [sp+Ch] [bp-44h]
  int v42; // [sp+10h] [bp-40h]
  int v43; // [sp+14h] [bp-3Ch]
  _DWORD *v44; // [sp+18h] [bp-38h]
  int v45; // [sp+1Ch] [bp-34h] BYREF
  int v46; // [sp+20h] [bp-30h] BYREF
  int v47; // [sp+24h] [bp-2Ch] BYREF
  int v48; // [sp+28h] [bp-28h] BYREF
  int v49; // [sp+2Ch] [bp-24h]

  v7 = (a3 >> 3) - 1;
  v48 = -1;
  v49 = a2;
  v45 = -1;
  v46 = -1;
  v41 = 0;
  v42 = 0;
  v43 = 0;
  v44 = 0;
  v38 = 0;
  v39 = 0;
  v40[0] = 0;
  v47 = -1;
  if ( v7 >= 0x10 )
  {
    if ( v7 >> 4 > 0xFF )
      return (unsigned int *)sub_804064();
    v7 = 47 - __clz(v7 >> 4);
  }
  result = (unsigned int *)HvpGetHCell(a1, a2, &v46);
  v11 = result;
  if ( result )
  {
    v12 = (_DWORD *)HvpGetCellMap(a1, a2);
    v13 = (int)v12;
    if ( !v12 )
      KeBugCheckEx(81, 1, a1, a2, 786);
    v14 = HvpMapEntryGetBinAddress((int)v12, v12, (char *)&v38, &v45);
    v15 = (_DWORD *)v14;
    if ( v11 != (unsigned int *)(v14 + 32) || a3 != *(_DWORD *)(v14 + 8) - 32 )
      goto LABEL_5;
    v18 = (_DWORD *)v14;
    v19 = v13;
    v41 = (_DWORD *)v13;
    while ( !HvpGetBinMemAlloc(a1, v18, a4) )
    {
      if ( v42 )
      {
        HvpMapEntryReleaseBinAddress(0, v19);
        v39 = 0;
      }
      v33 = (_DWORD *)HvpGetCellMap(a1, v18[1] + (a4 << 31) - 4096);
      v19 = (int)v33;
      v41 = v33;
      if ( !v33 )
        KeBugCheckEx(81, 1, a1, v18[1] + (a4 << 31) - 4096, 817);
      v18 = (_DWORD *)HvpMapEntryGetBinAddress((int)v33, v33, (char *)&v39, &v47);
      v34 = v18[8] == v18[2] - 32;
      v42 = v39;
      if ( !v34 )
        goto LABEL_5;
    }
    if ( !v18[1] )
      goto LABEL_5;
    v44 = (_DWORD *)v13;
    while ( 1 )
    {
      v20 = HvpGetBinMemAlloc(a1, v18, a4) + v18[1];
      if ( v15[1] + v15[2] >= v20 )
        break;
      if ( a5 )
      {
        if ( v43 )
        {
          HvpMapEntryReleaseBinAddress(v20, (int)v44);
          v40[0] = 0;
        }
        v35 = (_DWORD *)HvpGetCellMap(a1, v15[2] + (a4 << 31) + v15[1]);
        v44 = v35;
        if ( !v35 )
          KeBugCheckEx(81, 1, a1, v15[1] + v15[2] + (a4 << 31), 862);
        v15 = (_DWORD *)HvpMapEntryGetBinAddress((int)v35, v35, v40, &v48);
        v34 = v15[8] == v15[2] - 32;
        v43 = (unsigned __int8)v40[0];
        if ( v34 )
          continue;
      }
      goto LABEL_5;
    }
    if ( (v18[2] == HvpGetBinMemAlloc(a1, v18, a4) || HvpMarkDirty(a1, v18[1] + (a4 << 31), 40, 0))
      && (v21 = (*(int (__fastcall **)(int, _DWORD, int))(a1 + 12))(20, 0, 540495171), (v48 = v21) != 0) )
    {
      v16 = v38;
      if ( v38 )
      {
        HvpMapEntryReleaseBinAddress(v21, v13);
        v16 = 0;
        v38 = 0;
      }
      v13 = (int)v41;
      for ( i = v18; ; i = (_DWORD *)v37 )
      {
        v23 = HvpDelistFreeCell(a1, i[1] + (a4 << 31) + 32);
        if ( i == v15 )
          break;
        if ( v16 )
        {
          HvpMapEntryReleaseBinAddress(v23, v13);
          v38 = 0;
        }
        v36 = (_DWORD *)HvpGetCellMap(a1, i[1] + i[2] + (a4 << 31));
        v13 = (int)v36;
        if ( !v36 )
          KeBugCheckEx(81, 1, a1, i[1] + i[2] + (a4 << 31), 926);
        v37 = HvpMapEntryGetBinAddress((int)v36, v36, (char *)&v38, &v45);
        v16 = v38;
      }
      v24 = HvpGetBinMemAlloc(a1, v18, a4);
      v25 = v48;
      v18[2] = v24;
      *(_DWORD *)(v25 + 8) = v24;
      *(_DWORD *)(v25 + 12) = v18[1];
      v18[8] = v18[2] - 32;
      v26 = (int *)(a1 + 412 * a4 + 1352);
      v27 = *v26;
      *(_QWORD *)v25 = *(_QWORD *)&v27;
      if ( *(int **)(v27 + 4) != v26 )
        __fastfail(3u);
      *(_DWORD *)(v27 + 4) = v25;
      *v26 = v25;
      v28 = v18[1] + (a4 << 31);
      if ( !HvpGetCellMap(a1, v28) )
        KeBugCheckEx(81, 1, a1, v28, 957);
      *(_DWORD *)(v25 + 16) = 1;
      v45 = 0;
      v17 = (int)v41;
      if ( v18[2] )
      {
        do
        {
          v29 = (int *)HvpGetCellMap(a1, v28);
          if ( !v29 )
            KeBugCheckEx(81, 1, a1, v28, 968);
          v29[1] = *(_DWORD *)(v17 + 4) & 0xFFFFFFF0 | v29[1] & 0xD | 2;
          v30 = *(_DWORD *)(v17 + 8);
          v31 = v45;
          *v29 = v25;
          v29[2] = v30 & 0xFFFFFFF0;
          v28 += 4096;
          v32 = v18[2];
          v45 = v31 + 4096;
        }
        while ( v31 + 4096 < v32 );
      }
    }
    else
    {
LABEL_5:
      HvpAddFreeCellHint(a1, v49, v7, a4);
      v16 = v38;
      v17 = (int)v41;
    }
    result = (unsigned int *)HvpReleaseHCell(a1);
    if ( v42 )
      result = HvpMapEntryReleaseBinAddress((int)result, v17);
    if ( v43 )
      result = HvpMapEntryReleaseBinAddress((int)result, (int)v44);
    if ( v16 )
      result = HvpMapEntryReleaseBinAddress((int)result, v13);
  }
  return result;
}
