// HvApplyLogFile 
 
int __fastcall HvApplyLogFile(int a1, int a2, int a3, int a4, unsigned int *a5, int a6, _DWORD *a7, _DWORD *a8)
{
  unsigned int *v9; // r10
  int v10; // r8
  int v11; // r9
  unsigned int v12; // r6
  int v13; // r4
  int v14; // r7
  unsigned int v15; // r10
  __int64 *v16; // r8
  int v17; // r0
  int v19; // [sp+8h] [bp-78h]
  int v20; // [sp+Ch] [bp-74h]
  int v21; // [sp+1Ch] [bp-64h]
  unsigned int v22; // [sp+24h] [bp-5Ch] BYREF
  int v23; // [sp+28h] [bp-58h] BYREF
  unsigned int v24; // [sp+30h] [bp-50h] BYREF
  int v25; // [sp+34h] [bp-4Ch]
  int v26; // [sp+3Ch] [bp-44h]
  unsigned int v27; // [sp+44h] [bp-3Ch]
  char v28[16]; // [sp+48h] [bp-38h] BYREF
  _DWORD v29[10]; // [sp+58h] [bp-28h] BYREF

  v19 = a1;
  v9 = a5;
  v10 = a1;
  v11 = 0;
  v12 = 512;
  v20 = 0;
  while ( 1 )
  {
    v13 = HvpRecoverDataReadRoutine(v10, v9, v12, 40, (unsigned int *)&v23);
    if ( v13 < 0 )
      break;
    memmove((int)&v24, v23, 0x28u);
    if ( !HvpIsLogEntryHeaderCoherent(&v24, v12) || v26 != a2 )
      goto LABEL_17;
    v14 = v25;
    v13 = HvpRecoverDataReadRoutine(v10, v9, v12, v25, &v22);
    if ( v13 < 0 )
      break;
    v15 = v27;
    v16 = (__int64 *)(v22 + 40);
    v17 = HvpIsMetadataArrayCoherent(&v24, (unsigned int *)(v22 + 40), v27);
    if ( !v17 )
      goto LABEL_17;
    SymCryptMarvin32(v17, v16, v14 - 40, v29);
    if ( memcmp((unsigned int)v28, (unsigned int)v29, 8) )
      goto LABEL_17;
    v13 = HvpApplyLogEntry(v19, &v24, v16, &v16[v15]);
    if ( v13 < 0 )
      break;
    v20 = 1;
    ++v11;
    CmpTraceHiveMountLogEntryApplied(v14, v21);
    if ( a6 )
      HvpUpdateRecoveryVector(v16, v15, a6);
    v10 = v19;
    v9 = a5;
    ++a2;
    v12 += v14;
    if ( !v12 )
    {
      v13 = -2147483622;
      break;
    }
  }
  if ( v13 == -1073741801 || v13 == -1073741670 || v13 == -1073741492 )
    return v13;
LABEL_17:
  if ( v20 )
    v13 = 1073741833;
  else
    v13 = 0;
  *a7 = a2;
  *a8 = v11;
  return v13;
}
