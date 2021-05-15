// PiPnpRtlGetFilteredDeviceList 
 
int __fastcall PiPnpRtlGetFilteredDeviceList(_DWORD *a1)
{
  int v2; // r3
  unsigned __int16 *v3; // r6
  int v5; // r1
  int v7; // r4
  _WORD *v8; // r0
  int v9; // r4
  _WORD *v10; // r0
  unsigned __int16 *v11; // r0
  _WORD *v12; // r3
  unsigned int v13; // [sp+10h] [bp-48h] BYREF
  _WORD *v14; // [sp+14h] [bp-44h] BYREF
  __int16 v15; // [sp+18h] [bp-40h] BYREF
  int v16; // [sp+1Ah] [bp-3Eh]
  __int16 v17; // [sp+1Eh] [bp-3Ah]
  __int16 *v18; // [sp+20h] [bp-38h] BYREF
  BOOL v19; // [sp+24h] [bp-34h]
  int v20; // [sp+28h] [bp-30h]
  int v21; // [sp+2Ch] [bp-2Ch]

  v15 = 0;
  v16 = 0;
  v17 = 0;
  v2 = a1[3];
  v3 = 0;
  if ( (v2 & 0x7C) != 0 )
  {
    v7 = -1073741802;
LABEL_22:
    if ( v3 )
      ExFreePoolWithTag((unsigned int)v3);
    return v7;
  }
  if ( (v2 & 1) != 0 )
  {
    v8 = (_WORD *)a1[2];
    if ( v8 )
    {
      v9 = 0;
      while ( *v8 )
      {
        if ( *v8 == 92 )
          break;
        if ( (unsigned int)++v9 > 2 )
          break;
        v10 = wcschr(v8, 92);
        if ( v10 )
        {
          v8 = v10 + 1;
          if ( v8 )
            continue;
        }
        v11 = (unsigned __int16 *)ExAllocatePoolWithTag(1, 400, 1198550608);
        v3 = v11;
        if ( !v11 )
          return -1073741670;
        v7 = RtlStringCchCopyExW(v11, 200, a1[2], &v14, &v13, 2048);
        if ( v7 >= 0 )
        {
          if ( v13 < 2 )
          {
            v7 = -1073741811;
          }
          else
          {
            v12 = v14;
            *v14 = 92;
            v12[1] = 0;
            v7 = RtlInitUnicodeStringEx((int)&v15, v3);
            if ( v7 >= 0 )
            {
              v19 = 0;
              v20 = 0;
              v21 = 0;
              v18 = &v15;
              v19 = (a1[3] & 0x100) != 0;
              v20 = a1[4];
              v21 = a1[5];
              v7 = PiDmGetCmObjectListFromCache(1, PiPnpRtlEnumeratorFilterCallback, &v18, a1[6], a1[7], a1[8]);
            }
          }
        }
        goto LABEL_22;
      }
    }
    return -1073741811;
  }
  if ( (v2 & 2) != 0 )
    return sub_7EA198();
  if ( (v2 & 0x80) == 0 )
  {
    v18 = 0;
    v20 = 0;
    v21 = 0;
    v19 = (v2 & 0x100) != 0;
    v20 = a1[4];
    v21 = a1[5];
    return PiDmGetCmObjectListFromCache(1, PiPnpRtlEnumeratorFilterCallback, &v18, a1[6], a1[7], a1[8]);
  }
  v5 = a1[2];
  if ( !v5 )
    return -1073741811;
  v18 = 0;
  v20 = 0;
  v21 = 0;
  v19 = (v2 & 0x100) != 0;
  v20 = a1[4];
  v21 = a1[5];
  return PiDmGetCmObjectConstraintListFromCache(
           4,
           v5,
           (int)PiPnpRtlEnumeratorFilterCallback,
           (int)&v18,
           a1[6],
           a1[7],
           a1[8]);
}
