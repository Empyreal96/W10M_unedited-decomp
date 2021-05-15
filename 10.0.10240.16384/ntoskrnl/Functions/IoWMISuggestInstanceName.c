// IoWMISuggestInstanceName 
 
int __fastcall IoWMISuggestInstanceName(int a1, int a2, int a3, int a4)
{
  int v4; // r5
  __int16 v9; // r2
  unsigned int v10; // r4
  int v11; // r0
  int *v12; // r0
  int v13; // r0
  int v14; // r7
  int v15; // r9
  int v16; // r10
  int v17; // r0
  int v18; // r2
  int v19; // r3
  int v20; // r2
  int v21; // r3
  int v22; // r0
  int v23; // r2
  int v24; // r3
  unsigned int v26[2]; // [sp+8h] [bp-38h] BYREF
  int v27; // [sp+10h] [bp-30h] BYREF
  __int16 v28; // [sp+18h] [bp-28h]
  __int16 v29; // [sp+1Ah] [bp-26h]
  int v30; // [sp+1Ch] [bp-24h]

  v4 = -1073741776;
  if ( !WmipServiceDeviceObject )
    return -1073741823;
  v9 = 0;
  v10 = 0;
  v26[0] = 0;
  if ( a1 )
  {
    v11 = IoGetDeviceProperty(a1, 0, 0, 0, v26);
    v4 = v11;
    if ( v11 == -1073741789 )
    {
      v12 = (int *)ExAllocatePoolWithTag(1, v26[0], 1885957463);
      v10 = (unsigned int)v12;
      if ( !v12 )
        return -1073741670;
      v4 = IoGetDeviceProperty(a1, 0, v26[0], v12, v26);
      if ( v4 < 0 )
      {
LABEL_8:
        ExFreePoolWithTag(v10);
        return v4;
      }
    }
    else if ( v11 < 0 )
    {
      return v4;
    }
    v9 = v26[0];
  }
  if ( a2 )
  {
    v4 = IoOpenDeviceInterfaceRegistryKey(a2, 983103, (int)&v27);
    if ( v4 >= 0 )
    {
      v28 = 0;
      v29 = 0;
      v30 = 0;
      v13 = ZwQueryValueKey();
      v4 = v13;
      if ( v13 == -2147483643 || v13 == -1073741789 )
      {
        v14 = ExAllocatePoolWithTag(1, v26[1], 1885957463);
        if ( v14 )
        {
          v4 = ZwQueryValueKey();
          if ( v4 >= 0 )
          {
            v15 = *(_DWORD *)(v14 + 8);
            if ( a3 )
            {
              v16 = v26[0] + *(_DWORD *)(v14 + 12) + 2;
              v17 = ExAllocatePoolWithTag(1, v16, 1885957463);
              if ( v17 )
              {
                *(_DWORD *)(a4 + 4) = v17;
                *(_WORD *)a4 = 0;
                *(_WORD *)(a4 + 2) = v16;
                if ( v10 )
                  RtlAppendUnicodeToString((unsigned __int16 *)a4, v10, v18, v19);
                RtlAppendUnicodeToString((unsigned __int16 *)a4, (int)L"_", v18, v19);
                RtlAppendUnicodeToString((unsigned __int16 *)a4, v14 + v15, v20, v21);
              }
              else
              {
                v4 = -1073741670;
              }
              if ( v10 )
              {
                ExFreePoolWithTag(v10);
                v10 = 0;
              }
            }
            else
            {
              if ( v10 )
              {
                ExFreePoolWithTag(v10);
                v10 = 0;
              }
              v22 = ExAllocatePoolWithTag(1, *(_DWORD *)(v14 + 12), 1885957463);
              if ( v22 )
              {
                *(_DWORD *)(a4 + 4) = v22;
                *(_WORD *)a4 = 0;
                v24 = *(_DWORD *)(v14 + 12);
                *(_WORD *)(a4 + 2) = v24;
                RtlAppendUnicodeToString((unsigned __int16 *)a4, v14 + v15, v23, v24);
              }
              else
              {
                v4 = -1073741670;
              }
            }
          }
          ExFreePoolWithTag(v14);
        }
        else
        {
          v4 = -1073741670;
        }
      }
      ZwClose();
    }
    if ( v10 && v4 < 0 )
      goto LABEL_8;
  }
  else if ( v10 )
  {
    *(_WORD *)a4 = v9 - 2;
    *(_DWORD *)(a4 + 4) = v10;
    *(_WORD *)(a4 + 2) = v9;
  }
  else
  {
    *(_DWORD *)(a4 + 4) = 0;
    *(_WORD *)a4 = 0;
    *(_WORD *)(a4 + 2) = 0;
  }
  return v4;
}
