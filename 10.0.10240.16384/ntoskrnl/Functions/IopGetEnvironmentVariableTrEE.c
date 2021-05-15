// IopGetEnvironmentVariableTrEE 
 
int __fastcall IopGetEnvironmentVariableTrEE(int a1, int a2, unsigned __int16 *a3, _DWORD *a4, int a5, unsigned int *a6, _DWORD *a7)
{
  unsigned int v8; // r6
  int v9; // r0
  int v10; // r3
  _DWORD *v11; // r7
  int v12; // r5
  int v13; // r1
  int v14; // r3
  int v15; // r4
  int v16; // r5
  int v17; // r0
  int v18; // r3
  unsigned int *v19; // r4
  unsigned int v20; // r3
  unsigned int v21; // r2
  _DWORD *v23; // [sp+18h] [bp-28h] BYREF
  int v24; // [sp+1Ch] [bp-24h]
  int v25; // [sp+20h] [bp-20h]

  v24 = a2;
  v25 = a1;
  v23 = a4;
  v8 = 2 * (wcslen(a3) + 1);
  if ( ViVerifierDriverAddedThunkListHead )
  {
    if ( (MmVerifierData & 0x10) != 0 )
      v10 = 40;
    else
      v10 = 32;
    v9 = ExAllocatePoolWithTagPriority(1, v8 + 16, 538996553, v10);
  }
  else
  {
    v9 = ExAllocatePoolWithTag(1, v8 + 16, 538996553);
  }
  v11 = (_DWORD *)v9;
  if ( !v9 )
    return -1073741670;
  memmove(v9 + 16, (int)a3, v8);
  v13 = v23[1];
  v14 = v23[2];
  v15 = v23[3];
  *v11 = *v23;
  v11[1] = v13;
  v11[2] = v14;
  v11[3] = v15;
  v16 = *a6 + 12;
  if ( ViVerifierDriverAddedThunkListHead )
  {
    if ( (MmVerifierData & 0x10) != 0 )
      v18 = 40;
    else
      v18 = 32;
    v17 = ExAllocatePoolWithTagPriority(1, *a6 + 12, 538996553, v18);
  }
  else
  {
    v17 = ExAllocatePoolWithTag(1, *a6 + 12, 538996553);
  }
  v19 = (unsigned int *)v17;
  if ( !v17 )
  {
    v12 = -1073741670;
    goto LABEL_29;
  }
  v12 = IopIssueTrEERequest(0, v25, v24, (int)v11, v8 + 16, v17, v16, 0xCu, &v23);
  if ( v12 < 0 )
  {
    v20 = 0;
LABEL_19:
    *a6 = v20;
    goto LABEL_29;
  }
  if ( !*v19 )
  {
    if ( a7 )
      *a7 = v19[1];
    v21 = *a6;
    if ( *a6 >= v19[2] )
      v21 = v19[2];
    memmove(a5, (int)(v19 + 3), v21);
    v20 = v19[2];
    goto LABEL_19;
  }
  if ( *v19 == -2147483643 )
  {
    v12 = -1073741789;
    *a6 = v19[2];
  }
  else
  {
    *a6 = 0;
    v12 = IopEfiStatusToNTSTATUS(*v19);
  }
LABEL_29:
  ExFreePoolWithTag((unsigned int)v11);
  if ( v19 )
    ExFreePoolWithTag((unsigned int)v19);
  return v12;
}
