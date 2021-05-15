// PoInitiateProcessorWake 
 
int __fastcall PoInitiateProcessorWake(unsigned int a1)
{
  int v2; // r9
  int v3; // r5
  _DWORD *v4; // r7
  int v5; // r8
  int v6; // r4
  unsigned int v7; // r6
  unsigned int v8; // r0
  unsigned int v9; // r1
  int v10; // r4
  unsigned int v11; // r6
  unsigned int v12; // r10
  unsigned __int64 *v13; // r6
  int v14; // r6
  unsigned int v15; // r4
  unsigned int v16; // r0
  unsigned int v17; // r2
  int v18; // r2
  int v19; // r3
  unsigned __int64 v20; // kr00_8
  unsigned __int64 v21; // kr08_8
  unsigned __int64 v22; // [sp+8h] [bp-68h] BYREF
  unsigned __int64 v23; // [sp+10h] [bp-60h]
  _DWORD v24[2]; // [sp+18h] [bp-58h] BYREF
  _DWORD v25[8]; // [sp+20h] [bp-50h] BYREF
  _DWORD v26[12]; // [sp+40h] [bp-30h] BYREF

  if ( a1 >= KeNumberProcessors_0 )
    return sub_51C98C();
  v2 = (int)*(&KiProcessorBlock + a1);
  v3 = *(_DWORD *)(v2 + 2944);
  v4 = (_DWORD *)(v2 + 3000);
  v5 = *(_DWORD *)(v3 + 120);
  v6 = HIBYTE(*(_DWORD *)(v2 + 3000));
  if ( v6 != 1 )
  {
    while ( v6 != 8 && v6 && v6 != 7 )
    {
      switch ( v6 )
      {
        case 2:
          v6 = HIBYTE(*v4);
          break;
        case 4:
        case 6:
          __pld(v4);
          v7 = *v4;
          if ( HIBYTE(*v4) == v6 )
          {
            do
            {
              v8 = v7;
              __dmb(0xBu);
              do
                v9 = __ldrex(v4);
              while ( v9 == v7 && __strex(v7 & 0xFFFFFF | 0x8000000, v4) );
              v7 = v9;
              __dmb(0xBu);
            }
            while ( v9 != v8 && HIBYTE(v9) == v6 );
          }
          if ( HIBYTE(v7) == v6 )
          {
            if ( !*(_BYTE *)(v2 + 2985) )
              return 1;
            memset(v25, 0, sizeof(v25));
            v10 = v25[5];
            v12 = v25[0];
            v11 = v25[1];
            v23 = *(_QWORD *)&PopIdleTransitionTimeout;
            while ( !(*(int (__fastcall **)(int))(v3 + 112))(v5) )
            {
              if ( HIBYTE(*v4) != 8 )
                return 0;
              if ( v12 | v11 )
              {
                if ( ++v10 == 1000 )
                {
                  v10 = 0;
                  KeQueryPerformanceCounter(&v22, 0);
                  if ( v22 - __PAIR64__(v11, v12) > v23 )
                  {
                    if ( v2 )
                      KeBugCheck2(160, 1793, *(_DWORD *)(v2 + 2988), v2, *(_DWORD *)(v2 + 20), 0);
                    KeBugCheckEx(160, 1796, 0);
                  }
                }
                __dmb(0xAu);
                __yield();
              }
              else
              {
                KeQueryPerformanceCounter(v24, 0);
                v12 = v24[0];
                v11 = v24[1];
                __dmb(0xAu);
                __yield();
              }
            }
            v13 = (unsigned __int64 *)(v3 + 40);
            if ( (*(_DWORD *)(v3 + 40) & *(_DWORD *)(v3 + 44)) == -1 )
            {
              KeQueryPerformanceCounter(&v22, 0);
              __dmb(0xBu);
              v20 = v22;
              do
                v21 = __ldrexd(v13);
              while ( __strexd(v20, v13) );
              __dmb(0xBu);
            }
            return (*(int (__fastcall **)(int))(v3 + 116))(v5);
          }
          v6 = HIBYTE(v7);
          break;
        case 5:
          v14 = 0;
          __pld(v4);
          v15 = *v4;
          if ( (*v4 & 0xFF000000) == 83886080 )
          {
            do
            {
              v16 = v15;
              __dmb(0xBu);
              do
                v17 = __ldrex(v4);
              while ( v17 == v15 && __strex(v15 & 0xFFFFFF | 0x7000000, v4) );
              v15 = v17;
              __dmb(0xBu);
            }
            while ( v17 != v16 && (v17 & 0xFF000000) == 83886080 );
          }
          v6 = HIBYTE(v15);
          if ( v6 == 5 )
          {
            v18 = *(_DWORD *)(v3 + 60);
            v19 = *(_DWORD *)(v3 + 64);
            v26[0] = *(_DWORD *)(v3 + 56);
            v26[1] = v18;
            v26[2] = v19;
            if ( v19 )
              HalRequestIpi(0, v26);
            return v14;
          }
          break;
      }
      __dmb(0xAu);
      __yield();
      if ( v6 == 1 )
        return 0;
    }
  }
  return 0;
}
