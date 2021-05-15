// MiReplicatePteChange 
 
int __fastcall MiReplicatePteChange(unsigned int a1, unsigned int a2)
{
  int v2; // r9
  unsigned int v3; // r7
  int *v4; // r8
  int v5; // r3
  int v6; // r6
  int *v7; // r5
  int *v8; // r10
  int *v9; // r5
  int *v10; // r4
  int v11; // r3
  int v13; // r0
  _DWORD *v14; // r6
  int v15; // lr
  unsigned int v16; // r9
  unsigned int v17; // r8
  unsigned int v18; // r10
  int v19; // r7
  _DWORD *v20; // r1
  int v21; // r10
  int *v22; // r6
  int v23; // r0
  unsigned int v24; // r3
  int v25; // r9
  unsigned int v26; // r8
  unsigned int v27; // r4
  unsigned int v28; // r7
  unsigned int *v29; // r2
  unsigned int v30; // r0
  unsigned int v31; // [sp+0h] [bp-48h]
  int *v32; // [sp+4h] [bp-44h]
  int v33; // [sp+8h] [bp-40h]
  unsigned int v34; // [sp+Ch] [bp-3Ch]
  int *i; // [sp+10h] [bp-38h]
  unsigned int v36; // [sp+14h] [bp-34h]
  int v37; // [sp+18h] [bp-30h]
  int v38[10]; // [sp+20h] [bp-28h] BYREF

  __dmb(0xBu);
  v38[0] = 0;
  v38[1] = 0;
  v38[2] = 0;
  v2 = ((a2 >> 10) & 0x3FFFFC) - 0x40000000;
  v3 = ((a1 >> 10) & 0x3FFFFC) - 0x40000000;
  v31 = v2;
  v34 = v3;
  v4 = *(int **)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  for ( i = v4; a1 >= 0xC0000000; a1 <<= 10 )
  {
    if ( a1 > 0xC03FFFFF )
      break;
  }
  if ( a1 >= dword_63389C
    && ((v5 = *((unsigned __int8 *)&MiState[2423]
              + ((int)(((a1 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
         v5 == 11)
     || v5 == 1) )
  {
    v6 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324);
    v7 = (int *)(v6 + 16);
    v8 = (int *)(v6 + 16);
  }
  else
  {
    v6 = 0;
    v7 = &dword_6337D0;
    v8 = &dword_6337D0;
  }
  v32 = v8;
  v33 = v6;
  KeAcquireInStackQueuedSpinLock((unsigned int *)&dword_634980, (unsigned int)v38);
  if ( v6 && (*(_BYTE *)(v6 + 3361) & 6) == 2 )
  {
    v21 = PsInitialSystemProcess;
    v22 = (int *)v3;
    v23 = MiMapPageInHyperSpaceWorker(*(_DWORD *)(PsInitialSystemProcess + 24) >> 12, 0, 0x80000000);
    v24 = v2 - v3 + 4;
    v25 = v23;
    v26 = 1;
    if ( v3 > v31 )
      v27 = 0;
    else
      v27 = v24 >> 2;
    if ( v27 )
    {
      v28 = (v3 & 0xFFF) + v23 - v3;
      do
      {
        MiArmWritePdeOtherProcess(v21, (int *)((char *)v22 + v28), *v22, v24);
        ++v26;
        ++v22;
      }
      while ( v26 <= v27 );
      v3 = v34;
    }
    MiUnmapPageInHyperSpaceWorker(v25, 17, 0x80000000);
    v8 = v32;
    v6 = v33;
    v4 = i;
    v2 = v31;
  }
  v9 = (int *)*v7;
  if ( v9 != v8 )
  {
    v36 = v2 - v3 + 4;
    do
    {
      if ( v6 )
        v10 = v9 - 58;
      else
        v10 = v9 - 155;
      v11 = v10[48];
      if ( (v11 & 0x800000) == 0 )
      {
        if ( (v11 & 0xC00) == 0 )
          return sub_53AB70();
        if ( (v11 & 0x80) != 0 )
        {
          __dmb(0xBu);
          v29 = (unsigned int *)(v10 + 48);
          do
            v30 = __ldrex(v29);
          while ( __strex(v30 | 0x800000, v29) );
          __dmb(0xBu);
        }
        else if ( v10 != v4 )
        {
          v13 = MiMapPageInHyperSpaceWorker((unsigned int)v10[6] >> 12, 0, 0x80000000);
          v14 = (_DWORD *)((v3 & 0xFFF) + v13);
          v15 = v13;
          v37 = v13;
          v16 = 1;
          if ( v3 > v31 )
            v17 = 0;
          else
            v17 = v36 >> 2;
          if ( v17 )
          {
            v18 = v3 - (_DWORD)v14;
            do
            {
              v19 = *(_DWORD *)((char *)v14 + v18);
              v20 = (_DWORD *)(v10[8] + 4 * ((unsigned __int16)v14 & 0xFFF));
              if ( (v19 & 2) != 0 )
              {
                if ( (v19 & 0x400) != 0 )
                  MiArmWriteLargePageHardwarePde();
                else
                  MiArmWriteSimpleHardwarePde();
              }
              else
              {
                *v20 = 0;
                v20[1] = 0;
                v20[2] = 0;
                v20[3] = 0;
              }
              __dmb(0xBu);
              ++v16;
              *v14++ = v19;
            }
            while ( v16 <= v17 );
            v15 = v37;
            v3 = v34;
            v8 = v32;
          }
          MiUnmapPageInHyperSpaceWorker(v15, 17, 0x80000000);
          v6 = v33;
        }
      }
      v9 = (int *)*v9;
      v4 = i;
    }
    while ( v9 != v8 );
  }
  return KeReleaseInStackQueuedSpinLock((int)v38);
}
