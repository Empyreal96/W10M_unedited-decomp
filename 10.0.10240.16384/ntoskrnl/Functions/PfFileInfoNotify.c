// PfFileInfoNotify 
 
int __fastcall PfFileInfoNotify(_DWORD *a1)
{
  int v3; // r3
  unsigned int v4; // r8
  unsigned int v5; // lr
  int v6; // r3
  unsigned int v7; // r2
  int v8; // r4
  unsigned int v9; // r10
  int v10; // r4
  int v11; // r3
  unsigned int v12; // r1
  unsigned int v13; // r1
  int v14; // r3
  unsigned int v15; // r2
  int v16; // r4
  unsigned int v17; // r1
  unsigned int v18; // r2
  int v19; // lr
  unsigned int v20; // r1
  unsigned int v21; // r0
  int v22; // r0
  unsigned int v23; // r1
  int v24; // r3
  unsigned int v25; // r1
  unsigned int v26; // r0
  int v27; // r0
  unsigned int v28; // r1
  __int16 v29; // r3
  unsigned int v30; // r2
  int v31; // r4
  unsigned int v32; // r1
  unsigned int v33; // r2
  int v34; // lr
  unsigned int v35; // r1
  int *i; // r10
  unsigned int v37; // r0
  int v38; // r0
  unsigned int v39; // r1
  __int16 v40; // r3
  unsigned int v41; // r1
  unsigned int v42; // r1
  unsigned int v43; // r0
  unsigned int v44; // r1
  int v45; // r3

  if ( *a1 != 12 )
    return sub_546F98();
  v3 = a1[2];
  if ( (v3 & 8) != 0 )
  {
    v11 = a1[1];
    switch ( v11 )
    {
      case 7:
        __dmb(0xBu);
        do
        {
          v12 = __ldrex((unsigned int *)&dword_643B68);
          v13 = v12 + 1;
        }
        while ( __strex(v13, (unsigned int *)&dword_643B68) );
        __dmb(0xBu);
        a1[4] = v13;
        return 0;
      case 10:
        v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v15 + 308);
        v16 = KeAbPreAcquire((unsigned int)&dword_637350, 0, 0);
        do
          v17 = __ldrex((unsigned __int8 *)&dword_637350);
        while ( __strex(v17 | 1, (unsigned __int8 *)&dword_637350) );
        __dmb(0xBu);
        if ( (v17 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx(&dword_637350, v16, &dword_637350);
        if ( v16 )
          *(_BYTE *)(v16 + 14) |= 1u;
        if ( dword_637348 )
        {
          v10 = -1073741791;
        }
        else
        {
          v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          --*(_WORD *)(v18 + 308);
          v19 = KeAbPreAcquire((unsigned int)&dword_637354, 0, 0);
          do
            v20 = __ldrex((unsigned __int8 *)&dword_637354);
          while ( __strex(v20 | 1, (unsigned __int8 *)&dword_637354) );
          __dmb(0xBu);
          if ( (v20 & 1) != 0 )
            ExfAcquirePushLockExclusiveEx(&dword_637354, v19, &dword_637354);
          if ( v19 )
            *(_BYTE *)(v19 + 14) |= 1u;
          dword_637360 &= 0xFFFFFFFE;
          __dmb(0xBu);
          do
            v21 = __ldrex(&dword_637354);
          while ( __strex(v21 - 1, &dword_637354) );
          if ( (v21 & 2) != 0 && (v21 & 4) == 0 )
            ExfTryToWakePushLock(&dword_637354);
          v22 = KeAbPostRelease((unsigned int)&dword_637354);
          v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v24 = (__int16)(*(_WORD *)(v23 + 0x134) + 1);
          *(_WORD *)(v23 + 308) = v24;
          if ( !v24 && *(_DWORD *)(v23 + 100) != v23 + 100 && !*(_WORD *)(v23 + 310) )
            KiCheckForKernelApcDelivery(v22);
          dword_637348 = a1[4];
          __dmb(0xBu);
          do
            v25 = __ldrex(dword_63734C);
          while ( __strex(0, dword_63734C) );
          __dmb(0xBu);
          v10 = 0;
        }
        __dmb(0xBu);
        do
          v26 = __ldrex(&dword_637350);
        while ( __strex(v26 - 1, &dword_637350) );
        if ( (v26 & 2) != 0 && (v26 & 4) == 0 )
          ExfTryToWakePushLock(&dword_637350);
        v27 = KeAbPostRelease((unsigned int)&dword_637350);
        v28 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v29 = *(_WORD *)(v28 + 0x134) + 1;
        *(_WORD *)(v28 + 308) = v29;
        if ( !v29 && *(_DWORD *)(v28 + 100) != v28 + 100 && !*(_WORD *)(v28 + 310) )
        {
LABEL_104:
          KiCheckForKernelApcDelivery(v27);
          break;
        }
        break;
      case 12:
        if ( (dword_637410 & 2) != 0 )
        {
          v10 = -1073741431;
          goto LABEL_13;
        }
        return 0;
      case 11:
        v30 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v30 + 308);
        v31 = KeAbPreAcquire((unsigned int)&dword_637350, 0, 0);
        do
          v32 = __ldrex((unsigned __int8 *)&dword_637350);
        while ( __strex(v32 | 1, (unsigned __int8 *)&dword_637350) );
        __dmb(0xBu);
        if ( (v32 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx(&dword_637350, v31, &dword_637350);
        if ( v31 )
          *(_BYTE *)(v31 + 14) |= 1u;
        if ( dword_637348 )
        {
          v33 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          --*(_WORD *)(v33 + 308);
          v34 = KeAbPreAcquire((unsigned int)&dword_637354, 0, 0);
          do
            v35 = __ldrex((unsigned __int8 *)&dword_637354);
          while ( __strex(v35 | 1, (unsigned __int8 *)&dword_637354) );
          __dmb(0xBu);
          if ( (v35 & 1) != 0 )
            ExfAcquirePushLockExclusiveEx(&dword_637354, v34, &dword_637354);
          if ( v34 )
            *(_BYTE *)(v34 + 14) |= 1u;
          dword_637360 |= 1u;
          for ( i = (int *)dword_637358; i != &dword_637358; i = (int *)*i )
          {
            i[10] |= 4u;
            KeSetEvent((int)(i + 15), 0, 0);
          }
          __dmb(0xBu);
          do
            v37 = __ldrex(&dword_637354);
          while ( __strex(v37 - 1, &dword_637354) );
          if ( (v37 & 2) != 0 && (v37 & 4) == 0 )
            ExfTryToWakePushLock(&dword_637354);
          v38 = KeAbPostRelease((unsigned int)&dword_637354);
          v39 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v40 = *(_WORD *)(v39 + 0x134) + 1;
          *(_WORD *)(v39 + 308) = v40;
          if ( !v40 && *(_DWORD *)(v39 + 100) != v39 + 100 && !*(_WORD *)(v39 + 310) )
            KiCheckForKernelApcDelivery(v38);
          do
            v41 = __ldrex(dword_63734C);
          while ( !v41 && __strex(1u, dword_63734C) );
          __dmb(0xBu);
          if ( v41 && v41 != 1 )
            ExfWaitForRundownProtectionRelease(dword_63734C, v41, dword_63734C);
          __dmb(0xBu);
          do
            v42 = __ldrex(dword_63734C);
          while ( __strex(1u, dword_63734C) );
          __dmb(0xBu);
          dword_637348 = 0;
          v10 = 0;
        }
        else
        {
          v10 = -1073741275;
        }
        __dmb(0xBu);
        do
          v43 = __ldrex(&dword_637350);
        while ( __strex(v43 - 1, &dword_637350) );
        if ( (v43 & 2) != 0 && (v43 & 4) == 0 )
          ExfTryToWakePushLock(&dword_637350);
        v27 = KeAbPostRelease((unsigned int)&dword_637350);
        v44 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v45 = (__int16)(*(_WORD *)(v44 + 0x134) + 1);
        *(_WORD *)(v44 + 308) = v45;
        if ( !v45 && *(_DWORD *)(v44 + 100) != v44 + 100 && !*(_WORD *)(v44 + 310) )
          goto LABEL_104;
        break;
      default:
        goto LABEL_94;
    }
LABEL_59:
    if ( v10 >= 0 )
      return v10;
LABEL_13:
    if ( (int)a1[1] <= 3 )
      ++dword_643B1C;
    return v10;
  }
  if ( (v3 & 4) != 0 )
  {
    v14 = a1[1];
    if ( v14 == 2 )
    {
      PfSnLogStreamCreate(a1[4]);
    }
    else if ( v14 )
    {
      if ( v14 == 3 )
        PfSnNameRemoveAll(a1[4]);
    }
    else
    {
      PfSnLogVolumeCreate(a1[4]);
    }
  }
  if ( (a1[2] & 1) != 0 )
  {
    v4 = dword_643A78;
    v5 = dword_643A74;
    if ( dword_643A74 >= (unsigned int)dword_643A78 )
    {
      v6 = a1[1];
      if ( v6 != 4 && v6 != 2 && v6 != 3 )
      {
        v10 = -1073741697;
        goto LABEL_13;
      }
    }
    v7 = a1[1];
    if ( v7 == 4 )
    {
      v8 = a1[4];
      v9 = ((unsigned int)(*(_QWORD *)(v8 + 8) & 0xFFF) + *(_DWORD *)(v8 + 16) + 4095) >> 12;
      if ( PfSnNumActiveTraces )
      {
        PfSnLogFileDataAccess(*(_DWORD *)v8, *(_DWORD *)(v8 + 24), *(_DWORD *)(v8 + 28));
        v4 = dword_643A78;
        v5 = dword_643A74;
      }
      if ( v5 >= v4 )
      {
        v10 = -1073741697;
        goto LABEL_13;
      }
      v10 = PfLogFileDataAccess(
              *(_DWORD *)(a1[4] + 24),
              *(_DWORD *)(a1[4] + 28),
              *(_DWORD *)(a1[4] + 8),
              *(_DWORD *)(a1[4] + 12),
              v9,
              *(_DWORD *)(a1[4] + 20));
      goto LABEL_59;
    }
    if ( v7 <= 0xD )
      __asm { ADD             PC, R3 }
LABEL_94:
    v10 = -1073741637;
    goto LABEL_13;
  }
  return 0;
}
