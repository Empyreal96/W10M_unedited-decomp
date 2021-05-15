// MiZeroInParallelWorker 
 
int __fastcall MiZeroInParallelWorker(_DWORD *a1)
{
  unsigned int *v1; // r6
  int v2; // r5
  _DWORD *v3; // r8
  int v4; // r4
  int v5; // r7
  unsigned int v6; // r8
  unsigned int *v7; // r2
  unsigned int v8; // r1
  unsigned int v9; // r1
  unsigned int v11; // r2
  unsigned int v12; // r2
  unsigned int v13; // r10
  unsigned int v14; // r4
  int v15; // r0
  int v16; // r9
  unsigned int v17; // r5
  unsigned int v18; // r0
  int v19; // r3
  int v20; // r9
  unsigned int v21; // r3
  int v22; // r4
  unsigned int v23; // r3
  int v24; // r0
  int v25; // [sp+0h] [bp-48h]
  int v26; // [sp+8h] [bp-40h]
  int v27; // [sp+Ch] [bp-3Ch]
  unsigned int v28; // [sp+10h] [bp-38h]
  int v29; // [sp+14h] [bp-34h]
  unsigned int *v30; // [sp+18h] [bp-30h]
  int v31; // [sp+1Ch] [bp-2Ch]

  v1 = (unsigned int *)a1[3];
  v2 = dword_633818;
  v3 = a1;
  v26 = dword_633818;
  v27 = a1[1];
  v30 = v1;
  v4 = __mrc(15, 0, 13, 0, 3);
  v29 = v4;
  v5 = KeSetPriorityThread(v4 & 0xFFFFFFC0, *a1);
  if ( v2 )
  {
    v6 = 0;
    while ( 1 )
    {
      if ( !*v1 )
      {
        do
        {
          v11 = __ldrex(v1);
          v12 = v11 + 1;
        }
        while ( __strex(v12, v1) );
        __dmb(0xBu);
        if ( v12 == 1 )
        {
          if ( v1[1] != -1 )
            return sub_514274();
          v13 = v1[3];
          if ( !v6 )
          {
            v22 = MiMakeProtectionPfnCompatible(4, v1[3]);
            v6 = (MmProtectToPteMask[v22] | MiDetermineUserGlobalPteMask(0)) & 0x1ED | 0xFFFFF012;
          }
          do
          {
            v14 = v1[2];
            v25 = v14;
            if ( v14 > 0x100 )
            {
              v14 = 256;
              v25 = 256;
            }
            while ( 1 )
            {
              v15 = MiReservePtes(&dword_634D58);
              v16 = v15;
              v31 = v15;
              if ( v15 )
                break;
              v14 >>= 1;
              v25 = v14;
              if ( !v14 )
              {
                MiZeroPhysicalPage((int)(v13 - MmPfnDatabase) / 24, 3, *(unsigned __int8 *)(v13 + 18) >> 6);
                v23 = *(_DWORD *)v13;
                *(_DWORD *)v13 = v27;
                v13 = v23;
                --v1[2];
                goto LABEL_32;
              }
            }
            v17 = v15;
            if ( v14 )
            {
              v18 = v14;
              v28 = v14;
              do
              {
                v6 = v6 & 0xFFF | (((int)(v13 - MmPfnDatabase) / 24) << 12);
                if ( v17 + 0x40000000 > 0x3FFFFF )
                {
                  *(_DWORD *)v17 = v6;
                }
                else
                {
                  v19 = *(_DWORD *)v17;
                  v20 = 0;
                  __dmb(0xBu);
                  *(_DWORD *)v17 = v6;
                  if ( (v19 & 2) == 0 && (v6 & 2) != 0 )
                    v20 = 1;
                  if ( v17 >= 0xC0300000 && v17 <= 0xC0300FFF )
                  {
                    v24 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
                    MiArmWriteConvertedHardwarePde(v24, v24 + 4 * (v17 & 0xFFF), v6);
                    v18 = v28;
                  }
                  if ( v20 == 1 )
                  {
                    __dsb(0xFu);
                    __isb(0xFu);
                  }
                }
                v21 = *(_DWORD *)v13;
                v17 += 4;
                --v18;
                *(_DWORD *)v13 = v27;
                v13 = v21;
                v28 = v18;
              }
              while ( v18 );
              v14 = v25;
              v1 = v30;
              v16 = v31;
            }
            v1[2] -= v14;
            KeZeroPages((_DWORD *)(v16 << 10), v14 << 12);
            MiReleasePtes(&dword_634D58, v16, v14);
LABEL_32:
            ;
          }
          while ( v13 != 0xFFFFF );
          v4 = v29;
          v2 = v26;
        }
      }
      v1 += 4;
      v26 = --v2;
      v30 = v1;
      if ( !v2 )
      {
        v3 = a1;
        break;
      }
    }
  }
  __dmb(0xBu);
  v7 = v3 + 2;
  do
  {
    v8 = __ldrex(v7);
    v9 = v8 - 1;
  }
  while ( __strex(v9, v7) );
  if ( !v9 )
    KeSignalGate(v3 + 4, 1, v7);
  return KeSetPriorityThread(v4 & 0xFFFFFFC0, v5);
}
