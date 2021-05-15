// HvpFindNextDirtyBlockAndCreateTemporary 
 
int __fastcall HvpFindNextDirtyBlockAndCreateTemporary(int a1, int a2, int a3, _DWORD *a4, _DWORD *a5)
{
  int v7; // r10
  unsigned int v8; // r9
  int v9; // r0
  _DWORD *v10; // r1
  unsigned int i; // r3
  unsigned int v12; // r4
  unsigned int v13; // r5
  int v14; // r0
  int v15; // r6
  int v16; // r3
  unsigned int v17; // r8
  int v18; // r0
  int v19; // r8
  int v20; // r4
  int v21; // r4
  int v22; // r0
  unsigned int v23; // r3
  unsigned int v24; // r6
  unsigned int v25; // r3
  int v26; // [sp+10h] [bp-30h] BYREF
  unsigned int v27; // [sp+14h] [bp-2Ch] BYREF
  int v28; // [sp+18h] [bp-28h] BYREF
  _DWORD *v29; // [sp+1Ch] [bp-24h]

  v29 = a4;
  if ( !HvpFindNextDirtyRun(a2, a3, &v26, &v27, &v28) )
    return sub_54865C();
  v7 = v26;
  v8 = v26 << 9;
  if ( !HvpGetCellMap(a1, v26 << 9) )
    KeBugCheckEx(81, 1, a1);
  v9 = ((int (*)(void))HvpMapEntryGetFreeBin)();
  if ( v9 )
  {
    v23 = *(_DWORD *)(v9 + 12);
    goto LABEL_13;
  }
  for ( i = (v7 & 0xFFFFFFF8) - (*v10 >> 9); ; i = v23 >> 9 )
  {
    v12 = v27;
    if ( i >= v27 )
    {
      *a5 = (v7 + 8) << 9;
      *v29 = v28 << 9;
      return 0;
    }
    v13 = i << 9;
    v14 = HvpGetCellMap(a1, i << 9);
    v26 = v14;
    if ( !v14 )
      KeBugCheckEx(81, 1, a1);
    v15 = *(_DWORD *)(v14 + 4) & 0xFFFFFFF0;
    v16 = *(_DWORD *)(v14 + 8);
    v17 = v16 & 0xFFFFFFF0;
    if ( (v16 & 0xFFFFFFF0) != 0 )
    {
      if ( v8 < v13 )
        v24 = 0;
      else
        v24 = v8 - v13;
      if ( v24 < *(_DWORD *)((v16 & 0xFFFFFFF0) + 8) )
      {
        v25 = v13 - v17;
        do
        {
          if ( v25 + v24 + v17 >= v12 << 9 )
            break;
          v20 = HvViewMapCopyToFileOffset(a1 + 152, v24 + v13 + 4096, v24 + v17, 4096);
          if ( v20 < 0 )
            return v20;
          v24 += 4096;
          v12 = v27;
          v25 = v13 - v17;
        }
        while ( v24 < *(_DWORD *)(v17 + 8) );
      }
      v21 = v26;
      goto LABEL_12;
    }
    v18 = (*(int (__fastcall **)(_DWORD, int, int))(a1 + 12))(
            *(_DWORD *)((*(_DWORD *)(v14 + 4) & 0xFFFFFFF0) + 8),
            1,
            959794499);
    v19 = v18;
    if ( !v18 )
      return -1073741670;
    v20 = HvpProtectBin(a1, *(_DWORD *)(v15 + 8), 0, v13, v18, 1);
    if ( v20 < 0 )
      break;
    memmove(v19, v15, *(_DWORD *)(v15 + 8));
    v21 = v26;
    v22 = HvpMapEntryGetFreeBin(v26);
    HvpPointMapEntriesToBuffer(a1, v15, v19, *(_DWORD *)(v15 + 8), v13, v22);
LABEL_12:
    v23 = *(_DWORD *)(v21 + 16) + v13;
LABEL_13:
    ;
  }
  (*(void (__fastcall **)(int, _DWORD))(a1 + 16))(v19, *(_DWORD *)(v15 + 8));
  return v20;
}
