// ExpFindArcName 
 
int __fastcall ExpFindArcName(unsigned __int16 *a1, char **a2)
{
  int v2; // r9
  char *v3; // r0
  unsigned __int16 *v4; // r5
  int v5; // r4
  unsigned __int16 *v6; // r5
  char *v7; // r0
  char *v8; // r6
  int v9; // r10
  unsigned int v11; // [sp+10h] [bp-60h]
  _DWORD v14[2]; // [sp+28h] [bp-48h] BYREF
  unsigned __int16 v15[4]; // [sp+30h] [bp-40h] BYREF
  int v16; // [sp+38h] [bp-38h]
  int v17; // [sp+3Ch] [bp-34h]
  _DWORD *v18; // [sp+40h] [bp-30h]
  int v19; // [sp+44h] [bp-2Ch]
  int v20; // [sp+48h] [bp-28h]
  int v21; // [sp+4Ch] [bp-24h]

  v2 = 0;
  v3 = (char *)ExAllocatePoolWithTag(512, 18, 1920364101);
  v4 = (unsigned __int16 *)v3;
  if ( !v3 )
    return -1073741670;
  wcscpy_s(v3, 9, (char *)L"\\ArcName");
  RtlInitUnicodeString((unsigned int)v14, v4);
  v16 = 24;
  v17 = 0;
  v19 = 576;
  v18 = v14;
  v20 = 0;
  v21 = 0;
  v5 = ZwOpenDirectoryObject();
  ExFreePoolWithTag((unsigned int)v4);
  if ( v5 >= 0 )
  {
    v6 = 0;
    RtlInitUnicodeString((unsigned int)v15, L"SymbolicLink");
    while ( 1 )
    {
      v5 = ZwQueryDirectoryObject();
      if ( v5 == -1073741789 )
      {
        if ( v6 )
          ExFreePoolWithTag((unsigned int)v6);
        v6 = (unsigned __int16 *)ExAllocatePoolWithTag(512, v11, 1920364101);
        if ( !v6 )
        {
          v5 = -1073741670;
          goto LABEL_27;
        }
        v5 = ZwQueryDirectoryObject();
      }
      if ( v5 < 0 )
        break;
      if ( RtlEqualUnicodeString(v6 + 4, v15, 0) )
      {
        v11 = *v6 + 18;
        v7 = (char *)ExAllocatePoolWithTag(512, *v6 + 20, 1920364101);
        v8 = v7;
        if ( !v7 )
        {
          v5 = -1073741670;
          goto LABEL_25;
        }
        v9 = *v6 >> 1;
        wcscpy_s(v7, (v11 >> 1) + 1, (char *)L"\\ArcName\\");
        wcsncat_s(v8, (v11 >> 1) + 1, *((char **)v6 + 1), v9);
        *(_WORD *)&v8[2 * (v11 >> 1)] = 0;
        v5 = ExpTranslateSymbolicLink((unsigned __int16 *)v8, v14);
        if ( v5 < 0 )
        {
          ExFreePoolWithTag((unsigned int)v8);
          goto LABEL_22;
        }
        v2 = RtlEqualUnicodeString((unsigned __int16 *)v14, a1, 1);
        ExFreePoolWithTag(v14[1]);
        if ( v2 == 1 )
        {
          wcsncpy_s(v8, (v11 >> 1) + 1, *((char **)v6 + 1), v9);
          *(_WORD *)&v8[2 * v9] = 0;
          *a2 = v8;
          goto LABEL_22;
        }
        ExFreePoolWithTag((unsigned int)v8);
      }
    }
    if ( v5 == -2147483622 )
      v5 = 0;
LABEL_22:
    if ( v5 >= 0 && !v2 )
      v5 = -1073741766;
LABEL_25:
    if ( v6 )
      ExFreePoolWithTag((unsigned int)v6);
LABEL_27:
    ZwClose();
  }
  return v5;
}
