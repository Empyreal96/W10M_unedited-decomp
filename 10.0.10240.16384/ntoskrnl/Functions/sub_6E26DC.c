// sub_6E26DC 
 
int __fastcall sub_6E26DC(int a1, int a2, int a3, int a4, _BYTE *a5)
{
  _BYTE *v5; // r10
  int v6; // r7
  int v7; // r4
  unsigned int v8; // r1
  int result; // r0
  unsigned int v10; // r1
  unsigned __int64 v11; // r0
  int v12; // r2
  int v13; // r3
  signed __int64 v14; // kr10_8
  int v15; // r0
  int v16; // r3
  int v17; // r7
  int v18; // r0
  int v19; // r4
  unsigned int v20; // r1
  unsigned int v21; // r0
  int v22; // r2
  int v23; // r7
  unsigned __int8 *v24; // lr
  int v25; // r4
  int i; // r9
  int v27; // t1
  int v28; // r7
  char *j; // lr
  int v30; // t1
  int v31; // r7
  int v32; // r0
  int v33; // r1
  __int64 v34; // kr18_8
  unsigned int v35; // r1
  int v36; // r0
  int v37; // r1
  unsigned __int8 *v38; // lr
  int v39; // r7
  int k; // r4
  int v41; // t1
  int v42; // r1
  char *l; // r0
  int v44; // t1
  __int64 v45; // [sp+10h] [bp-128h] BYREF
  int v46; // [sp+18h] [bp-120h]
  int v47; // [sp+1Ch] [bp-11Ch]
  int v48; // [sp+20h] [bp-118h]
  int v49; // [sp+24h] [bp-114h]
  int v50[2]; // [sp+28h] [bp-110h] BYREF
  int v51; // [sp+30h] [bp-108h]
  int v52; // [sp+34h] [bp-104h]
  int v53; // [sp+38h] [bp-100h]
  int v54; // [sp+3Ch] [bp-FCh]
  int v55; // [sp+40h] [bp-F8h]
  int v56; // [sp+44h] [bp-F4h]
  int v57; // [sp+48h] [bp-F0h]
  int v58; // [sp+4Ch] [bp-ECh]
  int v59; // [sp+50h] [bp-E8h]
  int v60; // [sp+54h] [bp-E4h]
  int v61; // [sp+64h] [bp-D4h]
  int v62; // [sp+80h] [bp-B8h]
  int v63; // [sp+84h] [bp-B4h]
  int v64; // [sp+94h] [bp-A4h]
  int v65; // [sp+B0h] [bp-88h]
  int v66; // [sp+B4h] [bp-84h]
  _DWORD v67[2]; // [sp+B8h] [bp-80h] BYREF
  int v68; // [sp+C0h] [bp-78h]
  int v69; // [sp+C4h] [bp-74h]
  int v70; // [sp+C8h] [bp-70h]
  int v71; // [sp+CCh] [bp-6Ch]
  int v72; // [sp+D0h] [bp-68h]
  int v73; // [sp+D4h] [bp-64h]
  int v74; // [sp+D8h] [bp-60h]
  int v75; // [sp+DCh] [bp-5Ch]
  int v76; // [sp+E0h] [bp-58h]
  int v77; // [sp+E4h] [bp-54h]
  _DWORD v78[2]; // [sp+E8h] [bp-50h] BYREF
  int v79; // [sp+F0h] [bp-48h]
  __int64 v80; // [sp+F8h] [bp-40h]
  char v81; // [sp+110h] [bp-28h]

  v5 = a5;
  v6 = 0;
  v48 = a3;
  v49 = a4;
  v46 = a1;
  v47 = a2;
  if ( !off_920350 )
  {
    if ( !dword_922C44 )
    {
LABEL_25:
      v16 = dword_920284;
      goto LABEL_26;
    }
    v7 = KeAbPreAcquire((unsigned int)&dword_922C04, 0, 0);
    do
      v8 = __ldrex((unsigned int *)&dword_922C04);
    while ( !v8 && __strex(0x11u, (unsigned int *)&dword_922C04) );
    __dmb(0xBu);
    if ( v8 )
      return sub_7DB2E8(17);
    if ( v7 )
      *(_BYTE *)(v7 + 14) |= 1u;
    if ( !dword_922BEC )
      v6 = 1;
    __dmb(0xBu);
    do
      v10 = __ldrex((unsigned int *)&dword_922C04);
    while ( v10 == 17 && __strex(0, (unsigned int *)&dword_922C04) );
    if ( v10 != 17 )
      ExfReleasePushLockShared(&dword_922C04);
    KeAbPostRelease((unsigned int)&dword_922C04);
    if ( v6 == 1
      || sub_6E2570((int)v78, SHIDWORD(v11), v12, v13) >= 0
      && v80
      && (v14 = v80 + 900000, v80 + 900000 >= v80)
      && (KeQueryTickCount((int *)&v45),
          v15 = KeQueryTimeIncrement(),
          LODWORD(v11) = _rt_sdiv64(10000i64, v45 * (unsigned int)v15),
          v14 > (__int64)v11) )
    {
      if ( !v6 )
      {
LABEL_23:
        if ( !off_920350 )
          goto LABEL_24;
        goto LABEL_60;
      }
    }
    v17 = 0;
    if ( !off_920350 )
    {
      if ( !dword_922C44 )
        goto LABEL_25;
      v18 = KeAbPreAcquire((unsigned int)&dword_922C04, 0, 0);
      v19 = v18;
      do
        v20 = __ldrex((unsigned __int8 *)&dword_922C04);
      while ( __strex(v20 | 1, (unsigned __int8 *)&dword_922C04) );
      __dmb(0xBu);
      if ( (v20 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(&dword_922C04, v18, (unsigned int)&dword_922C04);
      if ( v19 )
        *(_BYTE *)(v19 + 14) |= 1u;
      if ( !dword_922BEC )
        v17 = 1;
      __dmb(0xBu);
      do
        v21 = __ldrex((unsigned int *)&dword_922C04);
      while ( __strex(v21 - 1, (unsigned int *)&dword_922C04) );
      if ( (v21 & 2) != 0 && (v21 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)&dword_922C04);
      KeAbPostRelease((unsigned int)&dword_922C04);
      if ( v17 )
      {
        dword_920284 = 5;
        v79 = 5;
        sub_6E34A4(v78, 2, 0);
        goto LABEL_23;
      }
      if ( !dword_922C44 )
      {
LABEL_55:
        v5 = a5;
        goto LABEL_23;
      }
      v22 = 1;
      v23 = *(_DWORD *)(dword_922C44 + 4);
      LOBYTE(v62) = 1;
      v24 = (unsigned __int8 *)(dword_922C44 + 20);
      if ( dword_922C44 == -20 )
        goto LABEL_59;
      v25 = 0;
      for ( i = 0; v23; v25 += v27 - 23737705 + i )
      {
        v27 = *v24++;
        --v23;
        v22 = __ROR4__(-23737705 * __ROR4__(-23737705 * (v27 - 23737705 + i), 21), 21);
        HIDWORD(v11) = -23737705 * v22;
        i = __ROR4__(-23737705 * v22, 21);
      }
      if ( !dword_922C3C )
        goto LABEL_50;
      if ( RtlULongLongToULong(8 * dword_922C3C, (unsigned int)dword_922C3C >> 29, &v45) )
      {
LABEL_59:
        v25 = 0;
        i = 0;
      }
      else
      {
        v28 = v45;
        for ( j = &byte_922C48; v28; v25 += v30 - 23737705 + i )
        {
          v30 = (unsigned __int8)*j++;
          --v28;
          v22 = __ROR4__(-23737705 * __ROR4__(-23737705 * (v30 - 23737705 + i), 21), 21);
          HIDWORD(v11) = -23737705 * v22;
          i = __ROR4__(-23737705 * v22, 21);
        }
      }
LABEL_50:
      v50[1] = i;
      v51 = 4;
      v50[0] = v25;
      v52 = v61;
      v53 = 0;
      v54 = 0;
      v55 = 0;
      v56 = 0;
      v57 = 0;
      v58 = 0;
      v59 = v62;
      v60 = v63;
      if ( sub_6E2570((int)v78, SHIDWORD(v11), v22, v63) >= 0 )
      {
        v31 = 4;
        if ( v78[0] != v25 || v78[1] != i )
        {
          v51 = 4;
          v31 = 6;
        }
        KeQueryTickCount((int *)&v45);
        v32 = KeQueryTimeIncrement();
        v53 = _rt_sdiv64(10000i64, v45 * (unsigned int)v32);
        v54 = v33;
        sub_6E34A4(v50, v31, 0);
      }
      goto LABEL_55;
    }
  }
  do
  {
LABEL_60:
    v34 = MEMORY[0xFFFF93B0];
    while ( 1 )
    {
      v35 = MEMORY[0xFFFF900C];
      __dmb(0xBu);
      LODWORD(v45) = MEMORY[0xFFFF9008];
      __dmb(0xBu);
      if ( v35 == MEMORY[0xFFFF9010] )
        break;
      __dmb(0xAu);
      __yield();
    }
  }
  while ( v34 != MEMORY[0xFFFF93B0] );
  LODWORD(v11) = _rt_udiv64((unsigned int)dword_989680, __PAIR64__(v35, v45) - v34);
  if ( v11 > 0x2A30 )
  {
    dword_920284 = 2;
    v79 = 2;
    sub_6E34A4(v78, 2, 0);
    v81 = 0;
    sub_6E34A4(v78, 32, 0);
  }
  v5 = a5;
LABEL_24:
  if ( !dword_922C44 )
    goto LABEL_25;
  v36 = sub_6E2570((int)v67, SHIDWORD(v11), v12, dword_922C44);
  if ( v36 < 0 )
  {
    if ( v36 != -1073741275 || !dword_922C44 )
      goto LABEL_27;
    v37 = *(_DWORD *)(dword_922C44 + 4);
    LOBYTE(v65) = 1;
    v38 = (unsigned __int8 *)(dword_922C44 + 20);
    if ( dword_922C44 == -20 )
      goto LABEL_80;
    v39 = 0;
    for ( k = 0; v37; --v37 )
    {
      v41 = *v38++;
      k = __ROR4__(-23737705 * __ROR4__(-23737705 * __ROR4__(-23737705 * (v41 - 23737705 + k), 21), 21), 21);
      v39 += v41 - 23737705 + k;
    }
    if ( !dword_922C3C )
      goto LABEL_81;
    if ( RtlULongLongToULong(8 * dword_922C3C, (unsigned int)dword_922C3C >> 29, &v45) )
    {
LABEL_80:
      v39 = 0;
      k = 0;
    }
    else
    {
      v42 = v45;
      for ( l = &byte_922C48; v42; --v42 )
      {
        v44 = (unsigned __int8)*l++;
        k = __ROR4__(-23737705 * __ROR4__(-23737705 * __ROR4__(-23737705 * (v44 - 23737705 + k), 21), 21), 21);
        v39 += v44 - 23737705 + k;
      }
    }
LABEL_81:
    v69 = v64;
    v70 = 0;
    v71 = 0;
    v72 = 0;
    v73 = 0;
    v74 = 0;
    v75 = 0;
    v67[0] = v39;
    v67[1] = k;
    v76 = v65;
    v77 = v66;
    v68 = 4;
    sub_6E34A4(v67, -1, 0);
    goto LABEL_27;
  }
  v16 = v68;
LABEL_26:
  if ( v16 )
  {
LABEL_27:
    *v5 = 1;
    return sub_6E29F0(v46);
  }
  result = -1073741772;
  *v5 = 0;
  return result;
}
