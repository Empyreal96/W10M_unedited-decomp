// HvSynchronizeAndDropTemporaryBins 
 
int __fastcall HvSynchronizeAndDropTemporaryBins(int a1, int a2, _DWORD *a3, unsigned int a4, char a5)
{
  char v5; // r4
  _DWORD *v6; // r7
  _BYTE *v10; // r0
  _BYTE *v11; // r9
  unsigned int v13; // r8
  int v14; // r6
  unsigned int v15; // r4
  int v16; // r0
  int v17; // r0
  _DWORD *v18; // r1
  unsigned int v19; // r4
  _DWORD *v20; // r0
  _DWORD *v21; // r7
  unsigned int v22; // r2
  int v23; // r3
  unsigned int v24; // r8
  unsigned int v25; // r3
  unsigned int v26; // lr
  unsigned int v27; // r2
  unsigned int v28; // r6
  int *v29; // r1
  int *v30; // r0
  char v31; // r3
  unsigned int v32; // r2
  unsigned int v33; // r8
  int v34; // r0
  int v35; // r7
  unsigned int *v36; // r6
  unsigned int v37; // r1
  unsigned int v38; // r2
  int v39; // r6
  int v40; // t1
  bool i; // zf
  int v42; // t1
  unsigned int v43; // [sp+8h] [bp-40h]
  int v44; // [sp+Ch] [bp-3Ch]
  unsigned int v45; // [sp+10h] [bp-38h]
  _DWORD *v46; // [sp+14h] [bp-34h]
  unsigned int v47; // [sp+18h] [bp-30h]
  unsigned int v48; // [sp+1Ch] [bp-2Ch]
  unsigned int v49[2]; // [sp+20h] [bp-28h] BYREF
  unsigned int v50; // [sp+28h] [bp-20h]

  v5 = *(_BYTE *)(a1 + 72);
  v6 = a3;
  v50 = a4;
  v46 = a3;
  if ( (v5 & 4) == 0 )
    return 0;
  v10 = (_BYTE *)ExAllocatePoolWithTag(1, *(_DWORD *)(a1 + 48), 808865091);
  v11 = v10;
  if ( !v10 )
    return sub_548698();
  v49[0] = *(_DWORD *)(a1 + 36);
  v49[1] = (unsigned int)v10;
  v47 = v49[0];
  if ( a2 )
  {
    RtlCopyBitMap((unsigned int *)(a1 + 36), v49, 0);
    RtlMergeBitMaps(v49, (unsigned int *)(a1 + 52));
    if ( (*(_DWORD *)(a1 + 3312) & 1) == 0 )
      goto LABEL_6;
    if ( *(_DWORD *)(a1 + 3288) != (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) || a5 )
    {
      RtlMergeBitMaps(v49, (unsigned int *)(a1 + 1876));
LABEL_6:
      if ( a5 )
        RtlMergeBitMaps(v49, (unsigned int *)(a1 + 1904));
      goto LABEL_8;
    }
  }
  else
  {
    memset(v10, 0, *(_DWORD *)(a1 + 48));
  }
LABEL_8:
  v13 = 0;
  v45 = 0;
  if ( a4 )
  {
    while ( 1 )
    {
      v14 = *v6;
      v15 = (*v6 & 0xFFFFF000) - 4096;
      v16 = HvpGetCellMap(a1, v15);
      if ( !v16 )
        KeBugCheckEx(81, 1, a1);
      v17 = HvpMapEntryGetFreeBin(v16);
      v19 = v17 ? *(_DWORD *)(v17 + 12) : v15 - *v18;
      if ( v19 < v6[2] + v14 - 4096 )
        break;
LABEL_38:
      ++v13;
      v6 += 3;
      v45 = v13;
      v46 = v6;
      if ( v13 >= v50 )
        goto LABEL_39;
    }
LABEL_13:
    v20 = (_DWORD *)HvpGetCellMap(a1, v19);
    v21 = v20;
    if ( !v20 )
      KeBugCheckEx(81, 1, a1);
    v49[0] = v20[1] & 0xFFFFFFF0;
    v22 = v20[2] & 0xFFFFFFF0;
    v23 = v20[4];
    v43 = v22;
    v44 = v23;
    if ( !v22 )
      goto LABEL_50;
    v24 = 0;
    if ( !v23 )
      goto LABEL_24;
    v25 = v19 - v22;
    v48 = v19 - v22;
    while ( 1 )
    {
      v26 = v24 + v22;
      v27 = (v25 + v24 + v22) >> 9;
      v28 = v27 + 7;
      if ( v27 + 7 >= v47 )
        goto LABEL_46;
      v29 = (int *)&v11[4 * (v27 >> 5)];
      v30 = (int *)&v11[4 * (v28 >> 5)];
      v31 = v27 & 0x1F;
      if ( v29 != v30 )
        break;
      v32 = 255 << v31;
LABEL_20:
      if ( (*v29 & v32) != 0 )
        goto LABEL_46;
      HvViewMapUnpinForFileOffset(a1 + 152, v24 + v19 + 4096, 4096);
LABEL_22:
      v24 += 4096;
      v22 = v43;
      v25 = v48;
      if ( v24 >= v21[4] )
      {
        v23 = v44;
LABEL_24:
        if ( !v49[0] )
        {
          v23 = v21[4];
LABEL_50:
          v19 += v23;
          goto LABEL_36;
        }
        v33 = v23 + v19;
        while ( v19 < v33 )
        {
          v34 = HvpGetCellMap(a1, v19);
          v35 = v34;
          if ( !v34 )
            KeBugCheckEx(81, 1, a1);
          v36 = (unsigned int *)(v34 + 12);
          do
            v37 = __ldrex(v36);
          while ( !v37 && __strex(1u, v36) );
          __dmb(0xBu);
          if ( v37 && v37 != 1 )
            ExfWaitForRundownProtectionRelease(v34 + 12, v37, 1);
          *(_DWORD *)(v35 + 8) = 0;
          __dmb(0xBu);
          do
            v38 = __ldrex(v36);
          while ( __strex(1u, v36) );
          __dmb(0xBu);
          v19 += 4096;
        }
        HvpFreeBin(a1, v44, 0, 0, v43);
LABEL_36:
        v6 = v46;
        if ( v19 >= *v46 + v46[2] - 4096 )
        {
          v13 = v45;
          goto LABEL_38;
        }
        goto LABEL_13;
      }
    }
    v40 = *v29++;
    for ( i = (v40 & (-1 << v31)) == 0; i; i = v42 == 0 )
    {
      if ( v29 == v30 )
      {
        v32 = 0xFFFFFFFF >> (31 - (v28 & 0x1F));
        goto LABEL_20;
      }
      v42 = *v29++;
    }
LABEL_46:
    v39 = HvViewMapCopyToFileOffset(a1 + 152, v24 + v19 + 4096, v26, 4096);
    if ( v39 < 0 )
      goto LABEL_40;
    goto LABEL_22;
  }
LABEL_39:
  v39 = 0;
LABEL_40:
  ExFreePoolWithTag(v11, 0);
  return v39;
}
