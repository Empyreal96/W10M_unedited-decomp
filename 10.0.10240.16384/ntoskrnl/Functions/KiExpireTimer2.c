// KiExpireTimer2 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KiExpireTimer2(int a1, int a2, __int64 a3, _DWORD *a4)
{
  int v4; // lr
  int v5; // r9
  int v7; // r7
  int result; // r0
  _QWORD *v10; // r5
  _QWORD *v11; // r4
  int v12; // r1 OVERLAPPED
  _DWORD *v13; // r2 OVERLAPPED
  int v14; // r3
  int v15; // r10
  unsigned int v16; // lr
  int v17; // r0
  unsigned int v18; // r2
  unsigned int v19; // r1
  int v20; // r3
  void (__fastcall *v21)(int, unsigned int); // r7
  int v22; // r3
  __int64 v23; // r4
  char v24; // r3
  int v25; // r2
  int v26; // r1
  unsigned int v27; // r2
  int v28; // r5
  int v29; // r0
  _DWORD *v30; // r5
  _DWORD *v31; // r1
  unsigned int v32; // r2
  __int64 v33; // r2
  BOOL v34; // r2
  int v35; // r3
  _DWORD *v36; // r4
  int v37; // r5
  int v38; // r3
  int v39; // r2
  int v40; // r7
  unsigned int v41; // r3
  unsigned int v42; // lr
  int v43; // r0
  BOOL v44; // r2
  unsigned int v45; // r2
  unsigned int v46; // r2
  _DWORD *v47; // r1
  unsigned int v48; // r1
  int v49; // [sp+8h] [bp-80h]
  unsigned int v50; // [sp+8h] [bp-80h]
  __int64 v52; // [sp+10h] [bp-78h] BYREF
  unsigned int v53; // [sp+18h] [bp-70h]
  char v54[4]; // [sp+1Ch] [bp-6Ch] BYREF
  int v55; // [sp+20h] [bp-68h]
  int v56; // [sp+24h] [bp-64h]
  _DWORD *v57; // [sp+28h] [bp-60h]
  int v58; // [sp+2Ch] [bp-5Ch]
  __int64 v59; // [sp+40h] [bp-48h]

  v4 = a2;
  v5 = *(_DWORD *)(a2 + 4);
  v57 = a4;
  v58 = *(_DWORD *)(v5 + 308);
  v7 = 0;
  v55 = 0;
  v56 = 0;
  v59 = 0i64;
  if ( (dword_682608 & 0x20000) != 0 )
    return sub_52BFB4();
  if ( !*(_QWORD *)(a1 + 56) || (*(_BYTE *)(a1 + 1) & 0x20) != 0 )
    goto LABEL_4;
  if ( (*(_BYTE *)(a1 + 81) & 4) != 0 )
    a3 = RtlGetInterruptTimePrecise(&v52);
  if ( RtlULongLongAdd(a3, HIDWORD(a3), *(_DWORD *)(a1 + 56), *(_DWORD *)(a1 + 60), &v52) < 0
    || (v23 = v52, ((unsigned int)v52 & HIDWORD(v52)) == -1) )
  {
    v7 = 1;
    v23 = -2i64;
  }
  v24 = *(_BYTE *)(a1 + 81);
  v25 = 0;
  v26 = 0;
  v52 = 0i64;
  if ( (v24 & 0x10) != 0 )
  {
    v33 = *(_QWORD *)(a1 + 48) - *(_QWORD *)(a1 + 40);
    if ( RtlULongLongAdd(v23, HIDWORD(v23), v33, HIDWORD(v33), &v52) < 0
      || (v26 = HIDWORD(v52), v25 = v52, ((unsigned int)v52 & HIDWORD(v52)) == -1) )
    {
      v25 = -2;
      v26 = -1;
    }
  }
  *(_QWORD *)(a1 + 40) = v23;
  *(_DWORD *)(a1 + 48) = v25;
  *(_DWORD *)(a1 + 52) = v26;
  while ( 1 )
  {
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented(&KiTimer2CollectionLock);
    }
    else
    {
      do
        v27 = __ldrex((unsigned int *)&KiTimer2CollectionLock);
      while ( __strex(1u, (unsigned int *)&KiTimer2CollectionLock) );
      __dmb(0xBu);
      if ( v27 )
        KxWaitForSpinLockAndAcquire(&KiTimer2CollectionLock);
    }
    v28 = KiInsertTimer2WithCollectionLockHeld(a1, 0, v54);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(&KiTimer2CollectionLock);
    }
    else
    {
      __dmb(0xBu);
      KiTimer2CollectionLock = 0;
    }
    if ( v28 )
      break;
    if ( v7 )
      goto LABEL_42;
    if ( RtlULongLongAdd(
           *(_DWORD *)(a1 + 40),
           *(_DWORD *)(a1 + 44),
           *(_DWORD *)(a1 + 56),
           *(_DWORD *)(a1 + 60),
           a1 + 40) < 0 )
    {
      *(_DWORD *)(a1 + 40) = -1;
      *(_DWORD *)(a1 + 44) = -1;
LABEL_63:
      v7 = 1;
      --*(_QWORD *)(a1 + 40);
      goto LABEL_64;
    }
    if ( (*(_DWORD *)(a1 + 44) & *(_DWORD *)(a1 + 40)) == -1 )
      goto LABEL_63;
