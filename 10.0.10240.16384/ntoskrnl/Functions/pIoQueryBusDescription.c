// pIoQueryBusDescription 
 
int __fastcall pIoQueryBusDescription(int a1, int a2, int a3, int a4, int *a5, unsigned __int8 a6)
{
  int v7; // r4
  unsigned int v8; // r5
  unsigned int v9; // r3
  int v10; // r7
  int v11; // r5
  int v12; // r10
  _DWORD *v13; // r3
  unsigned int v14; // r5
  int v15; // r2
  unsigned int v16; // r0
  int v17; // r1
  _DWORD *v18; // r3
  int v19; // r0
  _DWORD *v20; // r3
  int v21; // r3
  int v23; // [sp+20h] [bp-58h] BYREF
  int v24; // [sp+28h] [bp-50h] BYREF
  int v25; // [sp+2Ch] [bp-4Ch]
  int v26; // [sp+30h] [bp-48h]
  unsigned __int16 v27[2]; // [sp+38h] [bp-40h] BYREF
  int v28; // [sp+3Ch] [bp-3Ch]
  unsigned int v29; // [sp+40h] [bp-38h] BYREF
  unsigned int v30; // [sp+48h] [bp-30h] BYREF
  unsigned int v31; // [sp+4Ch] [bp-2Ch]
  unsigned int v32; // [sp+50h] [bp-28h]
  int varg_r0; // [sp+80h] [bp+8h]
  int varg_r1; // [sp+84h] [bp+Ch]
  int varg_r2; // [sp+88h] [bp+10h]
  int varg_r3; // [sp+8Ch] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v26 = a4;
  v7 = IopGetRegistryKeyInformation(a4, (int *)&v29, a3);
  if ( v7 >= 0 )
  {
    v8 = v29;
    v9 = *(_DWORD *)(v29 + 24);
    if ( v9 + 32 < v9 )
      return -1073741675;
    v7 = 0;
    v10 = ExAllocatePoolWithTag(1, v9 + 32, 1112239945);
    ExFreePoolWithTag(v8);
    if ( !v10 )
      return -1073741670;
    v11 = a6;
    v12 = 0;
    while ( 1 )
    {
      v13 = *(_DWORD **)(a1 + 4);
      if ( v13 && *v13 == *a5 || (v7 = ZwEnumerateKey(), v7 < 0) )
      {
LABEL_40:
        ExFreePoolWithTag(v10);
        return v7;
      }
      if ( v11 )
      {
        v14 = *(_DWORD *)(v10 + 12);
        if ( wcsncmp((_WORD *)(v10 + 16), L"MultifunctionAdapter", v14 >> 1)
          && wcsncmp((_WORD *)(v10 + 16), L"EisaAdapter", v14 >> 1)
          && wcsncmp((_WORD *)(v10 + 16), L"TcAdapter", v14 >> 1) )
        {
          goto LABEL_39;
        }
        v11 = a6;
      }
      v28 = v10 + 16;
      v27[0] = *(_DWORD *)(v10 + 12);
      v27[1] = *(_DWORD *)(v10 + 12);
      if ( IopOpenRegistryKey((int)&v23, v26, (int)v27, 131097, 0) >= 0 )
        break;
LABEL_39:
      v11 = a6;
      ++v12;
      if ( v7 < 0 )
        goto LABEL_40;
    }
    v24 = varg_r1;
    v25 = varg_r2;
    RtlAppendUnicodeToString((unsigned __int16 *)&v24, (int)L"\\", v15, varg_r2);
    RtlAppendUnicodeStringToString((unsigned __int16 *)&v24, v27);
    if ( v11 )
    {
      v21 = 0;
    }
    else
    {
      v7 = IopGetRegistryValues(v23, (int *)&v30);
      if ( v7 >= 0 )
      {
        v16 = v31;
        if ( v31 )
        {
          if ( *(_DWORD *)(v31 + 12) )
          {
            if ( *(_DWORD *)(*(_DWORD *)(v31 + 8) + v31) == **(_DWORD **)a1 )
            {
              v17 = *a5 + 1;
              *a5 = v17;
              v18 = *(_DWORD **)(a1 + 4);
              if ( !v18 || *v18 == v17 )
              {
                if ( *(_DWORD *)(a1 + 8) )
                  v19 = pIoQueryDeviceDescription(a1, v24, v25);
                else
                  v19 = (*(int (__fastcall **)(_DWORD, int *, _DWORD, int, unsigned int *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(a1 + 24))(
                          *(_DWORD *)(a1 + 28),
                          &v24,
                          **(_DWORD **)a1,
                          v17,
                          &v30,
                          0,
                          0,
                          0,
                          0,
                          0,
                          0);
                v7 = v19;
                v16 = v31;
              }
            }
          }
        }
        if ( v30 )
        {
          ExFreePoolWithTag(v30);
          v16 = v31;
          v30 = 0;
        }
        if ( v16 )
        {
          ExFreePoolWithTag(v16);
          v31 = 0;
        }
        if ( v32 )
        {
          ExFreePoolWithTag(v32);
          v32 = 0;
        }
      }
      v20 = *(_DWORD **)(a1 + 4);
      if ( v20 && *v20 == *a5 )
        goto LABEL_38;
      v21 = 1;
    }
    v7 = pIoQueryBusDescription(a1, v24, v25, v23, a5, v21);
    if ( v7 == -2147483622 )
      v7 = 0;
LABEL_38:
    ZwClose();
    v23 = 0;
    goto LABEL_39;
  }
  return v7;
}
