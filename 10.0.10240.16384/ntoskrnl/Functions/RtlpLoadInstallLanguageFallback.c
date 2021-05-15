// RtlpLoadInstallLanguageFallback 
 
int __fastcall RtlpLoadInstallLanguageFallback(int a1, _WORD *a2, _WORD *a3)
{
  unsigned __int16 *v3; // r5
  unsigned __int16 *v6; // r0
  int v7; // r6
  int v8; // r3
  unsigned __int16 *v9; // r4
  int v11; // [sp+Ch] [bp-44h] BYREF
  unsigned int v12; // [sp+10h] [bp-40h] BYREF
  unsigned __int16 v13[4]; // [sp+18h] [bp-38h] BYREF
  int v14; // [sp+20h] [bp-30h]
  int v15; // [sp+24h] [bp-2Ch]
  unsigned __int16 *v16; // [sp+28h] [bp-28h]
  int v17; // [sp+2Ch] [bp-24h]
  int v18; // [sp+30h] [bp-20h]
  int v19; // [sp+34h] [bp-1Ch]

  v3 = 0;
  if ( a1 && a2 && a3 )
  {
    v6 = (unsigned __int16 *)sub_4F4434(a1, 0xACu, (int)a3, 0);
    v3 = v6;
    if ( v6 )
    {
      memset(v6, 0, 344);
      *a2 = 0;
      *a3 = 0;
      v11 = 0;
      RtlInitUnicodeString((unsigned int)v13, L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\NLS\\Language");
      v14 = 24;
      v15 = 0;
      v17 = 576;
      v16 = v13;
      v18 = 0;
      v19 = 0;
      v7 = ZwOpenKey();
      if ( v7 >= 0 )
      {
        RtlInitUnicodeString((unsigned int)v13, L"InstallLanguageFallback");
        v12 = 4;
        v7 = LdrpQueryValueKey(0, (int)v13, &v11, (int)v3, &v12);
        if ( v7 >= 0 )
        {
          if ( v11 != 1 )
            goto LABEL_10;
          v8 = *v3;
          v9 = v3;
          while ( v8 )
          {
            if ( *v9 == 44 )
            {
              *v9++ = 0;
              break;
            }
            v8 = *++v9;
          }
          while ( *v9 && *v9 == 32 )
            ++v9;
          RtlInitUnicodeString((unsigned int)v13, v3);
          if ( RtlCultureNameToLCID(v13, &v11) )
          {
            *a2 = v11;
            if ( *v9 )
            {
              RtlInitUnicodeString((unsigned int)v13, v9);
              if ( RtlCultureNameToLCID(v13, &v11) )
              {
                *a3 = v11;
              }
              else
              {
                v7 = -1073741823;
                *a2 = 0;
              }
            }
          }
          else
          {
LABEL_10:
            v7 = -1073741823;
          }
        }
      }
    }
    else
    {
      v7 = -1073741801;
    }
  }
  else
  {
    v7 = -1073741811;
  }
  if ( v3 )
    ExFreePoolWithTag((unsigned int)v3);
  return v7;
}
