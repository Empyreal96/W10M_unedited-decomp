// MiComputeNodeMemory 
 
void __fastcall MiComputeNodeMemory(int a1, int a2, int a3, int a4)
{
  unsigned int v4; // r8
  unsigned int v5; // r9
  int v6; // r2
  int v7; // r7
  int v8; // r10
  int v9; // r1
  unsigned __int8 *i; // r4
  int v11; // r6
  int v12; // r5
  unsigned __int8 *v13; // r0
  int v14; // r6
  int v15; // r0
  unsigned int v16; // r2
  unsigned int v17; // r1
  int v18; // r0
  __int16 v19; // r3
  int v20; // [sp+0h] [bp-28h]
  int v21; // [sp+4h] [bp-24h]
  int v22; // [sp+8h] [bp-20h]

  v20 = a2;
  v21 = a3;
  v22 = a4;
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = 0;
  v6 = dword_63F720;
  v7 = dword_63F718;
  v8 = *(_DWORD *)dword_63F720;
  v21 = dword_63F720;
  v9 = v8 + 1;
  if ( KeNumberNodes )
  {
    for ( i = (unsigned __int8 *)(dword_63F718 + 92); ; i += 104 )
    {
      v11 = 0;
      v20 = 0;
      if ( v8 )
      {
        v12 = v6;
        v13 = (unsigned __int8 *)(v6 + 8 * v9);
        v14 = v8;
        do
        {
          if ( *v13 == v5 )
            *(&v20 + v13[1]) += *(_DWORD *)(v12 + 12);
          v13 += 2;
          v12 += 8;
          --v14;
        }
        while ( v14 );
        v11 = v20;
      }
      --*(_WORD *)(v4 + 310);
      v15 = KeAbPreAcquire((unsigned int)i, 0, 0);
      do
        v16 = __ldrex(i);
      while ( __strex(v16 | 1, i) );
      __dmb(0xBu);
      if ( (v16 & 1) != 0 )
        break;
      if ( v15 )
        *(_BYTE *)(v15 + 14) |= 1u;
      *(_DWORD *)(v7 + 64) = v11;
      *(_DWORD *)(v7 + 68) = v11;
      __dmb(0xBu);
      do
        v17 = __ldrex((unsigned int *)i);
      while ( __strex(v17 - 1, (unsigned int *)i) );
      if ( (v17 & 2) != 0 && (v17 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)i);
      v18 = KeAbPostRelease((unsigned int)i);
      v19 = *(_WORD *)(v4 + 310) + 1;
      *(_WORD *)(v4 + 310) = v19;
      if ( !v19 && *(_DWORD *)(v4 + 100) != v4 + 100 )
        KiCheckForKernelApcDelivery(v18);
      ++v5;
      v6 = v21;
      v7 += 104;
      v9 = v8 + 1;
      if ( v5 >= (unsigned __int16)KeNumberNodes )
        return;
    }
    sub_80FB58(v15);
  }
}
