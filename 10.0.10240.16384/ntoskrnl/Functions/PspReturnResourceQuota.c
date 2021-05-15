// PspReturnResourceQuota 
 
int __fastcall PspReturnResourceQuota(int a1, int a2, int a3, int a4)
{
  char *v4; // r4
  int v8; // r0
  int result; // r0
  _DWORD v10[8]; // [sp+0h] [bp-20h] BYREF

  v10[0] = a3;
  v10[1] = a4;
  v4 = (char *)&PspQuotaExpansionDescriptors + 28 * a1;
  v8 = PspLockQuotaExpansion(v4, v10);
  if ( a3 )
    v8 = (*((int (__fastcall **)(int, int))v4 + 4))(a1, a3);
  if ( a4 )
    result = sub_525090(v8);
  else
    result = PspUnlockQuotaExpansion(v4, LOBYTE(v10[0]));
  return result;
}
