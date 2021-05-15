// KeSetProcess 
 
int __fastcall KeSetProcess(int a1)
{
  unsigned int v2; // r10
  unsigned int v3; // r2
  int *v5; // r8
  int *v6; // r7
  unsigned int v7; // r1
  int *v8; // r4
  int v9; // r3
  int v10; // r2
  int v11; // r5
  int v12; // r9
  unsigned int v13; // r2
  unsigned int v14; // r1
  BOOL v15; // r2
  _DWORD *v16; // r1
  int v17; // [sp+Ch] [bp-24h]
  int v18; // [sp+10h] [bp-20h]

  v17 = KfRaiseIrql(2);
  v2 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  do
    v3 = __ldrex((unsigned __int8 *)a1);
  while ( __strex(v3 | 0x80, (unsigned __int8 *)a1) );
  __dmb(0xBu);
  if ( v3 >> 7 )
    return sub_515058();
  v5 = *(int **)(a1 + 8);
  v6 = (int *)(a1 + 8);
  v18 = *(_DWORD *)(a1 + 4);
  *(_DWORD *)(a1 + 4) = 1;
  while ( v5 != v6 )
  {
    v8 = v5;
    v9 = *((unsigned __int8 *)v5 + 8);
    v5 = (int *)*v5;
    if ( v9 == 1 )
    {
      v10 = *((unsigned __int16 *)v8 + 5);
      goto LABEL_12;
    }
    if ( v9 == 2 )
    {
      *((_BYTE *)v8 + 9) = 5;
      v11 = v8[3];
      *v8 = 0;
      KfRaiseIrql(2);
      v12 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x584);
      if ( (dword_682604 & 0x1000000) != 0 )
      {
        v15 = *(_BYTE *)(v12 + 132) == 2
           && *(_DWORD *)(v12 + 328) == *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
        EtwTraceEnqueueWork(v12, v8, v15);
      }
      do
        v13 = __ldrex((unsigned __int8 *)v11);
      while ( __strex(v13 | 0x80, (unsigned __int8 *)v11) );
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
        while ( (*(_DWORD *)v11 & 0x80) != 0 );
        do
          v13 = __ldrex((unsigned __int8 *)v11);
        while ( __strex(v13 | 0x80, (unsigned __int8 *)v11) );
      }
      if ( *(_DWORD *)(v11 + 12) == v11 + 8
        || *(_DWORD *)(v11 + 24) >= *(_DWORD *)(v11 + 28)
        || *(_DWORD *)(v12 + 152) == v11 && *(_BYTE *)(v12 + 395) == 15
        || !KiWakeQueueWaiter() )
      {
        ++*(_DWORD *)(v11 + 4);
        v16 = *(_DWORD **)(v11 + 20);
        *v8 = v11 + 16;
        v8[1] = (int)v16;
        if ( *v16 != v11 + 16 )
          __fastfail(3u);
        *v16 = v8;
        *(_DWORD *)(v11 + 20) = v8;
      }
      __dmb(0xBu);
      do
        v14 = __ldrex((unsigned int *)v11);
      while ( __strex(v14 & 0xFFFFFF7F, (unsigned int *)v11) );
    }
    else
    {
      v10 = 256;
LABEL_12:
      KiTryUnwaitThread(v2 + 1408, v8, v10, 0);
    }
  }
  *v6 = (int)v6;
  *(_DWORD *)(a1 + 12) = a1 + 8;
  __dmb(0xBu);
  do
    v7 = __ldrex((unsigned int *)a1);
  while ( __strex(v7 & 0xFFFFFF7F, (unsigned int *)a1) );
  KiExitDispatcher(v2 + 1408, 0, 1, 0, v17);
  return v18;
}
