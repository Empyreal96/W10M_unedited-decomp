// PopPowerButtonSettingCallback 
 
int __fastcall PopPowerButtonSettingCallback(unsigned int a1, int *a2, int a3)
{
  char *v6; // r0
  int v7; // r3
  int v8; // r4
  int v10; // [sp-4h] [bp-F8h] BYREF
  char v11; // [sp+0h] [bp-F4h] BYREF
  char v12; // [sp+Ch] [bp-E8h] BYREF
  char v13; // [sp+18h] [bp-DCh] BYREF
  int v14; // [sp+24h] [bp-D0h]

  PopAcquirePolicyLock();
  memmove((int)&v10, PopPolicy, 0xE8u);
  if ( !memcmp((unsigned int)&GUID_POWERBUTTON_ACTION, a1, 16) )
  {
    v6 = &v11;
  }
  else if ( !memcmp((unsigned int)&GUID_SLEEPBUTTON_ACTION, a1, 16) )
  {
    v6 = &v12;
  }
  else
  {
    if ( memcmp((unsigned int)&GUID_LIDCLOSE_ACTION, a1, 16) )
    {
      if ( !memcmp((unsigned int)&GUID_LIDOPEN_POWERSTATE, a1, 16) && a3 == 4 && a2 && (unsigned int)*a2 <= 7 )
        v14 = *a2;
      goto LABEL_10;
    }
    v6 = &v13;
  }
  if ( a3 != 4 || !a2 )
  {
    v8 = -1073741811;
    goto LABEL_11;
  }
  v7 = *a2;
  if ( *a2 == 2 || !v7 )
  {
    *(_DWORD *)v6 = 0;
    *((_DWORD *)v6 + 1) = 0;
    *((_DWORD *)v6 + 2) = 0;
    *(_DWORD *)v6 = v7;
LABEL_10:
    v8 = PopApplyPolicy(1, 0, &v10, 232);
LABEL_11:
    PopReleasePolicyLock();
    return v8;
  }
  return sub_7F1D3C(v6);
}
