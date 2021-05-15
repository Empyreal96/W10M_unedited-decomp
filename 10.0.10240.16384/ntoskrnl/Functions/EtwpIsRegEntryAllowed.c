// EtwpIsRegEntryAllowed 
 
int __fastcall EtwpIsRegEntryAllowed(int a1, int a2, unsigned __int8 *a3, int a4, int a5, char a6)
{
  int v6; // r7
  int result; // r0

  v6 = *(_DWORD *)(a4 + 72);
  if ( (*(_BYTE *)(a1 + 50) & 1) != 0 && (a3[17] || a3[18]) )
    goto LABEL_11;
  if ( v6 == 2 )
    return sub_80866C();
  if ( (*(_BYTE *)(a1 + 50) & 8) != 0
    && (a6 == 2 || !v6 && *(unsigned __int16 *)(a4 + 104) != *(unsigned __int16 *)(*(_DWORD *)(a1 + 16) + 48))
    || !a3[18] && (a6 == 2 && !EtwpIsGuidAllowed((_WORD *)(a2 + 644)) || EtwpCheckProviderLoggingAccess(a1, a3, a3[16])) )
  {
LABEL_11:
    result = 0;
  }
  else
  {
    result = 1;
  }
  return result;
}
