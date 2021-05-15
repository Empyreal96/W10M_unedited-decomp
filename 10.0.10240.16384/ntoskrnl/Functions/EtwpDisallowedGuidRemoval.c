// EtwpDisallowedGuidRemoval 
 
int __fastcall EtwpDisallowedGuidRemoval(_DWORD *a1, int a2)
{
  int v3; // r8
  int result; // r0
  int v5; // r9
  _DWORD *v6; // r7
  int v7; // r3
  int v8; // r4
  int v9; // r5
  _DWORD *v10; // r6
  _DWORD *v11; // r9
  _DWORD *v12; // t1
  _DWORD *v13; // r7
  int v14; // r5
  int v15; // r3
  unsigned int v16; // r1
  unsigned int v17; // r2
  int v18; // r4
  _DWORD *v19; // [sp+10h] [bp-28h] BYREF
  _DWORD *v20; // [sp+14h] [bp-24h]

  v20 = (_DWORD *)a2;
  v19 = 0;
  v3 = 0;
  result = EtwpFindGuidEntryByGuid((unsigned int)a1, 0);
  v5 = result;
  if ( result )
  {
    EtwpBuildNotificationPacket(result, 0, 0, &v19);
    v6 = v19;
    *v19 = 3;
    v7 = a1[1];
    v8 = a1[2];
    v9 = a1[3];
    v6[10] = *a1;
    v6[11] = v7;
    v6[12] = v8;
    v6[13] = v9;
    result = PsGetCurrentThreadProcessId();
    v6[9] = result;
    v12 = *(_DWORD **)(v5 + 28);
    v11 = (_DWORD *)(v5 + 28);
    v10 = v12;
    if ( v12 != v11 )
    {
      v13 = v20;
      do
      {
        v14 = (int)v10;
        v15 = v10[5];
        v10 = (_DWORD *)*v10;
        if ( v15 && *(_DWORD *)(v15 + 56) )
        {
          result = *(_DWORD *)(v14 + 20);
          v16 = 0;
          while ( 1 )
          {
            v17 = result + 32 * v16;
            if ( *(_DWORD *)(v17 + 88) )
            {
              if ( *(unsigned __int16 *)(v17 + 94) == *v13 )
                break;
            }
            v16 = (unsigned __int8)(v16 + 1);
            if ( v16 >= 8 )
              goto LABEL_12;
          }
          v3 = (unsigned __int8)(1 << v16);
LABEL_12:
          if ( v3 )
          {
            v18 = *(unsigned __int8 *)(v14 + 52);
            EtwpUpdateRegEntryEnableMask(v14, v3, 2, 1);
            result = EtwpCalculateUpdateNotification(v14, v3, v18, 0, 2, 1, (int *)&v19);
            if ( result )
              result = EtwpSendDataBlock(v14, (unsigned int)v19);
          }
        }
      }
      while ( v10 != v11 );
    }
  }
  return result;
}
