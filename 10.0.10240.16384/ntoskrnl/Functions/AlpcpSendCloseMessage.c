// AlpcpSendCloseMessage 
 
_DWORD *__fastcall AlpcpSendCloseMessage(_DWORD *result)
{
  unsigned int v1; // r3
  _DWORD *v2; // r7
  int v3; // r2
  unsigned int *v4; // r2
  int v5; // r5
  unsigned __int8 *v6; // r8
  int v7; // r0
  unsigned int v8; // r2
  unsigned int *v9; // r1
  unsigned int v10; // r2
  int v11; // r2
  int v12; // r2
  int v13; // r3
  char v14; // r2
  int v15; // r7
  int v16; // r3
  unsigned int *v17; // r6
  unsigned int v18; // r1
  unsigned int *v19; // r2
  unsigned int v20; // r0
  _DWORD v21[16]; // [sp+8h] [bp-40h] BYREF

  v1 = result[61];
  v2 = result;
  v3 = (v1 >> 1) & 3;
  if ( v3 != 1 && (v1 & 8) == 0 && ((result[38] & 0x1000) == 0 || v3 == 2) )
  {
    __dmb(0xBu);
    v4 = (unsigned int *)(result[2] + 36);
    do
      v5 = __ldrex(v4);
    while ( __strex(0, v4) );
    __dmb(0xBu);
    if ( v5 )
    {
      v6 = (unsigned __int8 *)(v5 - 4);
      v7 = KeAbPreAcquire(v5 - 4, 0, 0);
      do
        v8 = __ldrex(v6);
      while ( __strex(v8 | 1, v6) );
      __dmb(0xBu);
      if ( (v8 & 1) != 0 )
      {
        result = (_DWORD *)sub_80770C(v7);
      }
      else
      {
        if ( v7 )
          *(_BYTE *)(v7 + 14) |= 1u;
        *(_BYTE *)(v5 - 16) |= 1u;
        __dmb(0xBu);
        v9 = (unsigned int *)(v5 - 12);
        do
        {
          v10 = __ldrex(v9);
          v11 = v10 + 0x10000;
        }
        while ( __strex(v11, v9) );
        __dmb(0xBu);
        if ( v11 <= 0 )
          KeBugCheckEx(24, 0, v5, 38, v11);
        --*(_WORD *)(v5 - 14);
        *(_DWORD *)(v5 + 136) &= 0x7FFFFFFFu;
        *(_WORD *)(v5 + 122) = 32;
        *(_WORD *)(v5 + 120) = 8;
        *(_WORD *)(v5 + 124) = *(_WORD *)(v5 + 124) & 0xFF05 | 5;
        *(_WORD *)(v5 + 126) = 0;
        v12 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
        v21[0] = v2;
        v21[1] = v5;
        *(_DWORD *)(v5 + 144) = *(_DWORD *)(v12 + 200);
        v13 = *(_DWORD *)(v12 + 204);
        *(_DWORD *)(v5 + 128) = 0;
        *(_DWORD *)(v5 + 132) = 0;
        *(_DWORD *)(v5 + 148) = v13;
        v21[6] = 0x10000;
        result = (_DWORD *)AlpcpDispatchCloseMessage(v21);
        if ( (int)result < 0 )
        {
          if ( AlpcpMessageLogEnabled )
            AlpcpEnterStateChangeEventMessageLog(v5);
          v14 = *(_BYTE *)(v5 - 16);
          v15 = 0;
          if ( (v14 & 1) != 0 )
          {
            v16 = *(__int16 *)(v5 - 14);
            *(_WORD *)(v5 - 14) = 0;
            v15 = 0x10000 - v16;
            *(_BYTE *)(v5 - 16) = v14 & 0xFE;
          }
          v17 = (unsigned int *)(v5 - 4);
          __dmb(0xBu);
          do
            v18 = __ldrex(v17);
          while ( __strex(v18 - 1, v17) );
          if ( (v18 & 2) != 0 && (v18 & 4) == 0 )
            ExfTryToWakePushLock((unsigned int *)(v5 - 4));
          result = (_DWORD *)KeAbPostRelease(v5 - 4);
          if ( v15 > 0 )
          {
            __dmb(0xBu);
            v19 = (unsigned int *)(v5 - 12);
            do
            {
              v20 = __ldrex(v19);
              result = (_DWORD *)(v20 - v15);
            }
            while ( __strex((unsigned int)result, v19) );
            __dmb(0xBu);
            if ( (int)result <= 0 )
            {
              if ( result )
                KeBugCheckEx(24, 0, v5, 40, (int)result);
              result = (_DWORD *)AlpcpDestroyBlob(v5);
            }
          }
        }
      }
    }
  }
  return result;
}
