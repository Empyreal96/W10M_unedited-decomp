// PspInsertExpansionEntry 
 
int __fastcall PspInsertExpansionEntry(_DWORD *a1, int a2, int a3, int a4)
{
  _DWORD *v6; // r0
  int v7; // r2
  _DWORD v9[4]; // [sp+0h] [bp-10h] BYREF

  v9[0] = a3;
  v9[1] = a4;
  PspLockQuotaExpansion(a1, v9);
  v6 = (_DWORD *)a1[6];
  v7 = a2 + 136;
  *(_DWORD *)(a2 + 136) = a1 + 5;
  *(_DWORD *)(a2 + 140) = v6;
  if ( (_DWORD *)*v6 != a1 + 5 )
    sub_51E048(v6);
  *v6 = v7;
  a1[6] = v7;
  return PspUnlockQuotaExpansion(a1, LOBYTE(v9[0]));
}
