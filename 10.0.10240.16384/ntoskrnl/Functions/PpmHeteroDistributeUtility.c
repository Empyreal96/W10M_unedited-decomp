// PpmHeteroDistributeUtility 
 
int PpmHeteroDistributeUtility()
{
  unsigned int v0; // r7
  int *v1; // r0
  unsigned int v2; // r2
  int v3; // r8
  __int64 v4; // kr00_8
  int v5; // r10
  unsigned int v6; // r4
  unsigned int v7; // r2
  int v8; // r3
  int v9; // r2
  int v10; // r4
  int v11; // r5
  unsigned int v12; // r2
  int v13; // r3
  int v14; // r2
  int *v16; // [sp+4h] [bp-34h]
  int v17; // [sp+Ch] [bp-2Ch]
  unsigned int v18; // [sp+10h] [bp-28h]
  int v19; // [sp+14h] [bp-24h]

  PpmParkDistributeUtility();
  if ( PpmHeteroPolicy == 4 )
  {
    v0 = 0;
    v18 = 0;
    v1 = &PpmCurrentProfile[44 * dword_61EC0C];
    v16 = v1;
    v2 = PpmParkNumNodes;
    if ( PpmParkNumNodes )
    {
      v3 = 0;
      v19 = 0;
      do
      {
        v4 = *(_QWORD *)(v3 + PpmParkNodes + 16);
        v17 = v3 + PpmParkNodes;
        if ( ((unsigned int)v4 & ~HIDWORD(v4)) != 0 )
        {
          v5 = 0;
          v6 = *(_DWORD *)(v3 + PpmParkNodes + 24) & v4 & ~HIDWORD(v4);
          while ( v6 )
          {
            v7 = __clz(__rbit(v6));
            v6 &= ~(1 << v7);
            if ( v7 >= KeNumberProcessors_0 )
              v8 = 0;
            else
              v8 = (int)*(&KiProcessorBlock + v7);
            v9 = *(_DWORD *)(v8 + 3196);
            if ( v9 )
            {
              v5 = *((unsigned __int8 *)v1 + 201);
              *(_BYTE *)(v9 + 187) = v5;
              if ( (PoDebug & 0x40000) != 0 )
              {
                DbgPrint(
                  "PPM: PpmHeteroDistributeUtility()=> PpmState @ %p : Class1MinimumPerfSelection: %d%%\n",
                  (const void *)(v8 + 2944),
                  *(unsigned __int8 *)(v9 + 187));
                v1 = v16;
              }
            }
          }
          v3 = v19;
          v10 = 0;
          v11 = *(_DWORD *)(v17 + 12) & ~HIDWORD(v4);
          while ( v11 )
          {
            v12 = __clz(__rbit(v11));
            v11 &= ~(1 << v12);
            if ( v12 >= KeNumberProcessors_0 )
              v13 = 0;
            else
              v13 = (int)*(&KiProcessorBlock + v12);
            v14 = *(_DWORD *)(v13 + 3196);
            if ( v14 )
            {
              v10 = *((unsigned __int8 *)v1 + 200);
              *(_BYTE *)(v14 + 186) = v10;
              if ( (PoDebug & 0x40000) != 0 )
              {
                DbgPrint(
                  "PPM: PpmHeteroDistributeUtility()=> PpmState @ %p : Class0FloorPerfSelection: %d%%\n",
                  (const void *)(v13 + 2944),
                  *(unsigned __int8 *)(v14 + 186));
                v1 = v16;
              }
            }
          }
          PpmEventTraceHeteroDistributeUtility(v17, v10, v5);
          v0 = v18;
          v1 = v16;
          v2 = PpmParkNumNodes;
        }
        ++v0;
        v3 += 88;
        v18 = v0;
        v19 = v3;
      }
      while ( v0 < v2 );
    }
  }
  return 1;
}
