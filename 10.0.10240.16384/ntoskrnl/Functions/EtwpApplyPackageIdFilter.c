// EtwpApplyPackageIdFilter 
 
BOOL __fastcall EtwpApplyPackageIdFilter(int a1, _WORD *a2, _WORD *a3)
{
  BOOL v5; // r10
  BOOL v6; // r8
  BOOL v7; // r9
  unsigned int v8; // r5
  int v9; // r4
  unsigned int v10; // r4
  int v11; // r5
  _WORD *v12; // r2
  unsigned int v13; // r4
  int v14; // r5
  _WORD *v15; // r2
  BOOL v16; // r3
  int v18; // [sp+8h] [bp-1B8h]
  unsigned int v20; // [sp+10h] [bp-1B0h] BYREF
  unsigned int v21; // [sp+14h] [bp-1ACh] BYREF
  unsigned __int16 v22[128]; // [sp+18h] [bp-1A8h] BYREF
  unsigned __int16 v23[84]; // [sp+118h] [bp-A8h] BYREF

  v5 = 0;
  v6 = a2 == 0;
  v7 = a3 == 0;
  v18 = PsReferencePrimaryToken(*(_DWORD *)(a1 + 40));
  v8 = v18;
  v9 = SeSecurityAttributePresent(v18, (int)&PspSysAppIdClaim);
  SeSecurityAttributePresent(v18, (int)&PspPackagedAppClaim);
  if ( v9 )
  {
    v20 = 256;
    v21 = 130;
    if ( RtlQueryPackageIdentity(v18, (int)v22, (int)&v20, (int)v23, (int)&v21, 0) >= 0 )
    {
      if ( a2 )
      {
        v10 = 0;
        v11 = (v20 >> 1) - 1;
        if ( *a2 )
        {
          while ( 1 )
          {
            v12 = &a2[4 * v10];
            if ( (unsigned __int16)v12[2] == v11 && !wcsnicmp(*((_DWORD *)v12 + 2), v22, v11) )
              break;
            v10 = (unsigned __int16)(v10 + 1);
            if ( v10 >= (unsigned __int16)*a2 )
              goto LABEL_8;
          }
          v6 = 1;
        }
        else
        {
LABEL_8:
          v6 = 0;
        }
      }
      if ( a3 )
      {
        v13 = 0;
        v14 = (v21 >> 1) - 1;
        if ( *a3 )
        {
          while ( 1 )
          {
            v15 = &a3[4 * v13];
            if ( (unsigned __int16)v15[2] == v14 && !wcsnicmp(*((_DWORD *)v15 + 2), v23, v14) )
              break;
            v13 = (unsigned __int16)(v13 + 1);
            if ( v13 >= (unsigned __int16)*a3 )
              goto LABEL_14;
          }
          v7 = 1;
        }
        else
        {
LABEL_14:
          v7 = 0;
        }
      }
      v16 = v6 && v7;
      v8 = v18;
      v5 = v16;
    }
  }
  ObFastDereferenceObject((_DWORD *)(*(_DWORD *)(a1 + 40) + 244), v8);
  return v5;
}
