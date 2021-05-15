// PspExpandQuota 
 
int __fastcall PspExpandQuota(int a1, int a2, int a3, int a4, unsigned int *a5)
{
  char *v6; // r9
  int v10; // r0
  unsigned int v11; // r5
  unsigned int *v12; // r6
  unsigned int v13; // t1
  int result; // r0
  unsigned int v15; // r5
  unsigned int v16; // r4
  int v17; // [sp+0h] [bp-28h] BYREF
  int v18[9]; // [sp+4h] [bp-24h] BYREF

  v17 = a2;
  v18[0] = a3;
  v18[1] = a4;
  v6 = (char *)&PspQuotaExpansionDescriptors + 28 * a1;
  v10 = PspLockQuotaExpansion(v6, &v17);
  v13 = *(_DWORD *)(a2 + 128);
  v12 = (unsigned int *)(a2 + 128);
  v11 = v13;
  __dmb(0xBu);
  if ( a3 + a4 <= v13 )
    return sub_5250B0(v10);
  if ( (*((int (__fastcall **)(int, unsigned int, _DWORD, int *))v6 + 3))(a1, v11, 0, v18)
    || PspReleaseReturnedQuota(a1, v6)
    && (*((int (__fastcall **)(int, unsigned int, _DWORD, int *))v6 + 3))(a1, v11, 0, v18) )
  {
    v15 = v18[0] - v11;
    __dmb(0xBu);
    do
      v16 = __ldrex(v12);
    while ( __strex(v16 + v15, v12) );
    __dmb(0xBu);
    PspUnlockQuotaExpansion(v6, (unsigned __int8)v17);
    *a5 = v16 + v15;
    result = 1;
  }
  else
  {
    PspUnlockQuotaExpansion(v6, (unsigned __int8)v17);
    result = 0;
    *a5 = v11;
  }
  return result;
}
