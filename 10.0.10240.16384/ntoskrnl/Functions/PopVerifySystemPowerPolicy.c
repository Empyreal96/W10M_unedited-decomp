// PopVerifySystemPowerPolicy 
 
int __fastcall PopVerifySystemPowerPolicy(int a1, int a2)
{
  __int64 v4; // kr00_8
  int v5; // r1
  int v6; // r1
  int v7; // r1
  _DWORD *v8; // r5
  int v9; // r8
  BOOL v10; // r6
  int v11; // r1
  unsigned int v12; // r3
  unsigned int v13; // r3
  __int64 v14; // r2

  memmove(a2, a1, 0xE8u);
  if ( *(_DWORD *)a2 != 1 )
    return -1073741811;
  if ( byte_61EA45 )
  {
    *(_DWORD *)(a2 + 72) = 4;
  }
  else if ( byte_61EA44 )
  {
    *(_DWORD *)(a2 + 72) = 3;
  }
  else if ( byte_61EA43 )
  {
    *(_DWORD *)(a2 + 72) = 2;
  }
  if ( *(int *)(a2 + 68) < 2 )
    *(_DWORD *)(a2 + 68) = 2;
  if ( *(int *)(a2 + 68) > 4 )
    *(_DWORD *)(a2 + 68) = 4;
  if ( *(int *)(a2 + 72) < 2 )
    *(_DWORD *)(a2 + 72) = 2;
  if ( *(int *)(a2 + 72) > 4 )
    *(_DWORD *)(a2 + 72) = 4;
  v4 = *(_QWORD *)(a2 + 68);
  if ( SHIDWORD(v4) < (int)v4 )
    *(_DWORD *)(a2 + 72) = v4;
  if ( (int)v4 < PopAdminPolicy )
    *(_DWORD *)(a2 + 68) = PopAdminPolicy;
  if ( *(_DWORD *)(a2 + 72) > dword_61E9A4 )
    *(_DWORD *)(a2 + 72) = dword_61E9A4;
  if ( *(_DWORD *)(a2 + 192) < (unsigned int)dword_61E9A8 )
    *(_DWORD *)(a2 + 192) = dword_61E9A8;
  if ( *(_DWORD *)(a2 + 192) > (unsigned int)dword_61E9AC )
    *(_DWORD *)(a2 + 192) = dword_61E9AC;
  if ( *(_DWORD *)(a2 + 212) < (unsigned int)dword_61E9B0 )
    *(_DWORD *)(a2 + 212) = dword_61E9B0;
  if ( *(_DWORD *)(a2 + 212) > (unsigned int)dword_61E9B4 )
    *(_DWORD *)(a2 + 212) = dword_61E9B4;
  PopVerifyPowerActionPolicy((int *)(a2 + 4));
  PopVerifyPowerActionPolicy((int *)(a2 + 16));
  PopVerifyPowerActionPolicy((int *)(a2 + 28));
  PopVerifyPowerActionPolicy((int *)(a2 + 48));
  PopVerifySystemPowerState(a2 + 40, 1);
  PopVerifySystemPowerState(a2 + 68, v5);
  PopVerifySystemPowerState(a2 + 72, v6);
  PopVerifySystemPowerState(a2 + 76, v7);
  v8 = (_DWORD *)(a2 + 96);
  v9 = 4;
  do
  {
    v10 = v8[2] == 3;
    PopVerifyPowerActionPolicy(v8 + 2);
    if ( v10 && (int)v8[2] < 3 )
    {
      v8[2] = 6;
      PopVerifyPowerActionPolicy(v8 + 2);
    }
    PopVerifySystemPowerState(v8 + 5, 1);
    if ( v8[2] == 2 && (int)v8[5] > 4 )
    {
      v8[5] = 4;
      PopVerifySystemPowerState(v8 + 5, v11);
    }
    if ( v8[1] > 0x64u )
      v8[1] = 100;
    v8 += 6;
    --v9;
  }
  while ( v9 );
  PopVerifyPowerActionPolicy((int *)(a2 + 220));
  if ( !*(_DWORD *)(a2 + 92) )
    *(_DWORD *)(a2 + 92) = 1;
  if ( *(_DWORD *)(a2 + 88) && !byte_61EA47 )
    *(_DWORD *)(a2 + 88) = 0;
  v12 = *(_DWORD *)(a2 + 60);
  if ( v12 && v12 < 0x3C )
    *(_DWORD *)(a2 + 60) = 60;
  v13 = *(_DWORD *)(a2 + 88);
  if ( v13 && v13 < 0x3C )
    *(_DWORD *)(a2 + 88) = 60;
  if ( *(unsigned __int8 *)(a2 + 64) > 0x5Au )
    *(_BYTE *)(a2 + 64) = 90;
  if ( *(_DWORD *)(a2 + 60) && !*(_BYTE *)(a2 + 64) )
    *(_BYTE *)(a2 + 64) = 90;
  v14 = *(_QWORD *)(a2 + 68);
  if ( SHIDWORD(v14) < (int)v14 )
    *(_DWORD *)(a2 + 72) = v14;
  if ( *(_DWORD *)(a2 + 76) > (int)v14 )
    *(_DWORD *)(a2 + 76) = v14;
  return 0;
}
