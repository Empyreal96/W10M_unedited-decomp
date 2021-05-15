// ExpGetUILanguagePolicy 
 
int __fastcall ExpGetUILanguagePolicy(int a1, _WORD *a2)
{
  int v4; // r4
  unsigned __int16 v6[4]; // [sp+10h] [bp-148h] BYREF
  int v7[8]; // [sp+18h] [bp-140h] BYREF
  char v8[8]; // [sp+38h] [bp-120h] BYREF
  int v9; // [sp+4Ch] [bp-10Ch]
  unsigned int v10; // [sp+50h] [bp-108h]
  unsigned __int16 v11[130]; // [sp+54h] [bp-104h] BYREF

  RtlInitUnicodeString((unsigned int)v6, L"MultiUILanguageId");
  RtlInitUnicodeString((unsigned int)v8, L"Software\\Policies\\Microsoft\\Control Panel\\Desktop");
  v7[2] = 24;
  v7[3] = a1;
  v7[5] = 576;
  v7[4] = (int)v8;
  v7[6] = 0;
  v7[7] = 0;
  v4 = ZwOpenKey();
  if ( v4 >= 0 )
  {
    v4 = ZwQueryValueKey();
    if ( v4 >= 0 )
    {
      if ( v10 > 2 && v9 == 1 && ExpIsValidUILanguage(v11) )
      {
        RtlInitUnicodeString((unsigned int)v6, v11);
        v4 = RtlUnicodeStringToInteger(v6, 0x10u, v7);
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
  return v4;
}
