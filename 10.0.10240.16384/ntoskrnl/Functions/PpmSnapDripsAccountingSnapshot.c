// PpmSnapDripsAccountingSnapshot 
 
void PpmSnapDripsAccountingSnapshot()
{
  int v0; // r2
  unsigned int v1; // r5
  _DWORD *v2; // r6
  __int64 v3; // r0
  _QWORD *v4; // r3
  _BYTE v5[232]; // [sp-4h] [bp-E8h] BYREF

  v0 = dword_635500;
  __dmb(0xBu);
  if ( PpmPlatformStates && v0 != -1 )
  {
    v1 = 0;
    v2 = (_DWORD *)(*(_DWORD *)(PpmPlatformStates + 32) + 992 * v0 + 184);
    do
    {
      LODWORD(v3) = PpmConvertTimeTo(
                      *v2 - PpmDripsAccountingSnapshot[v1],
                      (*(_QWORD *)v2 - *(_QWORD *)&PpmDripsAccountingSnapshot[v1]) >> 32);
      v4 = &v5[v1 * 4];
      v1 += 2;
      v2 += 8;
      *v4 = v3;
    }
    while ( v1 < 52 );
    PpmEventTraceDripsAccountingSnapshot(v3, (int)v5);
  }
}
