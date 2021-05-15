// KeRegisterObjectNotification 
 
int __fastcall KeRegisterObjectNotification(unsigned int a1, unsigned int a2, int a3)
{
  unsigned __int64 v4; // r6
  int v5; // r0
  int v6; // r10
  unsigned int v7; // r4
  unsigned int i; // r3
  _DWORD *v9; // r1
  unsigned int v10; // r1
  int result; // r0
  unsigned int v12; // r2
  unsigned int v13; // r9
  int v14; // r4
  unsigned int v15; // r2
  unsigned int v16; // r1
  unsigned int v17; // r1
  BOOL v18; // r2
  unsigned int v19; // r2
  _DWORD *v20; // r1

  *(_BYTE *)(a3 + 8) = 2;
  *(_BYTE *)(a3 + 9) = 4;
  v4 = __PAIR64__(a1, a2);
  *(_QWORD *)(a3 + 12) = __PAIR64__(a1, a2);
  v5 = KfRaiseIrql(2);
  v6 = v5;
  do
    v7 = __ldrex((unsigned __int8 *)HIDWORD(v4));
  while ( __strex(v7 | 0x80, (unsigned __int8 *)HIDWORD(v4)) );
  __dmb(0xBu);
  for ( i = v7 >> 7; i; i = v12 >> 7 )
  {
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( (*(_DWORD *)HIDWORD(v4) & 0x80) != 0 );
    do
      v12 = __ldrex((unsigned __int8 *)HIDWORD(v4));
    while ( __strex(v12 | 0x80, (unsigned __int8 *)HIDWORD(v4)) );
    __dmb(0xBu);
  }
  if ( *(int *)(HIDWORD(v4) + 4) > 0 )
  {
    if ( (*(_BYTE *)HIDWORD(v4) & 7) == 1 )
    {
      *(_DWORD *)(HIDWORD(v4) + 4) = 0;
    }
    else if ( (*(_BYTE *)HIDWORD(v4) & 0x7F) == 5 )
    {
      return sub_50BC5C(0);
    }
    *(_BYTE *)(a3 + 9) = 5;
    *(_DWORD *)a3 = 0;
    KfRaiseIrql(2);
    v13 = (unsigned int)KeGetPcr() & 0xFFFFF000;
    v14 = *(_DWORD *)(v13 + 1412);
    if ( (dword_682604 & 0x1000000) != 0 )
    {
      v18 = *(_BYTE *)(v14 + 132) == 2
         && *(_DWORD *)(v14 + 328) == *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
      EtwTraceEnqueueWork(*(_DWORD *)(v13 + 1412), a3, v18);
    }
    do
      v15 = __ldrex((unsigned __int8 *)v4);
    while ( __strex(v15 | 0x80, (unsigned __int8 *)v4) );
    __dmb(0xBu);
    if ( v15 >> 7 )
    {
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( (*(_DWORD *)v4 & 0x80) != 0 );
        do
          v19 = __ldrex((unsigned __int8 *)v4);
        while ( __strex(v19 | 0x80, (unsigned __int8 *)v4) );
        __dmb(0xBu);
      }
      while ( v19 >> 7 );
    }
    if ( *(_DWORD *)(v4 + 12) == (_DWORD)v4 + 8
      || *(_DWORD *)(v4 + 24) >= *(_DWORD *)(v4 + 28)
      || *(_DWORD *)(v14 + 152) == (_DWORD)v4 && *(_BYTE *)(v14 + 395) == 15
      || !KiWakeQueueWaiter(v13 + 1408, v4, a3) )
    {
      ++*(_DWORD *)(v4 + 4);
      v20 = *(_DWORD **)(v4 + 20);
      *(_DWORD *)a3 = v4 + 16;
      *(_DWORD *)(a3 + 4) = v20;
      if ( *v20 != (_DWORD)v4 + 16 )
        __fastfail(3u);
      *v20 = a3;
      *(_DWORD *)(v4 + 20) = a3;
    }
    __dmb(0xBu);
    do
      v16 = __ldrex((unsigned int *)v4);
    while ( __strex(v16 & 0xFFFFFF7F, (unsigned int *)v4) );
    __dmb(0xBu);
    do
      v17 = __ldrex((unsigned int *)HIDWORD(v4));
    while ( __strex(v17 & 0xFFFFFF7F, (unsigned int *)HIDWORD(v4)) );
    KiExitDispatcher(((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408, 0, 1, 0, v6);
    result = 1;
  }
  else
  {
    v9 = *(_DWORD **)(HIDWORD(v4) + 12);
    *(_DWORD *)a3 = HIDWORD(v4) + 8;
    *(_DWORD *)(a3 + 4) = v9;
    if ( *v9 != HIDWORD(v4) + 8 )
      __fastfail(3u);
    *v9 = a3;
    *(_DWORD *)(HIDWORD(v4) + 12) = a3;
    __dmb(0xBu);
    do
      v10 = __ldrex((unsigned int *)HIDWORD(v4));
    while ( __strex(v10 & 0xFFFFFF7F, (unsigned int *)HIDWORD(v4)) );
    KfLowerIrql(v5);
    result = 0;
  }
  return result;
}
