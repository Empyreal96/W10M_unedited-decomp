// PopCalculateIdleInformation 
 
int __fastcall PopCalculateIdleInformation(int a1)
{
  int v1; // r4
  int result; // r0
  int v3; // r2
  unsigned int v4; // r5
  int v5; // r1
  unsigned int v6; // r6
  __int64 v7; // r8
  int v8; // r10
  int v9; // r7
  unsigned int v10; // r4
  __int64 v11; // r0
  unsigned __int64 v12; // kr08_8
  __int64 v13; // r0
  unsigned int v14; // [sp+0h] [bp-30h]
  int v15; // [sp+4h] [bp-2Ch]
  int v16; // [sp+8h] [bp-28h]
  int v17; // [sp+Ch] [bp-24h]

  v1 = a1;
  if ( !PpmPlatformStates )
    return sub_50F83C();
  v3 = *(_DWORD *)(PpmPlatformStates + 32);
  v4 = *(_DWORD *)(v3 + 4);
  result = 0;
  v5 = 0;
  v6 = 0;
  v14 = 0;
  v15 = dword_635500;
  v7 = 0i64;
  v8 = 0;
  if ( v4 )
  {
    v9 = v3 + 24;
    v10 = 0;
    do
    {
      v11 = *(_QWORD *)(v9 + 32);
      v16 = *(_DWORD *)(v9 + 36);
      v17 = v11;
      v12 = __PAIR64__(v14, v10) + PpmConvertTimeTo(v11, HIDWORD(v11), 1000000, 0);
      result = HIDWORD(v12);
      v14 = HIDWORD(v12);
      v10 = v12;
      if ( v6 == v15 && v15 != -1 )
      {
        v13 = PpmConvertTimeTo(v17, v16, 1000000, 0);
        v8 = *(_DWORD *)(v9 + 8);
        v7 = v13;
        result = HIDWORD(v12);
      }
      ++v6;
      v9 += 992;
    }
    while ( v6 < v4 );
    v5 = v12;
    v1 = a1;
  }
  *(_DWORD *)v1 = v5;
  *(_DWORD *)(v1 + 4) = result;
  *(_QWORD *)(v1 + 8) = v7;
  *(_DWORD *)(v1 + 16) = v8;
  return result;
}
