// PopUpdateTimeouts 
 
int __fastcall PopUpdateTimeouts(int a1, int a2, int a3)
{
  int result; // r0

  PopDiagTraceDisplayTimeout(*(_DWORD *)a2, *(unsigned __int8 *)(a2 + 5), *(unsigned __int8 *)(a2 + 4));
  result = PopPrintEx(3);
  dword_61DE4C = *(_DWORD *)a2;
  dword_61DE50 = *(_DWORD *)(a2 + 4);
  if ( a3 )
  {
    dword_61DE44 = *(_DWORD *)a3;
    dword_61DE48 = *(_DWORD *)(a3 + 4);
    result = PopDiagTraceInputTimeout(*(_DWORD *)a3, *(unsigned __int8 *)(a3 + 5), *(unsigned __int8 *)(a3 + 4));
  }
  if ( *(_BYTE *)(a2 + 4) )
    result = sub_7F223C(result);
  return result;
}
