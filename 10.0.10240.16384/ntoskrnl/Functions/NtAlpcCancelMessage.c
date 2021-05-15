// NtAlpcCancelMessage 
 
int __fastcall NtAlpcCancelMessage(_DWORD *a1, int a2, unsigned int a3, int a4)
{
  int v5; // lr
  unsigned int v6; // r4
  int v7; // r4
  int v8; // r9
  _DWORD *v9; // r6
  _DWORD *v10; // r8
  _DWORD *v11; // r5
  _DWORD *v12; // r9
  _DWORD *v13; // r4
  _DWORD *v14; // r3
  int v15; // r8
  unsigned int *v16; // r6
  unsigned int v17; // r1
  unsigned int *v18; // r2
  unsigned int v19; // r0
  int v20; // r0
  int v21; // r8
  unsigned int *v22; // r6
  unsigned int v23; // r1
  unsigned int *v24; // r2
  unsigned int v25; // r0
  int v26; // r0
  unsigned int v27; // r1
  __int16 v28; // r3
  _DWORD *v30[4]; // [sp+Ch] [bp-34h] BYREF
  int _1C[15]; // [sp+1Ch] [bp-24h] BYREF

  _1C[13] = a3;
  _1C[14] = a4;
  _1C[12] = a2;
  v5 = (int)a1;
  v30[0] = a1;
  _1C[11] = (int)a1;
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v6 + 308);
  if ( (a2 & 0xFFFFFFF0) != 0 )
  {
    v7 = -1073741811;
  }
  else
  {
    v8 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
    if ( v8 )
    {
      a1 = (_DWORD *)a3;
      if ( (a3 & 3) != 0 )
        ExRaiseDatatypeMisalignment(a3);
      if ( a3 >= MmUserProbeAddress )
        a1 = (_DWORD *)MmUserProbeAddress;
      v9 = *(_DWORD **)(a3 + 12);
      v30[1] = v9;
      v10 = *(_DWORD **)(a3 + 16);
      v30[2] = v10;
      v11 = *(_DWORD **)(a3 + 4);
      v30[3] = v11;
    }
    else
    {
      v9 = *(_DWORD **)(a3 + 12);
      v10 = *(_DWORD **)(a3 + 16);
      v11 = *(_DWORD **)(a3 + 4);
    }
    if ( v9 )
    {
      a1 = (_DWORD *)ObReferenceObjectByHandle(v5, 1, AlpcPortObjectType, v8, (int)_1C, 0);
      v7 = (int)a1;
      if ( (int)a1 >= 0 )
      {
        v12 = (_DWORD *)_1C[0];
        v7 = AlpcpLookupMessage(_1C[0], (int)v9, (int)v10, v30);
        if ( v7 >= 0 )
        {
          v13 = v30[0];
          if ( (a2 & 8) == 0
            || ((v12[61] & 6) != 4 ? (v14 = (_DWORD *)v30[0][15]) : (v14 = (_DWORD *)v30[0][14]), v11 == v14) )
          {
            if ( (v30[0][5] & 0x80) != 0 )
            {
              if ( AlpcpMessageLogEnabled )
                AlpcpEnterStateChangeEventMessageLog(v30[0]);
              v21 = 0;
              if ( (*(_BYTE *)(v13 - 4) & 1) != 0 )
              {
                v21 = 0x10000 - *((__int16 *)v13 - 7);
                *((_BYTE *)v13 - 16) &= 0xFEu;
                *((_WORD *)v13 - 7) = 0;
              }
              v22 = v13 - 1;
              __dmb(0xBu);
              do
                v23 = __ldrex(v22);
              while ( __strex(v23 - 1, v22) );
              if ( (v23 & 2) != 0 && (v23 & 4) == 0 )
                ExfTryToWakePushLock(v13 - 1);
              KeAbPostRelease((unsigned int)(v13 - 1));
              if ( v21 > 0 )
              {
                __dmb(0xBu);
                v24 = v13 - 3;
                do
                {
                  v25 = __ldrex(v24);
                  v26 = v25 - v21;
                }
                while ( __strex(v26, v24) );
                __dmb(0xBu);
                if ( v26 <= 0 )
                {
                  if ( v26 )
                    KeBugCheckEx(24, 0, (int)v13, 40, v26);
                  AlpcpDestroyBlob((int)v13);
                }
              }
              v7 = -1073740029;
            }
            else
            {
              v7 = AlpcpCancelMessage(v12, (int)v30[0], a2);
            }
          }
          else
          {
            if ( AlpcpMessageLogEnabled )
              AlpcpEnterStateChangeEventMessageLog(v30[0]);
            v15 = 0;
            if ( (*(_BYTE *)(v13 - 4) & 1) != 0 )
            {
              v15 = 0x10000 - *((__int16 *)v13 - 7);
              *((_BYTE *)v13 - 16) &= 0xFEu;
              *((_WORD *)v13 - 7) = 0;
            }
            v16 = v13 - 1;
            __dmb(0xBu);
            do
              v17 = __ldrex(v16);
            while ( __strex(v17 - 1, v16) );
            if ( (v17 & 2) != 0 && (v17 & 4) == 0 )
              ExfTryToWakePushLock(v13 - 1);
            KeAbPostRelease((unsigned int)(v13 - 1));
            if ( v15 > 0 )
            {
              __dmb(0xBu);
              v18 = v13 - 3;
              do
              {
                v19 = __ldrex(v18);
                v20 = v19 - v15;
              }
              while ( __strex(v20, v18) );
              __dmb(0xBu);
              if ( v20 <= 0 )
              {
                if ( v20 )
                  KeBugCheckEx(24, 0, (int)v13, 40, v20);
                AlpcpDestroyBlob((int)v13);
              }
            }
            v7 = -1073740007;
          }
        }
        a1 = (_DWORD *)ObfDereferenceObject((int)v12);
      }
    }
    else
    {
      v7 = -1073741559;
    }
  }
  v27 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v28 = *(_WORD *)(v27 + 0x134) + 1;
  *(_WORD *)(v27 + 308) = v28;
  if ( !v28 && *(_DWORD *)(v27 + 100) != v27 + 100 && !*(_WORD *)(v27 + 310) )
    KiCheckForKernelApcDelivery((int)a1);
  return v7;
}
