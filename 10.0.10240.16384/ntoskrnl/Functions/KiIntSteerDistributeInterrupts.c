// KiIntSteerDistributeInterrupts 
 
int KiIntSteerDistributeInterrupts()
{
  int v0; // r1
  int v1; // r4
  int v2; // r2
  int v3; // r0
  int v4; // r4
  int v5; // r1
  int v7; // r0
  unsigned int v8; // r2
  int v9; // r2
  int v10; // r3
  int v11; // r1
  unsigned int v12; // r2
  int v13; // r2
  int v14; // r3
  char v15; // [sp+0h] [bp-28h]
  char v16; // [sp+0h] [bp-28h]
  __int16 v17; // [sp+8h] [bp-20h] BYREF
  __int16 v18; // [sp+Ah] [bp-1Eh]
  int v19; // [sp+Ch] [bp-1Ch]
  int v20; // [sp+10h] [bp-18h]

  v19 = 0;
  v0 = KiIntTrackRootList;
  v1 = 0;
  v17 = 1;
  v18 = 1;
  v20 = 0;
  if ( (int *)KiIntTrackRootList != &KiIntTrackRootList )
  {
    do
    {
      if ( *(_BYTE *)(v0 + 100) )
      {
        v2 = *(_DWORD *)(v0 + 132);
        v3 = *(_DWORD *)(v0 + 120);
        if ( v2 != v3 && *(_DWORD *)(v0 + 96) == 1 )
        {
          v7 = v2 & ~v3;
          while ( v7 )
          {
            v8 = __clz(__rbit(v7));
            v7 &= ~(1 << v8);
            v15 = v8;
            if ( v8 >= KeNumberProcessors_0 )
              v9 = 0;
            else
              v9 = (int)*(&KiProcessorBlock + v8);
            v10 = *(_DWORD *)(v9 + 3272) + 1;
            *(_DWORD *)(v9 + 3272) = v10;
            if ( v10 == 1 )
            {
              v1 = (1 << v15) | v20;
              v20 = v1;
            }
            else
            {
              v1 = v20;
            }
          }
        }
      }
      v0 = *(_DWORD *)v0;
    }
    while ( (int *)v0 != &KiIntTrackRootList );
    if ( v1 )
      HalRequestIpi(0, &v17);
  }
  v4 = KiIntTrackRootList;
  v5 = 0;
  v17 = 1;
  v18 = 1;
  v19 = 0;
  v20 = 0;
  if ( (int *)KiIntTrackRootList == &KiIntTrackRootList )
    return sub_541204();
  do
  {
    if ( *(_BYTE *)(v4 + 100) && *(_DWORD *)(v4 + 132) != *(_DWORD *)(v4 + 120) )
    {
      KiIntSteerSetDestination(v4, v4 + 132);
      if ( *(_DWORD *)(v4 + 96) == 1 )
      {
        v11 = *(_DWORD *)(v4 + 120) & ~*(_DWORD *)(v4 + 132);
        while ( v11 )
        {
          v12 = __clz(__rbit(v11));
          v11 &= ~(1 << v12);
          v16 = v12;
          if ( v12 >= KeNumberProcessors_0 )
            v13 = 0;
          else
            v13 = (int)*(&KiProcessorBlock + v12);
          v14 = *(_DWORD *)(v13 + 3272) - 1;
          *(_DWORD *)(v13 + 3272) = v14;
          if ( !v14 )
            v20 |= 1 << v16;
        }
      }
      *(_WORD *)(v4 + 124) = *(_WORD *)(v4 + 136);
      *(_DWORD *)(v4 + 120) = *(_DWORD *)(v4 + 132);
      v5 = v20;
    }
    v4 = *(_DWORD *)v4;
  }
  while ( (int *)v4 != &KiIntTrackRootList );
  if ( v5 )
    HalRequestIpi(0, &v17);
  return 0;
}
