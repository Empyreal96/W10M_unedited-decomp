// MiMapViewOfSection 
 
int __fastcall MiMapViewOfSection(_DWORD *a1, int a2, unsigned int *a3, int a4, unsigned int a5, unsigned __int64 *a6, int *a7, int a8, int a9, int a10, int a11, _DWORD *a12)
{
  int v14; // r4
  int v15; // r0
  int v16; // r1
  int v17; // r9
  unsigned __int64 v18; // kr00_8
  unsigned int v19; // r4
  unsigned int v20; // r6
  unsigned __int64 v21; // kr08_8
  unsigned int v22; // r0
  int v23; // r0
  int v24; // r1
  int v25; // r8
  int v26; // r6
  int v27; // r4
  unsigned int *v28; // r0
  unsigned int v29; // r3
  int v30; // r0
  unsigned int *v31; // r1
  int *v32; // r2
  int v33; // r0
  int v34; // r0
  unsigned __int8 v36[4]; // [sp+28h] [bp-98h] BYREF
  unsigned int *v37; // [sp+2Ch] [bp-94h]
  int v38; // [sp+30h] [bp-90h] BYREF
  int *v39; // [sp+34h] [bp-8Ch]
  _DWORD *v40; // [sp+38h] [bp-88h]
  int v41; // [sp+3Ch] [bp-84h]
  unsigned int v42; // [sp+40h] [bp-80h]
  int v43; // [sp+44h] [bp-7Ch]
  unsigned __int64 *v44; // [sp+48h] [bp-78h]
  unsigned int *v45; // [sp+4Ch] [bp-74h]
  _DWORD *v46; // [sp+50h] [bp-70h] BYREF
  int v47; // [sp+54h] [bp-6Ch]
  int v48; // [sp+58h] [bp-68h]
  int *v49; // [sp+5Ch] [bp-64h]
  int v50; // [sp+60h] [bp-60h]
  int v51; // [sp+64h] [bp-5Ch]
  unsigned int *v52; // [sp+68h] [bp-58h]
  unsigned int *v53; // [sp+6Ch] [bp-54h]
  int v54; // [sp+70h] [bp-50h]
  unsigned __int64 *v55; // [sp+74h] [bp-4Ch]
  int v56; // [sp+78h] [bp-48h]
  _DWORD *v57; // [sp+7Ch] [bp-44h]
  int v58; // [sp+80h] [bp-40h]
  _DWORD _88[20]; // [sp+88h] [bp-38h] BYREF

  _88[16] = a1;
  _88[17] = a2;
  _88[18] = a3;
  v43 = a4;
  _88[19] = a4;
  v37 = a3;
  v41 = a2;
  v51 = a2;
  v53 = a3;
  v44 = a6;
  v55 = a6;
  v39 = a7;
  v49 = a7;
  v40 = a12;
  v47 = 0;
  v48 = 0;
  v57 = a1;
  v45 = (unsigned int *)MiSectionControlArea((int)a1);
  v52 = v45;
  v42 = *v45;
  v36[0] = 1;
  v38 = a10;
  if ( (a10 & 0x40000000) != 0 )
  {
    if ( (a10 & 0xF0) == 0 )
      return -1073741576;
    v36[0] = 0;
    v38 = a10 & 0xBFFFFFFF;
  }
  if ( (a1[8] & 0x20) != 0 )
  {
    v17 = a9;
    if ( (a9 & 0x20000000) != 0 )
      v17 = a9 & 0xDFFFFFFF;
  }
  else
  {
    v15 = MiMakeProtectionMask(a1[9] & 0xFFF);
    if ( !MiIsPteProtectionCompatible(v15, v16) )
      return -1073741746;
    v17 = a9;
  }
  v18 = *a6 + (unsigned int)*a7;
  if ( v18 < *a6 )
    return -1073741793;
  v19 = a1[6];
  v20 = a1[7];
  if ( v18 > __PAIR64__(v20, v19) && (v17 & 0x2000) == 0 )
    return -1073741793;
  if ( !*a7 )
  {
    v21 = __PAIR64__(v20, v19) - *a6;
    *a7 = v21;
    if ( HIDWORD(v21) > 1 || MmHighestUserAddress - *a3 - 0xFFFF < v21 )
      return -1073741793;
  }
  if ( a5 > *a7 && (v17 & 0x2000) == 0 )
    return -1073741581;
  if ( (unsigned __int64)(unsigned int)*a7 > *((_QWORD *)a1 + 3) && (v17 & 0x2000) == 0 )
    return -1073741793;
  if ( (v17 & 0x2000) != 0 && (a1[9] & 0x44) == 0 )
    return -1073741746;
  if ( (v17 & 0x800000) != 0 && ((a1[8] & 0x20) == 0 || (v17 & 0x20000000) != 0) )
    return -1073741577;
  v22 = v38;
  if ( (*(_WORD *)(v42 + 8) & 0x8000) != 0 )
    v22 = v38 & 0xFFFFF9FF | 0x200;
  if ( (*(_WORD *)(v42 + 8) & 0x4000) != 0 )
    v22 = v22 & 0xFFFFF9FF | 0x400;
  v23 = MiMakeProtectionMask(v22);
  v25 = v23;
  v56 = v23;
  if ( v23 == -1 )
    return -1073741755;
  v26 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v54 = v26;
  if ( (*(_DWORD *)(v26 + 188) & 0x400) != 0 || (BYTE2(MiFlags) & 3u) > 1 && (MiFlags & 0x40000) != 0 )
  {
    if ( (a1[8] & 0x20) != 0 )
    {
      v17 &= ~v24;
    }
    else if ( (v23 & 2) != 0 )
    {
      return MiArbitraryCodeBlocked(v26);
    }
  }
  v27 = v41;
  if ( v26 != v41 )
  {
    KiStackAttachProcess(v41, 0, (int)_88);
    v47 = 1;
    v48 = 1;
  }
  v28 = v45;
  v29 = v45[7];
  if ( (v29 & 0x400) != 0 )
  {
    if ( v40 )
    {
      v14 = -1073741575;
      goto LABEL_64;
    }
    v30 = MiMapViewOfPhysicalSection(v41, v37, v44, v39, v25, v43, v17, v36);
  }
  else
  {
    if ( (v29 & 0x20) != 0 )
    {
      if ( v40 )
      {
        v14 = -1073741575;
      }
      else if ( (v17 & 0x2000) != 0 )
      {
        v14 = -1073741577;
      }
      else
      {
        v31 = v37;
        v46 = (_DWORD *)*v37;
        v32 = v39;
        v38 = *v39;
        while ( 1 )
        {
          v14 = MiMapViewOfImageSection(v28, v26, v27, v31, v44, v32, a1, a8, v25, v43, v17, 0);
          v50 = v14;
          if ( (v17 & 0x20000000) == 0 )
            break;
          v42 = v17 & 0xDFFFFFFF;
          v33 = MiMapViewOfImageSection(v45, v26, v41, &v46, v44, &v38, a1, a8, v25, v43, v17 & 0xDFFFFFFF, 0);
          v58 = v33;
          if ( v14 < 0 )
          {
            *v37 = (unsigned int)v46;
            *v39 = v38;
            v14 = v33;
            goto LABEL_64;
          }
          if ( v33 < 0 )
          {
            v27 = v41;
            MiUnmapViewOfSection(v41, *v37, 0);
            v17 = v42;
            v32 = v39;
            v28 = v45;
            v31 = v37;
          }
          else
          {
            v34 = *v37;
            v42 = v38;
            v40 = v46;
            memmove(v34, (int)v46, v38);
            if ( v58 >= 0 )
            {
              MiUnmapViewOfSection(v41, v40, 0);
              KeSweepIcacheRange(1, *v37, v42);
              goto LABEL_64;
            }
            v27 = v41;
            MiUnmapViewOfSection(v41, *v37, 0);
            MiUnmapViewOfSection(v27, v40, 0);
            v17 &= 0xDFFFFFFF;
            v32 = v39;
            v28 = v45;
            v31 = v37;
          }
        }
      }
      goto LABEL_64;
    }
    v30 = MiMapViewOfDataSection(v45, v41, v37, (int)v44, v39, (int)a1, a8, v25, a5, v43, v17, a11, v36, v40);
  }
  v14 = v30;
LABEL_64:
  if ( v47 )
    KiUnstackDetachProcess((unsigned int)_88, 0);
  return v14;
}
