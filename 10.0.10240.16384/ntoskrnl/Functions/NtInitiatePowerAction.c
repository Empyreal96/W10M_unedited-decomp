// NtInitiatePowerAction 
 
int __fastcall NtInitiatePowerAction(int a1, int a2, int a3, int a4)
{
  int v8; // r5
  _DWORD *v9; // r6
  unsigned int v10; // r4
  _BYTE *v11; // r0
  __int64 v12; // r0
  int v14[2]; // [sp+8h] [bp-48h] BYREF
  int v15[4]; // [sp+10h] [bp-40h] BYREF
  int v16; // [sp+20h] [bp-30h] BYREF
  int v17; // [sp+24h] [bp-2Ch]
  _DWORD *v18; // [sp+28h] [bp-28h]
  int v19; // [sp+2Ch] [bp-24h]

  v14[0] = -1500000000;
  v14[1] = -1;
  v8 = 0;
  v9 = 0;
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( *(_BYTE *)(v10 + 346) )
  {
    if ( a1 == 7 )
      return -1073741811;
    if ( !SeSinglePrivilegeCheck(SeShutdownPrivilege, dword_922B8C, *(char *)(v10 + 346), (int)&SeShutdownPrivilege) )
      return -1073741727;
  }
  if ( a2 > 7 || a1 > 7 || (a3 & 0x10000000) != 0 || a1 == 2 && a2 >= 5 || (a3 & 0xFFFFFF0) != 0 )
    return -1073741811;
  v15[1] = a3;
  v15[2] = 0;
  v18 = 0;
  v19 = 0;
  v16 = 4;
  v17 = 128;
  v15[0] = a1;
  if ( !a4 )
  {
    v11 = (_BYTE *)ExAllocatePoolWithTag(512, 32, 1466122576);
    v9 = v11;
    if ( !v11 )
      return -1073741670;
    memset(v11, 0, 32);
    v9[7] = &v16;
    v9[4] = 0;
    KeInitializeEvent((int)v9, 0, 0);
    v18 = v9;
    v17 |= 0x20u;
  }
  PopAcquirePolicyLock();
  PopExecutePowerAction(&v16, 0, v15, a2, 1);
  PopReleasePolicyLock();
  if ( v9 )
  {
    if ( !v9[5] )
      goto LABEL_23;
    v8 = KeWaitForSingleObject((unsigned int)v9, 5, 0, (_DWORD *)1, v14);
    if ( v8 == 258 && (byte_61EC61 & 3) != 0 )
      v8 = KeWaitForSingleObject((unsigned int)v9, 5, 0, (_DWORD *)1, 0);
    PopAcquirePolicyLock();
    v12 = *(_QWORD *)(v9 + 5);
    if ( *(_DWORD **)(v12 + 4) != v9 + 5 || *(_DWORD **)HIDWORD(v12) != v9 + 5 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v12) = v12;
    *(_DWORD *)(v12 + 4) = HIDWORD(v12);
    PopReleasePolicyLock();
    if ( v8 >= 0 )
    {
LABEL_23:
      v8 = v9[4];
      if ( v8 >= 0 )
        v8 = 0;
    }
    ExFreePoolWithTag((unsigned int)v9);
  }
  return v8;
}
