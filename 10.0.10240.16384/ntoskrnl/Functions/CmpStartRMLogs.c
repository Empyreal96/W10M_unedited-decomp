// CmpStartRMLogs 
 
int __fastcall CmpStartRMLogs(_DWORD *a1)
{
  int v2; // r3
  int v3; // r7
  int v4; // r4
  int *v5; // r6
  int v6; // r0
  _BYTE v8[40]; // [sp-4h] [bp-28h] BYREF

  v2 = a1[15];
  v3 = 0;
  v4 = 0;
  if ( (v2 & 8) != 0 )
    return -1073741431;
  if ( (v2 & 1) == 0 )
  {
    if ( CmpUuidCreate((int)v8) >= 0 )
      v3 = 1;
    if ( (a1[15] & 2) != 0 )
      v5 = a1 + 17;
    else
      v5 = a1 + 16;
    CmpLockRegistryFreezeAware(0);
    v6 = CmpStartRMLog(a1, 0);
    v4 = v6;
    if ( v6 < 0 && v6 != -1073741697 && v6 != -1073741757 && v6 != -1073741670 && v3 == 1 )
    {
      a1[15] &= 0xFFFFFFFD;
      v4 = CmpStartRMLog(a1, v8);
    }
    CmpUnlockRegistry();
    *v5 = v4;
  }
  return v4;
}
