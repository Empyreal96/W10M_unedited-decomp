// NtCompareTokens 
 
int __fastcall NtCompareTokens(int a1, int a2, char *a3, int a4)
{
  unsigned int v6; // r6
  int v7; // r1
  int v8; // r8
  unsigned int v9; // r5
  char v10; // r4
  unsigned int v11; // r2
  unsigned int v12; // r2
  int v13; // r0
  unsigned int v14; // r2
  int v15; // r4
  int v16; // r9
  unsigned __int16 *v17; // r0
  int v18; // r3
  unsigned __int16 *v19; // r1
  int v20; // r2
  BOOL v21; // r4
  BOOL v22; // r4
  int v23; // r0
  unsigned int v24; // r1
  __int16 v25; // r3
  int v26; // r0
  unsigned int v27; // r1
  __int16 v28; // r3
  int v30; // [sp+14h] [bp-44h]
  int v31; // [sp+18h] [bp-40h]
  int v32; // [sp+1Ch] [bp-3Ch] BYREF
  int v33; // [sp+20h] [bp-38h] BYREF
  int v34; // [sp+24h] [bp-34h]
  int v35; // [sp+28h] [bp-30h]
  char *v36; // [sp+2Ch] [bp-2Ch]
  _DWORD _34[15]; // [sp+34h] [bp-24h] BYREF

  _34[14] = a4;
  v36 = a3;
  _34[13] = a3;
  _34[12] = a2;
  _34[11] = a1;
  v6 = 0;
  _34[0] = 0;
  v30 = 0;
  v32 = 0;
  v33 = 0;
  v34 = 0;
  v35 = 0;
  v7 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v31 = v7;
  if ( v7 )
  {
    if ( (unsigned int)a3 >= MmUserProbeAddress )
      a3 = (char *)MmUserProbeAddress;
    *a3 = *a3;
  }
  v8 = ObReferenceObjectByHandle(a1, 8, SeTokenObjectType, v7, _34);
  v9 = _34[0];
  if ( v8 >= 0 )
  {
    if ( a1 != a2 )
    {
      v8 = ObReferenceObjectByHandle(a2, 8, SeTokenObjectType, v31, _34);
      v6 = _34[0];
      if ( v8 < 0 )
      {
        v6 = 0;
        goto LABEL_44;
      }
      if ( v9 != _34[0] )
      {
        v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v11 + 308);
        if ( v9 >= v6 )
        {
          ExAcquireResourceSharedLite(*(_DWORD *)(v6 + 48), 1);
          v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          --*(_WORD *)(v14 + 308);
          v13 = *(_DWORD *)(v9 + 48);
        }
        else
        {
          ExAcquireResourceSharedLite(*(_DWORD *)(v9 + 48), 1);
          v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          --*(_WORD *)(v12 + 308);
          v13 = *(_DWORD *)(v6 + 48);
        }
        ExAcquireResourceSharedLite(v13, 1);
        v30 = 1;
        v15 = *(_DWORD *)(v6 + 148);
        v16 = *(_DWORD *)(v9 + 148);
        if ( !RtlEqualSid(*(unsigned __int16 **)v16, *(unsigned __int16 **)v15) )
          goto LABEL_44;
        if ( ((*(_DWORD *)(v16 + 4) ^ *(_DWORD *)(v15 + 4)) & 0x14) != 0 )
          goto LABEL_44;
        v8 = SeQueryInformationToken(v9, 29, &v32);
        if ( v8 < 0 )
          goto LABEL_44;
        v8 = SeQueryInformationToken(v6, 29, &v33);
        if ( v8 < 0
          || v32 != v33
          || v32
          && (!RtlEqualSid(*(unsigned __int16 **)(v9 + 480), *(unsigned __int16 **)(v6 + 480))
           || !SepCompareSidAndAttributeArrays(
                 *(_DWORD *)(v9 + 484),
                 *(_DWORD *)(v9 + 488),
                 *(_DWORD *)(v6 + 484),
                 *(_DWORD *)(v6 + 488))) )
        {
          goto LABEL_44;
        }
        v17 = *(unsigned __int16 **)(v9 + 640);
        v18 = v17 ? 1 : v34;
        v19 = *(unsigned __int16 **)(v6 + 640);
        v20 = v19 ? 1 : v35;
        if ( v18 != v20 || v18 && !RtlEqualSid(v17, v19) )
          goto LABEL_44;
        v21 = SeTokenIsRestricted(v9);
        if ( v21 != SeTokenIsRestricted(v6) )
          goto LABEL_44;
        if ( v21 )
        {
          v22 = SeTokenIsWriteRestricted(v9);
          if ( v22 != SeTokenIsWriteRestricted(v6)
            || !SepCompareSidAndAttributeArrays(
                  *(_DWORD *)(v9 + 152),
                  *(_DWORD *)(v9 + 128),
                  *(_DWORD *)(v6 + 152),
                  *(_DWORD *)(v6 + 128)) )
          {
            goto LABEL_44;
          }
        }
        if ( *(_DWORD *)(v9 + 72) != *(_DWORD *)(v6 + 72)
          || *(_DWORD *)(v9 + 76) != *(_DWORD *)(v6 + 76)
          || *(_DWORD *)(v9 + 64) != *(_DWORD *)(v6 + 64)
          || *(_DWORD *)(v9 + 68) != *(_DWORD *)(v6 + 68)
          || *(_DWORD *)(v9 + 188) != *(_DWORD *)(v6 + 188)
          || !SepCompareSidAndAttributeArrays(
                *(_DWORD *)(v9 + 148) + 8,
                *(_DWORD *)(v9 + 124) - 1,
                *(_DWORD *)(v6 + 148) + 8,
                *(_DWORD *)(v6 + 124) - 1)
          || !SepCompareClaimAttributes(*(_DWORD *)(v9 + 636), *(_DWORD *)(v6 + 636))
          || !AuthzBasepCompareLegacySecurityAttributesInformation(*(_DWORD *)(v9 + 476), *(_DWORD *)(v6 + 476)) )
        {
          goto LABEL_44;
        }
      }
    }
    v10 = 1;
    goto LABEL_45;
  }
  v9 = 0;
LABEL_44:
  v10 = 0;
LABEL_45:
  if ( v30 )
  {
    v23 = ExReleaseResourceLite(*(_DWORD *)(v9 + 48));
    v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v25 = *(_WORD *)(v24 + 0x134) + 1;
    *(_WORD *)(v24 + 308) = v25;
    if ( !v25 && *(_DWORD *)(v24 + 100) != v24 + 100 && !*(_WORD *)(v24 + 310) )
      KiCheckForKernelApcDelivery(v23);
    v26 = ExReleaseResourceLite(*(_DWORD *)(v6 + 48));
    v27 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v28 = *(_WORD *)(v27 + 0x134) + 1;
    *(_WORD *)(v27 + 308) = v28;
    if ( !v28 && *(_DWORD *)(v27 + 100) != v27 + 100 && !*(_WORD *)(v27 + 310) )
      KiCheckForKernelApcDelivery(v26);
  }
  if ( v9 )
    ObfDereferenceObject(v9);
  if ( v6 )
    ObfDereferenceObject(v6);
  *v36 = v10;
  return v8;
}
