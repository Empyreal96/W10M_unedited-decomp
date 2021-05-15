// PpmParkDistributeUtility 
 
int PpmParkDistributeUtility()
{
  int v0; // r10
  int v1; // r6
  unsigned int v2; // lr
  unsigned int v3; // r4
  unsigned int v4; // r0
  unsigned int v5; // r5
  int v6; // r7
  unsigned int v7; // r2
  unsigned int v8; // r1
  unsigned int v10; // r2
  int v11; // r3
  unsigned int v12; // r4
  unsigned int v13; // r8
  int v14; // r0
  unsigned int v15; // r5
  unsigned int v16; // r4
  unsigned int v17; // r2
  unsigned int v18; // r1
  _DWORD *v19; // r3
  _DWORD *v20; // r0
  unsigned int v21; // r1
  unsigned int v22; // r3
  unsigned int v23; // r2
  int v24; // r3
  unsigned int v25; // r1
  unsigned int v26; // r2
  int v27; // r3
  int v28; // [sp+0h] [bp-30h]
  BOOL v29; // [sp+4h] [bp-2Ch]
  int v30; // [sp+Ch] [bp-24h]
  int v31; // [sp+10h] [bp-20h]

  v29 = LOBYTE(PpmCurrentProfile[44 * dword_61EC0C + 26]) != 0;
  v0 = PpmParkNumNodes;
  v30 = PpmParkNumNodes;
  if ( !PpmParkNumNodes )
    return 1;
  v1 = PpmParkNodes;
  v2 = KeNumberProcessors_0;
  v31 = PpmParkNodes;
  v28 = KeNumberProcessors_0;
  do
  {
    if ( !*(_BYTE *)(v1 + 75) )
    {
      v3 = *(_DWORD *)(v1 + 20);
      v4 = 0;
      v5 = 0;
      v6 = *(_DWORD *)(v1 + 8) ^ v3;
      v7 = v6;
      while ( v7 )
      {
        v8 = __clz(__rbit(v7));
        v7 &= ~(1 << v8);
        if ( v8 >= v2 )
          return sub_540698(v4);
        v5 += *((_DWORD *)*(&KiProcessorBlock + v8) + 810);
        ++v4;
      }
      while ( v3 )
      {
        v10 = __clz(__rbit(v3));
        v3 &= ~(1 << v10);
        if ( v10 >= v2 )
          v11 = 0;
        else
          v11 = (int)*(&KiProcessorBlock + v10);
        v5 += *(_DWORD *)(v11 + 3240) - *(_DWORD *)(v11 + 3244);
      }
      if ( v4 <= 1 )
        v4 = 1;
      v12 = *(unsigned __int8 *)(v1 + 78);
      if ( v12 >= v4 )
        v12 = v4;
      if ( v12 <= 1 )
        v12 = 1;
      v13 = v5 / v4;
      v14 = v5 / v12;
      v15 = v28;
      v16 = v14;
      v17 = v6;
      while ( v17 )
      {
        v18 = __clz(__rbit(v17));
        v17 &= ~(1 << v18);
        if ( v18 >= v15 )
          v19 = 0;
        else
          v19 = *(&KiProcessorBlock + v18);
        v20 = v19 + 736;
        v21 = v19[810];
        if ( v13 <= v21 )
        {
          v6 ^= v19[262];
          if ( v16 > v21 )
          {
            v19[810] = v16;
            v15 = KeNumberProcessors_0;
          }
          else if ( v29 )
          {
            v22 = v19[811];
            if ( v22 <= v16 )
              v22 = v16;
            v20[74] = v22;
            v15 = KeNumberProcessors_0;
          }
        }
      }
      v0 = v30;
      while ( v6 )
      {
        v23 = __clz(__rbit(v6));
        v6 &= ~(1 << v23);
        if ( v23 >= v15 )
          v24 = 0;
        else
          v24 = (int)*(&KiProcessorBlock + v23);
        *(_DWORD *)(v24 + 3240) = v13;
        v15 = KeNumberProcessors_0;
      }
      v28 = v15;
      v1 = v31;
      v2 = v15;
      if ( v29 )
      {
        v25 = *(_DWORD *)(v31 + 20);
        while ( v25 )
        {
          v26 = __clz(__rbit(v25));
          v25 &= ~(1 << v26);
          if ( v26 >= v2 )
            v27 = 0;
          else
            v27 = (int)*(&KiProcessorBlock + v26);
          *(_DWORD *)(v27 + 3240) = *(_DWORD *)(v27 + 3244);
          v2 = KeNumberProcessors_0;
        }
        v0 = v30;
        v28 = v2;
      }
    }
    v1 += 88;
    v30 = --v0;
    v31 = v1;
  }
  while ( v0 );
  return 1;
}
