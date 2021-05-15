// MiSignalLargePageRebuild 
 
unsigned int __fastcall MiSignalLargePageRebuild(int a1, int a2, int a3, int a4)
{
  unsigned int result; // r0
  _WORD *v6; // r1
  unsigned int *v7; // r9
  unsigned int v8; // r2
  int v9; // r7
  int v10; // r6
  int v11; // r8
  _BYTE *v12; // r5
  char v13; // r3
  unsigned int v14; // r2
  int v15; // r3
  int v16; // r2
  _BYTE *v17; // r3
  _DWORD v18[10]; // [sp+0h] [bp-28h] BYREF

  v18[1] = a3;
  v18[2] = a4;
  if ( !*(_BYTE *)(a1 + 3076) )
  {
    v16 = (unsigned __int16)KeNumberNodes;
    *(_BYTE *)(a1 + 3076) = 1;
    if ( v16 )
    {
      v17 = (_BYTE *)(a1 + 3084);
      do
      {
        v17[1] = 8;
        *v17 = 8;
        v17 += 2;
        --v16;
      }
      while ( v16 );
    }
  }
  result = MiPageCombiningActive(a1, &KeNumberNodes);
  if ( result != 1 )
  {
    v7 = (unsigned int *)(a1 + 3080);
    result = 1;
    do
      v8 = __ldrex(v7);
    while ( !v8 && __strex(1u, v7) );
    if ( !v8 )
    {
      v9 = (unsigned __int16)*v6;
      v10 = 0;
      if ( !*v6 )
        goto LABEL_13;
      v11 = 0;
      v12 = (_BYTE *)(a1 + 3084);
      do
      {
        result = *(_DWORD *)(a1 + 24);
        if ( *v12 )
        {
          v13 = *v12 - 1;
          *v12 = v13;
          if ( !v13 )
          {
            result = MiNodeFreeZeroPages(result + v11, 0, 0);
            if ( result >= 0x4000 )
            {
              v10 = 1;
            }
            else
            {
              v12[1] = 8;
              *v12 = 8;
            }
          }
        }
        v12 += 2;
        --v9;
        v11 += 104;
      }
      while ( v9 );
      if ( v10 == 1
        && ((KeAcquireInStackQueuedSpinLock(&dword_634318, v18), (v15 = *(_DWORD *)(a1 + 8)) == 0) ? (v10 = 0) : (*(_DWORD *)(a1 + 8) = v15 + 1),
            result = KeReleaseInStackQueuedSpinLock(v18),
            v10 == 1) )
      {
        *(_DWORD *)(a1 + 3128) = a1;
        *(_DWORD *)(a1 + 3124) = MiRebuildLargePages;
        *(_DWORD *)(a1 + 3116) = 0;
        result = ExQueueWorkItem(a1 + 3116, 4);
      }
      else
      {
LABEL_13:
        __dmb(0xBu);
        do
          v14 = __ldrex(v7);
        while ( __strex(v14 - 1, v7) );
      }
    }
  }
  return result;
}
