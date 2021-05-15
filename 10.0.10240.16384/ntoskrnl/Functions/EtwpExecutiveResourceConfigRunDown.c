// EtwpExecutiveResourceConfigRunDown 
 
int __fastcall EtwpExecutiveResourceConfigRunDown(int a1, int a2)
{
  int v2; // r3
  int v4[4]; // [sp+8h] [bp-28h] BYREF
  int v5[6]; // [sp+18h] [bp-18h] BYREF

  v2 = 3918;
  if ( a2 )
    v2 = 3917;
  v4[0] = EtwpExecutiveResourceReleaseSampleRate;
  v4[1] = EtwpExecutiveResourceContentionSampleRate;
  v4[2] = EtwpExecutiveResourceTimeout;
  v5[0] = (int)v4;
  v5[1] = 0;
  v5[2] = 12;
  v5[3] = 0;
  return EtwpLogKernelEvent(v5, a1, 1, v2, 4200706);
}
