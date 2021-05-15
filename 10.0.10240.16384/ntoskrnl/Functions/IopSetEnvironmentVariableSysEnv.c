// IopSetEnvironmentVariableSysEnv 
 
int __fastcall IopSetEnvironmentVariableSysEnv(int a1, int a2, unsigned __int16 *a3, _DWORD *a4, int a5, unsigned int a6, int a7)
{
  unsigned int v9; // r7
  unsigned int v11; // r5
  int v12; // r1
  int v13; // r2
  int v14; // r3
  int v15; // r4
  int v16; // r3
  _DWORD *v17; // r0

  v9 = 2 * (wcslen(a3) + 1);
  if ( !ViVerifierDriverAddedThunkListHead )
    return sub_8156B4();
  if ( (MmVerifierData & 0x10) != 0 )
    v16 = 40;
  else
    v16 = 32;
  v17 = (_DWORD *)ExAllocatePoolWithTagPriority(1, v9 + a6 + 32, 538996553, v16);
  v11 = (unsigned int)v17;
  if ( !v17 )
    return -1073741670;
  v12 = a4[1];
  v13 = a4[2];
  v14 = a4[3];
  v17[4] = *a4;
  v17[5] = v12;
  v17[6] = v13;
  v17[7] = v14;
  v17[3] = a7;
  *v17 = 0;
  memmove((int)(v17 + 8), (int)a3, v9);
  memmove(v11 + v9 + 32, a5, a6);
  *(_DWORD *)(v11 + 4) = v9 + 32;
  *(_DWORD *)(v11 + 8) = a6;
  v15 = IopIssueSystemEnvironmentRequest(5373960, 1, 0, a2, v11, v9 + a6 + 32, 0, 0, 0);
  ExFreePoolWithTag(v11);
  return v15;
}
