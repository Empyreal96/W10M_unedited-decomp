// KeSetSchedulingGroupRankBias 
 
int __fastcall KeSetSchedulingGroupRankBias(int a1, int a2)
{
  int v2; // r4
  int v3; // r6
  _DWORD *v4; // r0
  unsigned int i; // r10
  _DWORD *v6; // r9
  int v7; // r6
  unsigned int *v8; // r7
  unsigned int v9; // r2
  int v10; // r2
  int v11; // r3
  unsigned int v13; // r1
  int v14; // r0
  int v15; // r1
  int *v16; // r3
  int v17; // r0
  int v18; // r7
  int v19; // r3
  _DWORD *v20; // r8
  __int64 v21; // r0
  __int64 v22; // kr00_8
  int v23; // [sp+0h] [bp-30h] BYREF
  int v24; // [sp+4h] [bp-2Ch]
  int v25; // [sp+8h] [bp-28h]
  _DWORD *v26; // [sp+Ch] [bp-24h]
  unsigned int v27; // [sp+10h] [bp-20h]

  v23 = 0;
  v2 = a2;
  v3 = a1;
  v24 = a2;
  v25 = a1;
  v4 = (_DWORD *)KfRaiseIrql(2);
  v26 = v4;
  v27 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  for ( i = 0; i < KeMaximumProcessors; v3 = v25 )
  {
    v6 = *(&KiProcessorBlock + i);
    v7 = v3 + 248 * i + 128;
    v8 = v6 + 6;
    while ( 1 )
    {
      do
        v9 = __ldrex(v8);
      while ( __strex(1u, v8) );
      __dmb(0xBu);
      if ( !v9 )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( *v8 );
    }
    if ( v2 )
    {
      v10 = *(unsigned __int8 *)(v7 + 92) | 8;
      v11 = *(_DWORD *)(v7 + 96);
      *(_BYTE *)(v7 + 92) = v10;
      *(_DWORD *)(v7 + 96) = v11 + 1;
      *(_BYTE *)(v7 + 92) = v10 | 4;
      if ( ((v10 | 4) & 1) != 0 )
        return sub_526184(v4, 1);
    }
    else
    {
      v13 = *(unsigned __int8 *)(v7 + 92);
      *(_DWORD *)(v7 + 96) -= (v13 >> 3) & 1;
      v14 = *(_DWORD *)(v7 + 96);
      *(_BYTE *)(v7 + 92) = v13 & 0xF7;
      if ( v14 )
      {
        if ( (v13 & 1) != 0 )
        {
          if ( *(_DWORD *)(v7 + 80) )
            JUMPOUT(0x52624C);
          if ( (*(_DWORD *)(v7 + 88) & 0xFFFFFFFC) != 0 )
            JUMPOUT(0x526254);
        }
      }
      else
      {
        if ( (v13 & 1) != 0 )
        {
          v15 = v7;
          do
          {
            v15 = *(_DWORD *)(v15 + 236);
            if ( !v15 )
              goto LABEL_21;
          }
          while ( !*(_DWORD *)(v15 + 96) );
          if ( !*(_DWORD *)(v15 + 236) )
          {
LABEL_21:
            v16 = &v23;
            v15 = 0;
            goto LABEL_22;
          }
          v16 = 0;
LABEL_22:
          v17 = KiMoveScbThreadsToNewReadylist(v7, v15, 0, v16, v23);
          if ( !*(_DWORD *)(v7 + 228) )
          {
            v18 = v7;
            do
            {
              v19 = *(_DWORD *)(v18 + 236);
              if ( v19 )
                v20 = (_DWORD *)(v19 + 228);
              else
                v20 = v6 + 494;
              v21 = KeQueryInterruptTime(v17);
              v22 = *(_QWORD *)(v18 + 56) - *(_QWORD *)(v18 + 64);
              *(_DWORD *)(v18 + 56) = v22 + v21;
              *(_BYTE *)(v18 + 92) &= 0xFEu;
              *(_DWORD *)(v18 + 60) = (unsigned __int64)(v22 + v21) >> 32;
              v17 = RtlRbRemoveNode(v20, v18 + 80);
              v18 = *(_DWORD *)(v18 + 236);
            }
            while ( v18 && (*(_BYTE *)(v18 + 92) & 1) != 0 && !*(_DWORD *)(v18 + 228) && !*(_WORD *)(v18 + 94) );
            v8 = v6 + 6;
          }
        }
        *(_BYTE *)(v7 + 92) &= 0xFBu;
      }
    }
    v4 = KiCheckForEffectivePriorityChange(v6, v7);
    __dmb(0xBu);
    *v8 = 0;
    ++i;
    v2 = v24;
  }
  return KiProcessDeferredReadyList(v27 + 1408, &v23, v26);
}
