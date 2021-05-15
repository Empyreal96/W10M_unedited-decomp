// PopCalculateIdleInformation 
 
void __fastcall PopCalculateIdleInformation(int a1)
{
  int v1; // r4
  int v2; // r2
  unsigned int v3; // r5
  unsigned int v4; // r0
  unsigned int v5; // r1
  unsigned int v6; // r6
  __int64 v7; // r8
  int v8; // r10
  int v9; // r7
  unsigned int v10; // r4
  __int64 v11; // r0
  __int64 v12; // r0
  unsigned int v13; // kr08_4
  __int64 v14; // r0
  unsigned int v15; // [sp+0h] [bp-30h]
  int v16; // [sp+4h] [bp-2Ch]
  int v17; // [sp+8h] [bp-28h]
  int v18; // [sp+Ch] [bp-24h]

  v1 = a1;
  if ( PpmPlatformStates )
  {
    v2 = *(_DWORD *)(PpmPlatformStates + 32);
    v3 = *(_DWORD *)(v2 + 4);
    v4 = 0;
    v5 = 0;
    v6 = 0;
    v15 = 0;
    v16 = dword_635500;
    v7 = 0i64;
    v8 = 0;
    if ( v3 )
    {
      v9 = v2 + 24;
      v10 = 0;
      do
      {
        v11 = *(_QWORD *)(v9 + 32);
        v17 = *(_DWORD *)(v9 + 36);
        v18 = v11;
        LODWORD(v12) = PpmConvertTimeTo(v11, SHIDWORD(v11));
        v13 = v10 + v12;
        v4 = (__PAIR64__(v15, v10) + v12) >> 32;
        v10 = v13;
        v15 = v4;
        if ( v6 == v16 && v16 != -1 )
        {
          LODWORD(v14) = PpmConvertTimeTo(v18, v17);
          v8 = *(_DWORD *)(v9 + 8);
          v7 = v14;
          v4 = v15;
        }
        ++v6;
        v9 += 992;
      }
      while ( v6 < v3 );
      v5 = v13;
      v1 = a1;
    }
    *(_DWORD *)v1 = v5;
    *(_DWORD *)(v1 + 4) = v4;
    *(_QWORD *)(v1 + 8) = v7;
    *(_DWORD *)(v1 + 16) = v8;
  }
  else
  {
    sub_50F83C();
  }
}
