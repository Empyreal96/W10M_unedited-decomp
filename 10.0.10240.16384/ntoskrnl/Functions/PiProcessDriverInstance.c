// PiProcessDriverInstance 
 
int __fastcall PiProcessDriverInstance(unsigned __int16 *a1, int a2, _BYTE *a3)
{
  int v5; // r4
  int v6; // r2
  unsigned int v7; // r5
  int v8; // r6
  unsigned int v9; // r4
  int v10; // r0
  signed int v11; // r3
  __int16 v12; // r3
  unsigned int v14; // r1
  int v15; // [sp+10h] [bp-50h] BYREF
  unsigned int v16; // [sp+14h] [bp-4Ch] BYREF
  __int16 v17; // [sp+18h] [bp-48h]
  __int16 v18; // [sp+1Ah] [bp-46h]
  const __int16 *v19; // [sp+1Ch] [bp-44h]
  unsigned int v20[2]; // [sp+20h] [bp-40h] BYREF
  int v21; // [sp+28h] [bp-38h] BYREF
  int v22; // [sp+2Ch] [bp-34h]
  char v23[48]; // [sp+30h] [bp-30h] BYREF

  v5 = PipOpenServiceEnumKeys(a2, 983103, 0, &v15, 1);
  if ( v5 >= 0 )
  {
    v5 = PiFindDevInstMatch(v15, a1, &v16, (int)&v21, v20);
    if ( v5 < 0 )
    {
LABEL_17:
      ZwClose();
      return v5;
    }
    v6 = v22;
    if ( v22 )
    {
      if ( *a3 )
      {
LABEL_14:
        if ( v6 )
          RtlFreeAnsiString(&v21);
        goto LABEL_16;
      }
      ZwDeleteValueKey();
      v14 = --v16;
      if ( v16 )
        PiRearrangeDeviceInstances(v15, v14, v20[0]);
    }
    else
    {
      if ( !*a3 )
      {
LABEL_16:
        v5 = 0;
        goto LABEL_17;
      }
      v7 = *a1;
      v8 = *((_DWORD *)a1 + 1);
      v9 = 0;
      if ( *(_WORD *)(v8 + 2 * (v7 >> 1) - 2) )
      {
        v10 = ExAllocatePoolWithTag(1, v7 + 2, 538996816);
        v9 = v10;
        if ( v10 )
        {
          memmove(v10, v8, v7);
          *(_WORD *)(v9 + 2 * (v7 >> 1)) = 0;
        }
      }
      v20[0] = (unsigned int)v23;
      RtlStringCchPrintfExW((int)v23, 10, v20, 0, 0, L"%u");
      v11 = (signed int)(v20[0] - (_DWORD)v23) >> 1;
      v18 = 20;
      if ( v11 == -1 )
        v12 = 20;
      else
        v12 = 2 * v11;
      v17 = v12;
      v19 = (const __int16 *)v23;
      ZwSetValueKey();
      if ( v9 )
        ExFreePoolWithTag(v9);
      ++v16;
    }
    v18 = 12;
    v17 = 10;
    v19 = L"Count";
    ZwSetValueKey();
    v18 = 26;
    v17 = 24;
    v19 = L"NextInstance";
    ZwSetValueKey();
    v6 = v22;
    goto LABEL_14;
  }
  return v5;
}
