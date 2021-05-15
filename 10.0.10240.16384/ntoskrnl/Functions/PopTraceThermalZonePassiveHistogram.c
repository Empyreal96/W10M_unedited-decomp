// PopTraceThermalZonePassiveHistogram 
 
int __fastcall PopTraceThermalZonePassiveHistogram(int a1)
{
  int result; // r0
  int v3; // r4
  int v4; // r5
  _DWORD v5[14]; // [sp+8h] [bp-C0h] BYREF
  int v6[10]; // [sp+40h] [bp-88h] BYREF
  int v7[24]; // [sp+68h] [bp-60h] BYREF

  result = IoGetDeviceAttachmentBaseRef(*(_DWORD *)(a1 + 24));
  v3 = result;
  if ( result )
    v4 = *(_DWORD *)(*(_DWORD *)(result + 176) + 20);
  else
    v4 = 0;
  if ( v4 )
  {
    result = PopDiagSnapPassiveHistogram(a1 + 368, v7);
    if ( (unsigned int)dword_6163C8 > 5 )
    {
      result = TlgKeywordOn((int)&dword_6163C8, 0x400000000000i64);
      if ( result )
      {
        v5[8] = v6;
        v5[9] = 0;
        v5[10] = 2;
        v5[11] = 0;
        v5[12] = *(_DWORD *)(v4 + 164);
        v5[13] = 0;
        v6[0] = *(unsigned __int16 *)(v4 + 160);
        v6[1] = 0;
        v6[2] = (int)v7;
        v6[3] = 0;
        v6[4] = 80;
        v6[5] = 0;
        v6[6] = (int)&PopThermalTrackingThresholds;
        v6[7] = 0;
        v6[8] = 20;
        v6[9] = 0;
        result = TlgWrite(&dword_6163C8, (unsigned __int8 *)&word_414412 + 1, 0, 0, 6, v5);
      }
    }
  }
  if ( v3 )
    result = ObfDereferenceObjectWithTag(v3);
  return result;
}
