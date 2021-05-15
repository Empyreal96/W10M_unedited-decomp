// BcdEnumerateObjects 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall BcdEnumerateObjects(int a1, _DWORD *a2, _BYTE *a3, unsigned int *a4, int *a5)
{
  _BYTE *v5; // r6
  unsigned int *v6; // r9
  int v8; // r8
  int v9; // r4
  unsigned int v10; // r7
  int v11; // r8
  int v12; // r9
  int *v13; // r6
  int v14; // r7
  unsigned int v15; // r5
  int v16; // t1
  int v17; // r4
  int v18; // r0
  unsigned int v20; // r5
  _QWORD *v21; // r10
  unsigned int v22; // r3
  unsigned int v23; // r6
  unsigned int v24; // r5
  unsigned int v25; // r9
  unsigned int v26; // r6
  unsigned __int16 **v27; // r8
  int v28; // r4
  unsigned int v29; // r4 OVERLAPPED
  unsigned int v30; // r2
  _BYTE *v31; // r2
  int v32; // r3
  unsigned int v33; // r3
  int v34; // r2
  unsigned int v35; // r3
  int v36; // r1
  int *v37; // [sp+0h] [bp-58h] BYREF
  int v38; // [sp+4h] [bp-54h]
  int v39; // [sp+8h] [bp-50h] BYREF
  _BYTE *v40; // [sp+Ch] [bp-4Ch]
  unsigned int v41; // [sp+10h] [bp-48h] BYREF
  unsigned int v42; // [sp+14h] [bp-44h] BYREF
  int v43[2]; // [sp+18h] [bp-40h] BYREF
  int v44; // [sp+20h] [bp-38h]
  _DWORD *v45; // [sp+24h] [bp-34h]
  unsigned int v46; // [sp+28h] [bp-30h]
  unsigned int *v47; // [sp+2Ch] [bp-2Ch]
  int v48; // [sp+30h] [bp-28h] BYREF
  unsigned int v49; // [sp+34h] [bp-24h]

  v5 = a3;
  v45 = a2;
  v6 = a4;
  v47 = a4;
  v40 = a3;
  if ( !a3 && *a4 || !a5 || !*a2 )
    return -1073741811;
  v8 = BiIsOfflineHandle(a1);
  v38 = v8;
  v9 = BiAcquireBcdSyncMutant(v8);
  if ( v9 < 0 )
    return v9;
  v39 = 0;
  v42 = 0;
  v10 = 0;
  v44 = 131097;
  v37 = 0;
  v9 = BiOpenKey(a1, L"Objects", 131097, &v39);
  if ( v9 < 0 )
    goto LABEL_32;
  v9 = BiEnumerateSubKeys(v39, &v37, &v41);
  v10 = (unsigned int)v37;
  if ( v9 < 0 )
    goto LABEL_32;
  v11 = 0;
  v43[0] = 0;
  v46 = (unsigned int)v37;
  if ( v41 )
  {
    v12 = (int)v45;
    v13 = v37;
    v14 = v44;
    v15 = v41;
    do
    {
      v16 = *v13++;
      if ( BiOpenKey(v39, v16, v14, &v37) >= 0 )
      {
        v17 = BiGetObjectDescription(v37, &v48);
        v18 = BiCloseKey(v37);
        if ( v17 >= 0 )
        {
          if ( *(_DWORD *)(v12 + 4) )
            return sub_813AE8(v18);
          ++v11;
        }
      }
      --v15;
    }
    while ( v15 );
    v10 = v46;
    v6 = v47;
    v5 = v40;
    v43[0] = v11;
  }
  v9 = RtlULongLongToULong(20 * v11, (20 * (unsigned __int64)(unsigned int)v11) >> 32, &v42);
  if ( v9 < 0 )
    goto LABEL_31;
  v20 = (v42 + 3) & 0xFFFFFFFC;
  v21 = &v5[v20];
  v9 = RtlULongLongToULong(8 * v11, (unsigned __int64)(unsigned int)v11 >> 29, &v42);
  if ( v9 < 0 )
    goto LABEL_31;
  v22 = (v42 + 3) & 0xFFFFFFFC;
  v23 = v22 + v20;
  v42 = v22 + v20;
  if ( v22 + v20 < v20 )
  {
    v9 = -1073741675;
    goto LABEL_31;
  }
  if ( v23 > *v6 )
  {
    v9 = -1073741789;
    *v6 = v23;
    *a5 = v11;
    goto LABEL_31;
  }
  v24 = 0;
  v25 = 0;
  if ( !v41 )
    goto LABEL_30;
  v26 = v43[0];
  v27 = (unsigned __int16 **)v10;
  while ( v24 < v26 )
  {
    if ( BiOpenKey(v39, *v27, v44, &v37) < 0 )
      goto LABEL_28;
    v28 = BiGetObjectDescription(v37, &v48);
    BiCloseKey(v37);
    if ( v28 < 0 )
      goto LABEL_28;
    v29 = v49;
    v30 = v45[1];
    if ( !v30 )
      goto LABEL_26;
    v33 = v30 >> 28;
    if ( v30 >> 28 != v49 >> 28 )
      goto LABEL_28;
    if ( v33 == 1 || v33 == 2 )
    {
      v36 = (v30 >> 20) & 0xF;
      if ( v36 && v36 != ((v49 >> 20) & 0xF) || (v30 & 0xFFFFF) != 0 && (v30 & 0xFFFFF) != (v49 & 0xFFFFF) )
        goto LABEL_28;
      v34 = HIBYTE(v30) & 0xF;
      if ( !v34 )
        goto LABEL_26;
      v35 = HIBYTE(v49) & 0xF;
    }
    else
    {
      if ( v33 != 3 )
      {
        if ( ((v30 ^ v49) & 0xFFFFFFF) == 0 )
          goto LABEL_26;
        goto LABEL_28;
      }
      v34 = v30 & 0xFFFFFFF;
      if ( !v34 )
        goto LABEL_26;
      v35 = v49 & 0xFFFFFFF;
    }
    if ( v34 == v35 )
    {
LABEL_26:
      RtlInitUnicodeString((unsigned int)v43, *v27);
      if ( RtlGUIDFromString((unsigned __int16 *)v43, v40) >= 0 )
      {
        v31 = v40;
        v32 = v48;
        *((_DWORD *)v40 + 4) = v21;
        *v21 = *(_QWORD *)(&v29 - 1);
        v40 = v31 + 20;
        ++v21;
        ++v24;
      }
    }
LABEL_28:
    ++v25;
    ++v27;
    if ( v25 >= v41 )
      break;
  }
  v23 = v42;
  v10 = v46;
LABEL_30:
  v9 = 0;
  *v47 = v23;
  *a5 = v24;
LABEL_31:
  v8 = v38;
LABEL_32:
  if ( v39 )
    BiCloseKey(v39);
  if ( v10 )
    ExFreePoolWithTag(v10);
  BiReleaseBcdSyncMutant(v8);
  return v9;
}
