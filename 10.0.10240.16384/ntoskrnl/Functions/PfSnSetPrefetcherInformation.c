// PfSnSetPrefetcherInformation 
 
int __fastcall PfSnSetPrefetcherInformation(int a1, int *a2, int a3, int a4)
{
  int v4; // r6
  int v6; // r4
  int v7; // r0
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r0
  int v12; // r5
  _DWORD v14[6]; // [sp+4h] [bp-78h] BYREF
  _DWORD _1C[29]; // [sp+1Ch] [bp-60h] BYREF
  int varg_r3; // [sp+90h] [bp+14h]

  _1C[26] = a1;
  _1C[27] = a2;
  _1C[28] = a3;
  varg_r3 = a4;
  v4 = (char)a4;
  LOBYTE(varg_r3) = a4;
  if ( a3 == 20 )
  {
    v7 = *a2;
    v8 = a2[1];
    v9 = a2[2];
    v10 = a2[3];
    v14[0] = *a2;
    v14[1] = v8;
    v14[2] = v9;
    v14[3] = v10;
    v14[4] = a2[4];
    if ( v14[0] == 1 && v14[1] == 1802856515 )
    {
      if ( v14[2] == 3 )
      {
        if ( v14[4] == 4 )
        {
          if ( v4 && (v14[3] & 3) != 0 )
            ExRaiseDatatypeMisalignment(v7);
          v12 = *(_DWORD *)v14[3];
          if ( *(_DWORD *)v14[3] != 2 && v4 )
            return -1073741790;
          v6 = PfSnBeginBootPhase(*(_DWORD *)v14[3]);
          if ( v12 == 2 )
          {
            memset(v14, 0, sizeof(v14));
            v14[0] = 4;
            v14[1] = 4;
            v14[2] = 1;
            PfpProcessScenarioPhase(v14, v4);
          }
          goto LABEL_40;
        }
      }
      else
      {
        if ( v14[2] != 5 && v14[2] != 8 )
        {
          v7 = SeSinglePrivilegeCheck(
                 SeProfileSingleProcessPrivilege,
                 dword_922B94,
                 v4,
                 (int)&SeProfileSingleProcessPrivilege);
          if ( !v7 )
            return -1073741790;
        }
        switch ( v14[2] )
        {
          case 5:
            if ( v14[4] == 12 )
            {
              if ( v4 && (v14[3] & 3) != 0 )
                ExRaiseDatatypeMisalignment(v7);
              v14[0] = *(_DWORD *)v14[3];
              v14[1] = *(_DWORD *)(v14[3] + 4);
              v14[2] = *(_DWORD *)(v14[3] + 8);
              v11 = PfSnOperationProcess(v14);
              goto LABEL_19;
            }
            break;
          case 6:
            if ( v14[4] != 76 )
              return -1073741306;
            if ( v4 && (v14[3] & 3) != 0 )
              ExRaiseDatatypeMisalignment(v7);
            memmove((int)_1C, v14[3], 0x4Cu);
            if ( _1C[0] == 1 )
            {
              PfSnPrefetchCacheEntryUpdate(_1C);
              return 0;
            }
            break;
          case 8:
            if ( v14[4] == 12 )
            {
              if ( v4 && (v14[3] & 3) != 0 )
                ExRaiseDatatypeMisalignment(v7);
              v14[0] = *(_DWORD *)v14[3];
              v14[1] = *(_DWORD *)(v14[3] + 4);
              v14[2] = *(_DWORD *)(v14[3] + 8);
              v11 = PfSnAppLaunchScenarioControl(v14, v4);
LABEL_19:
              v6 = v11;
LABEL_40:
              if ( v6 < 0 )
                return v6;
              return 0;
            }
            return -1073741306;
          default:
            return -1073741821;
        }
      }
    }
    return -1073741811;
  }
  return -1073741820;
}
