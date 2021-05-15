// EtwpThreadEnumCallback 
 
int __fastcall EtwpThreadEnumCallback(int a1, int a2, int a3)
{
  if ( (*(_DWORD *)(a2 + 960) & 1) != 0 )
    return sub_7CFA8C(a2);
  *(_DWORD *)(a3 + 20) = 6297859;
  if ( *(_BYTE *)(a3 + 38) )
    EtwpTraceThreadRundownWithStack(a2, a3);
  else
    EtwpTraceThreadRundown(a2, a3);
  return 0;
}
