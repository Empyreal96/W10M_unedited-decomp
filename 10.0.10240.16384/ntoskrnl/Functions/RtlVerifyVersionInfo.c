// RtlVerifyVersionInfo 
 
int __fastcall RtlVerifyVersionInfo(int a1, int a2, unsigned int a3, int a4)
{
  char v6; // r8
  int v7; // r9
  int result; // r0
  int v9; // r3
  int v10; // r10
  unsigned int v11; // r4
  int v12; // r9
  int v13; // r3
  int v14; // r4
  int v15; // r0
  int v16; // r0
  int v17; // r0
  int v18; // r0
  int v19; // r0
  int v20; // r0
  int v21; // r0
  char v22[4]; // [sp+8h] [bp-150h] BYREF
  int v23; // [sp+Ch] [bp-14Ch]
  int v24; // [sp+10h] [bp-148h]
  int v25; // [sp+14h] [bp-144h]
  int v26[80]; // [sp+18h] [bp-140h] BYREF

  v23 = 0;
  v6 = a2;
  v7 = a1;
  v25 = a1;
  if ( !a2 )
    return -1073741811;
  memset(v26, 0, 284);
  v26[0] = 284;
  result = RtlGetVersion(v26);
  if ( !result )
  {
    if ( (v6 & 0x40) != 0 )
    {
      LOWORD(v9) = *(_WORD *)(v7 + 280);
      if ( (_WORD)v9 )
      {
        v9 = (unsigned __int16)v9;
        v10 = LOWORD(v26[70]);
        v11 = 0;
        v24 = (unsigned __int16)v9;
        do
        {
          v12 = 1 << v11;
          if ( (v9 & (1 << v11)) != 0 )
          {
            if ( (a4 & 0x80000000) == 0 )
              return -1073741811;
            v15 = RtlpVerGetConditionMask(a3, a4, 64);
            if ( v15 == 6 )
            {
              if ( (v10 & v12) == 0 )
                return -1073741735;
              v9 = v24;
            }
            else
            {
              if ( v15 != 7 )
                return -1073741811;
              v9 = v24;
              if ( (v10 & v12) != 0 )
                return sub_552FF4();
            }
          }
          ++v11;
        }
        while ( v11 < 0x10 );
        if ( RtlpVerGetConditionMask(a3, a4, 64) == 7 )
          return -1073741735;
        v7 = v25;
      }
    }
    v13 = 1;
    v14 = 1;
    v22[0] = 1;
    if ( (v6 & 2) != 0 )
    {
      if ( (a4 & 0x80000000) != 0 )
        v14 = RtlpVerGetConditionMask(a3, a4, 2);
      else
        v14 = (unsigned __int8)(a3 >> 4);
      v17 = RtlpVerCompare(v14, *(_DWORD *)(v7 + 4), v26[1], v22, 0);
      v13 = (unsigned __int8)v22[0];
      if ( v17 )
      {
        if ( !v22[0] )
          goto LABEL_16;
      }
      else if ( !v22[0] )
      {
        return -1073741735;
      }
    }
    if ( (v6 & 1) == 0 )
      goto LABEL_12;
    if ( v14 == 1 )
    {
      if ( (a4 & 0x80000000) != 0 )
        v14 = RtlpVerGetConditionMask(a3, a4, 1);
      else
        v14 = (unsigned __int8)(a3 >> 2);
    }
    v18 = RtlpVerCompare(v14, *(_DWORD *)(v7 + 8), v26[2], v22, 1);
    v13 = (unsigned __int8)v22[0];
    if ( v18 )
    {
LABEL_12:
      if ( !v13 )
        goto LABEL_16;
    }
    else if ( !v22[0] )
    {
      return -1073741735;
    }
    if ( (v6 & 0x20) != 0 )
    {
      if ( v14 == 1 )
      {
        if ( (a4 & 0x80000000) != 0 )
          v14 = RtlpVerGetConditionMask(a3, a4, 32);
        else
          v14 = 0;
      }
      v19 = RtlpVerCompare(v14, *(unsigned __int16 *)(v7 + 276), LOWORD(v26[69]), v22, 0);
      v13 = (unsigned __int8)v22[0];
      if ( !v19 )
      {
        if ( !v22[0] )
          return -1073741735;
        goto LABEL_15;
      }
    }
    if ( v13 )
    {
LABEL_15:
      if ( (v6 & 0x10) != 0 )
      {
        if ( v14 == 1 )
        {
          if ( (a4 & 0x80000000) != 0 )
            v14 = RtlpVerGetConditionMask(a3, a4, 16);
          else
            v14 = 0;
        }
        if ( !RtlpVerCompare(v14, *(unsigned __int16 *)(v7 + 278), HIWORD(v26[69]), v22, 1) )
          return -1073741735;
      }
    }
LABEL_16:
    if ( (v6 & 4) != 0 )
    {
      v20 = (a4 & 0x80000000) != 0 ? RtlpVerGetConditionMask(a3, a4, 4) : BYTE2(a3);
      if ( !RtlpVerCompare(v20, *(_DWORD *)(v7 + 12), v26[3], v22, 0) )
        return -1073741735;
    }
    if ( (v6 & 8) != 0 )
    {
      v21 = (a4 & 0x80000000) != 0 ? RtlpVerGetConditionMask(a3, a4, 8) : 0;
      if ( !RtlpVerCompare(v21, *(_DWORD *)(v7 + 16), v26[4], v22, 0) )
        return -1073741735;
    }
    if ( (v6 & 0x80) != 0 )
    {
      v16 = (a4 & 0x80000000) != 0 ? RtlpVerGetConditionMask(a3, a4, 128) : 0;
      if ( !RtlpVerCompare(v16, *(unsigned __int8 *)(v7 + 282), BYTE2(v26[70]), v22, 0) )
        return -1073741735;
    }
    result = 0;
  }
  return result;
}
