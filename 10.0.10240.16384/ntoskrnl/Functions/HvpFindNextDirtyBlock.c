// HvpFindNextDirtyBlock 
 
int __fastcall HvpFindNextDirtyBlock(int a1, char **a2, char **a3, int *a4, unsigned int *a5, int *a6, char a7)
{
  int v9; // r9
  unsigned int v10; // r7
  char *v11; // r3
  int v12; // r0
  int *v13; // r5
  int v14; // r0
  unsigned int *v15; // r0
  int v16; // r4
  unsigned int v17; // r6
  char *v18; // r8
  unsigned int v20; // r10
  int v21; // r4
  int v22; // r0
  int *v23; // r8
  char *v24; // r2
  int v25; // r0
  unsigned int v26; // r0
  char v27; // [sp+8h] [bp-40h] BYREF
  char v28[3]; // [sp+9h] [bp-3Fh] BYREF
  unsigned int v29; // [sp+Ch] [bp-3Ch] BYREF
  char *v30; // [sp+10h] [bp-38h] BYREF
  int v31; // [sp+14h] [bp-34h]
  int v32; // [sp+18h] [bp-30h] BYREF
  int v33; // [sp+1Ch] [bp-2Ch] BYREF
  int v34; // [sp+20h] [bp-28h]
  char **v35; // [sp+24h] [bp-24h]

  v31 = a1;
  v35 = a3;
  v9 = 0;
  if ( !HvpFindNextDirtyRun(a2, a3, (char **)&v29, &v30, 0) )
    return 0;
  v10 = v29;
  v34 = (_DWORD)v30 << 9;
  v11 = (char *)(((_DWORD)v30 << 9) - (v29 << 9));
  v29 = (unsigned int)v11;
  if ( a7 )
  {
    v9 = ExAllocatePoolWithTag(1, (int)v11, 859131203);
    if ( !v9 )
      return sub_803798();
  }
  v12 = HvpGetCellMap(a1, v10 << 9);
  v13 = (int *)v12;
  if ( !v12 )
    KeBugCheckEx(81, 1, a1, v10 << 9, 4844);
  v14 = HvpMapEntryGetFreeBin(v12);
  if ( v14 )
    v15 = (unsigned int *)(HvpMapEntryGetBinAddress(v14, v13, &v27, &v32) - *(_DWORD *)(v14 + 12) + (v10 << 9));
  else
    v15 = (unsigned int *)HvpMapEntryGetBlockAddress(0, v13, &v27, &v32);
  if ( a7 )
    *a4 = v9;
  else
    *a4 = (int)v15 + ((v10 << 9) & 0xFFF);
  v16 = (v10 << 9) + 4096;
  *a6 = v16;
  v17 = 8 - (v10 & 7);
  v18 = &v30[-v10];
  if ( (unsigned int)&v30[-v10] < v17 )
    v17 = (unsigned int)&v30[-v10];
  if ( a7 )
  {
    v15 = (unsigned int *)memmove(v9, (int)&v15[128 * (v10 & 7)], v17 << 9);
    v9 += v17 << 9;
  }
  if ( (unsigned int)v18 > v17 )
  {
    v20 = v17 << 9;
    v21 = v16 & 0xFFFFF000;
    while ( v20 < v29 )
    {
      v22 = HvpGetCellMap(v31, v21);
      v23 = (int *)v22;
      if ( !v22 )
        KeBugCheckEx(81, 1, v31, v21, 4954);
      if ( !a7 )
      {
        v15 = (unsigned int *)HvpMapEntryIsNewAlloc(v22);
        if ( v15 )
          break;
      }
      v25 = HvpMapEntryGetFreeBin((int)v23);
      v32 = v25;
      if ( v25 )
      {
        v26 = HvpMapEntryGetBinAddress(v25, v23, v28, &v33);
        v15 = (unsigned int *)(v26 - *(_DWORD *)(v32 + 12) + v21);
      }
      else
      {
        v15 = (unsigned int *)HvpMapEntryGetBlockAddress(0, v23, v28, &v33);
      }
      if ( (unsigned int)(v34 - v21) <= 0x1000 )
      {
        if ( a7 )
          v15 = (unsigned int *)memmove(v9, (int)v15, v34 - v21);
        *a5 = v29;
        if ( v28[0] )
          v15 = HvpMapEntryReleaseBinAddress((int)v15, (int)v23);
        goto LABEL_14;
      }
      if ( a7 )
      {
        v15 = (unsigned int *)memmove(v9, (int)v15, 0x1000u);
        v9 += 4096;
      }
      v17 += 8;
      v21 += 4096;
      v20 += 4096;
      if ( v28[0] )
        v15 = HvpMapEntryReleaseBinAddress((int)v15, (int)v23);
    }
    v24 = v30;
    *a5 = v20;
    if ( (char *)(v17 + v10) != v24 )
      *v35 = (char *)(v17 + v10);
  }
  else
  {
    *a5 = v29;
  }
LABEL_14:
  if ( v27 )
    HvpMapEntryReleaseBinAddress((int)v15, (int)v13);
  return 1;
}