LABEL_64:
    if ( (*(_BYTE *)(a1 + 81) & 0x10) != 0 )
    {
      if ( RtlULongLongAdd(
             *(_DWORD *)(a1 + 48),
             *(_DWORD *)(a1 + 52),
             *(_DWORD *)(a1 + 56),
             *(_DWORD *)(a1 + 60),
             a1 + 48) < 0 )
      {
        *(_DWORD *)(a1 + 48) = -1;
        *(_DWORD *)(a1 + 52) = -1;
        goto LABEL_68;
      }
      if ( (*(_DWORD *)(a1 + 52) & *(_DWORD *)(a1 + 48)) == -1 )
LABEL_68:
        --*(_QWORD *)(a1 + 48);
    }
  }
  v55 = 1;
LABEL_42:
  v4 = a2;
LABEL_4:
  *(_DWORD *)(a1 + 4) = 1;
  if ( (*(_BYTE *)a1 & 0x7F) != 25 )
  {
    v35 = *(_DWORD *)(a1 + 8);
    v36 = (_DWORD *)(a1 + 8);
    if ( v35 == a1 + 8 )
    {
LABEL_109:
      *v36 = v36;
      *(_DWORD *)(a1 + 12) = a1 + 8;
      goto LABEL_20;
    }
    while ( 1 )
    {
      v37 = v35;
      LODWORD(v52) = *(_DWORD *)v35;
      v38 = *(unsigned __int8 *)(v35 + 8);
      if ( v38 == 1 )
        break;
      if ( v38 != 2 )
      {
        v39 = 256;
        goto LABEL_105;
      }
      *(_BYTE *)(v37 + 9) = 5;
      v40 = *(_DWORD *)(v37 + 12);
      *(_DWORD *)v37 = 0;
      KfRaiseIrql(2);
      v41 = (unsigned int)KeGetPcr();
      v42 = (v41 & 0xFFFFF000) + 1408;
      v43 = *(_DWORD *)((v41 & 0xFFFFF000) + 0x584);
      v53 = v43;
      if ( (dword_682604 & 0x1000000) != 0 )
      {
        v44 = *(_BYTE *)(v43 + 132) == 2
           && *(_DWORD *)(v43 + 328) == *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
        EtwTraceEnqueueWork(v43, v37, v44);
        v43 = v53;
      }
      do
        v45 = __ldrex((unsigned __int8 *)v40);
      while ( __strex(v45 | 0x80, (unsigned __int8 *)v40) );
      __dmb(0xBu);
      if ( v45 >> 7 )
      {
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( (*(_DWORD *)v40 & 0x80) != 0 );
          do
            v46 = __ldrex((unsigned __int8 *)v40);
          while ( __strex(v46 | 0x80, (unsigned __int8 *)v40) );
          __dmb(0xBu);
        }
        while ( v46 >> 7 );
      }
      if ( *(_DWORD *)(v40 + 12) == v40 + 8
        || *(_DWORD *)(v40 + 24) >= *(_DWORD *)(v40 + 28)
        || *(_DWORD *)(v43 + 152) == v40 && *(_BYTE *)(v43 + 395) == 15
        || !KiWakeQueueWaiter(v42, v40, v37) )
      {
        ++*(_DWORD *)(v40 + 4);
        v47 = *(_DWORD **)(v40 + 20);
        *(_DWORD *)v37 = v40 + 16;
        *(_DWORD *)(v37 + 4) = v47;
        if ( *v47 != v40 + 16 )
          __fastfail(3u);
        *v47 = v37;
        *(_DWORD *)(v40 + 20) = v37;
      }
      __dmb(0xBu);
      do
        v48 = __ldrex((unsigned int *)v40);
      while ( __strex(v48 & 0xFFFFFF7F, (unsigned int *)v40) );
LABEL_106:
      v35 = v52;
      if ( (_DWORD *)v52 == v36 )
        goto LABEL_109;
      v4 = a2;
    }
    v39 = *(unsigned __int16 *)(v37 + 10);
