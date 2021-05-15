// HvTruncateCurrentLogFileIfRequired 
 
int __fastcall HvTruncateCurrentLogFileIfRequired(int result)
{
  int v1; // r4
  int v2; // r3
  int v3; // r5
  int v4; // r6
  int v5; // r0
  unsigned int v6; // r1
  unsigned int v7; // r2

  v1 = result;
  v2 = *(_DWORD *)(result + 92);
  if ( (v2 & 1) == 0 && (v2 & 0x8000) == 0 )
  {
    v3 = *(_DWORD *)(result + 96);
    if ( v3 )
    {
      if ( *(_DWORD *)(result + 4 * v3 + 1776) )
      {
        v4 = HvpLogTypeToLogArrayIndex(*(_DWORD *)(result + 96));
        result = HvpShouldTruncateLogFile(v1, v3);
        if ( result )
        {
          v5 = v1 + 8 * v4;
          v6 = *(_DWORD *)(v5 + 1952);
          result = *(_DWORD *)(v5 + 1956);
          v7 = *(_DWORD *)(v1 + 108);
          if ( __PAIR64__(result, v6) > v7 )
            result = CmpDoFileSetSizeEx(v1, v3, v7, 0, 0);
        }
      }
    }
  }
  return result;
}
