// PpmPerfProcCapFloorSettingCallback 
 
int __fastcall PpmPerfProcCapFloorSettingCallback(unsigned int a1, int *a2, int a3)
{
  unsigned int v3; // r9
  BOOL v6; // r4
  int v7; // r2
  _DWORD *v8; // r3
  int v9; // r3
  int v10; // r4
  int v12; // [sp+0h] [bp-38h] BYREF
  _DWORD v13[3]; // [sp+8h] [bp-30h] BYREF
  int v14; // [sp+14h] [bp-24h]

  LOWORD(v12) = 0;
  v3 = *(unsigned __int8 *)(a1 + 15);
  v13[0] = 0;
  v13[1] = 0;
  v13[2] = 0;
  v14 = 0x10000;
  HIBYTE(v14) = v3;
  v6 = memcmp((unsigned int)v13, a1, 16) == 0;
  PpmAcquireLock((unsigned int *)&PpmPerfPolicyLock);
  if ( a3 != 4 || !a2 )
    goto LABEL_14;
  v7 = *a2;
  if ( (unsigned int)*a2 > 0x64 )
    v7 = 100;
  v8 = v3 >= KeNumberProcessors_0 ? 0 : *(&KiProcessorBlock + v3);
  if ( v8 )
  {
    v9 = v8[801];
    if ( v9 )
    {
      if ( v6 )
        *(_DWORD *)(v9 + 8) = v7;
      else
        *(_DWORD *)(v9 + 12) = v7;
    }
    v10 = 0;
  }
  else
  {
LABEL_14:
    v10 = -1073741811;
  }
  v12 |= 0xEu;
  PpmReapplyPerfPolicy(&v12);
  return v10;
}
