// KiOutSwapProcesses 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KiOutSwapProcesses(_DWORD *a1)
{
  _DWORD *v2; // r4
  int v3; // r7
  unsigned int v4; // r2
  _DWORD *v5; // r0
  unsigned int *v6; // r9
  int v7; // r2
  _DWORD *v8; // r5
  int v9; // r1 OVERLAPPED
  _DWORD *v10; // r2 OVERLAPPED
  unsigned int v11; // r1
  unsigned int v12; // r1
  int result; // r0
  unsigned int v14; // r2
  unsigned int v15; // r0
  unsigned int v16; // r1
  unsigned int v17; // r2
  int v18; // r7
  int *v19; // r5
  int v20; // r0
  int v21; // r1
  unsigned int v22; // r2
  unsigned int v23; // r0
  unsigned int v24; // r1
  unsigned int v25; // r2
  unsigned int v26; // r1
  int v27; // [sp+0h] [bp-28h]
  int v28; // [sp+4h] [bp-24h]

  while ( 1 )
  {
    v2 = a1 - 21;
    a1 = (_DWORD *)*a1;
    v3 = KfRaiseIrql(2);
    v28 = v3;
    do
      v4 = __ldrex((unsigned __int8 *)v2);
    while ( __strex(v4 | 0x80, (unsigned __int8 *)v2) );
    while ( 1 )
    {
      __dmb(0xBu);
      if ( !(v4 >> 7) )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( (*v2 & 0x80) != 0 );
      do
        v4 = __ldrex((unsigned __int8 *)v2);
      while ( __strex(v4 | 0x80, (unsigned __int8 *)v2) );
    }
    v5 = (_DWORD *)v2[19];
    v6 = v2 + 29;
    v7 = v2[29];
    v8 = v2 + 19;
    if ( v5 != v2 + 19 && (v2[29] & 7) != 6 )
    {
      *(_QWORD *)&v9 = *(_QWORD *)v8;
      if ( *(_DWORD **)(*v8 + 4) != v8 || (_DWORD *)*v10 != v8 )
        __fastfail(3u);
      *v10 = v9;
      *(_DWORD *)(v9 + 4) = v10;
      *v8 = v8;
      v2[20] = v2 + 19;
      __dmb(0xBu);
      do
        v11 = __ldrex(v6);
      while ( __strex(v11 ^ 3, v6) );
      __dmb(0xBu);
      do
        v12 = __ldrex(v2);
      while ( __strex(v12 & 0xFFFFFF7F, v2) );
      result = KiReadyOutSwappedThreads(v5, v3);
      goto LABEL_13;
    }
    __dmb(0xBu);
    v14 = (v7 ^ 0xFFFFFFFD) & 7;
    do
      v15 = __ldrex(v6);
    while ( __strex(v15 ^ v14, v6) );
    __dmb(0xBu);
    do
      v16 = __ldrex(v2);
    while ( __strex(v16 & 0xFFFFFF7F, v2) );
    KfLowerIrql(v3);
    MmOutSwapProcess(v2);
    v27 = 0;
    KfRaiseIrql(2);
    do
      v17 = __ldrex((unsigned __int8 *)v2);
    while ( __strex(v17 | 0x80, (unsigned __int8 *)v2) );
    while ( 1 )
    {
      __dmb(0xBu);
      if ( !(v17 >> 7) )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( (*v2 & 0x80) != 0 );
      do
        v17 = __ldrex((unsigned __int8 *)v2);
      while ( __strex(v17 | 0x80, (unsigned __int8 *)v2) );
    }
    if ( (_DWORD *)*v8 == v8 )
    {
      v18 = 1;
    }
    else
    {
      __pld(&KiProcessInSwapListHead);
      v18 = 2;
      v19 = v2 + 21;
      v20 = KiProcessInSwapListHead;
      do
      {
        *v19 = v20;
        v21 = v20;
        __dmb(0xBu);
        do
          v22 = __ldrex((unsigned int *)&KiProcessInSwapListHead);
        while ( v22 == v20 && __strex((unsigned int)v19, (unsigned int *)&KiProcessInSwapListHead) );
        v20 = v22;
      }
      while ( v22 != v21 );
      if ( !v22 )
        v27 = 1;
    }
    __dmb(0xBu);
    do
      v23 = __ldrex(v6);
    while ( __strex(v23 ^ v18 ^ 5, v6) );
    __dmb(0xBu);
    do
      v24 = __ldrex(v2);
    while ( __strex(v24 & 0xFFFFFF7F, v2) );
    if ( v27 )
      break;
LABEL_40:
    result = KfLowerIrql(v28);
LABEL_13:
    if ( !a1 )
      return result;
  }
  do
    v25 = __ldrex((unsigned __int8 *)&KiSwapEvent);
  while ( __strex(v25 | 0x80, (unsigned __int8 *)&KiSwapEvent) );
  __dmb(0xBu);
  if ( !(v25 >> 7) )
  {
    dword_624F24 = 1;
    __dmb(0xBu);
    do
      v26 = __ldrex((unsigned int *)&KiSwapEvent);
    while ( __strex(v26 & 0xFFFFFF7F, (unsigned int *)&KiSwapEvent) );
    goto LABEL_40;
  }
  return sub_516070();
}
