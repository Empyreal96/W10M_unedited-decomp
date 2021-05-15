// MiLockUnlockCommon 
 
int __fastcall MiLockUnlockCommon(int a1, unsigned int *a2, _DWORD *a3, int a4, unsigned int *a5, unsigned int *a6, _DWORD *a7)
{
  char v7; // r6
  unsigned int *v8; // r5
  int result; // r0
  int v10; // r8
  _DWORD *v11; // r1
  unsigned int v12; // r5
  unsigned int v13; // r4
  int _14[17]; // [sp+14h] [bp-2Ch] BYREF

  _14[14] = (int)a2;
  _14[15] = (int)a3;
  v7 = a4;
  _14[16] = a4;
  v8 = a2;
  _14[13] = a1;
  if ( (a4 & 0xFFFFFFFC) != 0 || (a4 & 3) == 0 )
    return -1073741811;
  v10 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v10 )
  {
    if ( (unsigned int)a2 >= MmUserProbeAddress )
      a2 = (unsigned int *)MmUserProbeAddress;
    *a2 = *a2;
    v11 = a3;
    if ( (unsigned int)a3 >= MmUserProbeAddress )
      v11 = (_DWORD *)MmUserProbeAddress;
    *v11 = *v11;
  }
  v12 = *v8;
  _14[1] = v12;
  v13 = *a3;
  _14[2] = *a3;
  if ( v12 > MmHighestUserAddress || MmHighestUserAddress - v12 < v13 || !v13 )
    return -1073741811;
  result = ObReferenceObjectByHandleWithTag(a1, 8, PsProcessType, v10, 1834380621, _14, 0);
  if ( result >= 0 )
  {
    if ( (v7 & 2) == 0 || SeSinglePrivilegeCheck(SeLockMemoryPrivilege, dword_922B7C, v10, (int)&SeLockMemoryPrivilege) )
    {
      *a5 = v12;
      *a6 = v13;
      *a7 = _14[0];
      result = 0;
    }
    else
    {
      ObfDereferenceObjectWithTag(_14[0]);
      result = -1073741727;
    }
  }
  return result;
}
