// PpmIdleCheckProcessorStateEligibility 
 
unsigned int __fastcall PpmIdleCheckProcessorStateEligibility(int a1, unsigned int a2, unsigned int a3, int a4, unsigned __int64 a5, unsigned int a6, char a7)
{
  int v7; // r5
  unsigned int result; // r0
  int (__fastcall *v10)(_DWORD, unsigned int); // r3

  v7 = *(_DWORD *)(a1 + 2944);
  if ( *(_BYTE *)(v7 + (a6 << 6) + 315) )
    return -2147483638;
  if ( a2 != -1 && a6 > a2 )
    return -2147483640;
  if ( !*(_BYTE *)(v7 + (a6 << 6) + 310) && *(_BYTE *)(v7 + 171) )
    return -2147483641;
  if ( a7 )
    goto LABEL_15;
  result = PpmCheckIdleVeto((_DWORD *)(v7 + (a6 << 6) + 288));
  if ( result )
    return result;
  if ( *(_DWORD *)(v7 + (a6 << 6) + 272) > a3 )
    return -2147483646;
  if ( *(unsigned int *)(v7 + (a6 << 6) + 276) > a5 )
    return -2147483645;
LABEL_15:
  v10 = *(int (__fastcall **)(_DWORD, unsigned int))(v7 + 100);
  if ( v10 )
    result = v10(*(_DWORD *)(v7 + 120), a6);
  else
    result = 0;
  return result;
}
