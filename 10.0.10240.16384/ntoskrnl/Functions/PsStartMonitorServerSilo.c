// PsStartMonitorServerSilo 
 
int __fastcall PsStartMonitorServerSilo(_DWORD *a1)
{
  int v2; // r5
  int v3; // r3
  int v4; // r3
  unsigned int *v6; // r0
  unsigned int v7; // r4
  unsigned int v8; // r1

  v2 = PspReferenceMonitorServerSilo(a1);
  if ( v2 >= 0 )
  {
    v3 = a1[5];
    __dmb(0xBu);
    if ( (v3 & 1) != 0 )
    {
      v2 = -1073741811;
    }
    else
    {
      v4 = a1[5] | 1;
      __dmb(0xBu);
      a1[5] = v4;
      if ( a1[8] )
      {
        if ( !PsIsSystemProcess(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74)) )
          return sub_810988();
        PspStartMonitorDeferred(a1);
      }
      else
      {
        v2 = 0;
      }
    }
    v6 = a1 + 7;
    __pld(a1 + 7);
    v7 = a1[7] & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v8 = __ldrex(v6);
    while ( v8 == v7 && __strex(v7 - 2, v6) );
    if ( v8 != v7 )
      ExfReleaseRundownProtection((unsigned __int8 *)v6);
  }
  return v2;
}
