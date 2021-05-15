// RtlpQueryRegistryValues 
 
int __fastcall RtlpQueryRegistryValues(int a1, unsigned __int16 *a2, _DWORD *a3, int a4, int a5, unsigned __int8 a6)
{
  int v6; // r10
  int v10; // r4
  unsigned __int16 *v11; // r1
  int v12; // r0
  _DWORD *v13; // r6
  int v15; // r0
  int v16; // r8
  int v17; // r5
  int v18; // r2
  __int64 v19; // kr00_8
  int v20; // r5
  bool v21; // cc
  int v22; // r0
  int v23; // r4
  int v24; // r0
  int v25; // r9
  int i; // r8
  int v27; // r4
  int v28; // r0
  int v29; // [sp+10h] [bp-70h]
  int v30; // [sp+10h] [bp-70h]
  int v31; // [sp+14h] [bp-6Ch]
  int v32; // [sp+18h] [bp-68h] BYREF
  int v33; // [sp+1Ch] [bp-64h] BYREF
  int v34; // [sp+20h] [bp-60h]
  int v35; // [sp+24h] [bp-5Ch] BYREF
  int v36; // [sp+28h] [bp-58h]
  int v37; // [sp+2Ch] [bp-54h]
  int v38; // [sp+30h] [bp-50h]
  __int16 v39[2]; // [sp+38h] [bp-48h] BYREF
  _DWORD *v40; // [sp+3Ch] [bp-44h]
  char v41[8]; // [sp+40h] [bp-40h] BYREF
  int v42; // [sp+48h] [bp-38h]
  int v43; // [sp+4Ch] [bp-34h]
  char *v44; // [sp+50h] [bp-30h]
  int v45; // [sp+54h] [bp-2Ch]
  int v46; // [sp+58h] [bp-28h]
  int v47; // [sp+5Ch] [bp-24h]

  v6 = a4;
  v37 = a4;
  v10 = RtlpGetRegistryHandle(a1, a2, 0, &v32);
  if ( v10 < 0 )
    return v10;
  v38 = a1 & 0x40000000;
  if ( (a1 & 0x40000000) != 0 )
    v11 = 0;
  else
    v11 = a2;
  RtlInitUnicodeString((unsigned int)v41, v11);
  v35 = 132;
  v12 = RtlpAllocDeallocQueryBuffer(&v35, 0);
  v13 = (_DWORD *)v12;
  if ( !v12 )
    return sub_80A7C0();
  *(_DWORD *)(v12 + 8) = 0;
  v15 = v32;
  v16 = 130;
  v17 = v32;
  v31 = v32;
  v36 = -2147483643;
  v34 = 130;
  while ( 2 )
  {
    if ( !*a3 && (a3[1] & 0x21) == 0 )
      goto LABEL_32;
    v18 = a3[1];
    if ( (v18 & 0x20) != 0 && (!a3[2] || (v18 & 1) != 0 || *a3) )
    {
LABEL_76:
      v10 = -1073741811;
      goto LABEL_32;
    }
    if ( (v18 & 3) != 0 && v17 != v15 )
    {
      ZwClose();
      v15 = v32;
      v17 = v32;
      v31 = v32;
    }
    v19 = *(_QWORD *)(a3 + 1);
    if ( (v19 & 1) != 0 )
    {
      if ( !HIDWORD(v19) )
        goto LABEL_76;
      RtlInitUnicodeString((unsigned int)v41, (unsigned __int16 *)HIDWORD(v19));
      v42 = 24;
      v43 = v32;
      v45 = 576;
      v44 = v41;
      v46 = 0;
      v47 = 0;
      v10 = ZwOpenKey();
      if ( v10 < 0 )
        break;
      if ( !*a3 )
        goto LABEL_21;
LABEL_54:
      v25 = 0;
      for ( i = 0; ; ++i )
      {
        v10 = ZwEnumerateValueKey();
        v30 = v10;
        if ( v10 == v36 )
        {
          v10 = -1073741789;
          v30 = -1073741789;
        }
        if ( v10 == -2147483622 )
        {
          if ( i || (a3[1] & 4) == 0 )
          {
            v10 = 0;
            goto LABEL_22;
          }
          v10 = -1073741772;
          goto LABEL_31;
        }
        if ( v10 >= 0 )
        {
          v33 = v34;
          v10 = RtlpCallQueryRegistryRoutine(v31, a3, v13, &v33, v37, &v33, a6);
          v30 = v10;
        }
        if ( v10 == -1073741789 )
        {
          v27 = v33 + 6;
          v35 = v33 + 6;
          v28 = RtlpAllocDeallocQueryBuffer(&v35, v13);
          v13 = (_DWORD *)v28;
          if ( !v28 )
            goto LABEL_69;
          *(_DWORD *)(v28 + 8) = 0;
          v21 = v25 <= 4;
          v34 = v27 - 2;
          ++v25;
          --i;
          if ( !v21 )
          {
            DbgPrint("RtlpQueryRegistryValues: Miscomputed buffer size at line %d\n", 1439);
LABEL_69:
            v10 = v30;
            goto LABEL_21;
          }
        }
        else
        {
          if ( v10 < 0 )
            goto LABEL_31;
          v25 = 0;
          if ( (a3[1] & 0x40) != 0 )
          {
            v40 = v13 + 5;
            v39[0] = v13[4];
            v39[1] = v13[4];
            if ( ZwDeleteValueKey() >= 0 )
              --i;
          }
        }
      }
    }
    if ( !HIDWORD(v19) )
    {
      if ( (v19 & 8) != 0 )
      {
        v10 = ((int (__fastcall *)(_DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD))*a3)(0, 0, 0, 0, v6, a3[3]);
        goto LABEL_21;
      }
      goto LABEL_54;
    }
    RtlInitUnicodeString((unsigned int)v39, (unsigned __int16 *)HIDWORD(v19));
    v20 = 0;
    while ( 1 )
    {
      v21 = v20++ <= 4;
      if ( !v21 )
      {
        DbgPrint("RtlpQueryRegistryValues: Miscomputed buffer size at line %d\n", 1258);
        goto LABEL_31;
      }
      v10 = ZwQueryValueKey();
      v29 = v10;
      if ( v10 == v36 )
      {
        v10 = -1073741789;
        v29 = -1073741789;
      }
      if ( v10 >= 0 )
        break;
      if ( v10 == -1073741772 )
      {
        v13[1] = 0;
        v13[3] = 0;
        v33 = v16;
        v10 = RtlpCallQueryRegistryRoutine(v31, a3, v13, &v33, v6, &v33, a6);
        v29 = v10;
      }
      if ( v10 != -1073741789 )
        goto LABEL_21;
LABEL_51:
      v23 = v33 + 6;
      v35 = v33 + 6;
      v24 = RtlpAllocDeallocQueryBuffer(&v35, v13);
      v13 = (_DWORD *)v24;
      if ( !v24 )
      {
        v10 = v29;
        goto LABEL_31;
      }
      v16 = v23 - 2;
      v10 = v29;
      *(_DWORD *)(v24 + 8) = 0;
      v34 = v16;
    }
    if ( v13[1] == 7 )
    {
      *(_WORD *)((char *)v13 + v33) = 0;
      v13[3] += 2;
    }
    v33 = v16;
    v22 = RtlpCallQueryRegistryRoutine(v31, a3, v13, &v33, v6, &v33, a6);
    v10 = v22;
    v29 = v22;
    if ( v22 == -1073741789 )
      goto LABEL_51;
    if ( v22 < 0 )
      break;
    if ( (a3[1] & 0x40) != 0 )
      ZwDeleteValueKey();
LABEL_21:
    if ( v10 >= 0 )
    {
LABEL_22:
      v17 = v31;
      v15 = v32;
      v16 = v34;
      v6 = v37;
      a3 += 7;
      continue;
    }
    break;
  }
LABEL_31:
  v17 = v31;
  v15 = v32;
LABEL_32:
  if ( v15 && !v38 )
  {
    ZwClose();
    v17 = v31;
    v15 = v32;
  }
  if ( v17 != v15 )
  {
    if ( v17 )
      ZwClose();
  }
  RtlpAllocDeallocQueryBuffer(0, v13);
  return v10;
}
