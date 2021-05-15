// EtwpRealtimeResetReferenceTime 
 
int __fastcall EtwpRealtimeResetReferenceTime(_DWORD *a1)
{
  int v1; // r2
  int v2; // r3
  int v3; // r4
  int v4; // r7

  v1 = a1[59];
  v2 = a1[60];
  v3 = a1[61];
  v4 = 0;
  a1[84] = a1[58];
  a1[85] = v1;
  a1[86] = v2;
  a1[87] = v3;
  if ( a1[66] )
    v4 = EtwpRealtimeUpdateReferenceTime(a1, a1 + 84);
  return v4;
}
