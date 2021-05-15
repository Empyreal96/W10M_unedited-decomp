// PfSnLogHelper 
 
int __fastcall PfSnLogHelper(int a1, int a2, _DWORD *a3)
{
  _DWORD *v5; // r5
  _DWORD *v6; // r0
  _DWORD *v7; // r4

  v5 = 0;
  v6 = (_DWORD *)PfSnReferenceProcessTrace(a1);
  v7 = v6;
  if ( v6 )
  {
    if ( PfSnTraceGetLogEntry(v6, a2, a3) < 0 )
      return sub_803100();
    v5 = v7;
  }
  return (int)v5;
}
