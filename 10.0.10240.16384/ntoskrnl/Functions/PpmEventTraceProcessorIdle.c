// PpmEventTraceProcessorIdle 
 
_BYTE *__fastcall PpmEventTraceProcessorIdle(_BYTE *result)
{
  _BYTE *v1; // r7
  int v2; // r4
  unsigned int v3; // r2
  int v4; // r3
  int v5; // r8
  int v6; // r9
  _DWORD *v7; // r5
  unsigned int v8; // r7
  _DWORD *v9; // r0
  int v10; // r1
  _DWORD *v11; // r2
  int v12; // lr
  int v13; // r3
  __int16 v14; // [sp+8h] [bp-28h] BYREF
  unsigned int v15; // [sp+Ch] [bp-24h] BYREF
  int v16; // [sp+10h] [bp-20h] BYREF

  v1 = result;
  if ( PpmEtwRegistered )
  {
    result = (_BYTE *)EtwEventEnabled(PpmEtwHandle, dword_61DEC4, (int)PPM_ETW_CURRENT_IDLE_RUNDOWN);
    if ( result )
    {
      v2 = *((_DWORD *)v1 + 736);
      if ( v2 )
      {
        v3 = *(_DWORD *)(v2 + 28);
        v15 = v3;
        v4 = *(_DWORD *)(v2 + 32);
      }
      else
      {
        v3 = 0;
        v15 = 0;
        v4 = 0;
      }
      v16 = v4;
      v5 = 2 * (v3 + 2);
      v6 = 37 * v3;
      result = (_BYTE *)ExAllocatePoolWithTag(1, 37 * v3 + 32 * (v3 + 2), 1699565648);
      v7 = result;
      if ( result )
      {
        memset(result, 0, v6 + 16 * v5);
        v14 = (unsigned __int8)v1[1052];
        *v7 = &v14;
        v7[1] = 0;
        v7[2] = 2;
        v7[3] = 0;
        v7[4] = v1 + 1053;
        v7[5] = 0;
        v7[6] = 1;
        v7[7] = 0;
        v7[8] = &v16;
        v7[9] = 0;
        v7[10] = 4;
        v7[11] = 0;
        v7[12] = &v15;
        v7[13] = 0;
        v7[14] = 4;
        v7[15] = 0;
        v8 = 0;
        v9 = &v7[4 * v5];
        if ( v15 )
        {
          v10 = v2 + 252;
          v11 = v7 + 16;
          do
          {
            *v9 = *(_DWORD *)(v10 + 20);
            v9[1] = *(_DWORD *)(v10 + 24);
            *((_BYTE *)v9 + 8) = *(_BYTE *)(v10 + 56);
            *(_DWORD *)((char *)v9 + 9) = *(unsigned __int8 *)(v10 + 57);
            *(_DWORD *)((char *)v9 + 13) = *(unsigned __int8 *)(v10 + 58);
            *(_DWORD *)((char *)v9 + 17) = *(unsigned __int8 *)(v10 + 59);
            *(_DWORD *)((char *)v9 + 21) = *(unsigned __int8 *)(v10 + 60);
            *(_DWORD *)((char *)v9 + 25) = *(unsigned __int8 *)(v10 + 61);
            *(_DWORD *)((char *)v9 + 29) = *(unsigned __int8 *)(v10 + 62);
            *(_DWORD *)((char *)v9 + 33) = *(unsigned __int8 *)(v10 + 63);
            v11[1] = 0;
            v11[2] = 37;
            *v11 = v9;
            v11[3] = 0;
            v12 = *(_DWORD *)(v10 + 16);
            if ( v12 )
            {
              v13 = *(unsigned __int16 *)(v10 + 14);
              v11[4] = v12;
            }
            else
            {
              v11[4] = L"<unspecified>";
              v13 = 28;
            }
            v11[6] = v13;
            v11[7] = 0;
            v11[5] = 0;
            ++v8;
            v9 = (_DWORD *)((char *)v9 + 37);
            v10 += 64;
            v11 += 8;
          }
          while ( v8 < v15 );
        }
        EtwWrite(PpmEtwHandle, dword_61DEC4, (int)PPM_ETW_CURRENT_IDLE_RUNDOWN, 0);
        result = (_BYTE *)ExFreePoolWithTag((unsigned int)v7);
      }
    }
  }
  return result;
}
