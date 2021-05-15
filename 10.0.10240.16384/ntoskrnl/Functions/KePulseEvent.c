// KePulseEvent 
 
int __fastcall KePulseEvent(int a1, int a2, int a3)
{
  unsigned int v7; // r7
  unsigned int v8; // r2
  int v9; // r6
  int *v10; // r8
  int *v11; // r5
  unsigned int v12; // r1
  int *v13; // r1
  int v14; // r3
  int v15; // r2
  unsigned int v16; // r2
  int v17; // r0
  unsigned int v18; // r3
  unsigned int v19; // lr
  int v20; // r0
  BOOL v21; // r2
  int v22; // r1
  unsigned int v23; // r2
  unsigned int v24; // r2
  int v25; // r1
  _DWORD *v26; // r0
  unsigned int v27; // r1
  int v28; // [sp+8h] [bp-38h]
  _DWORD *v29; // [sp+Ch] [bp-34h]
  int v30; // [sp+18h] [bp-28h]
  int v31; // [sp+1Ch] [bp-24h]

  if ( (*(_BYTE *)a1 & 0x7F) != 0 )
    return sub_516BE4();
  v31 = KfRaiseIrql(2);
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
        v16 = __ldrex((unsigned __int8 *)a1);
      while ( __strex(v16 | 0x80, (unsigned __int8 *)a1) );
      __dmb(0xBu);
    }
    while ( v16 >> 7 );
  }
  v9 = *(_DWORD *)(a1 + 4);
  if ( !v9 )
  {
    *(_DWORD *)(a1 + 4) = 1;
    v10 = *(int **)(a1 + 8);
    v11 = (int *)(a1 + 8);
    if ( v10 == (int *)(a1 + 8) )
    {
LABEL_8:
      *v11 = (int)v11;
      *(_DWORD *)(a1 + 12) = a1 + 8;
      goto LABEL_9;
    }
    while ( 1 )
    {
      v13 = v10;
      v14 = *((unsigned __int8 *)v10 + 8);
      v10 = (int *)*v10;
      v29 = v13;
      if ( v14 == 1 )
      {
        v15 = *((unsigned __int16 *)v13 + 5);
      }
      else
      {
        if ( v14 == 2 )
        {
          *((_BYTE *)v13 + 9) = 5;
          v17 = v13[3];
          *v13 = 0;
          v28 = v17;
          KfRaiseIrql(2);
          v18 = (unsigned int)KeGetPcr();
          v19 = (v18 & 0xFFFFF000) + 1408;
          v20 = *(_DWORD *)((v18 & 0xFFFFF000) + 0x584);
          v30 = v20;
          if ( (dword_682604 & 0x1000000) != 0 )
          {
            v21 = *(_BYTE *)(v20 + 132) == 2
               && *(_DWORD *)(v20 + 328) == *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
            EtwTraceEnqueueWork(v20, v29, v21);
            v20 = v30;
          }
          v22 = v28;
          do
            v23 = __ldrex((unsigned __int8 *)v28);
          while ( __strex(v23 | 0x80, (unsigned __int8 *)v28) );
          __dmb(0xBu);
          if ( v23 >> 7 )
          {
            do
            {
              do
              {
                __dmb(0xAu);
                __yield();
              }
              while ( (*(_DWORD *)v28 & 0x80) != 0 );
              do
                v24 = __ldrex((unsigned __int8 *)v28);
              while ( __strex(v24 | 0x80, (unsigned __int8 *)v28) );
              __dmb(0xBu);
            }
            while ( v24 >> 7 );
          }
          if ( *(_DWORD *)(v28 + 12) == v28 + 8
            || *(_DWORD *)(v28 + 24) >= *(_DWORD *)(v28 + 28)
            || *(_DWORD *)(v20 + 152) == v28 && *(_BYTE *)(v20 + 395) == 15 )
          {
LABEL_40:
            ++*(_DWORD *)(v22 + 4);
            v25 = v22 + 16;
            v26 = *(_DWORD **)(v25 + 4);
            *v29 = v25;
            v29[1] = v26;
            if ( *v26 != v25 )
              __fastfail(3u);
            *v26 = v29;
            *(_DWORD *)(v25 + 4) = v29;
          }
          else if ( !KiWakeQueueWaiter(v19, v28, v29) )
          {
            v22 = v28;
            goto LABEL_40;
          }
          __dmb(0xBu);
          do
            v27 = __ldrex((unsigned int *)v28);
          while ( __strex(v27 & 0xFFFFFF7F, (unsigned int *)v28) );
          goto LABEL_15;
        }
        v15 = 256;
      }
      KiTryUnwaitThread(v7 + 1408, v13, v15, 0);
LABEL_15:
      if ( v10 == v11 )
        goto LABEL_8;
    }
  }
LABEL_9:
  *(_DWORD *)(a1 + 4) = 0;
  __dmb(0xBu);
  do
    v12 = __ldrex((unsigned int *)a1);
  while ( __strex(v12 & 0xFFFFFF7F, (unsigned int *)a1) );
  KiExitDispatcher(v7 + 1408, a3, 1, a2, v31);
  return v9;
}
