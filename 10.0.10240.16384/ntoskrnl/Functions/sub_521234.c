// sub_521234 
 
void __fastcall sub_521234(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r6
  int v6; // r7
  int v7; // r9
  int v8; // lr
  int v9; // r5
  int v10; // r0
  int v11; // r7
  BOOL v12; // r2
  unsigned int v13; // r2
  int *v14; // r1
  unsigned int v15; // r1
  int v16; // r3
  int v17; // [sp+64h] [bp+14h]

  if ( a4 == 2 )
  {
    *(_BYTE *)(v4 + 9) = 5;
    v9 = *(_DWORD *)(v4 + 12);
    *(_DWORD *)v4 = v8;
    KfRaiseIrql(2);
    v10 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + v6;
    v11 = *(_DWORD *)(v10 + 4);
    v17 = v10;
    if ( (dword_682604 & 0x1000000) != 0 )
    {
      v12 = *(_BYTE *)(v11 + 132) == 2
         && *(_DWORD *)(v11 + 328) == *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
      EtwTraceEnqueueWork(v11, v4, v12);
      v10 = v17;
    }
    do
      v13 = __ldrex((unsigned __int8 *)v9);
    while ( __strex(v13 | 0x80, (unsigned __int8 *)v9) );
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
      while ( (*(_DWORD *)v9 & 0x80) != 0 );
      do
        v13 = __ldrex((unsigned __int8 *)v9);
      while ( __strex(v13 | 0x80, (unsigned __int8 *)v9) );
    }
    if ( *(_DWORD *)(v9 + 12) == v9 + 8
      || *(_DWORD *)(v9 + 24) >= *(_DWORD *)(v9 + 28)
      || *(_DWORD *)(v11 + 152) == v9 && *(_BYTE *)(v11 + 395) == 15
      || !KiWakeQueueWaiter(v10, v9, v4) )
    {
      ++*(_DWORD *)(v9 + 4);
      v14 = *(int **)(v9 + 20);
      *(_DWORD *)v4 = v9 + 16;
      *(_DWORD *)(v4 + 4) = v14;
      if ( *v14 != v9 + 16 )
        __fastfail(3u);
      *v14 = v4;
      *(_DWORD *)(v9 + 20) = v4;
    }
    __dmb(0xBu);
    do
      v15 = __ldrex((unsigned int *)v9);
    while ( __strex(v15 & 0xFFFFFF7F, (unsigned int *)v9) );
    v16 = *(_DWORD *)(v5 + 4) - 1;
    *(_DWORD *)(v5 + 4) = v16;
    if ( !v16 )
      JUMPOUT(0x454B3A);
  }
  else
  {
    KiTryUnwaitThread(a1, v4, 256, 0);
  }
  if ( v7 == v5 + 8 )
    JUMPOUT(0x454B40);
  JUMPOUT(0x454AFA);
}
