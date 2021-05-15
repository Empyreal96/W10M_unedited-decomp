// ArbAddInaccessibleAllocationRange 
 
int __fastcall ArbAddInaccessibleAllocationRange(int a1, int a2)
{
  int v4; // r4
  unsigned __int16 *v5; // r1
  unsigned int v6; // r5
  unsigned __int16 *v8; // r1
  int v9; // r7
  unsigned int v10; // r6
  int v11; // r3
  int v12; // r2
  _DWORD *v13; // [sp+18h] [bp-58h] BYREF
  int v14; // [sp+1Ch] [bp-54h]
  int v15; // [sp+20h] [bp-50h]
  _DWORD *v16; // [sp+24h] [bp-4Ch] BYREF
  __int16 v17[2]; // [sp+28h] [bp-48h] BYREF
  const __int16 *v18; // [sp+2Ch] [bp-44h]
  __int16 v19[2]; // [sp+30h] [bp-40h] BYREF
  const __int16 *v20; // [sp+34h] [bp-3Ch]
  int v21; // [sp+38h] [bp-38h]
  int v22; // [sp+3Ch] [bp-34h]
  __int16 *v23; // [sp+40h] [bp-30h]
  int v24; // [sp+44h] [bp-2Ch]
  int v25; // [sp+48h] [bp-28h]
  int v26; // [sp+4Ch] [bp-24h]

  v16 = 0;
  v17[1] = 118;
  v17[0] = 118;
  v18 = L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Arbiters";
  v21 = 24;
  v22 = 0;
  v23 = v17;
  v25 = 0;
  v26 = 0;
  v24 = 576;
  v4 = ZwOpenKey();
  if ( v4 < 0 )
    return v4;
  v19[1] = 34;
  v19[0] = 34;
  v20 = L"InaccessibleRange";
  v21 = 24;
  v24 = 576;
  v22 = v15;
  v23 = v19;
  v25 = 0;
  v26 = 0;
  v4 = ZwOpenKey();
  if ( v4 >= 0 )
  {
    v5 = *(unsigned __int16 **)(a1 + 12);
    v13 = 0;
    v4 = ArbpGetRegistryValue(v14, v5, (int *)&v13);
    v6 = (unsigned int)v13;
    if ( v4 < 0 )
      return sub_80E894();
    if ( v13[1] == 1 )
    {
      v8 = (unsigned __int16 *)((char *)v13 + v13[2]);
      if ( v8[(v13[3] >> 1) - 1] )
        goto LABEL_20;
      v4 = ArbpGetRegistryValue(v14, v8, (int *)&v16);
      if ( v4 < 0 )
        return sub_80E894();
      ExFreePoolWithTag(v6);
      v6 = (unsigned int)v16;
      v13 = v16;
    }
    if ( *(_DWORD *)(v6 + 4) == 10 )
    {
      v9 = *(_DWORD *)(v6 + 8) + v6 + 32;
      v10 = *(_DWORD *)(v6 + 8) + v6 + 40;
      if ( v10 < v9 + 32 * *(_DWORD *)(*(_DWORD *)(v6 + 8) + v6 + 36) + 8 )
      {
        do
        {
          v11 = *(unsigned __int8 *)(v10 + 1);
          v12 = *(_DWORD *)(a1 + 16);
          if ( v11 == v12 || v11 == 7 && v12 == 3 )
          {
            v4 = RtlAddRange(a2, *(_QWORD *)(v10 + 16), *(_QWORD *)(v10 + 24), 64, 1, 0, 0);
            if ( v4 < 0 )
              break;
          }
          v10 += 32;
        }
        while ( v10 < v9 + 32 * *(_DWORD *)(v9 + 4) + 8 );
        v6 = (unsigned int)v13;
      }
      goto LABEL_15;
    }
LABEL_20:
    v4 = -1073741811;
LABEL_15:
    if ( v6 )
      ExFreePoolWithTag(v6);
    ZwClose();
  }
  ZwClose();
  return v4;
}
