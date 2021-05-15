// MiPfAllocateMdls 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall MiPfAllocateMdls(_DWORD *a1, int a2, int a3)
{
  unsigned int v4; // r10
  _DWORD *v5; // r4
  int v6; // r6
  _DWORD *v7; // r9
  _DWORD *v8; // r0
  int v9; // r3
  unsigned int v10; // lr
  _DWORD *v11; // r8
  _DWORD *v12; // r5
  int v13; // r1
  int v14; // r2
  unsigned int v16; // r9
  unsigned int v17; // r8
  int v18; // r0
  int v19; // r5
  int v20; // r0
  unsigned int v21; // r2 OVERLAPPED
  int v22; // r1
  unsigned int v23; // r2
  __int64 v24; // r0
  int v25; // r8
  int v26; // r0
  int v27; // r3
  unsigned int v28; // r2
  int *v29; // r1
  _DWORD *v30; // [sp+0h] [bp-60h]
  _DWORD *v31; // [sp+4h] [bp-5Ch]
  unsigned int v32; // [sp+8h] [bp-58h]
  _DWORD *v33; // [sp+Ch] [bp-54h]
  _DWORD *v34; // [sp+10h] [bp-50h]
  _DWORD *v35; // [sp+14h] [bp-4Ch]
  int v36; // [sp+18h] [bp-48h]
  int v37; // [sp+20h] [bp-40h]
  unsigned int v38; // [sp+24h] [bp-3Ch]
  int v39; // [sp+28h] [bp-38h]
  unsigned int v41; // [sp+34h] [bp-2Ch]
  _DWORD *v42; // [sp+38h] [bp-28h]
  unsigned int v43; // [sp+3Ch] [bp-24h]

  v4 = a1[6];
  v5 = (_DWORD *)a1[10];
  v6 = a1[2];
  v38 = a1[7];
  v36 = a1[1];
  v43 = v4;
  v30 = v5;
  if ( !v6 )
    v6 = a1[1] + 80;
  v7 = &a1[a1[9] + 16];
  v8 = 0;
  v9 = 0;
  v42 = v7;
  v32 = 0;
  v33 = 0;
  v10 = 0;
  v34 = 0;
  v35 = 0;
  v11 = 0;
  if ( v5 >= v7 )
    return v9;
  v12 = v5 + 1;
  v31 = v5 + 1;
  v13 = dword_6348C0;
  do
  {
    v14 = *v5;
    if ( (*v5 & 2) == 0 )
      goto LABEL_6;
    if ( !v8 )
    {
      if ( (v14 & 0xFFFFFFFC) == 0 )
        goto LABEL_10;
LABEL_6:
      if ( (v14 & 1) != 0 )
      {
        if ( (v14 & 0xFFFFFFFC) == 0 )
          goto LABEL_40;
        if ( !v8 )
        {
          v11 = v5;
          v35 = v5;
LABEL_39:
          v8 = v5;
          v33 = v5;
          v10 = v14 & 0xFFFFFFFC;
LABEL_40:
          if ( !v8 )
            goto LABEL_10;
          goto LABEL_19;
        }
        if ( (int)((v14 & 0xFFFFFFFC) - v10) >> 2 <= v13 )
          goto LABEL_39;
      }
      else
      {
        if ( !v8 )
        {
          v11 = v5;
          v35 = v5;
LABEL_9:
          v8 = v5;
          v33 = v5;
          v10 = v14 & 0xFFFFFFFC;
          if ( v12 != v7 )
            goto LABEL_10;
          goto LABEL_19;
        }
        if ( (int)((v14 & 0xFFFFFFFC) - v10) >> 2 <= v13 )
          goto LABEL_9;
      }
LABEL_18:
      v30 = v5 - 1;
      v31 = v12 - 1;
      goto LABEL_19;
    }
    if ( (v14 & 0xFFFFFFFC) != 0 )
      goto LABEL_18;
LABEL_19:
    v16 = *v11 & 0xFFFFFFFC;
    v41 = *v8 & 0xFFFFFFFC;
    v17 = ((int)(v41 - v16) >> 2) + 1;
    v18 = MiGetInPageSupportBlock(0);
    v19 = v18;
    v39 = v18;
    if ( !v18 )
      return -1073741670;
    *(_DWORD *)(v18 + 140) = 0;
    v20 = MiSetInPagePriority(v18, v38, v4);
    v21 = v17 << 12;
    if ( v17 > 0x10 )
    {
      v37 = MmCreateMdl(0, 0, v21);
      if ( v37 )
        goto LABEL_22;
      MiFreeInPageSupportBlock(v19);
      return -1073741670;
    }
    v22 = 0;
    *(_WORD *)(v20 + 156) = 4 * (((v21 + 4095) >> 12) + 7);
    v37 = v20 + 152;
    *(_DWORD *)(v20 + 152) = 0;
    *(_WORD *)(v20 + 158) = 0;
    *(_QWORD *)(v20 + 168) = *(_QWORD *)(&v21 - 1);
    *(_DWORD *)(v20 + 176) = 0;
LABEL_22:
    while ( 1 )
    {
      v23 = *(_DWORD *)(v6 + 4);
      if ( v16 >= v23 && v16 < v23 + 4 * *(_DWORD *)(v6 + 28) )
        break;
      if ( (*(_WORD *)(v6 + 18) & 2) != 0 )
        return sub_80686C();
      if ( (*(_DWORD *)(v36 + 28) & 0x20) != 0 )
      {
        v27 = *(_DWORD *)(v6 + 12);
        if ( v27 )
        {
          v28 = *(_DWORD *)(v27 + 16);
          if ( v16 >= v28 && v16 < v28 + 4 * *(_DWORD *)(v6 + 28) )
            break;
        }
      }
      if ( a1[2] )
      {
        if ( !v34 )
        {
          v6 = *(_DWORD *)(a1[3] + 12);
          v34 = (_DWORD *)a1[3];
          goto LABEL_47;
        }
        if ( v32 >= v34[2] )
        {
          v6 = *(_DWORD *)(*v34 + 12);
          v34 = (_DWORD *)*v34;
LABEL_47:
          v32 = 1;
        }
        else
        {
          v6 = v34[v32++ + 3];
        }
      }
      else
      {
        v6 = *(_DWORD *)(v6 + 8);
      }
    }
    LODWORD(v24) = MiStartingOffset((_DWORD *)v6, v16);
    v5 = v30;
    *(_QWORD *)(v39 + 56) = v24;
    v25 = v24;
    if ( (*v33 & 1) != 0 && (*(_DWORD *)(v36 + 28) & 0x20) != 0 )
    {
      v26 = MiEndingOffsetWithLock((_DWORD *)v6);
      if ( (unsigned int)(v26 - v25) <= *(_DWORD *)(v37 + 20) )
        *(_DWORD *)(v37 + 20) = (v26 - v25 + 511) & 0xFFFFFE00;
    }
    v11 = v35;
    *(_DWORD *)(v39 + 116) = v33;
    *(_DWORD *)(v39 + 120) = v36;
    *(_DWORD *)(v39 + 136) = v35;
    *(_DWORD *)(v39 + 128) = a3;
    if ( a3 )
      *(_BYTE *)(v39 + 114) |= 0x80u;
    *(_DWORD *)(v39 + 144) = v37;
    v29 = (int *)a1[15];
    *(_DWORD *)v39 = a1 + 14;
    *(_DWORD *)(v39 + 4) = v29;
    if ( (_DWORD *)*v29 != a1 + 14 )
      __fastfail(3u);
    *v29 = v39;
    a1[15] = v39;
    v12 = v31;
    v10 = v41;
    v7 = v42;
    ++a1[12];
    v8 = 0;
    v4 = v43;
    v13 = dword_6348C0;
    v33 = 0;
LABEL_10:
    ++v5;
    ++v12;
    v30 = v5;
    v31 = v12;
  }
  while ( v5 < v7 );
  return 0;
}
