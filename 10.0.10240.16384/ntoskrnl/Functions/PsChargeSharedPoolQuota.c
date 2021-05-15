// PsChargeSharedPoolQuota 
 
int __fastcall PsChargeSharedPoolQuota(int a1, int a2, int a3)
{
  int v4; // r4
  unsigned int *v5; // r2
  unsigned int v6; // r1

  if ( a1 == PsInitialSystemProcess )
    return 1;
  v4 = *(_DWORD *)(a1 + 332);
  if ( a2 && PspChargeQuota(*(_DWORD *)(a1 + 332), 0, 1, a2) < 0 )
    return 0;
  if ( a3 && PspChargeQuota(v4, 0, 0, a3) < 0 )
    return sub_7C04C0();
  __dmb(0xBu);
  v5 = (unsigned int *)(v4 + 1024);
  do
    v6 = __ldrex(v5);
  while ( __strex(v6 + 1, v5) );
  __dmb(0xBu);
  return v4;
}
