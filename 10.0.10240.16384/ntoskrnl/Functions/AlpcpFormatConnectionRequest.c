// AlpcpFormatConnectionRequest 
 
int __fastcall AlpcpFormatConnectionRequest(int *a1, int a2, int a3, int a4, __int16 *a5, int a6, _DWORD *a7, int *a8, unsigned __int8 a9, char a10)
{
  int v10; // r4
  int v13; // r6
  int v14; // r5
  int v15; // r0
  unsigned int v16; // r5
  int v18; // r1
  unsigned int v19; // r2
  __int16 v20; // r3
  int v21; // r2
  int v22; // r7
  bool v23; // zf
  unsigned int *v24; // lr
  int v25; // r4
  int v26; // r0
  int v27; // r8
  unsigned int *v28; // r7
  unsigned int v29; // r1
  unsigned int *v30; // r2
  unsigned int v31; // r0
  int v32; // r0
  int v33; // r8
  unsigned int *v34; // r7
  unsigned int v35; // r1
  unsigned int *v36; // r2
  unsigned int v37; // r0
  int v38; // r0
  int v39; // [sp+8h] [bp-28h] BYREF
  int v40; // [sp+Ch] [bp-24h]
  int *v41; // [sp+10h] [bp-20h]

  v10 = **(_DWORD **)(a3 + 8);
  v40 = a4;
  v41 = a1;
  if ( a4 )
  {
    if ( a9 )
    {
      v18 = *(_DWORD *)(v10 + 168);
      if ( (unsigned __int16)*a5 > (unsigned int)(v18 - 24) )
        *a5 = v18 - 24;
    }
    else
    {
      v16 = (unsigned __int16)*a5;
      if ( v16 >= (unsigned __int16)(v16 + 24) || v16 + 24 != (unsigned __int16)a5[1] )
        return sub_7F4168();
    }
  }
  v13 = AlpcpAllocateMessage(&v39, 0, 0);
  if ( v13 < 0 )
    return v13;
  v14 = v39;
  if ( a9 )
  {
    if ( !a7 )
    {
      *(_DWORD *)(v39 + 140) = 0;
      goto LABEL_31;
    }
    v15 = AlpcpMapLegacyPortView(a3, a7, v39 + 56);
    *(_DWORD *)(v14 + 140) = a7[3];
  }
  else
  {
    v15 = AlpcpCaptureAttributes(a3, a2, a6, v39, v39 + 56);
  }
  v13 = v15;
LABEL_31:
  if ( v13 < 0 )
  {
    if ( AlpcpMessageLogEnabled )
      AlpcpEnterStateChangeEventMessageLog(v14);
    v27 = 0;
    if ( (*(_BYTE *)(v14 - 16) & 1) != 0 )
    {
      v27 = 0x10000 - *(__int16 *)(v14 - 14);
      *(_BYTE *)(v14 - 16) &= 0xFEu;
      *(_WORD *)(v14 - 14) = 0;
    }
    v28 = (unsigned int *)(v14 - 4);
    __dmb(0xBu);
    do
      v29 = __ldrex(v28);
    while ( __strex(v29 - 1, v28) );
    if ( (v29 & 2) != 0 && (v29 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(v14 - 4));
    KeAbPostRelease(v14 - 4);
    if ( v27 <= 0 )
      return v13;
    __dmb(0xBu);
    v30 = (unsigned int *)(v14 - 12);
    do
    {
      v31 = __ldrex(v30);
      v32 = v31 - v27;
    }
    while ( __strex(v32, v30) );
    __dmb(0xBu);
    if ( v32 > 0 )
      return v13;
    if ( v32 )
      KeBugCheckEx(24, 0, v14, 40, v32);
    goto LABEL_47;
  }
  v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(v14 + 128) = *(_DWORD *)(v19 + 0x36C);
  *(_DWORD *)(v14 + 132) = *(_DWORD *)(v19 + 0x370);
  v20 = *a5;
  *(_WORD *)(v14 + 120) = *a5;
  *(_WORD *)(v14 + 122) = v20 + 24;
  *(_WORD *)(v14 + 124) = *(_WORD *)(v14 + 124) & 0xFF0A | 0xA;
  if ( !*(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
    *(_WORD *)(v14 + 124) |= a5[2] & 0x8000;
  if ( !*a5 || (v13 = AlpcpSetupMessageDataForDeferredCopy(v14, v40, *a5, (unsigned __int16)*a5, a9, a10), v13 >= 0) )
  {
    if ( a9 )
    {
      v21 = *(_DWORD *)(v14 + 76);
      if ( v21 )
      {
        *a8 = v21;
        v22 = *(_DWORD *)(v21 - 12);
        v23 = v22 == 0;
        if ( v22 <= 0 )
        {
LABEL_65:
          if ( !v23 )
            KeBugCheckEx(24, 0, v21, 32, v22);
        }
        else
        {
          v24 = (unsigned int *)(v21 - 12);
          while ( 1 )
          {
            v25 = v22;
            __dmb(0xBu);
            do
              v26 = __ldrex(v24);
            while ( v26 == v22 && __strex(v22 + 1, v24) );
            v22 = v26;
            __dmb(0xBu);
            if ( v26 == v25 )
              break;
            if ( v26 <= 0 )
            {
              v23 = v26 == 0;
              goto LABEL_65;
            }
          }
        }
      }
    }
    *v41 = v14;
    return v13;
  }
  if ( AlpcpMessageLogEnabled )
    AlpcpEnterStateChangeEventMessageLog(v14);
  v33 = 0;
  if ( (*(_BYTE *)(v14 - 16) & 1) != 0 )
  {
    v33 = 0x10000 - *(__int16 *)(v14 - 14);
    *(_BYTE *)(v14 - 16) &= 0xFEu;
    *(_WORD *)(v14 - 14) = 0;
  }
  v34 = (unsigned int *)(v14 - 4);
  __dmb(0xBu);
  do
    v35 = __ldrex(v34);
  while ( __strex(v35 - 1, v34) );
  if ( (v35 & 2) != 0 && (v35 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)(v14 - 4));
  KeAbPostRelease(v14 - 4);
  if ( v33 > 0 )
  {
    __dmb(0xBu);
    v36 = (unsigned int *)(v14 - 12);
    do
    {
      v37 = __ldrex(v36);
      v38 = v37 - v33;
    }
    while ( __strex(v38, v36) );
    __dmb(0xBu);
    if ( v38 <= 0 )
    {
      if ( v38 )
        KeBugCheckEx(24, 0, v14, 40, v38);
LABEL_47:
      AlpcpDestroyBlob(v14);
      return v13;
    }
  }
  return v13;
}
