// ExpUpdateDebugInfo 
 
unsigned int *__fastcall ExpUpdateDebugInfo(int a1, int a2, unsigned int a3, unsigned int a4)
{
  unsigned int v4; // r9
  unsigned int *result; // r0
  unsigned int *v6; // r5
  int v7; // r8
  int v8; // r8
  int v9; // r4
  int v10; // r10
  unsigned int v11; // r2
  unsigned int v12; // r3
  unsigned int v13; // r3
  unsigned int v14; // r10
  unsigned int v15; // r6
  unsigned int v16; // r4
  unsigned int i; // r3
  unsigned int *v18; // r2
  unsigned int v19; // r0
  unsigned int v20; // r1
  unsigned int *v21; // r2
  unsigned int v22; // r1
  unsigned int v23; // r1
  unsigned int v24; // r0
  int v25; // r1
  int v26; // r3
  unsigned int *v27; // r6
  unsigned int v28; // r0
  unsigned int v29; // r4
  unsigned int v30; // r0
  unsigned int *v31; // r4
  unsigned int v32; // r6
  unsigned int v33; // r1
  int v34; // [sp+4h] [bp-34h]
  unsigned int v35; // [sp+8h] [bp-30h]
  int v36; // [sp+Ch] [bp-2Ch]

  v4 = a4;
  v35 = a3;
  v34 = a2;
  v36 = a1;
  result = ExReferenceHandleDebugInfo(a1);
  v6 = result;
  if ( result )
  {
    v7 = 0;
    if ( (result[2] & 3) != 0 )
    {
      v8 = (int)(result + 3);
      v9 = KeAbPreAcquire((unsigned int)(result + 3), 0, 0);
      v10 = KfRaiseIrql(1);
      do
        v11 = __ldrex((unsigned __int8 *)v8);
      while ( __strex(v11 & 0xFE, (unsigned __int8 *)v8) );
      __dmb(0xBu);
      if ( (v11 & 1) == 0 )
        ExpAcquireFastMutexContended(v8, v9);
      if ( v9 )
        *(_BYTE *)(v9 + 14) |= 1u;
      *(_DWORD *)(v8 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      *(_DWORD *)(v8 + 28) = v10;
      v7 = 1;
    }
    v12 = v6[2];
    if ( (v12 & 1) != 0 )
    {
      v6[2] = v12 & 0xBFFFFFFE | 0x80000000;
      v6[11] = 0;
      memset((_BYTE *)v6 + 48, 0, 80 * v6[1] + 48);
    }
    v13 = v6[2];
    if ( (v13 & 2) != 0 && v4 == 2 )
    {
      v14 = v6[11];
      v15 = v14;
      if ( (v13 & 0x40000000) != 0 )
        v15 = v6[1];
      v16 = 1;
      if ( v15 )
      {
        for ( i = v6[1]; ; i = v6[1] )
        {
          if ( !i )
            __brkdiv0();
          v18 = &v6[20 * (v16 % i)];
          if ( v18[15] == 1 && v18[14] == v35 )
            break;
          if ( ++v16 > v15 )
            goto LABEL_39;
        }
        v6[11] = v14 - 1;
        v19 = v6[1];
        if ( !v19 )
          __brkdiv0();
        v20 = (v14 - 1) % v19;
        if ( v20 )
          memmove((int)&v6[20 * (v16 % i) + 12], (int)&v6[20 * v20 + 12], 0x50u);
      }
    }
    else
    {
      __dmb(0xBu);
      v21 = v6 + 11;
      do
      {
        v22 = __ldrex(v21);
        v23 = v22 + 1;
      }
      while ( __strex(v23, v21) );
      __dmb(0xBu);
      v24 = v6[1];
      if ( !v24 )
        __brkdiv0();
      v25 = v23 % v24;
      if ( !v25 )
      {
        v26 = v6[2] | 0x40000000;
        v6[2] = v26;
        if ( (v26 & 4) != 0 )
          __debugbreak();
      }
      v27 = &v6[20 * v25 + 12];
      *v27 = *(_DWORD *)(v34 + 876);
      v27[1] = *(_DWORD *)(v34 + 880);
      v27[2] = v35;
      v27[3] = v4;
      v28 = RtlWalkFrameChain((int)&v6[20 * v25 + 16], 16, 0x300u);
      if ( v28 <= 3 )
        v29 = 0;
      else
        v29 = v28 - 3;
      v30 = RtlWalkFrameChain((int)&v27[v29 + 4], 16 - v29, 1u);
      memset(&v27[v30 + 4 + v29], 0, 4 * (16 - (v30 + v29)));
    }
LABEL_39:
    if ( v7 )
    {
      v31 = v6 + 3;
      v6[4] = 0;
      v32 = v6[10];
      __dmb(0xBu);
      do
        v33 = __ldrex(v31);
      while ( !v33 && __strex(1u, v31) );
      if ( v33 )
        ExpReleaseFastMutexContended(v6 + 3, v33);
      KfLowerIrql((unsigned __int8)v32);
      KeAbPostRelease((unsigned int)(v6 + 3));
    }
    result = (unsigned int *)ExDereferenceHandleDebugInfo(v36, v6);
  }
  return result;
}
