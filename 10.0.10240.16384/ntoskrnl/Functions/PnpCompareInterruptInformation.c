// PnpCompareInterruptInformation 
 
int __fastcall PnpCompareInterruptInformation(int a1, int a2, int a3)
{
  int v4; // r3
  int result; // r0

  v4 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 48);
  if ( !v4 )
    return sub_7DF178();
  if ( *(_DWORD *)v4 != a3 )
    JUMPOUT(0x7DF1AA);
  result = RtlCompareMemory((unsigned __int8 *)(v4 + 4), a2, a3);
  if ( result != a3 )
    JUMPOUT(0x7DF1FE);
  return result;
}
