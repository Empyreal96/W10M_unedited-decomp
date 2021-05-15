// KIsUnlockSettingEnabled 
 
int __fastcall KIsUnlockSettingEnabled(int a1, bool *a2)
{
  int result; // r0
  int v5; // r3
  int v6[2]; // [sp+0h] [bp-28h] BYREF
  __int16 v7[2]; // [sp+8h] [bp-20h] BYREF
  const __int16 *v8; // [sp+Ch] [bp-1Ch]
  __int16 v9[2]; // [sp+10h] [bp-18h] BYREF
  const __int16 *v10; // [sp+14h] [bp-14h]

  v9[0] = 148;
  v9[1] = 150;
  v10 = L"\\Registry\\Machine\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\AppModelUnlock";
  v7[0] = 116;
  v7[1] = 118;
  v8 = L"\\Registry\\Machine\\SOFTWARE\\Policies\\Microsoft\\Windows\\Appx";
  v6[0] = 0xFFFF;
  result = KGetUnlockSetting(v7, a1, v6);
  if ( result >= 0 )
  {
    v5 = v6[0];
    if ( v6[0] == 0xFFFF )
    {
      result = KGetUnlockSetting(v9, a1, v6);
      if ( result < 0 )
        return result;
      v5 = v6[0];
    }
    *a2 = v5 == 1;
  }
  return result;
}
