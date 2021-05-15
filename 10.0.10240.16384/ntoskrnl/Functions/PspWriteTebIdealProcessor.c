// PspWriteTebIdealProcessor 
 
unsigned int *__fastcall PspWriteTebIdealProcessor(_DWORD *a1, _DWORD *a2)
{
  int v4; // r5
  int v5; // r9
  unsigned int *v6; // r0
  unsigned int v7; // r4
  unsigned int v8; // r1
  unsigned int *result; // r0
  int v10; // r1
  unsigned int v11; // r3
  char v12; // r3
  unsigned int v13; // r2
  int v14; // r4
  int v15; // r5
  int v16; // lr
  int v17; // r8
  unsigned int v18; // r3
  unsigned int v19; // r2
  unsigned int v20; // r4
  unsigned int v21; // r1
  int v22; // [sp+0h] [bp-58h]
  int v23; // [sp+8h] [bp-50h] BYREF
  int v24; // [sp+Ch] [bp-4Ch]
  int *v25; // [sp+10h] [bp-48h]
  _DWORD *v26; // [sp+14h] [bp-44h]
  int v27; // [sp+18h] [bp-40h]
  _BYTE v28[56]; // [sp+20h] [bp-38h] BYREF

  v26 = a2;
  v24 = a2[39];
  v27 = v24;
  v4 = a2[84];
  v25 = &v23;
  v5 = 0;
  if ( a2 != a1 )
  {
    v6 = a2 + 235;
    __pld(a2 + 235);
    v7 = a2[235] & 0xFFFFFFFE;
    do
      v8 = __ldrex(v6);
    while ( v8 == v7 && __strex(v7 + 2, v6) );
    __dmb(0xBu);
    if ( v8 != v7 )
    {
      result = (unsigned int *)ExfAcquireRundownProtection(v6);
      if ( !result )
        return result;
    }
    v5 = 1;
  }
  v10 = 0;
  if ( v4 != a1[29] )
  {
    KiStackAttachProcess(v4, 0, (int)v28);
    v10 = 1;
  }
  v11 = a2[31];
  if ( v11 )
  {
    if ( v11 < 0x20 )
    {
      result = KiProcessorIndexToNumberMappingTable;
      v13 = KiProcessorIndexToNumberMappingTable[v11];
      if ( v13 )
      {
        LOWORD(v23) = v13 >> 6;
        v12 = v13 & 0x3F;
        HIWORD(v23) = v13 & 0x3F;
      }
      else
      {
        v12 = BYTE2(v23);
      }
      goto LABEL_18;
    }
    v12 = BYTE2(v23);
  }
  else
  {
    v12 = 0;
    v23 = 0;
  }
  result = KiProcessorIndexToNumberMappingTable;
LABEL_18:
  v14 = 0;
  v15 = 0;
  v16 = 0;
  v17 = v24;
  while ( 1 )
  {
    HIBYTE(v23) = v12;
    *(_DWORD *)(v17 + 3956) = v23;
    __dmb(0xFu);
    v18 = a2[31];
    if ( !v18 )
    {
      HIBYTE(v22) = 0;
      v15 = 0;
      v14 = 0;
LABEL_24:
      LOWORD(v22) = v15;
      BYTE2(v22) = v14;
      v16 = v22;
      goto LABEL_25;
    }
    if ( v18 < 0x20 )
    {
      v19 = KiProcessorIndexToNumberMappingTable[v18];
      if ( v19 )
      {
        HIBYTE(v22) = 0;
        v15 = (unsigned __int16)(v19 >> 6);
        v14 = KiProcessorIndexToNumberMappingTable[v18] & 0x3F;
        goto LABEL_24;
      }
    }
LABEL_25:
    if ( v15 == (unsigned __int16)v23 && v14 == BYTE2(v23) )
      break;
    v23 = v16;
    v12 = BYTE2(v16);
  }
  if ( v10 )
    result = (unsigned int *)KiUnstackDetachProcess((unsigned int)v28, 0);
  if ( v5 )
  {
    result = a2 + 235;
    __pld(a2 + 235);
    v20 = a2[235] & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v21 = __ldrex(result);
    while ( v21 == v20 && __strex(v20 - 2, result) );
    if ( v21 != v20 )
      result = (unsigned int *)ExfReleaseRundownProtection((unsigned __int8 *)result);
  }
  return result;
}
