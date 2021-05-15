// PfpParametersRead 
 
int __fastcall PfpParametersRead(_DWORD *a1)
{
  int v1; // r2
  int v2; // r3
  int v3; // r4
  int v4; // r2
  int v5; // r3
  int v6; // r8
  int result; // r0
  int v9; // r1
  int v10; // r2
  int v11; // r3
  int v12; // r2
  int v13; // r3
  int v14[2]; // [sp+8h] [bp-40h] BYREF
  int v15; // [sp+10h] [bp-38h] BYREF
  int v16; // [sp+14h] [bp-34h]
  int v17; // [sp+18h] [bp-30h] BYREF
  int v18; // [sp+1Ch] [bp-2Ch] BYREF
  int v19; // [sp+20h] [bp-28h] BYREF
  int v20; // [sp+24h] [bp-24h] BYREF
  int v21[8]; // [sp+28h] [bp-20h] BYREF

  v1 = a1[10];
  v2 = a1[11];
  v3 = a1[12];
  v15 = a1[9];
  v16 = v1;
  v17 = v2;
  v18 = v3;
  v4 = a1[14];
  v5 = a1[15];
  v19 = a1[13];
  v20 = v4;
  v21[0] = v5;
  v6 = a1[1];
  v14[0] = 4;
  if ( PfpGetParameter(v6, L"EnableSuperfetch", 4, &v15, v14) >= 0 )
    return sub_8178EC();
  v15 = 0x80000000;
  v14[0] = 4;
  PfpGetParameter(v6, L"SavedSectInfoTracesMax", 4, &v17, v14);
  v14[0] = 4;
  PfpGetParameter(v6, L"SavedPageAccessTracesMax", 4, &v18, v14);
  v14[0] = 4;
  PfpGetParameter(a1[1], L"PrefetchTimeoutStandby", 4, &v19, v14);
  v14[0] = 4;
  PfpGetParameter(a1[1], L"PrefetchTimeoutHibernate", 4, &v20, v14);
  v14[0] = 4;
  PfpGetParameter(a1[1], L"PrefetchTimeoutHiberBoot", 4, v21, v14);
  result = PfpParametersVerify(&v15);
  if ( result >= 0 )
  {
    ++a1[119];
    v9 = v16;
    v10 = v17;
    v11 = v18;
    a1[9] = v15;
    a1[10] = v9;
    a1[11] = v10;
    a1[12] = v11;
    v12 = v20;
    v13 = v21[0];
    result = 0;
    a1[13] = v19;
    a1[14] = v12;
    a1[15] = v13;
  }
  return result;
}
