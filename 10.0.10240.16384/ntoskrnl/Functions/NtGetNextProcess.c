// NtGetNextProcess 
 
int __fastcall NtGetNextProcess(int a1, int a2, int a3, int a4, _DWORD *a5)
{
  int v5; // r6
  int v6; // r2
  _DWORD *v7; // r2
  int v8; // r4
  int v9; // r0
  int *v10; // r5
  int *v11; // r0
  unsigned int v12; // r6
  int v13; // r3
  int v14; // r4
  __int16 v15; // r3
  int v16; // r2
  int *v18; // [sp+14h] [bp-17Ch] BYREF
  BOOL v19; // [sp+18h] [bp-178h]
  int v20; // [sp+1Ch] [bp-174h]
  int v21; // [sp+20h] [bp-170h]
  int v22; // [sp+24h] [bp-16Ch]
  int v23; // [sp+2Ch] [bp-164h] BYREF
  char v24[16]; // [sp+30h] [bp-160h] BYREF
  int v25; // [sp+40h] [bp-150h]
  int v26; // [sp+44h] [bp-14Ch]
  int v27; // [sp+4Ch] [bp-144h] BYREF
  _DWORD _A8[62]; // [sp+A8h] [bp-E8h] BYREF
  int varg_r2; // [sp+1A0h] [bp+10h]
  int varg_r3; // [sp+1A4h] [bp+14h]

  _A8[60] = a1;
  varg_r2 = a3;
  varg_r3 = a4;
  v22 = a2;
  _A8[61] = a2;
  v18 = (int *)a1;
  v19 = (BOOL)a5;
  v5 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v21 = v5;
  if ( v5 )
    v6 = a3 & 0xDF2;
  else
    v6 = a3 & 0x10FF2;
  v20 = v6;
  varg_r2 = v6;
  if ( v5 )
  {
    v7 = a5;
    if ( (unsigned int)a5 >= MmUserProbeAddress )
      v7 = (_DWORD *)MmUserProbeAddress;
    *v7 = *v7;
  }
  *a5 = 0;
  if ( a4 )
    return -1073741811;
  if ( a1 )
  {
    v8 = ObReferenceObjectByHandleWithTag(a1, 0, PsProcessType, v5, 1850045264, (int *)&v18, 0);
    if ( v8 < 0 )
      return v8;
    v9 = (int)v18;
  }
  else
  {
    v9 = 0;
  }
  v10 = PsGetNextProcess(v9);
  v18 = v10;
  if ( !v10 )
    return -2147483622;
  v11 = (int *)SeSinglePrivilegeCheck(SeDebugPrivilege, dword_922784, v5, (int)&SeDebugPrivilege);
  v19 = v11 != 0;
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  do
  {
    if ( (v10[48] & 0x4000000) != 0 )
      goto LABEL_28;
    --*(_WORD *)(v12 + 308);
    __dmb(0xFu);
    v13 = v10[42];
    __dmb(0xBu);
    if ( (v13 & 1) != 0 )
    {
      v14 = KeAbPreAcquire((unsigned int)(v10 + 42), 0, 0);
      ExfAcquirePushLockExclusiveEx(v10 + 42, v14, (unsigned int)(v10 + 42));
      if ( v14 )
        *(_BYTE *)(v14 + 14) |= 1u;
      v11 = (int *)ExfReleasePushLockExclusive((unsigned int *)v10 + 42);
      if ( v14 )
        v11 = (int *)KeAbPostRelease((unsigned int)(v10 + 42));
    }
    v15 = *(_WORD *)(v12 + 308) + 1;
    *(_WORD *)(v12 + 308) = v15;
    if ( !v15 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
      KiCheckForKernelApcDelivery((int)v11);
    if ( (v10[48] & 0x4000000) != 0 )
    {
LABEL_28:
      v8 = SeCreateAccessState((int)v24, (int)_A8, v22, (_DWORD *)(PsProcessType + 52));
      if ( v8 < 0 )
        goto LABEL_38;
      if ( v19 )
      {
        v16 = v25;
        if ( (v25 & 0x2000000) != 0 )
          v16 = 0x1FFFFF;
        v26 |= v16;
        v25 = 0;
      }
      v8 = ObOpenObjectByPointer((int)v10, v20, v24, 0, PsProcessType, v21, &v23);
      SepDeleteAccessState((int)v24);
      SeReleaseSubjectContext((int)&v27);
      if ( v8 >= 0 )
      {
        *a5 = v23;
        goto LABEL_38;
      }
      if ( v8 != -1073741790 )
        goto LABEL_38;
    }
    v11 = PsGetNextProcess((int)v10);
    v10 = v11;
    v18 = v11;
  }
  while ( v11 );
  v8 = -2147483622;
LABEL_38:
  if ( v10 )
    ObfDereferenceObjectWithTag((int)v10);
  return v8;
}
