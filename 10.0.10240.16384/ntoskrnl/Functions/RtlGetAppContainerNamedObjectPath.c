// RtlGetAppContainerNamedObjectPath 
 
int __fastcall RtlGetAppContainerNamedObjectPath(int a1, int a2, int a3, int a4)
{
  int v8; // r9
  int v9; // r4
  int v10; // r3
  int v11; // r0
  int v12; // r2
  int v13; // r4
  _BYTE *v14; // r0
  _BYTE *v15; // r5
  int v16; // r2
  int v17; // r3
  int v19[2]; // [sp+10h] [bp-500h] BYREF
  unsigned __int16 v20[2]; // [sp+18h] [bp-4F8h] BYREF
  int v21; // [sp+1Ch] [bp-4F4h]
  int v22; // [sp+20h] [bp-4F0h] BYREF
  char v23[4]; // [sp+24h] [bp-4ECh] BYREF
  unsigned __int16 v24[2]; // [sp+28h] [bp-4E8h] BYREF
  int v25; // [sp+2Ch] [bp-4E4h]
  int v26; // [sp+30h] [bp-4E0h] BYREF
  unsigned __int16 v27[2]; // [sp+38h] [bp-4D8h] BYREF
  const __int16 *v28; // [sp+3Ch] [bp-4D4h]
  int v29; // [sp+40h] [bp-4D0h] BYREF
  int v30; // [sp+44h] [bp-4CCh] BYREF
  int v31[20]; // [sp+48h] [bp-4C8h] BYREF
  int v32[18]; // [sp+98h] [bp-478h] BYREF
  __int16 v33; // [sp+E0h] [bp-430h] BYREF
  char v34[518]; // [sp+E2h] [bp-42Eh] BYREF
  unsigned __int16 v35; // [sp+2E8h] [bp-228h] BYREF
  char v36[518]; // [sp+2EAh] [bp-226h] BYREF

  v19[0] = 0;
  v33 = 0;
  v8 = 1;
  memset(v34, 0, sizeof(v34));
  v35 = 0;
  memset(v36, 0, sizeof(v36));
  v22 = 0;
  v27[0] = 2;
  v27[1] = 4;
  v28 = L"\\";
  if ( !a4 )
    return -1073741811;
  if ( a1 && a2 )
    return -1073741776;
  *(_WORD *)a4 = 0;
  *(_WORD *)(a4 + 2) = 0;
  *(_DWORD *)(a4 + 4) = 0;
  v20[0] = 0;
  v20[1] = 0;
  v21 = 0;
  v24[0] = 0;
  v24[1] = 0;
  v25 = 0;
  if ( a2 )
  {
    a1 = -4;
    goto LABEL_10;
  }
  if ( !a1 )
  {
    a1 = -6;
LABEL_10:
    if ( a2 )
      goto LABEL_15;
  }
  v26 = 0;
  v9 = NtQueryInformationToken(a1, 29, &v26, 4, v23);
  if ( v9 < 0 )
    goto LABEL_47;
  if ( !v26 )
    goto LABEL_46;
  v9 = NtQueryInformationToken(a1, 31, v32, 72, v23);
  if ( v9 < 0 )
    goto LABEL_47;
  a2 = v32[0];
  if ( !v32[0] )
  {
LABEL_46:
    v9 = 0;
    goto LABEL_47;
  }
LABEL_15:
  v9 = NtQueryInformationToken(a1, 42, &v22, 4, v23);
  if ( v9 >= 0 )
  {
    if ( !v22
      || (v9 = NtQueryInformationToken(a1, 1, v31, 76, v23), v9 >= 0)
      && (v9 = RtlConvertSidToUnicodeString(v24, v31[0], 1), v9 >= 0) )
    {
      v9 = NtQueryInformationToken(a1, 12, &v29, 4, v23);
      if ( v9 >= 0 )
      {
        v9 = RtlGetAppContainerSidType(a2, &v30);
        if ( v9 >= 0 )
        {
          if ( v30 == 2 )
          {
            v9 = RtlConvertSidToUnicodeString(v20, a2, 1);
            if ( v9 >= 0 )
            {
LABEL_29:
              if ( a3 )
                v11 = RtlStringCchPrintfW(&v33, 0x104u, (int)L"AppContainerNamedObjects\\", v10);
              else
                v11 = RtlStringCchPrintfW(
                        &v33,
                        0x104u,
                        (int)L"%ws\\%ld\\AppContainerNamedObjects\\",
                        (int)L"\\Sessions");
              v9 = v11;
              if ( v11 >= 0 )
              {
                v9 = RtlStringCbLengthW((int)&v33, 0x104u, v19);
                if ( v9 >= 0 )
                {
                  if ( !v22 || a3 )
                    v12 = v19[0];
                  else
                    v12 = v24[0] + v19[0] + 2;
                  v13 = v20[0] + v12 + 2;
                  v14 = (_BYTE *)ExpAllocateStringRoutine(v13);
                  v15 = v14;
                  if ( v14 )
                  {
                    memset(v14, 0, v13);
                    *(_WORD *)a4 = 0;
                    *(_WORD *)(a4 + 2) = v13;
                    *(_DWORD *)(a4 + 4) = v15;
                    v9 = RtlAppendUnicodeToString((unsigned __int16 *)a4, (int)&v33, v16, v17);
                    if ( v9 >= 0 )
                    {
                      if ( !v22
                        || a3
                        || (v9 = RtlAppendUnicodeStringToString((unsigned __int16 *)a4, v24), v9 >= 0)
                        && (v9 = RtlAppendUnicodeStringToString((unsigned __int16 *)a4, v27), v9 >= 0) )
                      {
                        v9 = RtlAppendUnicodeStringToString((unsigned __int16 *)a4, v20);
                      }
                    }
                  }
                  else
                  {
                    v9 = -1073741670;
                  }
                }
              }
              goto LABEL_47;
            }
          }
          else
          {
            v9 = RtlGetAppContainerParent(a2, v19);
            if ( v9 >= 0 )
            {
              v9 = RtlConvertSidToUnicodeString(v20, v19[0], 1);
              if ( v9 >= 0 )
              {
                ExFreePoolWithTag(v19[0]);
                v9 = RtlStringCchPrintfW(&v35, 0x104u, (int)L"%s\\%u-%u-%u-%u", v21);
                if ( v9 >= 0 )
                {
                  RtlFreeAnsiString(v20);
                  RtlInitUnicodeString((unsigned int)v20, &v35);
                  v8 = 0;
                  goto LABEL_29;
                }
              }
              else
              {
                ExFreePoolWithTag(v19[0]);
              }
            }
          }
        }
      }
    }
  }
LABEL_47:
  RtlFreeAnsiString(v24);
  if ( v9 < 0 )
    RtlFreeAnsiString(a4);
  if ( v8 )
    RtlFreeAnsiString(v20);
  return v9;
}
