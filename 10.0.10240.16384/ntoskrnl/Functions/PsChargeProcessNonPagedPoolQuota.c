// PsChargeProcessNonPagedPoolQuota 
 
int __fastcall PsChargeProcessNonPagedPoolQuota(int a1, int a2)
{
  int v4; // r0

  if ( a1 == PsInitialSystemProcess )
    return 0;
  v4 = *(_DWORD *)(a1 + 332);
  __dmb(0xBu);
  return PspChargeQuota(v4, a1, 0, a2);
}
