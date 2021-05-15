// EtwpBufferingModeFlush 
 
int __fastcall EtwpBufferingModeFlush(unsigned int *a1)
{
  unsigned int v2; // r5
  unsigned int v3; // r7
  int v4; // r8
  unsigned int v5; // r10
  unsigned int v6; // r9
  void **v7; // r2
  _DWORD *v8; // r4
  _DWORD *v9; // r3
  int v10; // r7
  unsigned int *v11; // r2
  unsigned int v12; // r0
  unsigned int i; // r2
  unsigned int v14; // r1
  int v15; // r4
  unsigned int *v16; // r2
  unsigned int v17; // r5
  unsigned int v18; // r5
  unsigned int v19; // r7
  int v20; // r1
  int j; // r4
  unsigned int *v22; // r2
  unsigned int v23; // r1
  void **v25; // [sp+0h] [bp-30h]
  unsigned int v26; // [sp+4h] [bp-2Ch]
  unsigned int v27; // [sp+8h] [bp-28h]

  v2 = a1[1];
  v3 = *a1;
  v4 = 0;
  v26 = v2;
  v27 = *a1;
  __dmb(0xBu);
  if ( (a1[3] & 0x10000000) != 0 )
    v5 = 1;
  else
    v5 = KeNumberProcessors_0;
  if ( EtwpFileSystemReady )
    a1[152] |= 4u;
  if ( a1[30] )
  {
    v4 = EtwpCreateLogFile(a1, 0);
    v6 = 0;
    if ( v4 >= 0 )
    {
      if ( v5 )
      {
        v7 = &KiProcessorBlock;
        v25 = &KiProcessorBlock;
        do
        {
          if ( (a1[3] & 0x10000000) != 0 )
          {
            v8 = a1 + 22;
          }
          else
          {
            if ( v6 >= KeNumberProcessors_0 )
              v9 = 0;
            else
              v9 = *v7;
            v8 = (_DWORD *)(v9[899] + 4 * (v3 + 32));
            v7 = v25;
          }
          v10 = *v8 & 0xFFFFFFF8;
          if ( v10 )
          {
            __dmb(0xBu);
            v11 = (unsigned int *)(v10 + 8);
            do
              v12 = __ldrex(v11);
            while ( __strex(v12 + v2, v11) );
            __dmb(0xBu);
            if ( v12 <= v2 )
              *(_DWORD *)(v10 + 4) = v12;
            __pld(v8);
            for ( i = *v8; (i ^ v10) <= 7; i = v14 )
            {
              __dmb(0xBu);
              do
                v14 = __ldrex(v8);
              while ( v14 == i && __strex(0, v8) );
              if ( v14 == i )
                break;
            }
            if ( (i & 0xFFFFFFF8) == v10 )
            {
              __dmb(0xBu);
              v15 = -(i & 7);
              v16 = (unsigned int *)((i & 0xFFFFFFF8) + 12);
              do
                v17 = __ldrex(v16);
              while ( __strex(v17 + v15, v16) );
              __dmb(0xBu);
              EtwpPrepareDirtyBuffer((int)a1, v10);
              v2 = v26;
            }
            v7 = v25;
          }
          ++v6;
          ++v7;
          v3 = v27;
          v25 = v7;
        }
        while ( v6 < v5 );
      }
      EtwpLockUnlockBufferList(a1);
      v19 = a1[151];
      v18 = a1[150];
      for ( j = EtwpFindAndLockBufferForFlushing(a1, v20, v18, v19);
            j;
            j = EtwpFindAndLockBufferForFlushing(a1, v23, v18, v19) )
      {
        EtwpWaitForBufferReferenceCount(j);
        if ( EtwpPrepareHeader((int)a1, j, 0) != -2147483614 )
          v4 = EtwpFlushBufferToLogfile((int)a1);
        __dmb(0xBu);
        v22 = (unsigned int *)(j + 44);
        do
          v23 = __ldrex(v22);
        while ( __strex(0, v22) );
        __dmb(0xBu);
        if ( v4 < 0 )
          break;
        v19 = (__PAIR64__(v19, v18--) - 1) >> 32;
      }
      EtwpFinalizeHeader(a1, a1[148], 0);
      a1[44] = 0;
    }
    if ( a1[148] )
    {
      ZwClose();
      a1[148] = 0;
    }
    RtlFreeAnsiString(a1 + 25);
  }
  return v4;
}
