// PopFxTracePerfRegistration 
 
_DWORD *__fastcall PopFxTracePerfRegistration(_DWORD *result, int a2)
{
  _DWORD *v3; // r6
  int *v4; // r4
  int *v5; // r8
  int v6; // r2
  unsigned int v7; // r4
  int v8; // r1
  int v9; // t1
  int v10; // r7
  _BYTE *v11; // r5
  int v12; // r9
  _DWORD *v13; // r4
  unsigned int v14; // lr
  int v15; // r0
  _DWORD *v16; // r1
  _DWORD *v17; // r2
  int v18; // r3
  int v19; // r1
  _BYTE *v20; // lr
  int v21; // r10
  int v22; // r10
  unsigned int v23; // r3
  int v24; // [sp+8h] [bp-58h]
  int v25; // [sp+24h] [bp-3Ch]
  int v26; // [sp+30h] [bp-30h]
  int v27; // [sp+38h] [bp-28h]
  int v28[9]; // [sp+3Ch] [bp-24h] BYREF

  v3 = result;
  if ( a2 )
    v4 = POP_ETW_EVENT_PERFORMANCE_STATE_REGISTRATION_RUNDOWN;
  else
    v4 = POP_ETW_EVENT_PERFORMANCE_STATE_REGISTRATION;
  if ( PopDiagHandleRegistered )
  {
    result = (_DWORD *)EtwEventEnabled(PopDiagHandle, dword_61E154, (int)v4);
    if ( result )
    {
      PopDiagTraceFxPerfRegistration((int)v4);
      v5 = a2 ? POP_ETW_EVENT_PERFORMANCE_STATE_SET_REGISTRATION_RUNDOWN : POP_ETW_EVENT_PERFORMANCE_STATE_SET_REGISTRATION;
      result = (_DWORD *)EtwEventEnabled(PopDiagHandle, dword_61E154, (int)v5);
      if ( result )
      {
        v6 = v3[21];
        v7 = 0;
        if ( v6 )
        {
          result = (_DWORD *)v3[22];
          do
          {
            v9 = *result;
            result += 8;
            v8 = v9;
            if ( !*(_DWORD *)(v9 + 20) && *(_DWORD *)(v8 + 24) > v7 )
              v7 = *(_DWORD *)(v8 + 24);
            --v6;
          }
          while ( v6 );
        }
        v10 = 0;
        if ( v7 )
        {
          result = (_DWORD *)RtlULongLongToULong(8 * v7, (unsigned __int64)v7 >> 29, v28);
          if ( (int)result < 0 )
            return result;
          v10 = 8 * v7;
          result = (_DWORD *)ExAllocatePoolWithTag(1, 8 * v7, 1297630800);
          v11 = result;
          if ( !result )
            return result;
        }
        else
        {
          v11 = 0;
        }
        v28[0] = 0;
        if ( v3[21] )
        {
          v12 = 0;
          do
          {
            v13 = *(_DWORD **)(v12 + v3[22]);
            if ( v13[5] )
            {
              v21 = v13[6];
              v19 = 0;
              v20 = 0;
              v27 = v13[7];
              v26 = v13[8];
              v18 = v13[9];
            }
            else
            {
              memset(v11, 0, v10);
              v14 = 0;
              if ( v13[6] )
              {
                v15 = 0;
                v16 = v11;
                do
                {
                  ++v14;
                  v17 = (_DWORD *)(v13[7] + v15);
                  v15 += 16;
                  *v16 = *v17;
                  v16[1] = v17[1];
                  v16 += 2;
                }
                while ( v14 < v13[6] );
              }
              v18 = 0;
              v19 = v13[6];
              v27 = 0;
              v26 = 0;
              v20 = v11;
              v21 = 0;
            }
            v24 = v21;
            v22 = v28[0];
            result = (_DWORD *)PopDiagTraceFxPerfSetRegistration(
                                 (int)v5,
                                 *(_DWORD *)(*(_DWORD *)(*v3 + 48) + 28),
                                 *(_DWORD *)(*v3 + 16),
                                 v28[0],
                                 v13[5],
                                 v13[4],
                                 v24,
                                 v27,
                                 v26,
                                 v18,
                                 v13,
                                 v19,
                                 v20,
                                 v25,
                                 *(_DWORD *)(v12 + v3[22] + 8),
                                 *(_DWORD *)(v12 + v3[22] + 12));
            v23 = v3[21];
            v28[0] = v22 + 1;
            v12 += 32;
          }
          while ( v22 + 1 < v23 );
        }
        if ( v11 )
          result = (_DWORD *)ExFreePoolWithTag((unsigned int)v11);
      }
    }
  }
  return result;
}
