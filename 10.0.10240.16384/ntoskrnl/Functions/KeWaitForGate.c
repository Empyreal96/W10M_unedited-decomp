// KeWaitForGate 
 
int __fastcall KeWaitForGate(int a1, char a2)
{
  unsigned int v4; // r4
  _DWORD *v5; // r8
  unsigned int *v6; // r5
  int v7; // r0
  int v8; // r7
  int v9; // r3
  unsigned int v10; // r2
  int v12; // r7
  unsigned int v13; // r2
  _DWORD *v14; // r1
  unsigned int v15; // r1
  unsigned int v16; // r1
  unsigned int v17; // r0
  unsigned int v18; // r3
  unsigned int v19; // r2

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = (_DWORD *)(v4 + 216);
  v6 = (unsigned int *)(v4 + 44);
  while ( 1 )
  {
    v7 = KfRaiseIrql(2);
    v8 = v7;
    while ( 1 )
    {
      v9 = *(_DWORD *)(v4 + 76);
      *(_BYTE *)(v4 + 134) = v8;
      *(_BYTE *)(v4 + 72) = 0;
      *(_DWORD *)(v4 + 76) = v9 & 0xFFFFFFEF;
      *(_BYTE *)(v4 + 135) = 0;
      do
        v10 = __ldrex(v6);
      while ( __strex(1u, v6) );
      __dmb(0xBu);
      if ( v10 )
        return sub_5238D0(v7, 1);
      if ( !*(_BYTE *)(v4 + 121) || *(_WORD *)(v4 + 310) || v8 )
        break;
      __dmb(0xBu);
      *v6 = 0;
      KfLowerIrql(1);
      KiDeliverApc(0, 0, 0);
      v7 = KfRaiseIrql(2);
    }
    *(_BYTE *)(v4 + 132) = 5;
    *(_BYTE *)(v4 + 395) = a2;
    __dmb(0xBu);
    *v6 = 0;
    v12 = 0;
    *(_DWORD *)(v4 + 304) = KeTickCount;
    *(_BYTE *)(v4 + 224) = 1;
    *(_BYTE *)(v4 + 225) = 4;
    *(_WORD *)(v4 + 226) = 0;
    *(_DWORD *)(v4 + 232) = a1;
    do
      v13 = __ldrex((unsigned __int8 *)a1);
    while ( __strex(v13 | 0x80, (unsigned __int8 *)a1) );
    while ( 1 )
    {
      __dmb(0xBu);
      if ( !(v13 >> 7) )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( (*(_DWORD *)a1 & 0x80) != 0 );
      do
        v13 = __ldrex((unsigned __int8 *)a1);
      while ( __strex(v13 | 0x80, (unsigned __int8 *)a1) );
    }
    if ( *(_DWORD *)(a1 + 4) )
      break;
    v14 = *(_DWORD **)(a1 + 12);
    *v5 = a1 + 8;
    *(_DWORD *)(v4 + 220) = v14;
    if ( *v14 != a1 + 8 )
      __fastfail(3u);
    *v14 = v5;
    *(_DWORD *)(a1 + 12) = v5;
    __dmb(0xBu);
    do
      v15 = __ldrex((unsigned int *)a1);
    while ( __strex(v15 & 0xFFFFFF7F, (unsigned int *)a1) );
    *(_BYTE *)(v4 + 363) = 1;
    v12 = KiCommitThreadWait(v4, v5, 0);
    if ( v12 != 256 )
      return v12;
  }
  *(_DWORD *)(a1 + 4) = 0;
  __dmb(0xBu);
  do
    v16 = __ldrex((unsigned int *)a1);
  while ( __strex(v16 & 0xFFFFFF7F, (unsigned int *)a1) );
  *(_BYTE *)(v4 + 132) = 2;
  v17 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  __dmb(0xFu);
  v18 = *v6;
  __dmb(0xBu);
  if ( v18 )
  {
    while ( 1 )
    {
      do
        v19 = __ldrex(v6);
      while ( __strex(1u, v6) );
      __dmb(0xBu);
      if ( !v19 )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( *v6 );
    }
    __dmb(0xBu);
    *v6 = 0;
  }
  KiExitThreadWait(v17 + 1408, v4, 0);
  return v12;
}
