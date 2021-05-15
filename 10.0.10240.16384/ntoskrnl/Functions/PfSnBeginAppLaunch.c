// PfSnBeginAppLaunch 
 
int __fastcall PfSnBeginAppLaunch(int a1, unsigned int a2, int a3)
{
  unsigned int v6; // r5
  int v7; // r6
  int v8; // r0
  int v9; // r1
  unsigned int v11; // r4
  int v12; // r0
  int v13; // r3
  int v14; // r4
  unsigned int v15; // [sp+Ch] [bp-70h] BYREF
  int v16; // [sp+10h] [bp-6Ch] BYREF
  int v17; // [sp+14h] [bp-68h] BYREF
  int v18[24]; // [sp+1Ch] [bp-60h] BYREF

  v6 = 0;
  v15 = 0;
  v16 = 0;
  memset(v18, 0, 64);
  v7 = 0;
  if ( PfSnCheckScenario(0, &v17) < 0 )
    goto LABEL_22;
  if ( !a2 )
  {
    v8 = PfCalculateProcessHash(a1, &v15);
    v6 = v15;
    if ( v8 < 0 )
      goto LABEL_22;
    a2 = v15;
  }
  v9 = PfSnFindImageFileName(a2, &v15);
  if ( !v9 )
    return sub_8086F8();
  v11 = v15;
  if ( v15 >= 0x1D )
    v11 = 29;
  memmove((int)v18, v9, 2 * v11);
  *((_WORD *)v18 + v11) = 0;
  v18[15] = *(_DWORD *)(a1 + 408);
  v12 = PfSnIsHostingApplication(v18);
  if ( PfSnScanCommandLine(&v16, v12) < 0 || (v18[15] += v16, PfSnCheckModernApp(&v15, &v16) < 0) )
LABEL_22:
    JUMPOUT(0x8086FA);
  if ( v15 )
  {
    v13 = v16 + v18[15];
    v7 = 8;
  }
  else
  {
    v13 = v18[15];
  }
  v18[15] = v13 + a3;
  if ( (dword_637410 & 0x20) != 0 || v17 == 2 )
    v7 |= 2u;
  v14 = PfSnBeginScenario(a1, v18, 0, v7);
  if ( v14 >= 0 )
    v14 = 0;
  if ( v6 )
    ExFreePoolWithTag(v6);
  return v14;
}
