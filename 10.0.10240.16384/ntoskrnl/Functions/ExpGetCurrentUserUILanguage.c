// ExpGetCurrentUserUILanguage 
 
int __fastcall ExpGetCurrentUserUILanguage(int a1, _WORD *a2, int a3)
{
  int v4; // r4
  int v6; // [sp+8h] [bp-158h] BYREF
  int v7[8]; // [sp+10h] [bp-150h] BYREF
  char v8[8]; // [sp+30h] [bp-130h] BYREF
  unsigned __int16 v9[4]; // [sp+38h] [bp-128h] BYREF
  char v10[8]; // [sp+48h] [bp-118h] BYREF
  int v11; // [sp+54h] [bp-10Ch]
  unsigned __int16 v12[130]; // [sp+5Ch] [bp-104h] BYREF

  v4 = OpenGlobalizationUserSettingsKey(a1, 0, a3, (int)&v6, (int)&v6);
  if ( v4 >= 0 )
  {
    RtlInitUnicodeString((unsigned int)v10, L"MultiUILanguageId");
    RtlInitUnicodeString((unsigned int)v8, L"Control Panel\\Desktop");
    v7[2] = 24;
    v7[5] = 1600;
    v7[3] = v6;
    v7[4] = (int)v8;
    v7[6] = 0;
    v7[7] = 0;
    if ( ExpGetUILanguagePolicy() < 0 )
    {
      v4 = ZwOpenKey();
      if ( v4 >= 0 )
      {
        v4 = ZwQueryValueKey();
        if ( v4 >= 0 )
        {
          if ( v11 == 1 && ExpIsValidUILanguage(v12) )
          {
            RtlInitUnicodeString((unsigned int)v9, v12);
            v4 = RtlUnicodeStringToInteger(v9, 0x10u, v7);
            if ( v4 >= 0 )
              *a2 = v7[0];
          }
          else
          {
            v4 = -1073741823;
          }
        }
        ZwClose();
      }
    }
    CloseGlobalizationUserSettingsKey(v6);
  }
  return v4;
}
