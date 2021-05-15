// PpmParkCalculateUnparkCount 
 
int PpmParkCalculateUnparkCount()
{
  int *v0; // r3
  int v1; // r0
  unsigned int v2; // lr
  int v3; // r10
  int v4; // r5
  unsigned __int16 v5; // r9
  int v6; // r4
  unsigned int v7; // r8
  int v8; // r3
  unsigned __int8 v9; // r7
  int v10; // r0
  unsigned int v11; // r1
  unsigned int v12; // r6
  unsigned int v13; // r5
  unsigned int v14; // r2
  bool v15; // cc
  unsigned int v17; // [sp+0h] [bp-48h]
  unsigned int v18; // [sp+4h] [bp-44h]
  unsigned __int16 v19; // [sp+8h] [bp-40h]
  unsigned int v20; // [sp+Ch] [bp-3Ch]
  unsigned int v21; // [sp+10h] [bp-38h]
  int v22; // [sp+14h] [bp-34h]
  int v23; // [sp+18h] [bp-30h]
  int v24; // [sp+1Ch] [bp-2Ch]
  int v25; // [sp+20h] [bp-28h]
  int v26; // [sp+24h] [bp-24h]

  if ( !PpmIsParkingEnabled )
    return 1;
  v0 = &PpmCurrentProfile[44 * dword_61EC0C];
  v22 = *((unsigned __int8 *)v0 + 110);
  v17 = v0[29];
  v23 = *((unsigned __int8 *)v0 + 109);
  v18 = v0[28];
  v21 = *((unsigned __int8 *)v0 + 107);
  if ( PpmCheckCurrentPipelineId == 5 )
  {
    v17 = 0;
    v18 = 0;
  }
  v1 = 0;
  v2 = PpmParkNumNodes;
  v25 = PpmParkNumNodes;
  if ( !PpmParkNumNodes )
    return 1;
  v3 = PpmParkNodes;
  v4 = (unsigned __int8)PpmParkUnparkCores;
  v5 = 0;
  v19 = 0;
  v20 = (unsigned __int8)PpmParkGranularity;
  v26 = PpmParkNodes;
  v24 = (unsigned __int8)PpmParkUnparkCores;
  while ( 1 )
  {
    v6 = v3 + 88 * v1;
    if ( (*(_BYTE *)(v6 + 82) & 1) == 0 )
      break;
LABEL_22:
    v1 = ++v5;
    v19 = v5;
    if ( v5 >= v2 )
      return 1;
  }
  v7 = *(_DWORD *)v6 + 1;
  v8 = 0;
  *(_DWORD *)v6 = v7;
  v9 = 0;
  while ( 1 )
  {
    v10 = v8 + v6;
    v11 = *(unsigned __int8 *)(v8 + v6 + 64);
    if ( *(_BYTE *)(v8 + v6 + 64) )
    {
      if ( ((1 << (v8 + 1)) & *(unsigned __int8 *)(v6 + 82)) == 0 )
        break;
    }
LABEL_20:
    v8 = ++v9;
    if ( v9 >= 2u )
    {
      v2 = v25;
      v3 = v26;
      v5 = v19;
      goto LABEL_22;
    }
  }
  if ( v4 )
    v12 = 1;
  else
    v12 = v20;
  v13 = *(unsigned __int8 *)(v6 + 76);
  if ( v13 < v11 && *(unsigned __int8 *)(v6 + 77) > v21 )
    v13 = (unsigned __int8)(v13 + 1);
  v14 = *(unsigned __int8 *)(v10 + 74);
  v15 = v14 > v13;
  if ( v14 >= v13 )
    goto LABEL_16;
  if ( v7 < v17 || v14 >= v11 )
  {
    v15 = v14 > v13;
LABEL_16:
    if ( !v15 || v14 <= v12 || v7 < v18 )
    {
LABEL_17:
      if ( v14 >= v11 )
        LOBYTE(v14) = v11;
      v4 = v24;
      *(_BYTE *)(v10 + 74) = v14;
      goto LABEL_20;
    }
    *(_DWORD *)v6 = 0;
    if ( v23 )
      JUMPOUT(0x5406DA);
LABEL_32:
    v14 = v13;
    goto LABEL_17;
  }
  *(_DWORD *)v6 = 0;
  if ( !v22 )
    goto LABEL_32;
  return sub_5406B0();
}
