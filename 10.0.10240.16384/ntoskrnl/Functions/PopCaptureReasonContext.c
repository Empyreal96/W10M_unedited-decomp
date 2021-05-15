// PopCaptureReasonContext 
 
int __fastcall PopCaptureReasonContext(int a1, char a2, bool *a3, int *a4)
{
  unsigned int v6; // r9
  unsigned int v7; // r8
  unsigned int v8; // r4
  int v9; // r0
  int v10; // r0
  int v11; // r5
  unsigned int v12; // r6
  int v13; // r0
  unsigned int v14; // r2
  int v15; // r4
  unsigned int v17; // r5
  unsigned int v18; // r2
  unsigned __int16 *v19; // r1
  int v20; // t1
  unsigned int v21; // r3
  unsigned int v22; // r2
  int v23; // r3
  unsigned int v24; // r6
  __int64 *v25; // r2
  __int64 *v26; // r0
  int v27; // [sp+0h] [bp-38h]
  int v28; // [sp+4h] [bp-34h] BYREF
  unsigned int v29; // [sp+8h] [bp-30h]
  int *v30; // [sp+Ch] [bp-2Ch]
  __int64 v31; // [sp+10h] [bp-28h] BYREF

  *a4 = 0;
  v30 = a4;
  v27 = a2;
  v6 = 16;
  if ( a3 )
    *a3 = 0;
  v28 = 0;
  v29 = 0;
  v7 = 0;
  if ( !a1 )
  {
    v8 = 0x80000000;
    goto LABEL_8;
  }
  if ( *(_DWORD *)a1 )
    return -1073741811;
  v8 = *(_DWORD *)(a1 + 4);
  if ( (v8 & 1) != 0 )
  {
    if ( ((*(unsigned __int16 *)(a1 + 8) + 2) & 1) == 0 )
    {
      v6 = *(unsigned __int16 *)(a1 + 8) + 38;
LABEL_8:
      v9 = a2;
      goto LABEL_9;
    }
    return -1073741811;
  }
  if ( (v8 & 2) == 0 )
  {
    if ( (v8 & 0x80000000) != 0 )
      goto LABEL_8;
    return -1073741811;
  }
  if ( ((*(unsigned __int16 *)(a1 + 8) + 2) & 1) != 0 )
    return -1073741811;
  v6 = *(unsigned __int16 *)(a1 + 8) + 38;
  v29 = *(_DWORD *)(a1 + 20);
  v17 = v29;
  if ( ULongLongToULong(8 * v17, v17 >> 29, &v28) < 0 )
    return -1073741811;
  v9 = v27;
  v7 = *(_DWORD *)(a1 + 24);
  if ( v27 && v28 )
  {
    if ( (v7 & 3) != 0 )
      sub_5294D8();
    if ( v7 + v28 > MmUserProbeAddress || v7 + v28 < v7 )
      *(_BYTE *)MmUserProbeAddress = 0;
  }
  v18 = 0;
  if ( v17 )
  {
    v19 = (unsigned __int16 *)v7;
    do
    {
      v20 = *v19;
      v19 += 4;
      v21 = v20 + 2 + v6;
      if ( v21 < v6 )
        return -1073741811;
      ++v18;
      v6 = v21;
    }
    while ( v18 < v17 );
  }
LABEL_9:
  if ( v9 )
    v10 = ExAllocatePoolWithQuotaTag(9u, v6, 2017677904);
  else
    v10 = ExAllocatePoolWithTag(1, v6, 2017677904);
  v11 = v10;
  if ( !v10 )
    JUMPOUT(0x5294DC);
  *v30 = v10;
  if ( (v8 & 0x80000000) == 0 )
  {
    v12 = (v10 + 19) & 0xFFFFFFFC;
    *(_DWORD *)(v10 + 12) = v10 - v12 + v6;
    v28 = v12 + 20;
    *(_DWORD *)v12 = v8;
    v13 = a1 + 8;
    v14 = v11 + v6;
    if ( (v8 & 1) != 0 )
    {
      *(_DWORD *)(v12 + 4) = 20;
      v15 = PopSafeCopyUnicodeString(v13, &v28, v14, v27);
      if ( v15 >= 0 )
        goto LABEL_15;
    }
    else
    {
      *(_DWORD *)(v12 + 4) = 20;
      v15 = PopSafeCopyUnicodeString(v13, &v28, v14, v27);
      if ( v15 >= 0 )
      {
        v22 = v29;
        *(_WORD *)(v12 + 8) = *(_WORD *)(a1 + 16);
        v23 = v28;
        *(_DWORD *)(v12 + 12) = v22;
        *(_DWORD *)(v12 + 16) = v23 - v12;
        v24 = 0;
        if ( !v22 )
        {
LABEL_15:
          if ( a3 )
            *a3 = (*(_DWORD *)(a1 + 4) & 4) != 0;
          return 0;
        }
        while ( 1 )
        {
          if ( v27 )
          {
            v25 = (__int64 *)v7;
            if ( v7 >= MmUserProbeAddress )
              v25 = (__int64 *)MmUserProbeAddress;
            v26 = &v31;
            v31 = *v25;
          }
          else
          {
            v26 = (__int64 *)v7;
          }
          v15 = PopSafeCopyUnicodeString(v26, &v28, v11 + v6, v27);
          if ( v15 < 0 )
            break;
          ++v24;
          v7 += 8;
          if ( v24 >= v29 )
            goto LABEL_15;
        }
      }
    }
    ExFreePoolWithTag(v11, 2017677904);
    *v30 = 0;
    return v15;
  }
  *(_DWORD *)(v10 + 12) = 0;
  return 0;
}
