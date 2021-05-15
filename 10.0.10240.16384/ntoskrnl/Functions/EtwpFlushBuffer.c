// EtwpFlushBuffer 
 
int __fastcall EtwpFlushBuffer(_DWORD *a1, int a2, char a3)
{
  int v3; // r6
  int v6; // r4
  int v8; // r0

  v3 = -1073741823;
  v6 = -1073741823;
  if ( EtwpPrepareHeader() == -2147483614 && (a3 & 1) == 0 )
    return 0;
  if ( (a1[152] & 8) == 0 || (v3 = EtwpFlushBufferToRealtime(a1, a2), v3 >= 0) )
  {
    if ( a1[148] )
    {
      v8 = EtwpFlushBufferToLogfile(a1, a2);
      v6 = v8;
      if ( v8 < 0 )
        EtwpSendSessionNotification(a1, 3, v8);
    }
    if ( v6 < 0 && v3 < 0 )
      return v6;
    return 0;
  }
  return sub_809BD0();
}
