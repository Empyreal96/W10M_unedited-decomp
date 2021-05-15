// ExpWnfDeliverThreadNotifications 
 
int __fastcall ExpWnfDeliverThreadNotifications(int a1, _BYTE *a2, int a3, int a4)
{
  _DWORD *v4; // r8
  unsigned int *v5; // r6
  int v6; // r0
  int v7; // r4
  unsigned int v8; // r2
  unsigned __int8 *v9; // r6
  int v10; // r0
  int v11; // r4
  unsigned int v12; // r2
  _DWORD *i; // r9
  _DWORD *v14; // r6
  int v15; // r5
  unsigned int *v16; // r0
  unsigned int v17; // r4
  unsigned int v18; // r1
  int v19; // r8
  _DWORD *v20; // r4
  int v21; // r2
  int v22; // r2
  _DWORD *v23; // lr
  _DWORD *v24; // r4
  int v25; // r1
  int v26; // r2
  int v27; // r3
  int v28; // lr
  int v29; // r3
  unsigned int *v30; // r0
  unsigned int v31; // r4
  unsigned int v32; // r1
  int v33; // r6
  int v34; // r0
  _DWORD *v35; // r1
  int v36; // r3
  unsigned int *v37; // r2
  unsigned int v38; // r1
  unsigned int v39; // r1
  unsigned int *v40; // r4
  unsigned int v41; // r1
  unsigned int *v42; // r4
  unsigned int v43; // r2
  unsigned int *v44; // r0
  unsigned int v45; // r4
  unsigned int v46; // r1
  unsigned int *v47; // r0
  unsigned int v48; // r4
  unsigned int v49; // r1
  unsigned int *v50; // r4
  unsigned int v51; // r1
  unsigned int *v52; // r4
  unsigned int v53; // r2
  int v56; // [sp+Ch] [bp-6Ch]
  int v57; // [sp+10h] [bp-68h]
  int v58; // [sp+14h] [bp-64h] BYREF
  int v59; // [sp+18h] [bp-60h]
  _BYTE *v60; // [sp+1Ch] [bp-5Ch]
  _BYTE *v61; // [sp+20h] [bp-58h]
  int v62; // [sp+24h] [bp-54h]
  _DWORD *v63; // [sp+28h] [bp-50h]
  int v64; // [sp+2Ch] [bp-4Ch]
  _DWORD *v65; // [sp+30h] [bp-48h]
  int v66; // [sp+34h] [bp-44h]
  int v67; // [sp+38h] [bp-40h]
  int v68; // [sp+3Ch] [bp-3Ch]
  _DWORD v69[4]; // [sp+40h] [bp-38h] BYREF
  int v70; // [sp+50h] [bp-28h]
  int v71; // [sp+54h] [bp-24h]
  int varg_r0; // [sp+80h] [bp+8h]
  _BYTE *varg_r1; // [sp+84h] [bp+Ch]
  int varg_r2; // [sp+88h] [bp+10h]
  int varg_r3; // [sp+8Ch] [bp+14h]

  varg_r2 = a3;
  varg_r3 = a4;
  v60 = a2;
  varg_r1 = a2;
  v4 = (_DWORD *)a1;
  varg_r0 = a1;
  v64 = -2147483622;
  v57 = -2147483622;
  v59 = 0;
  v62 = 0;
  v56 = 0;
  v58 = 0;
  v68 = a3 - 48;
  v69[1] = a3 - 48;
  v61 = a2 + 48;
  v69[2] = a2 + 48;
LABEL_2:
  v5 = v4 + 10;
  v6 = KeAbPreAcquire((unsigned int)(v4 + 10), 0, 0);
  v7 = v6;
  do
    v8 = __ldrex(v5);
  while ( !v8 && __strex(0x11u, v5) );
  __dmb(0xBu);
  if ( v8 )
    ExfAcquirePushLockSharedEx(v4 + 10, v6, (unsigned int)(v4 + 10));
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  v9 = (unsigned __int8 *)(v4 + 13);
  v10 = KeAbPreAcquire((unsigned int)(v4 + 13), 0, 0);
  v11 = v10;
  do
    v12 = __ldrex(v9);
  while ( __strex(v12 | 1, v9) );
  __dmb(0xBu);
  if ( (v12 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v4 + 13, v10, (unsigned int)(v4 + 13));
  if ( v11 )
    *(_BYTE *)(v11 + 14) |= 1u;
  for ( i = (_DWORD *)v4[14]; ; i = (_DWORD *)*i )
  {
    v63 = i;
    if ( i == v4 + 14 )
      break;
    v14 = i - 16;
    v65 = i - 16;
    if ( i[2] != 1 )
      continue;
    v15 = *(i - 9);
    v66 = v15;
    if ( v15 )
    {
      v16 = (unsigned int *)(v15 + 4);
      __pld((void *)(v15 + 4));
      v17 = *(_DWORD *)(v15 + 4) & 0xFFFFFFFE;
      do
        v18 = __ldrex(v16);
      while ( v18 == v17 && __strex(v17 + 2, v16) );
      __dmb(0xBu);
      if ( v18 != v17 && !ExfAcquireRundownProtection(v16) )
      {
        v15 = 0;
        v66 = 0;
      }
    }
    v19 = i[3] & *(i - 1);
    v67 = v19;
    if ( !v15 )
    {
      v19 &= 0xFFFFFFFE;
      v67 = v19;
    }
    if ( !v19 )
      goto LABEL_50;
    v20 = v60;
    memset(v60, 0, 48);
    v70 = *(i - 8);
    v21 = *(i - 7);
    v70 ^= 0xA3BC0074;
    v71 = v21 ^ 0x41C64E6D;
    v20[2] = v70;
    v20[3] = v21 ^ 0x41C64E6D;
    v22 = *(i - 13);
    *v20 = *(i - 14);
    v20[1] = v22;
    if ( (v19 & 1) == 0 )
    {
      v28 = v59;
      goto LABEL_35;
    }
    v23 = *(_DWORD **)(v15 + 40);
    if ( v23 )
    {
      v24 = v20 + 7;
      v25 = v23[1];
      v26 = v23[2];
      v27 = v23[3];
      *v24 = *v23;
      v24[1] = v25;
      v24[2] = v26;
      v24[3] = v27;
      v20 = v60;
    }
    v28 = ExpWnfReadStateData(v15, &v58, v61, v68, v69);
    v59 = v28;
    v62 = v28;
    if ( v28 >= 0 )
    {
      v56 = v58;
      v20[4] = v58;
      v20[5] = v69[0];
LABEL_35:
      v20[11] = v61 - (_BYTE *)v20;
      v20[6] = v19;
      v29 = v56;
      goto LABEL_36;
    }
    v29 = v58;
    v56 = v58;
LABEL_36:
    if ( v15 )
    {
      v30 = (unsigned int *)(v15 + 4);
      __pld((void *)(v15 + 4));
      v31 = *(_DWORD *)(v15 + 4) & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v32 = __ldrex(v30);
      while ( v32 == v31 && __strex(v31 - 2, v30) );
      if ( v32 != v31 )
      {
        ExfReleaseRundownProtection((unsigned __int8 *)v30);
        v28 = v59;
      }
      v15 = 0;
      v29 = v56;
    }
    if ( v28 < 0 )
    {
      v4 = (_DWORD *)a1;
      if ( v57 == v64 )
        v57 = v28;
      continue;
    }
    if ( !v29 )
      v19 &= 0xFFFFFFFE;
    if ( v19 )
    {
      i[4] = v19;
      i[3] = 0;
      i[2] = 2;
      v33 = 0;
      v4 = (_DWORD *)a1;
      goto LABEL_83;
    }
LABEL_50:
    i = (_DWORD *)i[1];
    v34 = v14[16];
    v35 = (_DWORD *)v14[17];
    if ( *(_DWORD **)(v34 + 4) != v14 + 16 || (_DWORD *)*v35 != v14 + 16 )
      __fastfail(3u);
    *v35 = v34;
    *(_DWORD *)(v34 + 4) = v35;
    v14[18] = 0;
    v36 = v14[19];
    v14[19] = 0;
    v14[20] = 0;
    if ( v15 )
    {
      if ( (v36 & 1) != 0 )
      {
        __dmb(0xBu);
        v37 = (unsigned int *)(v15 + 92);
        do
        {
          v38 = __ldrex(v37);
          v39 = v38 - 1;
        }
        while ( __strex(v39, v37) );
        __dmb(0xBu);
        if ( !v39 )
        {
          v4 = (_DWORD *)a1;
          v40 = (unsigned int *)(a1 + 52);
          __dmb(0xBu);
          do
            v41 = __ldrex(v40);
          while ( __strex(v41 - 1, v40) );
          if ( (v41 & 2) != 0 && (v41 & 4) == 0 )
            ExfTryToWakePushLock(v40);
          KeAbPostRelease((unsigned int)v40);
          v42 = (unsigned int *)(a1 + 40);
          __dmb(0xBu);
          do
            v43 = __ldrex(v42);
          while ( v43 == 17 && __strex(0, v42) );
          if ( v43 != 17 )
            ExfReleasePushLockShared((_DWORD *)(a1 + 40));
          KeAbPostRelease(a1 + 40);
          ExpWnfNotifyNameSubscribers(v15, 8, 1, 1);
          v44 = (unsigned int *)(v15 + 4);
          __pld((void *)(v15 + 4));
          v45 = *(_DWORD *)(v15 + 4) & 0xFFFFFFFE;
          __dmb(0xBu);
          do
            v46 = __ldrex(v44);
          while ( v46 == v45 && __strex(v45 - 2, v44) );
          if ( v46 != v45 )
            ExfReleaseRundownProtection((unsigned __int8 *)v44);
          goto LABEL_2;
        }
      }
      v47 = (unsigned int *)(v15 + 4);
      __pld((void *)(v15 + 4));
      v48 = *(_DWORD *)(v15 + 4) & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v49 = __ldrex(v47);
      while ( v49 == v48 && __strex(v48 - 2, v47) );
      if ( v49 != v48 )
        ExfReleaseRundownProtection((unsigned __int8 *)v47);
    }
    v4 = (_DWORD *)a1;
  }
  v33 = v57;
LABEL_83:
  v50 = v4 + 13;
  __dmb(0xBu);
  do
    v51 = __ldrex(v50);
  while ( __strex(v51 - 1, v50) );
  if ( (v51 & 2) != 0 && (v51 & 4) == 0 )
    ExfTryToWakePushLock(v4 + 13);
  KeAbPostRelease((unsigned int)(v4 + 13));
  v52 = v4 + 10;
  __dmb(0xBu);
  do
    v53 = __ldrex(v52);
  while ( v53 == 17 && __strex(0, v52) );
  if ( v53 != 17 )
    ExfReleasePushLockShared(v4 + 10);
  KeAbPostRelease((unsigned int)(v4 + 10));
  return v33;
}
