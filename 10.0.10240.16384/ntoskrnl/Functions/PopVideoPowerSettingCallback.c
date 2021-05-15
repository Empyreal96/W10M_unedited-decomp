// PopVideoPowerSettingCallback 
 
int __fastcall PopVideoPowerSettingCallback(unsigned int a1, _DWORD *a2, int a3, int a4)
{
  int v7; // r4
  int v9; // r1
  _DWORD v11[64]; // [sp-4h] [bp-100h] BYREF

  v7 = -1073741811;
  if ( !memcmp((unsigned int)&GUID_VIDEO_POWERDOWN_TIMEOUT, a1, 16) && a3 == 4 && a2 )
  {
    PopAcquirePolicyLock(0, v9);
    memmove((int)v11, PopPolicy, 0xE8u);
    v11[48] = *a2;
    v7 = PopApplyPolicy(1, 0, v11, 232);
    PopReleasePolicyLock(v7);
    PopAdaptivePowerSettingCallback(a1, a2, 4, a4);
  }
  return v7;
}
