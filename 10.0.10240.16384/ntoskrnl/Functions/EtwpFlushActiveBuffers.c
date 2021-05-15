// EtwpFlushActiveBuffers 
 
int __fastcall EtwpFlushActiveBuffers(unsigned int *a1, int a2)
{
  unsigned int v4; // r3
  int v5; // r7
  unsigned int *v6; // r2
  unsigned int v7; // r1
  int v8; // r7
  unsigned int *v9; // r2
  int v10; // r10
  void **v11; // lr
  _DWORD **v12; // r4
  BOOL v13; // r9
  _DWORD *v14; // r4
  unsigned int v15; // r8
  unsigned int v16; // r3
  _DWORD *v17; // r8
  int v18; // r5
  int v19; // r0
  _DWORD *v20; // r1
  int v21; // r3
  int v22; // r3
  int v23; // r3
  unsigned int v24; // r3
  _DWORD *v25; // r5
  int v26; // lr
  unsigned int v27; // r2
  unsigned int *v28; // r0
  unsigned int v29; // r5
  unsigned int i; // r2
  unsigned int v31; // r1
  int v32; // r1
  int v33; // r4
  unsigned int *v34; // r2
  unsigned int v35; // r5
  int v36; // r3
  _DWORD *v37; // r1
  int v38; // r3
  int v39; // r3
  unsigned int v40; // r3
  int v41; // [sp+0h] [bp-B8h]
  unsigned int *v42; // [sp+8h] [bp-B0h]
  void **v43; // [sp+Ch] [bp-ACh]
  int v44; // [sp+10h] [bp-A8h]
  _DWORD v45[40]; // [sp+18h] [bp-A0h] BYREF

  v41 = a2;
  if ( a1[148] || a1[68] )
  {
    if ( a1[160] )
      return sub_809B00();
    v4 = a1[3];
    v5 = 0;
    v44 = 0;
    if ( (v4 & 0x40000) != 0 )
    {
      __dmb(0xBu);
      v6 = a1 + 22;
      do
        v7 = __ldrex(v6);
      while ( __strex(0, v6) );
      __dmb(0xBu);
      if ( v7 )
      {
        v45[0] = v7;
        v5 = 1;
      }
      goto LABEL_16;
    }
    if ( (v4 & 0x10000000) != 0 )
      v36 = 1;
    else
      v36 = KeNumberProcessors_0;
    v10 = v36 - 1;
    if ( v36 - 1 < 0 )
    {
LABEL_15:
      EtwpLockUnlockBufferList(a1);
LABEL_16:
      v12 = 0;
      if ( v5 > 0 )
      {
        v17 = &v45[v5];
        do
        {
          v18 = 0;
          v19 = 1;
          if ( v5 > 1 )
          {
            v26 = 0;
            do
            {
              if ( *(_QWORD *)(v45[v19] + 16) > *(_QWORD *)(v45[v26] + 16) )
              {
                v18 = v19;
                v26 = v19;
              }
              ++v19;
            }
            while ( v19 < v5 );
          }
          v20 = (_DWORD *)v45[v18];
          v21 = v20[8];
          v45[v18] = v21;
          if ( !v21 )
          {
            v22 = *(v17 - 1);
            --v5;
            --v17;
            v45[v18] = v22;
          }
          v23 = v20[3];
          __dmb(0xBu);
          if ( v23 <= 0 && (v24 = v20[1], v24 <= 0x48) && (v24 || (v40 = v20[2], __dmb(0xBu), v40 <= 0x48)) )
          {
            EtwpCompleteBuffer(a1);
          }
          else
          {
            v20[8] = v12;
            v12 = (_DWORD **)(v20 + 8);
          }
        }
        while ( v5 > 0 );
      }
      v8 = 0;
      v13 = 0;
      if ( v12 )
      {
        v25 = *v12;
        do
        {
          if ( !v25 )
            v13 = v41 != 0;
          EtwpAdjustFreeBuffers(a1);
          EtwpWaitForBufferReferenceCount(v12 - 8);
          v8 = EtwpFlushBuffer(a1, v12 - 8, v13);
          EtwpCompleteBuffer(a1);
          v12 = (_DWORD **)v25;
          if ( v25 )
            v25 = (_DWORD *)*v25;
        }
        while ( v12 );
        if ( a1[33] && v41 && ((a1[3] & 0x10000000) == 0 || v44) )
          EtwpRequestFlushTimer((int)a1, 0);
      }
      else if ( v41 && (a1[152] & 8) != 0 && !a1[82] )
      {
        if ( a1[66] )
          EtwpRealtimeSendEmptyMarker(a1);
      }
      return v8;
    }
    v9 = v45;
    v42 = v45;
    v11 = &KiProcessorBlock + v10;
    v43 = v11;
    while ( 1 )
    {
      if ( (a1[3] & 0x10000000) != 0 )
      {
        v14 = a1 + 22;
      }
      else
      {
        if ( v10 >= (unsigned int)KeNumberProcessors_0 )
          v37 = 0;
        else
          v37 = *v11;
        v38 = v37[899];
        a2 = v41;
        v14 = (_DWORD *)(v38 + 4 * (*a1 + 32));
        v9 = v42;
      }
      v15 = *v14 & 0xFFFFFFF8;
      if ( !v15 )
        goto LABEL_14;
      if ( a2 )
      {
        __dmb(0xBu);
        v27 = a1[1];
        v28 = (unsigned int *)(v15 + 8);
        do
          v29 = __ldrex(v28);
        while ( __strex(v29 + v27, v28) );
        __dmb(0xBu);
        if ( v29 <= a1[1] )
          *(_DWORD *)(v15 + 4) = v29;
        __pld(v14);
        for ( i = *v14; (i ^ v15) <= 7; i = v31 )
        {
          __dmb(0xBu);
          do
            v31 = __ldrex(v14);
          while ( v31 == i && __strex(0, v14) );
          if ( v31 == i )
            break;
        }
        v32 = i & 0xFFFFFFF8;
        if ( (i & 0xFFFFFFF8) == v15 )
        {
          __dmb(0xBu);
          v33 = -(i & 7);
          v34 = (unsigned int *)(v32 + 12);
          do
            v35 = __ldrex(v34);
          while ( __strex(v35 + v33, v34) );
          __dmb(0xBu);
          EtwpPrepareDirtyBuffer((int)a1, v32);
          v11 = v43;
        }
        else
        {
          if ( v32 )
          {
            do
            {
              v39 = *(_DWORD *)(v32 + 32);
              if ( v39 == v15 )
                break;
              v32 = *(_DWORD *)(v32 + 32);
            }
            while ( v39 );
          }
          v44 = 1;
          *(_DWORD *)(v32 + 32) = 0;
        }
        ++v5;
        *v42 = v15;
        v9 = v42 + 1;
      }
      else
      {
        v16 = *(_DWORD *)(v15 + 32);
        if ( !v16 )
          goto LABEL_14;
        *v9 = v16;
        ++v5;
        ++v9;
        *(_DWORD *)(v15 + 32) = 0;
      }
      v42 = v9;
LABEL_14:
      --v10;
      --v11;
      a2 = v41;
      v43 = v11;
      if ( v10 < 0 )
        goto LABEL_15;
    }
  }
  if ( a1[33] )
    EtwpRequestFlushTimer((int)a1, 0);
  return 259;
}
