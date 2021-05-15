// CmpCreateHwProfileFriendlyName 
 
int __fastcall CmpCreateHwProfileFriendlyName(int a1, char a2, int a3, int a4)
{
  int v7; // r4
  __int16 *v8; // r1
  unsigned int v9; // r5
  int v10; // r1
  int v11; // r2
  int v12; // r3
  int v13; // r0
  int v14; // r3
  int v15; // r0
  int v16; // r2
  int v17; // r3
  unsigned int *v19; // [sp+0h] [bp-210h]
  int v20; // [sp+10h] [bp-200h] BYREF
  char *v21; // [sp+14h] [bp-1FCh]
  unsigned int v22; // [sp+18h] [bp-1F8h] BYREF
  char v23[8]; // [sp+20h] [bp-1F0h] BYREF
  int v24; // [sp+28h] [bp-1E8h]
  int v25; // [sp+2Ch] [bp-1E4h]
  char *v26; // [sp+30h] [bp-1E0h]
  int v27; // [sp+34h] [bp-1DCh]
  int v28; // [sp+38h] [bp-1D8h]
  int v29; // [sp+3Ch] [bp-1D4h]
  char v30[8]; // [sp+40h] [bp-1D0h] BYREF
  unsigned __int16 v31[4]; // [sp+48h] [bp-1C8h] BYREF
  unsigned __int16 v32[82]; // [sp+58h] [bp-1B8h] BYREF
  int v33; // [sp+FCh] [bp-114h]
  int v34; // [sp+100h] [bp-110h]

  if ( !a4 )
    return -1073741811;
  if ( !a1 )
    goto LABEL_31;
  if ( (a2 & 3) == 3 )
    goto LABEL_9;
  if ( (a2 & 2) != 0 )
  {
    v8 = L"Docked";
    v9 = 1073807362;
    goto LABEL_10;
  }
  if ( (a2 & 1) == 0 )
  {
LABEL_9:
    v8 = L"Unknown";
    v9 = 1073807363;
  }
  else
  {
    v9 = 1073807361;
    v8 = L"Undocked";
  }
LABEL_10:
  RtlInitUnicodeString((unsigned int)v23, (unsigned __int16 *)v8);
  v13 = KeGetBugMessageResourceEntry(v9, v10, v11, v12);
  if ( v13 )
  {
    if ( (*(_WORD *)(v13 + 2) & 1) != 0 )
    {
      if ( RtlCreateUnicodeString((int)&v20, (unsigned __int16 *)(v13 + 4)) )
        goto LABEL_16;
      v15 = -1073741823;
    }
    else
    {
      RtlInitAnsiString((unsigned int)v31, v13 + 4);
      v15 = RtlAnsiStringToUnicodeString((unsigned __int16 *)&v20, v31, 1, v14);
    }
    if ( v15 >= 0 )
    {
LABEL_16:
      v16 = (unsigned __int16)v20;
      if ( (unsigned __int16)v20 > 4u )
      {
        LOWORD(v20) = v20 - 4;
        *(_WORD *)&v21[2 * ((unsigned __int16)(v16 - 4) >> 1)] = 0;
        v16 = (unsigned __int16)v20;
      }
      if ( (unsigned int)(v16 + 12) <= 0xA0 )
      {
        RtlInitUnicodeString((unsigned int)v30, L"Hardware Profiles");
        v24 = 24;
        v25 = a1;
        v27 = 576;
        v26 = v30;
        v28 = 0;
        v29 = 0;
        v7 = ZwOpenKey();
        if ( v7 >= 0 )
        {
          if ( ZwQueryValueKey() >= 0 && v33 == 4 )
            v17 = *(_DWORD *)((char *)&v32[80] + v34) + 1;
          else
            v17 = 1;
          v22 = v17;
          v19 = &v22;
          v7 = ZwSetValueKey();
          if ( v7 >= 0 )
          {
            if ( v9 == 1073807363 || v22 > 1 )
              swprintf_s((int)v32, 80, (int)L"%s %u", v21, v22, 4);
            else
              wcscpy_s((char *)v32, 80, v21);
          }
        }
      }
      else
      {
        v7 = -1073741823;
      }
      RtlFreeAnsiString(&v20);
      if ( v7 >= 0 )
        goto LABEL_32;
      goto LABEL_31;
    }
  }
LABEL_31:
  v32[0] = 0;
  swprintf_s((int)v32, 80, (int)L"%04d", a3, v19);
  v7 = 0;
LABEL_32:
  if ( !RtlCreateUnicodeString(a4, v32) )
    v7 = -1073741823;
  return v7;
}
