// HdlspGetLine 
 
int __fastcall HdlspGetLine(__int64 a1, int a2, int a3)
{
  unsigned int v3; // r8
  unsigned int *v4; // r4
  int v5; // r9
  int v6; // r6
  unsigned int v7; // r2
  unsigned int v8; // r3
  int v9; // r2
  int result; // r0
  int v11; // r3
  int v12; // r0
  int v13; // r2
  unsigned int v14; // r3
  int v15; // r3
  int v16; // r2
  unsigned int v17; // r0
  int v18; // r1
  _BYTE *v19; // r2
  _BYTE *v20; // r0
  int v21; // r2
  int v22; // r3
  unsigned int v23; // r2
  int v24; // r1
  unsigned int v25; // r3
  int v26[8]; // [sp+0h] [bp-20h] BYREF
  int vars4; // [sp+24h] [bp+4h]

  v26[0] = a3;
  v3 = HIDWORD(a1);
  v4 = (unsigned int *)HeadlessGlobals;
  v5 = a1;
  if ( (*(_DWORD *)(HeadlessGlobals + 24) & 2) != 0 )
  {
    v6 = 255;
  }
  else
  {
    v6 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented((int)v4);
    }
    else
    {
      HIDWORD(a1) = 1;
      do
        v7 = __ldrex(v4);
      while ( __strex(1u, v4) );
      __dmb(0xBu);
      if ( v7 )
        KxWaitForSpinLockAndAcquire(v4);
    }
    v4 = (unsigned int *)HeadlessGlobals;
  }
  v8 = v4[6];
  v9 = 16;
  if ( (v8 & 0x10) != 0 )
  {
    if ( v6 != 255 )
    {
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented(v4, vars4);
      }
      else
      {
        __dmb(0xBu);
        *v4 = 0;
      }
      KfLowerIrql(v6);
    }
    return 0;
  }
  v4[6] = v8 | 0x10;
  if ( v6 != 255 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v4, vars4);
    }
    else
    {
      __dmb(0xBu);
      *v4 = 0;
    }
    a1 = KfLowerIrql(v6);
    v4 = (unsigned int *)HeadlessGlobals;
  }
  v11 = v4[6];
  if ( (v11 & 0x20) != 0 )
    goto LABEL_62;
  while ( 1 )
  {
    while ( 1 )
    {
      if ( InbvPortPollOnly(v4[8], SHIDWORD(a1), v9, v11)
        && InbvPortGetByte(*(_DWORD *)(HeadlessGlobals + 32), (int)v26) )
      {
        HIDWORD(a1) = LOBYTE(v26[0]);
      }
      else
      {
        HIDWORD(a1) = 0;
        LOBYTE(v26[0]) = 0;
      }
      if ( !HIDWORD(a1) )
        goto LABEL_45;
      *(_BYTE *)(*(_DWORD *)(HeadlessGlobals + 56) + *(_DWORD *)(HeadlessGlobals + 16)) = BYTE4(a1);
      v4 = (unsigned int *)HeadlessGlobals;
      v9 = LOBYTE(v26[0]);
      v11 = *(unsigned __int8 *)(HeadlessGlobals + 81);
      if ( !*(_BYTE *)(HeadlessGlobals + 81) || LOBYTE(v26[0]) != 10 )
        break;
      *(_BYTE *)(HeadlessGlobals + 81) = 0;
    }
    *(_BYTE *)(HeadlessGlobals + 81) = LOBYTE(v26[0]) == 13;
    v9 = LOBYTE(v26[0]);
    if ( LOBYTE(v26[0]) == 10 || LOBYTE(v26[0]) == 13 )
      break;
    switch ( LOBYTE(v26[0]) )
    {
      case 8u:
      case 0x7Fu:
        v11 = v4[14];
        if ( v11 )
        {
          HdlspSendStringAtBaud("\b \b");
          v4 = (unsigned int *)HeadlessGlobals;
          v11 = *(_DWORD *)(HeadlessGlobals + 56) - 1;
LABEL_43:
          v4[14] = v11;
        }
        break;
      case 3u:
        v13 = v4[14] + 1;
        v14 = v4[4];
        v4[14] = v13;
        goto LABEL_48;
      case 9u:
      case 0x1Bu:
        HdlspSendStringAtBaud("\a");
LABEL_45:
        *(_DWORD *)(HeadlessGlobals + 24) &= 0xFFFFFFEF;
        return 0;
      default:
        v12 = v4[3];
        if ( v4[14] != 78 )
        {
          sprintf_s(v12, 80, (int)"%c", LOBYTE(v26[0]));
          HdlspSendStringAtBaud(*(_DWORD *)(HeadlessGlobals + 12));
          v4 = (unsigned int *)HeadlessGlobals;
          v11 = *(_DWORD *)(HeadlessGlobals + 56) + 1;
          goto LABEL_43;
        }
        sprintf_s(v12, 80, (int)"\b%c", LOBYTE(v26[0]));
        HdlspSendStringAtBaud(*(_DWORD *)(HeadlessGlobals + 12));
        v4 = (unsigned int *)HeadlessGlobals;
        break;
    }
  }
  HdlspSendStringAtBaud("\r\n");
  v13 = *(_DWORD *)(HeadlessGlobals + 56);
  v14 = *(_DWORD *)(HeadlessGlobals + 16);
LABEL_48:
  *(_BYTE *)(v13 + v14) = 0;
  v4 = (unsigned int *)HeadlessGlobals;
  v15 = *(_DWORD *)(HeadlessGlobals + 56) + 1;
  *(_DWORD *)(HeadlessGlobals + 56) = v15;
  v16 = v15 - 1;
  if ( v15 != 1 )
  {
    v17 = v4[4];
    do
    {
      v18 = *(unsigned __int8 *)(v17 + v16);
      if ( *(_BYTE *)(v17 + v16) && (unsigned __int8)v18 != 32 && v18 != 9 )
        break;
      --v16;
    }
    while ( v16 );
  }
  v19 = (_BYTE *)(v16 + v4[4]);
  if ( *v19 )
  {
    v19[1] = 0;
    v4 = (unsigned int *)HeadlessGlobals;
  }
  v20 = (_BYTE *)v4[4];
  v21 = 0;
  if ( *v20 )
  {
    do
    {
      v22 = (unsigned __int8)v20[v21];
      if ( v22 != 9 && v22 != 32 )
        break;
      ++v21;
    }
    while ( v20[v21] );
    if ( v21 )
    {
      strcpy_s(v20, 80, &v20[v21]);
      v4 = (unsigned int *)HeadlessGlobals;
    }
  }
LABEL_62:
  v23 = v4[14];
  v24 = v4[4];
  if ( v3 < v23 )
  {
    memmove(v5, v24, v3);
    memmove(v4[4], v4[4] + v3, v4[14] - v3);
    v4 = (unsigned int *)HeadlessGlobals;
    *(_DWORD *)(HeadlessGlobals + 24) |= 0x20u;
    v4[14] -= v3;
  }
  else
  {
    memmove(v5, v24, v23);
    v25 = v4[6];
    v4[14] = 0;
    v4[6] = v25 & 0xFFFFFFDF;
  }
  result = 1;
  v4[6] &= 0xFFFFFFEF;
  return result;
}