LABEL_105:
    KiTryUnwaitThread(v4, v37, v39, 0);
    goto LABEL_106;
  }
  v10 = *(_QWORD **)(a1 + 8);
  if ( v10 != (_QWORD *)(a1 + 8) )
  {
    while ( 1 )
    {
      v11 = v10;
      *(_QWORD *)&v12 = *v10;
      v10 = *(_QWORD **)v10;
      if ( *(_QWORD **)(v12 + 4) != v11 || (_QWORD *)*v13 != v11 )
        __fastfail(3u);
      *v13 = v12;
      *(_DWORD *)(v12 + 4) = v13;
      v14 = *((unsigned __int8 *)v11 + 8);
      if ( v14 == 1 )
      {
        if ( KiTryUnwaitThread(v4, v11, *((unsigned __int16 *)v11 + 5), 0) )
        {
          v22 = *(_DWORD *)(a1 + 4) - 1;
          *(_DWORD *)(a1 + 4) = v22;
          if ( !v22 )
            break;
        }
      }
      else if ( v14 == 2 )
      {
        *((_BYTE *)v11 + 9) = 5;
        v15 = *((_DWORD *)v11 + 3);
        *(_DWORD *)v11 = 0;
        KfRaiseIrql(2);
        v16 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
        v17 = *(_DWORD *)(v16 + 4);
        v53 = v16;
        v49 = v17;
        if ( (dword_682604 & 0x1000000) != 0 )
        {
          v34 = *(_BYTE *)(v17 + 132) == 2
             && *(_DWORD *)(v17 + 328) == *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
          EtwTraceEnqueueWork(v17, v11, v34);
          v16 = v53;
          v17 = v49;
        }
        do
          v18 = __ldrex((unsigned __int8 *)v15);
        while ( __strex(v18 | 0x80, (unsigned __int8 *)v15) );
        __dmb(0xBu);
        if ( v18 >> 7 )
        {
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
            }
            while ( (*(_DWORD *)v15 & 0x80) != 0 );
            do
              v32 = __ldrex((unsigned __int8 *)v15);
            while ( __strex(v32 | 0x80, (unsigned __int8 *)v15) );
            __dmb(0xBu);
          }
          while ( v32 >> 7 );
        }
        if ( *(_DWORD *)(v15 + 12) == v15 + 8
          || *(_DWORD *)(v15 + 24) >= *(_DWORD *)(v15 + 28)
          || *(_DWORD *)(v17 + 152) == v15 && *(_BYTE *)(v17 + 395) == 15
          || !KiWakeQueueWaiter(v16, v15, v11) )
        {
          ++*(_DWORD *)(v15 + 4);
          v31 = *(_DWORD **)(v15 + 20);
          *(_DWORD *)v11 = v15 + 16;
          *((_DWORD *)v11 + 1) = v31;
          if ( *v31 != v15 + 16 )
            __fastfail(3u);
          *v31 = v11;
          *(_DWORD *)(v15 + 20) = v11;
        }
        __dmb(0xBu);
        do
          v19 = __ldrex((unsigned int *)v15);
        while ( __strex(v19 & 0xFFFFFF7F, (unsigned int *)v15) );
        v20 = *(_DWORD *)(a1 + 4) - 1;
        *(_DWORD *)(a1 + 4) = v20;
        if ( !v20 )
          break;
      }
      else
      {
        KiTryUnwaitThread(v4, v11, 256, 0);
      }
      if ( v10 == (_QWORD *)(a1 + 8) )
        break;
      v4 = a2;
    }
  }
LABEL_20:
  v21 = (void (__fastcall *)(int, unsigned int))(bswap32(__ROR4__(
                                                           KiWaitNever ^ *(_DWORD *)(a1 + 64),
                                                           -(char)KiWaitNever) ^ a1) ^ KiWaitAlways);
  if ( v21 )
  {
    v50 = bswap32(__ROR4__(KiWaitNever ^ *(_DWORD *)(a1 + 68), -(char)KiWaitNever) ^ a1) ^ KiWaitAlways;
    KiUpdateTimer2Flags(a1, v55 | 0x10, 0);
    v29 = a2;
    if ( *(_DWORD *)(a2 + 1540) )
    {
      KiProcessThreadWaitList(a2, 1, 0, 2);
      v29 = a2;
    }
    v30 = &v57[3 * ((*v57)++ & 0xF)];
    v30[4] = v21;
    v30[5] = KeTickCount;
    *(_DWORD *)(v29 + 2332) = 0;
    v21(a1, v50);
    v30[6] = KeTickCount;
    result = KiUnmarkTimer2Running((unsigned int *)a1);
  }
  else
  {
    result = KiUpdateTimer2Flags(a1, v55, 4);
  }
  if ( v58 != *(_DWORD *)(v5 + 308) )
    KeBugCheck2(199, 5, v21, v58, *(_DWORD *)(v5 + 308), 0);
  return result;
}
