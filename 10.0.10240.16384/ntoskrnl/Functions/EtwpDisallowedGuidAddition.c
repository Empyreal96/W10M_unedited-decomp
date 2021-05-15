// EtwpDisallowedGuidAddition 
 
int __fastcall EtwpDisallowedGuidAddition(_DWORD *a1, _DWORD *a2)
{
  int result; // r0
  int v5; // r8
  _DWORD *v6; // r7
  int v7; // r3
  int v8; // r4
  int v9; // r5
  int v10; // r4
  int v11; // r5
  unsigned int v12; // r1
  int v13; // r2
  int v14; // r1
  int v15[8]; // [sp+10h] [bp-20h] BYREF

  v15[0] = 0;
  result = EtwpFindGuidEntryByGuid((unsigned int)a1, 0);
  v5 = result;
  if ( result )
  {
    EtwpBuildNotificationPacket(result, 0, 0, v15);
    v6 = (_DWORD *)v15[0];
    *(_DWORD *)v15[0] = 3;
    v7 = a1[1];
    v8 = a1[2];
    v9 = a1[3];
    v6[10] = *a1;
    v6[11] = v7;
    v6[12] = v8;
    v6[13] = v9;
    result = PsGetCurrentThreadProcessId();
    v6[9] = result;
    v10 = *(_DWORD *)(v5 + 28);
LABEL_12:
    while ( v10 != v5 + 28 )
    {
      v11 = v10;
      result = *(unsigned __int8 *)(v10 + 52);
      v10 = *(_DWORD *)v10;
      if ( result )
      {
        v12 = 0;
        while ( 1 )
        {
          v13 = *(_DWORD *)(v11 + 20) + 32 * v12;
          if ( *(_DWORD *)(v13 + 88) )
          {
            if ( *(unsigned __int16 *)(v13 + 94) == *a2 )
              break;
          }
          v12 = (unsigned __int8)(v12 + 1);
          if ( v12 >= 8 )
            goto LABEL_12;
        }
        v14 = (unsigned __int8)(1 << v12);
        if ( v14 )
        {
          if ( (v14 & result) != 0 )
          {
            *(_BYTE *)(v11 + 52) = result & ~(_BYTE)v14;
            EtwpCalculateUpdateNotification(v11, v14, result, result, 2, 0, v15);
            result = EtwpSendDataBlock(v11, v15[0]);
          }
        }
      }
    }
  }
  return result;
}
