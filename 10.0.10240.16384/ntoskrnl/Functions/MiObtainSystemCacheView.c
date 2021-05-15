// MiObtainSystemCacheView 
 
int MiObtainSystemCacheView()
{
  int v0; // r2
  int v1; // r0
  unsigned int v2; // r0
  unsigned int v3; // r8
  int v4; // r4
  char v5; // r1
  int v6; // r5
  int v7; // r1
  int v8; // r2
  unsigned int v9; // r3
  int v10; // r6
  int v11; // r0
  unsigned int *v12; // r1
  int *v13; // r0
  _DWORD *v14; // r1
  _DWORD *v15; // r1
  unsigned int v17; // r7
  int v18; // r4
  char *v19; // r10
  int v20; // r8
  int v21; // r2
  int v22; // lr
  char *v23; // r7
  int v24; // t1
  unsigned int *v25; // r4
  int v26; // r0
  unsigned int v27; // r1
  unsigned int v28; // r4
  unsigned int *v29; // r2
  unsigned int v30; // r0
  int v31; // r0
  int v32; // r0
  int v33; // r0
  int v34; // r0
  int v35[3]; // [sp+0h] [bp-108h] BYREF
  unsigned int v36; // [sp+Ch] [bp-FCh]
  int v37; // [sp+10h] [bp-F8h]
  int v38; // [sp+14h] [bp-F4h]
  int v39; // [sp+1Ch] [bp-ECh]
  int v40; // [sp+20h] [bp-E8h] BYREF
  char v41; // [sp+24h] [bp-E4h]
  char v42; // [sp+25h] [bp-E3h]
  int v43; // [sp+28h] [bp-E0h]
  int v44; // [sp+2Ch] [bp-DCh]
  int v45; // [sp+30h] [bp-D8h]
  int v46; // [sp+34h] [bp-D4h]
  char var50[84]; // [sp+B8h] [bp-50h] BYREF

  if ( !MiChargeWsles(&dword_634E00, 64, 0) )
    JUMPOUT(0x53BA40);
  v44 = 0;
  v42 = 0;
  v46 = 0;
  v39 = 0;
  v40 = 0;
  v45 = 0;
  v41 = 0;
  v43 = 33;
  v38 = KfRaiseIrql(2);
  v1 = KeAcquireInStackQueuedSpinLockAtDpcLevel(&dword_6342D0, v35, v0, 6224);
  v36 = ((unsigned int)&dword_6342C4 >> 10) & 0x3FFFFC;
  v37 = 4194300;
  if ( (unsigned int)dword_6342C4 >> 12 != (int)(v36 - dword_6342CC - 0x40000000) >> 2 )
  {
LABEL_3:
    v2 = RemoveListHeadPte(&dword_6342C4);
    v3 = v2 + 12;
    v4 = (int)(((v2 >> 10) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2;
    v5 = byte_6338A0[v4];
    v6 = v2;
    v37 = v2;
    byte_6338A0[v4] = v5 + 1;
    v7 = *(_DWORD *)(v2 + 12) >> 12;
    if ( v7 )
    {
      if ( v7 == 1 )
      {
        v10 = 1;
LABEL_7:
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseQueuedSpinLockInstrumented(v35);
        }
        else
        {
          v11 = v35[0];
          if ( !v35[0] )
          {
            v12 = (unsigned int *)v35[1];
            __dmb(0xBu);
            do
              v13 = (int *)__ldrex(v12);
            while ( v13 == v35 && __strex(0, v12) );
            if ( v13 == v35 )
              goto LABEL_13;
            v11 = KxWaitForLockChainValid(v35);
          }
          v35[0] = 0;
          __dmb(0xBu);
          v29 = (unsigned int *)(v11 + 4);
          do
            v30 = __ldrex(v29);
          while ( __strex(v30 ^ 1, v29) );
        }
LABEL_13:
        if ( v44 )
        {
          MiFlushTbList(&v40);
          v22 = v39;
          if ( v39 )
          {
            v23 = var50;
            do
            {
              v24 = *(_DWORD *)v23;
              v23 += 4;
              v25 = (unsigned int *)(v24 + 12);
              v26 = *(_DWORD *)(v24 + 12);
              __dmb(0xBu);
              do
                v27 = __ldrex(v25);
              while ( v27 == v26 && __strex(v26 & 0xFFF, v25) );
              __dmb(0xBu);
              --v22;
            }
            while ( v22 );
          }
        }
        KfLowerIrql(v38);
        if ( v10 == 1 )
          MiWaitForSystemCacheViewFlush(v6);
        if ( (unsigned int)(v6 + 0x40000000) > 0x3FFFFF )
        {
          *(_DWORD *)v6 = 0;
        }
        else
        {
          __dmb(0xBu);
          *(_DWORD *)v6 = 0;
          if ( (unsigned int)(v6 + 1070596096) <= 0xFFF )
          {
            v31 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v31, (_DWORD *)(v31 + 4 * (v6 & 0xFFF)), 0);
          }
        }
        v14 = (_DWORD *)(v6 + 4);
        if ( (unsigned int)(v6 + 1073741828) > 0x3FFFFF )
        {
          *v14 = 0;
        }
        else
        {
          __dmb(0xBu);
          *v14 = 0;
          if ( (unsigned int)(v6 + 1070596100) <= 0xFFF )
          {
            v32 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v32, (_DWORD *)(v32 + 4 * ((unsigned __int16)v14 & 0xFFF)), 0);
          }
        }
        v15 = (_DWORD *)(v6 + 8);
        if ( (unsigned int)(v6 + 1073741832) > 0x3FFFFF )
        {
          *v15 = 0;
        }
        else
        {
          __dmb(0xBu);
          *v15 = 0;
          if ( (unsigned int)(v6 + 1070596104) <= 0xFFF )
          {
            v33 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v33, (_DWORD *)(v33 + 4 * ((unsigned __int16)v15 & 0xFFF)), 0);
          }
        }
        if ( v3 + 0x40000000 > 0x3FFFFF )
        {
          *(_DWORD *)v3 = 0;
        }
        else
        {
          __dmb(0xBu);
          *(_DWORD *)v3 = 0;
          if ( v3 + 1070596096 <= 0xFFF )
          {
            v34 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v34, (_DWORD *)(v34 + 4 * (v3 & 0xFFF)), 0);
          }
        }
        return v6;
      }
      __dmb(0xFu);
      v8 = KiTbFlushTimeStamp;
      __dmb(0xBu);
      v9 = (v8 - (*(_DWORD *)(v2 + 8) >> 12)) & 0xFFFFF;
      if ( v9 <= 2 && ((*(_DWORD *)(v2 + 8) & 0x1000) != 0 || v9 < 2) )
      {
        v17 = v36;
        v18 = v2;
        v19 = var50;
        v20 = 0;
        do
        {
          if ( v44 )
          {
            *(_DWORD *)v19 = v18;
            v19 += 4;
            ++v20;
          }
          MiInsertTbFlushEntry(&v40, v18 << 10, 64);
          *(_DWORD *)(v18 + 12) = *(_DWORD *)(v18 + 12) & 0xFFF | 0x1000;
          if ( v20 == 12 )
            break;
          v21 = *(_DWORD *)v18 >> 12;
          if ( v21 == (int)(v17 - dword_6342CC - 0x40000000) >> 2 )
            break;
          v18 = dword_6342CC + 4 * v21;
        }
        while ( (*(_DWORD *)(v18 + 12) & 0xFFFFF000) == 0x2000 );
        v6 = v37;
        v39 = v20;
        v3 = v37 + 12;
      }
    }
    v10 = 0;
    goto LABEL_7;
  }
  v28 = v36;
  while ( 1 )
  {
    v1 = MiExpandSystemCache(v1);
    if ( !v1 )
      return sub_53B7D4();
    if ( (unsigned int)dword_6342C4 >> 12 != (int)(v28 - dword_6342CC - 0x40000000) >> 2 )
      goto LABEL_3;
  }
}
