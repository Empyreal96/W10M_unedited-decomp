// KiIpiSendRequestEx 
 
_DWORD *__fastcall KiIpiSendRequestEx(_DWORD *result, int a2, int *a3, int a4, int a5, int a6)
{
  _DWORD *v6; // r4
  int v7; // r3

  v6 = result;
  if ( (a3[2] & ~result[262]) != 0 )
  {
    result = (_DWORD *)KiIpiSendRequest(result, 0, a3, 0, 0, a6);
    while ( 1 )
    {
      v7 = v6[384];
      __dmb(0xBu);
      if ( !v7 )
        break;
      __dmb(0xAu);
      __yield();
    }
  }
  return result;
}
