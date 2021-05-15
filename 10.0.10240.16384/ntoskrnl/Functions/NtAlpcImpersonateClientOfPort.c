// NtAlpcImpersonateClientOfPort 
 
int __fastcall NtAlpcImpersonateClientOfPort(int a1, int a2, int a3, int a4)
{
  unsigned int v5; // r4
  char v6; // r10
  int v7; // r5
  int v8; // r6
  int v9; // r4
  int v10; // r5
  int v11; // r6
  unsigned int *v12; // r8
  unsigned int v13; // r1
  unsigned int *v14; // r2
  unsigned int v15; // r0
  int v16; // r0
  unsigned int v17; // r1
  __int16 v18; // r3
  int v20[2]; // [sp+Ch] [bp-2Ch] BYREF
  int v21; // [sp+14h] [bp-24h]
  _DWORD _18[14]; // [sp+18h] [bp-20h] BYREF

  _18[11] = a2;
  _18[13] = a4;
  _18[12] = a3;
  _18[10] = a1;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v5 + 308);
  v6 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) && (a2 & 7) != 0 )
    ExRaiseDatatypeMisalignment(a1);
  v21 = *(_DWORD *)(a2 + 16);
  v7 = v21;
  v8 = *(_DWORD *)(a2 + 20);
  v20[1] = v8;
  if ( v21 )
  {
    if ( !a3 || a3 == 1 )
    {
      a1 = ObReferenceObjectByHandle(a1, 1, AlpcPortObjectType, v6, (int)v20, 0);
      v9 = a1;
      if ( a1 >= 0 )
      {
        v9 = AlpcpLookupMessage(v20[0], v7, v8, _18);
        if ( v9 >= 0 )
        {
          v10 = _18[0];
          v9 = AlpcpImpersonateMessage(v20[0], _18[0], a3 == 1);
          if ( AlpcpMessageLogEnabled )
            AlpcpEnterStateChangeEventMessageLog(v10);
          v11 = 0;
          if ( (*(_BYTE *)(v10 - 16) & 1) != 0 )
          {
            v11 = 0x10000 - *(__int16 *)(v10 - 14);
            *(_BYTE *)(v10 - 16) &= 0xFEu;
            *(_WORD *)(v10 - 14) = 0;
          }
          v12 = (unsigned int *)(v10 - 4);
          __dmb(0xBu);
          do
            v13 = __ldrex(v12);
          while ( __strex(v13 - 1, v12) );
          if ( (v13 & 2) != 0 && (v13 & 4) == 0 )
            ExfTryToWakePushLock((unsigned int *)(v10 - 4));
          KeAbPostRelease(v10 - 4);
          if ( v11 > 0 )
          {
            __dmb(0xBu);
            v14 = (unsigned int *)(v10 - 12);
            do
            {
              v15 = __ldrex(v14);
              v16 = v15 - v11;
            }
            while ( __strex(v16, v14) );
            __dmb(0xBu);
            if ( v16 <= 0 )
            {
              if ( v16 )
                KeBugCheckEx(24, 0, v10, 40, v16);
              AlpcpDestroyBlob(v10);
            }
          }
        }
        a1 = ObfDereferenceObject(v20[0]);
      }
    }
    else
    {
      v9 = -1073741811;
    }
  }
  else
  {
    v9 = -1073741811;
  }
  v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v18 = *(_WORD *)(v17 + 0x134) + 1;
  *(_WORD *)(v17 + 308) = v18;
  if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 && !*(_WORD *)(v17 + 310) )
    KiCheckForKernelApcDelivery(a1);
  return v9;
}
