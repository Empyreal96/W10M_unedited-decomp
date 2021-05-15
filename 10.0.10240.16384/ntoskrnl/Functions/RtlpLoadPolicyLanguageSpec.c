// RtlpLoadPolicyLanguageSpec 
 
int __fastcall RtlpLoadPolicyLanguageSpec(int a1, _DWORD *a2, _BYTE *a3, _WORD *a4)
{
  unsigned __int16 *v5; // r5
  int v9; // r0
  int v10; // r4
  unsigned __int16 *v11; // r0
  int v12; // r4
  int v13; // r1
  int v14; // r2
  __int16 v16; // [sp+8h] [bp-30h] BYREF
  __int16 v17; // [sp+Ah] [bp-2Eh] BYREF
  int v18; // [sp+Ch] [bp-2Ch] BYREF
  int v19[2]; // [sp+10h] [bp-28h] BYREF
  unsigned __int16 v20; // [sp+18h] [bp-20h] BYREF
  _WORD *v21; // [sp+1Ch] [bp-1Ch]

  v16 = 0;
  v5 = 0;
  v17 = -1;
  if ( a2 && a1 )
  {
    v19[0] = 1;
    v18 = 0;
    RtlInitUnicodeString((unsigned int)&v20, L"PreferredUILanguages");
    v9 = LdrpQueryValueKey(a1, (int)&v20, v19, 0, (unsigned int *)&v18);
    v10 = v18;
    if ( !v18 || v9 == -1073741772 )
      return -1073741823;
    v11 = (unsigned __int16 *)ExAllocatePoolWithTag(1, v18, 1920232557);
    v5 = v11;
    if ( !v11 || (memset(v11, 0, v10), !v5) )
    {
      v12 = -1073741801;
      goto LABEL_24;
    }
    v12 = LdrpQueryValueKey(a1, (int)&v20, v19, (int)v5, (unsigned int *)&v18);
    if ( v12 >= 0 )
    {
      if ( v19[0] == 1 && (RtlInitUnicodeString((unsigned int)&v20, v5), RtlCultureNameToLCID(&v20, v19)) )
      {
        if ( v19[0] != 4096 && v19[0] != 5120 )
        {
          v13 = 1;
          v14 = SLOWORD(v19[0]);
          goto LABEL_17;
        }
        v12 = RtlpMuiRegGetOrAddString(a2, v21, 0, &v16);
        if ( v12 >= 0 )
        {
          v14 = v16;
          v13 = 3;
LABEL_17:
          v12 = RtlpMuiRegGetInstalledLanguageIndex(a2, v13, v14, &v17);
          if ( v12 >= 0 )
          {
            if ( a3 )
              *a3 = 2;
            if ( a4 )
              *a4 = v17;
          }
          goto LABEL_24;
        }
      }
      else
      {
        v12 = -1073741823;
      }
    }
  }
  else
  {
    v12 = -1073741811;
  }
LABEL_24:
  if ( v5 )
    ExFreePoolWithTag((unsigned int)v5);
  return v12;
}
