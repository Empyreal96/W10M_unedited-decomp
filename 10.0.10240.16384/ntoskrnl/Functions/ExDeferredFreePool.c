// ExDeferredFreePool 
 
int __fastcall ExDeferredFreePool(int result, int a2)
{
  unsigned int *v2; // r7
  unsigned int *v3; // r9
  unsigned int v4; // r2
  unsigned int v5; // r2
  unsigned int v6; // r2
  int v7; // r10
  int v8; // r4
  _DWORD *v9; // r8
  unsigned int v10; // r6
  int v11; // r4
  int v12; // r5
  unsigned int v13; // r2
  _DWORD *v14; // r2
  unsigned int v15; // r2
  int v16; // r4
  unsigned int v17; // r1
  _DWORD *v18; // lr
  int v19; // r5
  int v20; // r10
  unsigned int *v21; // r2
  unsigned int v22; // r1
  unsigned int *v23; // r2
  int v24; // r0
  unsigned int v25; // r4
  int v26; // r4
  __int64 v27; // r0
  int v28; // r1
  __int64 v29; // kr00_8
  __int16 v30; // r3
  int v31; // r5
  __int16 v32; // r1
  __int16 v33; // r3
  int v34; // r1
  __int64 v35; // r0
  int v36; // r2
  unsigned int *v37; // r1
  unsigned int v38; // r2
  int v39; // r4
  unsigned int v40; // r1
  int v41; // r4
  unsigned int *v42; // r2
  unsigned int v43; // r5
  _DWORD *v44; // r4
  unsigned int *v45; // r2
  unsigned int v46; // r4
  int v47; // [sp+8h] [bp-40h]
  int v48; // [sp+Ch] [bp-3Ch]
  _DWORD *v49; // [sp+10h] [bp-38h]
  int v50; // [sp+14h] [bp-34h]
  int v51; // [sp+18h] [bp-30h]
  _DWORD *v52; // [sp+1Ch] [bp-2Ch]
  char v53[40]; // [sp+20h] [bp-28h] BYREF

  v2 = (unsigned int *)result;
  v3 = (unsigned int *)(result + 140);
  do
  {
    v4 = __ldrex(v3);
    v5 = v4 + 1;
  }
  while ( __strex(v5, v3) );
  if ( v5 == 1 || a2 )
  {
    v47 = 0;
    v7 = 0;
    v8 = *(_DWORD *)result & 1;
    v49 = 0;
    v50 = v8;
    v9 = 0;
    if ( v8 )
    {
      v10 = result + 4;
      v11 = KeAbPreAcquire(result + 4, 0, 0);
      v12 = KfRaiseIrql(1);
      do
        v13 = __ldrex((unsigned __int8 *)v10);
      while ( __strex(v13 & 0xFE, (unsigned __int8 *)v10) );
      __dmb(0xBu);
      if ( (v13 & 1) == 0 )
        ExpAcquireFastMutexContended((int)(v2 + 1), v11);
      if ( v11 )
        *(_BYTE *)(v11 + 14) |= 1u;
      v2[2] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v2[8] = v12;
      PsBoostThreadIoEx(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 0, 0);
      v8 = v50;
    }
    else
    {
      v10 = result + 4;
      KeAcquireInStackQueuedSpinLock((unsigned int *)(result + 4), (unsigned int)v53);
    }
    v14 = (_DWORD *)v2[128];
    if ( v14 )
    {
      while ( 1 )
      {
        v18 = v14;
        while ( 1 )
        {
          v52 = (_DWORD *)*v14;
          v19 = (int)(v14 - 3);
          v48 = v7 + 1;
          if ( *(v14 - 1) != (ExpPoolQuotaCookie ^ (unsigned int)(v14 - 3)) )
            KeBugCheckEx(25, 13, v19, *(v14 - 1), ExpPoolQuotaCookie ^ v19);
          v20 = 0;
          v21 = v2 + 33;
          v51 = *(unsigned __int16 *)v19 >> 9;
          do
            v22 = __ldrex(v21);
          while ( __strex(v22 + 1, v21) );
          v23 = v2 + 36;
          v24 = -8 * (*(_WORD *)(v19 + 2) & 0x1FF);
          do
            v25 = __ldrex(v23);
          while ( __strex(v25 + v24, v23) );
          v26 = v19 + 8 * (*(_WORD *)(v19 + 2) & 0x1FF);
          if ( (((_WORD)v19 + 8 * (*(_WORD *)(v19 + 2) & 0x1FF)) & 0xFFF) != 0 && (*(_WORD *)(v26 + 2) & 0xFE00) == 0 )
          {
            v20 = 1;
            if ( (*(_WORD *)(v26 + 2) & 0x1FF) != 1 )
            {
              v27 = *(_QWORD *)(v26 + 8);
              if ( *(_DWORD *)(v27 + 4) != v26 + 8 || *(_DWORD *)HIDWORD(v27) != v26 + 8 )
                __fastfail(3u);
              *(_DWORD *)HIDWORD(v27) = v27;
              *(_DWORD *)(v27 + 4) = HIDWORD(v27);
            }
            *(_WORD *)(v19 + 2) = *(_WORD *)(v19 + 2) & 0xFE00 | (*(_WORD *)(v26 + 2) + *(_WORD *)(v19 + 2)) & 0x1FF;
          }
          if ( (*(_WORD *)v19 & 0x1FF) != 0 )
          {
            v28 = v19 - 8 * (*(_WORD *)v19 & 0x1FF);
            if ( (*(_WORD *)(v28 + 2) & 0xFE00) == 0 )
            {
              v20 = 1;
              if ( (*(_WORD *)(v28 + 2) & 0x1FF) != 1 )
              {
                v29 = *(_QWORD *)(v28 + 8);
                if ( *(_DWORD *)(v29 + 4) != v28 + 8 || *(_DWORD *)HIDWORD(v29) != v28 + 8 )
                  __fastfail(3u);
                *(_DWORD *)HIDWORD(v29) = v29;
                *(_DWORD *)(v29 + 4) = HIDWORD(v29);
              }
              v30 = *(_WORD *)(v19 + 2);
              v19 = v28;
              *(_WORD *)(v28 + 2) = *(_WORD *)(v28 + 2) & 0xFE00 | (v30 + *(_WORD *)(v28 + 2)) & 0x1FF;
            }
          }
          if ( (v19 & 0xFFF) != 0 || (((_WORD)v19 + 8 * (*(_WORD *)(v19 + 2) & 0x1FF)) & 0xFFF) != 0 )
          {
            v32 = *(_WORD *)(v19 + 2) & 0x1FF;
            v33 = *(_WORD *)v19;
            *(_WORD *)(v19 + 2) = v32;
            v34 = v32 & 0x1FF;
            *(_WORD *)v19 = v33 & 0x1FF | ((_WORD)v51 << 9);
            if ( v20 && (((_WORD)v19 + 8 * (_WORD)v34) & 0xFFF) != 0 )
              *(_WORD *)(v19 + 8 * v34) ^= (*(_WORD *)(v19 + 8 * v34) ^ v34) & 0x1FF;
            HIDWORD(v35) = &v2[2 * v34 + 158];
            LODWORD(v35) = *(_DWORD *)HIDWORD(v35);
            v36 = v19 + 8;
            *(_QWORD *)(v19 + 8) = v35;
            if ( *(_DWORD *)(v35 + 4) != HIDWORD(v35) )
              __fastfail(3u);
            v31 = v47;
            *(_DWORD *)(v35 + 4) = v36;
            *(_DWORD *)HIDWORD(v35) = v36;
          }
          else
          {
            *(_DWORD *)v19 = v9;
            v9 = (_DWORD *)v19;
            v31 = ++v47;
          }
          if ( v52 == v49 )
            break;
          v7 = v48;
          v14 = v52;
        }
        v37 = v2 + 128;
        do
          v14 = (_DWORD *)__ldrex(v37);
        while ( v14 == v18 && __strex(0, v37) );
        if ( v14 == v18 )
          break;
        v7 = v48;
        v49 = v18;
      }
      do
        v38 = __ldrex(v3);
      while ( __strex(v38 - 1, v3) );
      if ( v50 )
      {
        PsBoostThreadIoEx(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 1, 0);
        v39 = *(_DWORD *)(v10 + 28);
        *(_DWORD *)(v10 + 4) = 0;
        __dmb(0xBu);
        do
          v40 = __ldrex((unsigned int *)v10);
        while ( !v40 && __strex(1u, (unsigned int *)v10) );
        if ( v40 )
          ExpReleaseFastMutexContended((unsigned int *)v10, v40);
        KfLowerIrql((unsigned __int8)v39);
        KeAbPostRelease(v10);
      }
      else
      {
        KeReleaseInStackQueuedSpinLock((int)v53);
      }
      if ( v9 )
      {
        v41 = -v31;
        v42 = v2 + 96;
        do
          v43 = __ldrex(v42);
        while ( __strex(v43 + v41, v42) );
        do
        {
          v44 = (_DWORD *)*v9;
          MiFreePoolPages((unsigned int)v9, 0x1000u);
          v9 = v44;
        }
        while ( v44 );
      }
      v45 = v2 + 129;
      result = -v48;
      do
        v46 = __ldrex(v45);
      while ( __strex(v46 - v48, v45) );
    }
    else
    {
      do
        v15 = __ldrex(v3);
      while ( __strex(v15 - 1, v3) );
      if ( v8 )
      {
        PsBoostThreadIoEx(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 1, 0);
        v16 = *(_DWORD *)(v10 + 28);
        *(_DWORD *)(v10 + 4) = 0;
        __dmb(0xBu);
        do
          v17 = __ldrex((unsigned int *)v10);
        while ( !v17 && __strex(1u, (unsigned int *)v10) );
        if ( v17 )
          ExpReleaseFastMutexContended((unsigned int *)v10, v17);
        KfLowerIrql((unsigned __int8)v16);
        result = KeAbPostRelease(v10);
      }
      else
      {
        result = KeReleaseInStackQueuedSpinLock((int)v53);
      }
    }
  }
  else
  {
    do
      v6 = __ldrex(v3);
    while ( __strex(v6 - 1, v3) );
  }
  return result;
}
