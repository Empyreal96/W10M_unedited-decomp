// KeSetEvent 
 
int __fastcall KeSetEvent(int a1, int a2, int a3)
{
  int v6; // r10
  unsigned int v7; // r6
  unsigned int v8; // r2
  int v9; // r5
  unsigned __int8 *v10; // r3
  unsigned int v11; // r1
  int v13; // r1
  __int64 v14; // kr00_8
  int v15; // r3
  int v16; // r3
  int v17; // r2
  _DWORD *v18; // r3
  int v19; // r1
  int v20; // r3
  int v21; // r2
  int v22; // r0
  int v23; // lr
  int v24; // r0
  int v25; // r1
  unsigned int v26; // r2
  unsigned int v27; // r1
  int v28; // r3
  int v29; // r0
  int v30; // lr
  int v31; // r0
  int v32; // r1
  unsigned int v33; // r2
  unsigned int v34; // r1
  int v35; // r1
  unsigned __int8 **v36; // r0
  int v37; // r1
  int **v38; // r0
  unsigned int v39; // r2
  unsigned int v40; // r2
  unsigned int v41; // r2
  BOOL v42; // r2
  unsigned __int8 *v43; // [sp+8h] [bp-30h]
  int v44; // [sp+8h] [bp-30h]
  int v45; // [sp+Ch] [bp-2Ch]
  int *v46; // [sp+Ch] [bp-2Ch]
  int v47; // [sp+Ch] [bp-2Ch]
  int v48; // [sp+10h] [bp-28h]
  unsigned __int8 *v49; // [sp+18h] [bp-20h]
  int v50; // [sp+18h] [bp-20h]

  if ( (*(_BYTE *)a1 & 0x7F) != 0 )
  {
    v45 = 0;
  }
  else
  {
    if ( *(_DWORD *)(a1 + 4) == 1 && !a3 )
      return 1;
    v45 = 1;
  }
  v6 = KfRaiseIrql(2);
  v7 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  do
    v8 = __ldrex((unsigned __int8 *)a1);
  while ( __strex(v8 | 0x80, (unsigned __int8 *)a1) );
  __dmb(0xBu);
  if ( v8 >> 7 )
  {
    do
    {
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( (*(_DWORD *)a1 & 0x80) != 0 );
      do
        v39 = __ldrex((unsigned __int8 *)a1);
      while ( __strex(v39 | 0x80, (unsigned __int8 *)a1) );
      __dmb(0xBu);
    }
    while ( v39 >> 7 );
  }
  v9 = *(_DWORD *)(a1 + 4);
  *(_DWORD *)(a1 + 4) = 1;
  if ( !v9 )
  {
    if ( !v45 )
    {
      v10 = *(unsigned __int8 **)(a1 + 8);
      if ( v10 == (unsigned __int8 *)(a1 + 8) )
        goto LABEL_9;
      while ( 1 )
      {
        v13 = (int)v10;
        v14 = *(_QWORD *)v10;
        v49 = *(unsigned __int8 **)v10;
        v43 = v10;
        if ( *(unsigned __int8 **)(*(_DWORD *)v10 + 4) != v10 || *(unsigned __int8 **)HIDWORD(v14) != v10 )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v14) = v14;
        *(_DWORD *)(v14 + 4) = HIDWORD(v14);
        v15 = v10[8];
        if ( v15 == 1 )
        {
          if ( KiTryUnwaitThread(v7 + 1408, v13, *(unsigned __int16 *)(v13 + 10), 0) )
          {
            v16 = *(_DWORD *)(a1 + 4) - 1;
            *(_DWORD *)(a1 + 4) = v16;
            if ( !v16 )
              goto LABEL_9;
          }
          goto LABEL_68;
        }
        if ( v15 != 2 )
        {
          KiTryUnwaitThread(v7 + 1408, v13, 256, 0);
          goto LABEL_68;
        }
        *(_BYTE *)(v13 + 9) = 5;
        v22 = *(_DWORD *)(v13 + 12);
        *(_DWORD *)v13 = 0;
        v47 = v22;
        KfRaiseIrql(2);
        v23 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
        v24 = *(_DWORD *)(v23 + 4);
        if ( (dword_682604 & 0x1000000) != 0 )
          return sub_50C864();
        v25 = v47;
        do
          v26 = __ldrex((unsigned __int8 *)v47);
        while ( __strex(v26 | 0x80, (unsigned __int8 *)v47) );
        __dmb(0xBu);
        if ( v26 >> 7 )
        {
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
            }
            while ( (*(_DWORD *)v47 & 0x80) != 0 );
            do
              v40 = __ldrex((unsigned __int8 *)v47);
            while ( __strex(v40 | 0x80, (unsigned __int8 *)v47) );
            __dmb(0xBu);
          }
          while ( v40 >> 7 );
        }
        if ( *(_DWORD *)(v47 + 12) != v47 + 8
          && *(_DWORD *)(v47 + 24) < *(_DWORD *)(v47 + 28)
          && (*(_DWORD *)(v24 + 152) != v47 || *(_BYTE *)(v24 + 395) != 15) )
        {
          if ( KiWakeQueueWaiter(v23, v47, (int)v43) )
            goto LABEL_37;
          v25 = v47;
        }
        ++*(_DWORD *)(v25 + 4);
        v35 = v25 + 16;
        v36 = *(unsigned __int8 ***)(v35 + 4);
        *(_DWORD *)v43 = v35;
        *((_DWORD *)v43 + 1) = v36;
        if ( *v36 != (unsigned __int8 *)v35 )
          __fastfail(3u);
        *v36 = v43;
        *(_DWORD *)(v35 + 4) = v43;
LABEL_37:
        __dmb(0xBu);
        do
          v27 = __ldrex((unsigned int *)v47);
        while ( __strex(v27 & 0xFFFFFF7F, (unsigned int *)v47) );
        v28 = *(_DWORD *)(a1 + 4) - 1;
        *(_DWORD *)(a1 + 4) = v28;
        if ( !v28 )
          goto LABEL_9;
LABEL_68:
        v10 = v49;
        if ( v49 == (unsigned __int8 *)(a1 + 8) )
          goto LABEL_9;
      }
    }
    v17 = *(_DWORD *)(a1 + 8);
    v18 = (_DWORD *)(a1 + 8);
    if ( v17 == a1 + 8 )
    {
LABEL_21:
      *v18 = v18;
      v18[1] = v18;
      goto LABEL_9;
    }
    while ( 1 )
    {
      v19 = v17;
      v20 = *(unsigned __int8 *)(v17 + 8);
      v46 = (int *)v17;
      v48 = *(_DWORD *)v17;
      if ( v20 == 1 )
      {
        v21 = *(unsigned __int16 *)(v17 + 10);
      }
      else
      {
        if ( v20 == 2 )
        {
          *(_BYTE *)(v17 + 9) = 5;
          v29 = *(_DWORD *)(v17 + 12);
          *(_DWORD *)v17 = 0;
          v44 = v29;
          KfRaiseIrql(2);
          v30 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
          v31 = *(_DWORD *)(v30 + 4);
          v50 = v31;
          if ( (dword_682604 & 0x1000000) != 0 )
          {
            v42 = *(_BYTE *)(v31 + 132) == 2
               && *(_DWORD *)(v31 + 328) == *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
            EtwTraceEnqueueWork(v31, v46, v42);
            v31 = v50;
          }
          v32 = v44;
          do
            v33 = __ldrex((unsigned __int8 *)v44);
          while ( __strex(v33 | 0x80, (unsigned __int8 *)v44) );
          __dmb(0xBu);
          if ( v33 >> 7 )
          {
            do
            {
              do
              {
                __dmb(0xAu);
                __yield();
              }
              while ( (*(_DWORD *)v44 & 0x80) != 0 );
              do
                v41 = __ldrex((unsigned __int8 *)v44);
              while ( __strex(v41 | 0x80, (unsigned __int8 *)v44) );
              __dmb(0xBu);
            }
            while ( v41 >> 7 );
          }
          if ( *(_DWORD *)(v44 + 12) == v44 + 8
            || *(_DWORD *)(v44 + 24) >= *(_DWORD *)(v44 + 28)
            || *(_DWORD *)(v31 + 152) == v44 && *(_BYTE *)(v31 + 395) == 15 )
          {
LABEL_61:
            ++*(_DWORD *)(v32 + 4);
            v37 = v32 + 16;
            v38 = *(int ***)(v37 + 4);
            *v46 = v37;
            v46[1] = (int)v38;
            if ( *v38 != (int *)v37 )
              __fastfail(3u);
            *v38 = v46;
            *(_DWORD *)(v37 + 4) = v46;
          }
          else if ( !KiWakeQueueWaiter(v30, v44, (int)v46) )
          {
            v32 = v44;
            goto LABEL_61;
          }
          __dmb(0xBu);
          do
            v34 = __ldrex((unsigned int *)v44);
          while ( __strex(v34 & 0xFFFFFF7F, (unsigned int *)v44) );
          goto LABEL_25;
        }
        v21 = 256;
      }
      KiTryUnwaitThread(v7 + 1408, v19, v21, 0);
LABEL_25:
      v17 = v48;
      v18 = (_DWORD *)(a1 + 8);
      if ( v48 == a1 + 8 )
        goto LABEL_21;
    }
  }
LABEL_9:
  __dmb(0xBu);
  do
    v11 = __ldrex((unsigned int *)a1);
  while ( __strex(v11 & 0xFFFFFF7F, (unsigned int *)a1) );
  KiExitDispatcher(v7 + 1408, a3, 1, a2, v6);
  return v9;
}
