// PspEnforceLimitsJobPreCallback 
 
int __fastcall PspEnforceLimitsJobPreCallback(int a1, _DWORD *a2)
{
  int v4; // r3
  int v5; // r8
  _DWORD *v6; // r4
  int result; // r0
  unsigned int *v8; // r2
  unsigned int v9; // r0

  v4 = PspEnforcementSequenceNumber;
  __dmb(0xBu);
  *(_DWORD *)(a1 + 688) = v4;
  if ( (*(_DWORD *)(a1 + 400) & 6) != 0 || *(_DWORD *)(a1 + 420) || (*(_DWORD *)(a1 + 744) & 0x800) != 0 )
  {
    *a2 = *(_DWORD *)(a1 + 360);
    a2[1] = *(_DWORD *)(a1 + 364);
    a2[2] = *(_DWORD *)(a1 + 384);
    a2[3] = 0;
    v5 = 0;
    while ( !*(_DWORD *)(a1 + 520) )
    {
      v6 = &a2[v5];
      PspQueryRateControlHistory(a1, 1, 0, v6 + 9, v5++);
      v6[6] = 1;
      if ( v5 >= 3 )
        return 0;
    }
    result = sub_7C27F0();
  }
  else
  {
    memset((_BYTE *)(a1 + 600), 0, 80);
    __dmb(0xBu);
    v8 = (unsigned int *)(a1 + 744);
    do
      v9 = __ldrex(v8);
    while ( __strex(v9 & 0xFFBFFFFF, v8) );
    __dmb(0xBu);
    result = -1073741536;
  }
  return result;
}
