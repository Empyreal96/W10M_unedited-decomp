// ArbAddMmConfigRangeAsBootReserved 
 
int __fastcall ArbAddMmConfigRangeAsBootReserved(int a1, int a2)
{
  int v3; // r6
  unsigned int v4; // r4
  int v5; // r5
  int v8; // r3
  unsigned int i; // r7
  int v10; // r7
  int v11; // r0
  int v12; // r3
  int v13; // r2
  unsigned int v14; // [sp+1Ch] [bp-54h] BYREF
  int v15; // [sp+20h] [bp-50h]
  __int16 v16[2]; // [sp+28h] [bp-48h] BYREF
  const __int16 *v17; // [sp+2Ch] [bp-44h]
  __int16 v18[2]; // [sp+30h] [bp-40h] BYREF
  const __int16 *v19; // [sp+34h] [bp-3Ch]
  int v20; // [sp+38h] [bp-38h]
  int v21; // [sp+3Ch] [bp-34h]
  __int16 *v22; // [sp+40h] [bp-30h]
  int v23; // [sp+44h] [bp-2Ch]
  int v24; // [sp+48h] [bp-28h]
  int v25; // [sp+4Ch] [bp-24h]

  v3 = ArbMmConfigRange;
  v4 = 0;
  v5 = 0;
  v15 = 0;
  if ( ArbMmConfigRange )
    goto LABEL_8;
  v16[1] = 118;
  v16[0] = 118;
  v17 = L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Arbiters";
  v20 = 24;
  v21 = 0;
  v22 = v16;
  v23 = 576;
  v24 = 0;
  v25 = 0;
  v5 = ZwOpenKey();
  if ( v5 >= 0 )
  {
    v18[1] = 34;
    v18[0] = 34;
    v19 = L"ReservedResources";
    v20 = 24;
    v23 = 576;
    v21 = v15;
    v22 = v18;
    v24 = 0;
    v25 = 0;
    v5 = ZwOpenKey();
    if ( v5 < 0 )
    {
LABEL_12:
      ZwClose();
      return v5;
    }
    v14 = 0;
    v5 = ArbpGetRegistryValue(0, L"MmConfigRange", (int *)&v14);
    v4 = v14;
    if ( v5 < 0 )
      return sub_80E8B8();
    if ( *(_DWORD *)(v14 + 4) != 10 )
    {
      v5 = -1073741811;
LABEL_9:
      if ( v4 )
        ExFreePoolWithTag(v4);
      ZwClose();
      goto LABEL_12;
    }
    v3 = *(_DWORD *)(v14 + 8) + v14 + 32;
    v8 = *(_DWORD *)(*(_DWORD *)(v14 + 8) + v14 + 36);
    if ( v8 )
    {
      v10 = 32 * (v8 - 1);
      v11 = ExAllocatePoolWithTag(512, v10 + 40, 1315074625);
      ArbMmConfigRange = v11;
      if ( v11 )
        memmove(v11, v3, v10 + 40);
    }
LABEL_8:
    for ( i = v3 + 8; i < v3 + 32 * *(_DWORD *)(v3 + 4) + 8; i += 32 )
    {
      v12 = *(unsigned __int8 *)(i + 1);
      v13 = *(_DWORD *)(a1 + 16);
      if ( v12 == v13 || v12 == 7 && v13 == 3 )
      {
        v5 = RtlAddRange(a2, *(_QWORD *)(i + 16), *(_QWORD *)(i + 24), 1, 1, 0, 0);
        if ( v5 < 0 )
          break;
      }
    }
    goto LABEL_9;
  }
  return v5;
}
