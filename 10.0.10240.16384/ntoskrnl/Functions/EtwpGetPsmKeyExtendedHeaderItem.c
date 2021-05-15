// EtwpGetPsmKeyExtendedHeaderItem 
 
_DWORD *__fastcall EtwpGetPsmKeyExtendedHeaderItem(_WORD *a1, int a2, int a3, int a4)
{
  __int16 v5; // r6
  __int16 v6; // r8
  int v7; // r10
  int v8; // r9
  int v9; // r4
  _DWORD *result; // r0
  int v11[8]; // [sp+0h] [bp-20h] BYREF

  v11[0] = a4;
  v5 = 0;
  v6 = 8;
  v7 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v8 = PsReferencePrimaryToken(v7);
  v9 = SeSecurityAttributePresent(v8, (int)&PspSysAppIdClaim);
  SeSecurityAttributePresent(v8, (int)&PspPackagedAppClaim);
  if ( v9 )
  {
    v11[0] = 466;
    if ( EtwpQueryPsmKey(v8, a1 + 4, v11) >= 0 )
      v5 = v11[0];
    v6 = v5 + 8;
  }
  result = ObFastDereferenceObject((_DWORD *)(v7 + 244), v8);
  *a1 = (v6 + 7) & 0xFFF8;
  a1[1] = 9;
  a1[2] = 0;
  a1[3] = v5;
  return result;
}
