// WdipSemCaptureState 
 
int __fastcall WdipSemCaptureState(int a1, int a2)
{
  int result; // r0
  int v4; // r7
  unsigned int v5; // r3
  unsigned int v6; // r6
  int v7; // r3
  int v8; // r0
  unsigned int v9; // r4

  result = 0;
  v4 = 0;
  if ( !a2 )
  {
    if ( !a1 )
      return -1073741811;
    __dmb(0xBu);
    v5 = WdipContextLoggerId;
    do
      v6 = __ldrex((unsigned int *)&WdipContextLoggerId);
    while ( __strex(v5, (unsigned int *)&WdipContextLoggerId) );
    __dmb(0xBu);
    v7 = *(_DWORD *)(a1 + 32);
    if ( v7 )
    {
      if ( v7 != 1 )
      {
        if ( v7 != 2 )
          return result;
        return WdipSemEnableDisableTrace((unsigned __int16)v6, a1, 0);
      }
      v8 = *(_DWORD *)(a1 + 40);
      if ( *(_BYTE *)(v8 + 69) )
      {
LABEL_15:
        result = WdipSemEnableDisableTrace((unsigned __int16)v6, a1, 0);
        if ( !v4 )
          return result;
        return WdipSemEnableDisableTrace((unsigned __int16)v6, a1, 0);
      }
      v9 = *(unsigned __int8 *)(a1 + 18);
      if ( v9 <= *(unsigned __int8 *)(v8 + 48) )
        v9 = *(unsigned __int8 *)(v8 + 48);
      result = WdipSemEnableDisableTrace((unsigned __int16)v6, a1, v9);
      if ( result >= 0 )
      {
        v4 = 1;
        goto LABEL_15;
      }
    }
  }
  return result;
}
