// PpmEventDomainPerfStateChange 
 
int __fastcall PpmEventDomainPerfStateChange(int result)
{
  int v1; // r5
  __int64 v2; // kr00_8
  unsigned int v3; // r1
  int v4; // r6
  int v5; // r3
  int v6; // r6
  unsigned __int16 v7; // r4
  char *v8; // r0
  _DWORD *v9; // r2
  int *v10; // r2
  int v11; // r6
  int *v12; // r4
  int *v13; // r4
  int *v14; // r4
  __int16 v15; // [sp+8h] [bp-E8h] BYREF
  int v16; // [sp+Ch] [bp-E4h] BYREF
  int v17; // [sp+10h] [bp-E0h] BYREF
  _DWORD v18[4]; // [sp+30h] [bp-C0h] BYREF
  int v19[12]; // [sp+40h] [bp-B0h] BYREF
  char v20; // [sp+70h] [bp-80h] BYREF

  v1 = result;
  v17 = *(_DWORD *)(result + 160);
  v16 = *(_DWORD *)(result + 124);
  if ( WmiPerfStateDomainEventEnabled )
    return sub_51F454();
  if ( PpmEtwRegistered )
  {
    v2 = *(_QWORD *)&PpmEtwHandle;
    result = EtwEventEnabled(PpmEtwHandle, dword_61DEC4, PPM_ETW_DOMAIN_PERF_STATE_CHANGE);
    if ( result )
    {
      v3 = 0;
      v4 = *(_DWORD *)(v1 + 20);
      v15 = 0;
      v18[1] = 0;
      v18[2] = 0;
      v18[0] = dword_681D78[0] & v4;
      if ( (dword_681D78[0] & v4) != 0 )
      {
        v3 = 1;
        v15 = 1;
      }
      v19[0] = (int)&v17;
      v19[1] = 0;
      v19[2] = 4;
      v19[3] = 0;
      v19[4] = (int)&v16;
      v19[5] = 0;
      v19[6] = 4;
      v19[7] = 0;
      v19[8] = (int)&v15;
      v19[9] = 0;
      v19[10] = 2;
      v5 = 0;
      v6 = 3;
      v19[11] = 0;
      if ( v3 )
      {
        v7 = 0;
        v8 = &v20;
        do
        {
          v9 = &v18[3 * v5];
          *(_DWORD *)v8 = v9 + 1;
          *((_DWORD *)v8 + 1) = 0;
          *((_DWORD *)v8 + 2) = 2;
          *((_DWORD *)v8 + 3) = 0;
          *((_DWORD *)v8 + 4) = v9;
          *((_DWORD *)v8 + 5) = 0;
          *((_DWORD *)v8 + 6) = 4;
          *((_DWORD *)v8 + 7) = 0;
          v6 += 2;
          v8 += 32;
          v5 = ++v7;
        }
        while ( v7 < v3 );
      }
      v10 = &v19[4 * v6];
      *v10 = v1 + 120;
      v10[1] = 0;
      v11 = v6 + 1;
      v12 = &v19[4 * v11];
      v10[2] = 4;
      v10[3] = 0;
      *v12 = v1 + 144;
      v12[1] = 0;
      ++v11;
      v12[2] = 4;
      v12[3] = 0;
      v13 = &v19[4 * v11];
      *v13 = v1 + 140;
      v13[1] = 0;
      v13[2] = 4;
      v13[3] = 0;
      v14 = &v19[4 * v11 + 4];
      *v14 = v1 + 152;
      v14[1] = 0;
      v14[2] = 4;
      v14[3] = 0;
      result = EtwWrite(v2, SHIDWORD(v2), (int)PPM_ETW_DOMAIN_PERF_STATE_CHANGE, 0);
    }
  }
  return result;
}
