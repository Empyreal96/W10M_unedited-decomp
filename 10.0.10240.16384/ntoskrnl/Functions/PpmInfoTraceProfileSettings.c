// PpmInfoTraceProfileSettings 
 
int PpmInfoTraceProfileSettings()
{
  int *v0; // r8
  int i; // r7
  char **v2; // r6
  char v3; // r2
  unsigned int v4; // r10
  int v5; // lr
  char *v6; // r5
  int v7; // r1
  int v8; // r2
  int v9; // r3
  unsigned int v10; // r4
  int result; // r0
  int *v12; // r7
  int *v13; // r5
  int v14; // r9
  int v15; // [sp+10h] [bp-40h]
  int v16; // [sp+14h] [bp-3Ch]
  int v17; // [sp+18h] [bp-38h]
  int v18; // [sp+1Ch] [bp-34h]
  _DWORD v19[3]; // [sp+20h] [bp-30h] BYREF
  int v20; // [sp+2Ch] [bp-24h]

  v0 = &PpmDefaultProfile;
  for ( i = 0; ; i = (unsigned __int8)(v15 + 1) )
  {
    v2 = &PpmPolicyConfigTable;
    v17 = 42;
    v15 = i;
    do
    {
      v3 = *((_BYTE *)v2 + 24);
      v4 = 1;
      v5 = 1 << (v3 - 32);
      v18 = 1 << v3;
      v16 = v5;
      if ( (*((_BYTE *)v2 + 25) & 4) != 0 )
        v4 = 2;
      v6 = v2[1];
      v7 = *((_DWORD *)v6 + 1);
      v8 = *((_DWORD *)v6 + 2);
      v9 = *((_DWORD *)v6 + 3);
      v19[0] = *(_DWORD *)v6;
      v19[1] = v7;
      v19[2] = v8;
      v20 = v9;
      v10 = 0;
      LOBYTE(result) = HIBYTE(v20);
      v12 = v0 + 8;
      v13 = v0 + 52;
      do
      {
        if ( v12[2 * v10 + 1] & v5 | v12[2 * v10] & v18 )
        {
          PpmEventTraceProfileSetting(
            *((unsigned __int8 *)v0 + 4),
            (int)*v2,
            (int)v19,
            (unsigned __int8)v10,
            (int)&v2[4][(_DWORD)v2[5] * v10 + (_DWORD)v12],
            (int)v2[5],
            0,
            1);
          v5 = v16;
          LOBYTE(result) = HIBYTE(v20);
        }
        if ( v13[2 * v10 + 1] & v5 | v13[2 * v10] & v18 )
        {
          PpmEventTraceProfileSetting(
            *((unsigned __int8 *)v0 + 4),
            (int)*v2,
            (int)v19,
            (unsigned __int8)v10,
            (int)&v2[4][(_DWORD)v2[5] * v10 + (_DWORD)v13],
            (int)v2[5],
            1,
            1);
          v5 = v16;
          LOBYTE(result) = HIBYTE(v20);
        }
        result = (unsigned __int8)(result + 1);
        ++v10;
        HIBYTE(v20) = result;
      }
      while ( v10 < v4 );
      v14 = v17;
      v2 += 7;
      --v17;
    }
    while ( v14 != 1 );
    if ( v15 == (unsigned __int8)PpmProfileCount )
      break;
    v0 = (int *)(PpmProfiles + 424 * v15);
  }
  return result;
}
