// CmpRemoveSubKey 
 
int __fastcall CmpRemoveSubKey(int a1, int a2, unsigned int a3)
{
  int (__fastcall *v5)(int, unsigned int, int *); // r3
  _WORD *v7; // r9
  int v8; // r0
  int v9; // r5
  unsigned __int16 v11; // r3
  unsigned int v12; // r10
  char *v13; // r7
  int v14; // r0
  _WORD *v15; // r0
  _WORD *v16; // r6
  unsigned int v17; // r8
  unsigned int v18; // r5
  unsigned int v19; // r3
  int v20; // r3
  _WORD *v21; // r0
  unsigned int v22; // r2
  int v23; // r1
  int v24; // r0
  int v25; // r5
  unsigned int v26; // r3
  unsigned int v27; // r3
  unsigned __int16 v28; // [sp+8h] [bp-B8h] BYREF
  unsigned __int16 v29; // [sp+Ah] [bp-B6h]
  char *v30; // [sp+Ch] [bp-B4h]
  int v31; // [sp+10h] [bp-B0h] BYREF
  int v32; // [sp+14h] [bp-ACh] BYREF
  unsigned int v33; // [sp+18h] [bp-A8h]
  int v34; // [sp+1Ch] [bp-A4h] BYREF
  unsigned int v35; // [sp+20h] [bp-A0h]
  unsigned int v36; // [sp+24h] [bp-9Ch] BYREF
  unsigned int v37; // [sp+28h] [bp-98h]
  int v38; // [sp+2Ch] [bp-94h]
  int v39; // [sp+30h] [bp-90h] BYREF
  char v40[136]; // [sp+38h] [bp-88h] BYREF

  v28 = 0;
  v29 = 0;
  v30 = 0;
  v5 = *(int (__fastcall **)(int, unsigned int, int *))(a1 + 4);
  v31 = -1;
  v32 = -1;
  v37 = -1;
  v34 = -1;
  v7 = 0;
  v8 = v5(a1, a3, &v32);
  v9 = v8;
  if ( !v8 )
    return sub_805DD8();
  if ( (*(_WORD *)(v8 + 2) & 0x20) != 0 )
  {
    v38 = 1;
    v11 = 2 * *(_WORD *)(v8 + 72);
    v12 = v11;
    v28 = v11;
    v29 = v11;
    if ( v11 > 0x64u )
    {
      v13 = (char *)ExAllocatePoolWithTag(1, v11, 538987843);
      v30 = v13;
      if ( !v13 )
        goto LABEL_27;
    }
    else
    {
      v13 = v40;
      v30 = v40;
    }
    CmpCopyCompressedName(v13, v12, v9 + 76, *(unsigned __int16 *)(v9 + 72));
  }
  else
  {
    v38 = 0;
    v26 = *(unsigned __int16 *)(v8 + 72);
    v13 = (char *)(v8 + 76);
    v30 = (char *)(v8 + 76);
    v28 = v26;
    v12 = v26;
    v29 = v26;
  }
  (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v32);
  v14 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, a2, &v32);
  if ( v14 )
  {
    v35 = v14 + 4 * (a3 >> 31);
    v33 = *(_DWORD *)(v35 + 28);
    v15 = (_WORD *)(*(int (__fastcall **)(int, unsigned int, int *))(a1 + 4))(a1, v33, &v31);
    v16 = v15;
    if ( v15 )
    {
      v17 = 0x80000000;
      if ( *v15 == 26994 )
      {
        v17 = CmpFindSubKeyInRoot(a1, (int)v15, (int)&v28, &v36);
        if ( (v17 & 0x80000000) != 0 )
        {
          v25 = 0;
LABEL_19:
          if ( v16 )
            (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v31);
          goto LABEL_21;
        }
        v7 = v16;
        v37 = v33;
        HvpGetCellContextMove(&v34, &v31);
        v33 = v36;
        v16 = (_WORD *)(*(int (__fastcall **)(int, unsigned int, int *))(a1 + 4))(a1, v36, &v31);
        if ( !v16 )
          goto LABEL_30;
      }
      CmpFindSubKeyInLeafWithStatus(a1, (int)v16, (int)&v28, &v36, (unsigned int *)&v39);
      v18 = v39;
      if ( v39 < 0 )
      {
LABEL_30:
        v25 = 0;
LABEL_17:
        if ( v7 )
          (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v34);
        goto LABEL_19;
      }
      --*(_DWORD *)(v35 + 20);
      v19 = (unsigned __int16)(v16[1] - 1);
      v16[1] = v19;
      if ( v19 )
      {
        if ( v18 >= v19 )
        {
LABEL_16:
          v25 = 1;
          goto LABEL_17;
        }
        v20 = (unsigned __int16)v16[1];
        if ( *v16 == 26988 )
        {
          v22 = 4 * (v20 - v18);
          v23 = (int)&v16[2 * v18 + 4];
          v24 = (int)&v16[2 * v18 + 2];
        }
        else
        {
          v21 = &v16[4 * v18];
          v22 = 8 * (v20 - v18);
          v23 = (int)(v21 + 6);
          v24 = (int)(v21 + 2);
        }
LABEL_15:
        memmove(v24, v23, v22);
        goto LABEL_16;
      }
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v31);
      v16 = 0;
      HvFreeCell(a1, v33);
      if ( v7 )
      {
        v27 = (unsigned __int16)(v7[1] - 1);
        v7[1] = v27;
        if ( v27 )
        {
          if ( v17 >= v27 )
            goto LABEL_16;
          v22 = 4 * ((unsigned __int16)v7[1] - v17);
          v23 = (int)&v7[2 * v17 + 4];
          v24 = (int)&v7[2 * v17 + 2];
          goto LABEL_15;
        }
        (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v34);
        v7 = 0;
        HvFreeCell(a1, v37);
      }
      *(_DWORD *)(v35 + 28) = -1;
      goto LABEL_16;
    }
LABEL_27:
    v25 = 0;
LABEL_21:
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v32);
    goto LABEL_22;
  }
  v25 = 0;
LABEL_22:
  if ( v12 > 0x64 && v38 )
  {
    if ( v13 )
      ExFreePoolWithTag((unsigned int)v13);
  }
  return v25;
}
