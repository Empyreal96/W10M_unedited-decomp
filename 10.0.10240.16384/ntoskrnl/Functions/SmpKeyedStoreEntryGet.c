// SmpKeyedStoreEntryGet 
 
int __fastcall SmpKeyedStoreEntryGet(int a1, int a2, int a3, int a4)
{
  int v4; // r8
  int *v5; // r10
  unsigned int v7; // r2
  int v8; // r0
  int v9; // r4
  unsigned int v10; // r2
  int v11; // r4
  int v12; // r7
  unsigned int v13; // r2
  int v14; // r0
  int v15; // r1
  int v16; // r5
  unsigned int v17; // r2
  int v18; // r0
  unsigned int v19; // r1
  __int16 v20; // r3
  unsigned int v22; // r5
  int v23; // r0
  unsigned int v24; // r5
  unsigned int v25; // r1
  unsigned int v26; // r3
  _DWORD *i; // r2
  int v28; // r0
  unsigned int v29; // r3
  unsigned int v30; // r5
  unsigned int v31; // r0
  char v32; // r3
  unsigned int v33; // r1
  int *v34; // lr
  unsigned int v35; // r3
  int v36; // r2
  unsigned int v37; // r1
  int v38; // r9
  int v39; // r7
  _DWORD *v40; // lr
  int v41; // r2
  int v42; // r2
  char v43; // r3
  unsigned int v44; // r3
  int v45; // r1
  int v46; // r2
  unsigned int v47; // [sp+0h] [bp-38h] BYREF
  int v48; // [sp+4h] [bp-34h]
  int v49; // [sp+8h] [bp-30h]
  int *v50; // [sp+Ch] [bp-2Ch]
  int v51; // [sp+10h] [bp-28h]
  int v52; // [sp+14h] [bp-24h]

  v52 = a4;
  v4 = a3;
  v49 = a3;
  v50 = (int *)a2;
  v5 = (int *)a2;
  if ( !a4 )
  {
    if ( a3 > 0 )
    {
      v22 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v22 + 308);
      v23 = KeAbPreAcquire(a1, 0, 0);
      do
        v24 = __ldrex((unsigned __int8 *)a1);
      while ( __strex(v24 | 1, (unsigned __int8 *)a1) );
      __dmb(0xBu);
      if ( (v24 & 1) != 0 )
        return sub_515D58(v23);
      if ( v23 )
        *(_BYTE *)(v23 + 14) |= 1u;
    }
    else
    {
      v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v7 + 308);
      v8 = KeAbPreAcquire(a1, 0, 0);
      v9 = v8;
      do
        v10 = __ldrex((unsigned int *)a1);
      while ( !v10 && __strex(0x11u, (unsigned int *)a1) );
      __dmb(0xBu);
      if ( v10 )
        ExfAcquirePushLockSharedEx(a1, v8, a1);
      if ( v9 )
        *(_BYTE *)(v9 + 14) |= 1u;
    }
  }
  if ( v4 )
    goto LABEL_13;
  v11 = *(_DWORD *)(a1 + 16);
  if ( v11 && *(_DWORD *)(v11 + 4) == *v5 )
    goto LABEL_17;
  if ( *v5 != *(_DWORD *)(a1 + 20) )
  {
LABEL_13:
    v12 = a1 + 4;
    v13 = *(_DWORD *)(a1 + 8);
    v14 = -1 << (v13 & 0x1F);
    v15 = *v5;
    v16 = *v5 & v14;
    v47 = v16;
    if ( v13 >> 5 )
    {
      v11 = *(_DWORD *)(a1 + 12)
          + 4
          * ((37 * (37 * (37 * ((unsigned __int8)v47 + 11623883) + BYTE1(v47)) + BYTE2(v47)) + HIBYTE(v47)) & ((v13 >> 5) - 1));
      while ( 1 )
      {
        v11 = *(_DWORD *)v11;
        if ( (v11 & 1) != 0 )
          break;
        if ( v16 == (*(_DWORD *)(v11 + 4) & v14) )
          goto LABEL_44;
      }
      v11 = 0;
LABEL_44:
      if ( v11 )
      {
        if ( v4 == 2 )
        {
          v26 = *(_DWORD *)(a1 + 8);
          v47 = *(_DWORD *)(v11 + 4) & (-1 << (v26 & 0x1F));
          for ( i = (_DWORD *)(*(_DWORD *)(a1 + 12)
                             + 4
                             * ((37 * (37 * (37 * ((unsigned __int8)v47 + 11623883) + BYTE1(v47)) + BYTE2(v47))
                               + HIBYTE(v47)) & ((v26 >> 5) - 1))); (*i & 1) == 0; i = (_DWORD *)*i )
          {
            if ( *i == v11 )
            {
              *i = *(_DWORD *)v11;
              --*(_DWORD *)v12;
              *(_DWORD *)v11 |= 0x80000002;
              break;
            }
          }
          if ( *(_DWORD *)(a1 + 16) == v11 )
            *(_DWORD *)(a1 + 16) = 0;
        }
        else
        {
          *(_DWORD *)(a1 + 16) = v11;
        }
        goto LABEL_17;
      }
    }
    if ( v4 == 1 )
    {
      v11 = (int)(v5 - 1);
      v28 = *(_DWORD *)(a1 + 8) >> 5;
      v29 = *(_DWORD *)v12;
      v51 = 1414032755;
      if ( v29 >= 2 * v28 && RtlULongLongToULong(2 * v28, 0, &v47) >= 0 )
      {
        v30 = v47;
        if ( v47 < 4 )
          v30 = 4;
        v31 = ExAllocatePoolWithTag(512, 4 * v30, 1414032755);
        if ( v31 )
        {
          if ( ((v30 - 1) & v30) != 0 )
          {
            v32 = -1;
            while ( v30 )
            {
              v30 >>= 1;
              ++v32;
            }
            v30 = 1 << v32;
          }
          if ( v30 > 0x4000000 )
            v30 = 0x4000000;
          v33 = 0;
          v34 = (int *)v31;
          if ( v31 > v31 + 4 * v30 )
            v35 = 0;
          else
            v35 = (4 * v30 + 3) >> 2;
          if ( v35 )
          {
            do
            {
              ++v33;
              *v34++ = v12 | 1;
            }
            while ( v33 < v35 );
          }
          v36 = *(_DWORD *)(a1 + 8);
          v48 = -1 << (v36 & 0x1F);
          v37 = 0;
          if ( (v36 & 0xFFFFFFE0) != 0 )
          {
            do
            {
              v38 = *(_DWORD *)(v12 + 8);
              v39 = v48;
              while ( 1 )
              {
                v40 = *(_DWORD **)(v38 + 4 * v37);
                if ( ((unsigned __int8)v40 & 1) != 0 )
                  break;
                *(_DWORD *)(v38 + 4 * v37) = *v40;
                v47 = v40[1] & v39;
                v41 = (37 * (37 * (37 * ((unsigned __int8)v47 + 11623883) + BYTE1(v47)) + BYTE2(v47)) + HIBYTE(v47)) & (v30 - 1);
                *v40 = *(_DWORD *)(v31 + 4 * v41);
                *(_DWORD *)(v31 + 4 * v41) = v40;
              }
              v12 = a1 + 4;
              ++v37;
            }
            while ( v37 < *(_DWORD *)(a1 + 8) >> 5 );
            v4 = v49;
            v5 = v50;
          }
          v43 = *(_QWORD *)(v12 + 4);
          v42 = *(_DWORD *)(v12 + 8);
          *(_DWORD *)(v12 + 8) = v31;
          *(_DWORD *)(v12 + 4) = v43 & 0x1F | (32 * v30);
          if ( v42 )
            ST_STORE<SM_TRAITS>::StDmSparseBitmapFree(v42);
        }
        else if ( (*(_DWORD *)(a1 + 8) & 0xFFFFFFE0) == 0 )
        {
          goto LABEL_16;
        }
      }
      v44 = *(_DWORD *)(v12 + 4);
      v47 = *(_DWORD *)(v11 + 4) & (-1 << (v44 & 0x1F));
      v45 = ((v44 >> 5) - 1) & (37 * (37 * (37 * ((unsigned __int8)v47 + 11623883) + BYTE1(v47)) + BYTE2(v47))
                              + HIBYTE(v47));
      v46 = *(_DWORD *)(v12 + 8);
      *(_DWORD *)v11 = *(_DWORD *)(v46 + 4 * v45);
      *(_DWORD *)(v46 + 4 * v45) = v11;
      ++*(_DWORD *)v12;
      if ( *(_DWORD *)(a1 + 20) == *v5 )
        *(_DWORD *)(a1 + 20) = 0;
      goto LABEL_17;
    }
    *(_DWORD *)(a1 + 20) = v15;
  }
LABEL_16:
  v11 = 0;
LABEL_17:
  if ( !v52 )
  {
    __dmb(0xBu);
    if ( v4 > 0 )
    {
      do
        v25 = __ldrex((unsigned int *)a1);
      while ( __strex(v25 - 1, (unsigned int *)a1) );
      if ( (v25 & 2) != 0 && (v25 & 4) == 0 )
        ExfTryToWakePushLock(a1);
    }
    else
    {
      do
        v17 = __ldrex((unsigned int *)a1);
      while ( v17 == 17 && __strex(0, (unsigned int *)a1) );
      if ( v17 != 17 )
        ExfReleasePushLockShared(a1, 0);
    }
    v18 = KeAbPostRelease(a1);
    v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v20 = *(_WORD *)(v19 + 0x134) + 1;
    *(_WORD *)(v19 + 308) = v20;
    if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 && !*(_WORD *)(v19 + 310) )
      KiCheckForKernelApcDelivery(v18);
  }
  return v11;
}
