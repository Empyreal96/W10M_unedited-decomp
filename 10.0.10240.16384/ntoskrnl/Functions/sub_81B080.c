// sub_81B080 
 
int sub_81B080()
{
  _DWORD *v0; // r4
  int v1; // r5
  int v2; // r6
  unsigned int v3; // r2
  void *v4; // r1
  int v5; // r3
  int v6; // r2
  int v7; // r5
  int v8; // r1
  unsigned int v9; // r0
  unsigned int v10; // r2
  int v11; // r0
  unsigned int v12; // r1
  __int16 v13; // r3
  __int16 v15[2]; // [sp+0h] [bp-28h] BYREF
  int v16; // [sp+4h] [bp-24h]
  int v17; // [sp+8h] [bp-20h]
  int (__fastcall *v18)(int); // [sp+24h] [bp-4h]

  ExfAcquirePushLockExclusiveEx(v0, v2, (unsigned int)v0);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  v0[1] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( !v1 || *(_BYTE *)(v1 + 7) )
    goto LABEL_12;
  if ( *(_WORD *)(v1 + 4) || (v3 = *(unsigned __int8 *)(v1 + 6), v3 >= KeNumberProcessors_0) )
    v3 = -1;
  if ( v3 == -1 )
  {
LABEL_12:
    v7 = -1073741811;
    goto LABEL_13;
  }
  v15[0] = 1;
  v15[1] = 1;
  v16 = 0;
  v17 = 1 << v3;
  if ( *(_BYTE *)(v1 + 13) )
  {
    v4 = PpmUpdateIdleStatesInplace;
    v5 = 0;
LABEL_28:
    v6 = v1;
    goto LABEL_29;
  }
  if ( *(_DWORD *)(v1 + 60) )
  {
    v4 = PpmInstallNewIdleStates;
    v5 = 3;
    goto LABEL_28;
  }
  v4 = PpmRemoveIdleStates;
  v5 = 0;
  v6 = 0;
LABEL_29:
  v7 = PopExecuteOnTargetProcessors((int)v15, (int)v4, v6, v5);
LABEL_13:
  v0[1] = 0;
  __pld(v0);
  v8 = *v0;
  v9 = *v0 - 16;
  if ( (*v0 & 0xFFFFFFF0) <= 0x10 )
    v9 = 0;
  if ( (v8 & 2) != 0 )
    goto LABEL_20;
  __dmb(0xBu);
  do
    v10 = __ldrex(v0);
  while ( v10 == v8 && __strex(v9, v0) );
  if ( v10 != v8 )
LABEL_20:
    ExfReleasePushLock(v0, v8);
  v11 = KeAbPostRelease((unsigned int)v0);
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v13 = *(_WORD *)(v12 + 0x134) + 1;
  *(_WORD *)(v12 + 308) = v13;
  if ( !v13 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
    KiCheckForKernelApcDelivery(v11);
  return v18(v7);
}
