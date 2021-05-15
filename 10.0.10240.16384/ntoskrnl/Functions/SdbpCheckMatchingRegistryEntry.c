// SdbpCheckMatchingRegistryEntry 
 
int __fastcall SdbpCheckMatchingRegistryEntry(int a1, unsigned __int16 *a2, int a3, _WORD *a4, int a5, int a6, int a7, int a8, unsigned int a9, int a10, _DWORD *a11)
{
  unsigned __int16 *v14; // r5
  _DWORD *v15; // r6
  int v16; // r4
  int v17; // r0
  int v18; // r0
  unsigned int v19; // r2
  unsigned int v20; // r7
  bool v21; // zf
  unsigned __int16 *v23; // r0
  int v24; // r0
  unsigned int v25; // r0
  unsigned int v26; // r0
  unsigned __int16 *v27; // r0
  int v28; // [sp+0h] [bp-258h]
  int v29; // [sp+8h] [bp-250h] BYREF
  int v30; // [sp+Ch] [bp-24Ch]
  _DWORD v31[2]; // [sp+10h] [bp-248h] BYREF
  int v32; // [sp+18h] [bp-240h]
  int v33; // [sp+1Ch] [bp-23Ch]
  _DWORD *v34; // [sp+20h] [bp-238h]
  int v35; // [sp+24h] [bp-234h]
  int v36; // [sp+28h] [bp-230h]
  int v37; // [sp+2Ch] [bp-22Ch]
  unsigned __int16 v38[276]; // [sp+30h] [bp-228h] BYREF

  *a11 = 0;
  v29 = 0;
  v30 = 0;
  v38[0] = 0;
  v31[0] = 0;
  v31[1] = 0;
  v32 = 0;
  v33 = 0;
  v34 = 0;
  v35 = 0;
  v36 = 0;
  v37 = 0;
  v14 = 0;
  v15 = 0;
  v16 = 0;
  if ( RtlStringCchPrintfW(v38, 0x104u, (int)L"\\REGISTRY\\MACHINE\\%s", a1) < 0 )
  {
    AslLogCallPrintf(1, (int)"SdbpCheckMatchingRegistryEntry", 882, "Failed to construct full key path");
    goto LABEL_27;
  }
  RtlInitUnicodeString((unsigned int)v31, v38);
  v32 = 24;
  v33 = 0;
  v35 = 576;
  v34 = v31;
  v36 = 0;
  v37 = 0;
  if ( ZwOpenKey() < 0 )
    goto LABEL_26;
  if ( !a2 || !*a2 )
    goto LABEL_25;
  RtlInitUnicodeString((unsigned int)v31, a2);
  v17 = ZwQueryValueKey();
  if ( v17 < 0 && v17 != -2147483643 && v17 != -1073741789 )
    goto LABEL_26;
  v15 = AslAlloc(v17, v29);
  if ( !v15 )
  {
    AslLogCallPrintf(1, (int)"SdbpCheckMatchingRegistryEntry", 982, "Failed to allocate memory", 0, &v29);
    goto LABEL_27;
  }
  v28 = v29;
  v18 = ZwQueryValueKey();
  if ( v18 < 0 )
  {
    AslLogCallPrintf(1, (int)"SdbpCheckMatchingRegistryEntry", 993, "Failed to read value", v29, &v29);
    goto LABEL_27;
  }
  v19 = v15[1];
  if ( !a3 )
  {
LABEL_25:
    *a11 = 1;
    goto LABEL_26;
  }
  if ( v19 != a3 )
    goto LABEL_26;
  v20 = (unsigned int)v15 + v15[2];
  if ( !v19 )
    goto LABEL_54;
  if ( v19 <= 2 )
  {
    v27 = (unsigned __int16 *)AslAlloc(v18, v15[3] + 2);
    v14 = v27;
    if ( !v27 )
    {
      AslLogCallPrintf(1, (int)"SdbpCheckMatchingRegistryEntry", 1030, "Failed to allocate memory", v29, &v29);
      goto LABEL_27;
    }
    memmove((int)v27, v20, v15[3]);
    v14[v15[3] >> 1] = 0;
    goto LABEL_44;
  }
  switch ( v19 )
  {
    case 3u:
      if ( a10 != v15[3] )
        goto LABEL_26;
      v21 = memcmp(a9, v20, a10) == 0;
      goto LABEL_23;
    case 4u:
      v21 = a5 == *(_DWORD *)v20;
LABEL_23:
      if ( !v21 )
        goto LABEL_26;
      goto LABEL_25;
    case 7u:
      v23 = (unsigned __int16 *)AslAlloc(v18, v15[3]);
      v14 = v23;
      if ( !v23 )
      {
        AslLogCallPrintf(1, (int)"SdbpCheckMatchingRegistryEntry", 1053, "Failed to allocate memory", v29, &v29);
        goto LABEL_27;
      }
      *v23 = 0;
      while ( *(_WORD *)v20 )
      {
        if ( *v14 )
        {
          v25 = wcslen(v14);
          if ( RtlStringCchCatW(v14, v15[3] - v25, (int)L";", v15[3]) < 0 )
          {
            AslLogCallPrintf(1, (int)"SdbpCheckMatchingRegistryEntry", 1069, "Failed to copy delimiter", v28, &v29);
            goto LABEL_27;
          }
          v26 = wcslen(v14);
          v24 = RtlStringCchCatW(v14, v15[3] - v26, v20, v15[3]);
        }
        else
        {
          v24 = RtlStringCchCopyW(v14, v15[3], v20);
        }
        if ( v24 < 0 )
        {
          AslLogCallPrintf(1, (int)"SdbpCheckMatchingRegistryEntry", 1078, "Failed to copy string", v28, &v29);
          goto LABEL_27;
        }
        v20 += 2 * (wcslen((unsigned __int16 *)v20) + 1);
      }
LABEL_44:
      if ( !AslStringPatternMatchW(a4, v14) )
        goto LABEL_26;
      goto LABEL_25;
    case 0xBu:
      if ( a7 == *(_DWORD *)v20 )
      {
        v21 = a8 == *(_DWORD *)(v20 + 4);
        goto LABEL_23;
      }
LABEL_26:
      v16 = 1;
      goto LABEL_27;
  }
LABEL_54:
  AslLogCallPrintf(1, (int)"SdbpCheckMatchingRegistryEntry", 1139, "Unknown registry value data type", v29, &v29);
LABEL_27:
  if ( v30 )
    ZwClose();
  if ( v15 )
    ExFreePoolWithTag((unsigned int)v15);
  if ( v14 )
    ExFreePoolWithTag((unsigned int)v14);
  return v16;
}
