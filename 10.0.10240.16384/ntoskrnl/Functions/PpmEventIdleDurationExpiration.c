// PpmEventIdleDurationExpiration 
 
int __fastcall PpmEventIdleDurationExpiration(int result)
{
  int v1; // r5
  __int64 v2; // kr00_8
  unsigned int v3; // r1
  int v4; // r3
  int v5; // r6
  unsigned __int16 v6; // r0
  char *v7; // r5
  _DWORD *v8; // r4
  __int16 v9; // [sp+8h] [bp-60h] BYREF
  _DWORD v10[8]; // [sp+10h] [bp-58h] BYREF
  char v11; // [sp+30h] [bp-38h] BYREF

  v1 = result;
  if ( PpmEtwRegistered )
  {
    v2 = *(_QWORD *)&PpmEtwHandle;
    result = EtwEventEnabled(PpmEtwHandle, dword_61DEC4, (int)PPM_ETW_IDLE_DURATION_EXPIRATION);
    if ( result )
    {
      v3 = 0;
      v9 = 0;
      v10[0] = 0;
      v10[1] = 0;
      v10[2] = 0;
      v10[0] = *(_DWORD *)(v1 + 8);
      if ( v10[0] )
      {
        v3 = 1;
        v9 = 1;
      }
      v10[4] = &v9;
      v10[5] = 0;
      v10[6] = 2;
      v4 = 0;
      v5 = 1;
      v10[7] = 0;
      if ( v3 )
      {
        v6 = 0;
        v7 = &v11;
        do
        {
          v8 = &v10[3 * v4];
          *(_DWORD *)v7 = v8 + 1;
          *((_DWORD *)v7 + 1) = 0;
          *((_DWORD *)v7 + 2) = 2;
          *((_DWORD *)v7 + 3) = 0;
          *((_DWORD *)v7 + 5) = 0;
          *((_DWORD *)v7 + 6) = 4;
          *((_DWORD *)v7 + 4) = v8;
          *((_DWORD *)v7 + 7) = 0;
          v5 += 2;
          v7 += 32;
          v4 = ++v6;
        }
        while ( v6 < v3 );
      }
      result = EtwWrite(v2, SHIDWORD(v2), (int)PPM_ETW_IDLE_DURATION_EXPIRATION, 0);
    }
  }
  return result;
}
