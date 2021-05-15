// IopSetEnvironmentVariableTrEE 
 
int __fastcall IopSetEnvironmentVariableTrEE(int a1, int a2, unsigned __int16 *a3, _DWORD *a4, int a5, unsigned int a6, int a7)
{
  unsigned int v8; // r9
  _DWORD *v9; // r0
  int v10; // r3
  unsigned int v11; // r6
  int v12; // r4
  int v13; // r1
  int v14; // r3
  int v15; // r4
  int v16; // r3
  int v17; // r1
  unsigned __int16 *v19; // [sp+18h] [bp-30h] BYREF
  int v20; // [sp+1Ch] [bp-2Ch]
  int v21; // [sp+20h] [bp-28h]
  unsigned int v22[9]; // [sp+24h] [bp-24h] BYREF

  v20 = a2;
  v21 = a1;
  v19 = a3;
  v8 = 2 * (wcslen(a3) + 1);
  if ( ViVerifierDriverAddedThunkListHead )
  {
    if ( (MmVerifierData & 0x10) != 0 )
      v10 = 40;
    else
      v10 = 32;
    v9 = (_DWORD *)ExAllocatePoolWithTagPriority(1, v8 + a6 + 32, 538996553, v10);
  }
  else
  {
    v9 = (_DWORD *)ExAllocatePoolWithTag(1, v8 + a6 + 32, 538996553);
  }
  v11 = (unsigned int)v9;
  if ( !v9 )
    return -1073741670;
  v13 = a4[1];
  v14 = a4[2];
  v15 = a4[3];
  v9[1] = *a4;
  v9[2] = v13;
  v9[3] = v14;
  v9[4] = v15;
  v16 = a7;
  if ( (a7 & 1) != 0 )
    v16 = a7 | 6;
  v17 = (int)v19;
  v9[5] = v16;
  *v9 = 32;
  memmove((int)(v9 + 8), v17, v8);
  *(_DWORD *)(v11 + 24) = a6;
  *(_DWORD *)(v11 + 28) = v8 + 32;
  memmove(v8 + 32 + v11, a5, a6);
  v12 = IopIssueTrEERequest(2, v21, v20, v11, v8 + a6 + 32, (int)v22, 4, 4u, &v19);
  if ( v12 >= 0 && v22[0] )
    v12 = IopEfiStatusToNTSTATUS(v22[0]);
  ExFreePoolWithTag(v11);
  return v12;
}
