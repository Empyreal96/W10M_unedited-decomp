// KiSetClockInterval 
 
int __fastcall KiSetClockInterval(int a1, int a2)
{
  unsigned int v3; // r6
  _DWORD *v4; // r1
  int result; // r0
  unsigned int v6; // r0

  v3 = a1;
  if ( *(_BYTE *)(a2 + 12) )
    a1 = RtlRbRemoveNode(&KiClockIntervalRequests, (_DWORD *)a2);
  *(_DWORD *)(a2 + 16) = v3;
  v4 = (_DWORD *)KiClockIntervalRequests;
  if ( KiClockIntervalRequests )
  {
    while ( v3 < v4[4] )
    {
      if ( !*v4 )
        goto LABEL_7;
      v4 = (_DWORD *)*v4;
    }
    result = sub_50F410(a1);
  }
  else
  {
LABEL_7:
    v6 = RtlRbInsertNodeEx((unsigned int)&KiClockIntervalRequests, (unsigned int)v4, 0, (_DWORD *)a2);
    *(_BYTE *)(a2 + 12) = 1;
    result = KiSetClockIntervalToMinimumRequested(v6);
  }
  return result;
}
