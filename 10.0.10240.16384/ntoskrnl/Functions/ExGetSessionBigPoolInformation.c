// ExGetSessionBigPoolInformation 
 
int __fastcall ExGetSessionBigPoolInformation(int a1, int a2, unsigned int *a3, int *a4)
{
  int v4; // r6
  unsigned int v5; // r7
  unsigned int *v6; // r8
  _DWORD *v7; // r9
  int result; // r0
  int v9; // r10
  int v10; // r5
  int v11; // r4
  _DWORD *v12; // r8
  int v13; // r0
  int v14; // r3
  int v15; // r2
  unsigned int v16; // r3
  unsigned int v17; // r1
  _DWORD *v18; // r0
  int v19; // r0
  int v20; // r2
  unsigned int *v21; // [sp+8h] [bp-50h]
  int v22; // [sp+Ch] [bp-4Ch] BYREF
  int v23; // [sp+10h] [bp-48h]
  int v24; // [sp+14h] [bp-44h] BYREF
  int *v25; // [sp+18h] [bp-40h]
  unsigned int v26; // [sp+1Ch] [bp-3Ch]
  char v27[56]; // [sp+20h] [bp-38h] BYREF

  v25 = a4;
  v26 = a2;
  *a3 = 0;
  v4 = 0;
  v21 = a3;
  v5 = 0;
  v23 = 1;
  v6 = a3;
  v7 = 0;
  if ( a2 )
  {
    result = ExLockUserBuffer(a1, a2, *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A), 1, &v24, &v22);
    if ( result < 0 )
      return result;
    v9 = v22;
    v10 = v24;
  }
  else
  {
    v10 = 0;
    v9 = 0;
  }
  v11 = MmGetNextSession();
  if ( !v11 )
    goto LABEL_30;
  while ( 1 )
  {
    v12 = (_DWORD *)(v10 + v5);
    v13 = MmGetSessionId(v11);
    v24 = v13;
    v14 = *v25;
    if ( *v25 == -1 || v13 == v14 )
      break;
LABEL_21:
    v11 = MmGetNextSession();
    if ( !v11 )
      goto LABEL_25;
  }
  if ( MmAttachSession(v11, (int)v27, v13, v14) < 0 )
  {
LABEL_20:
    if ( *v25 != -1 )
      goto LABEL_24;
    goto LABEL_21;
  }
  v16 = v5 + 24;
  if ( v5 >= 0xFFFFFFE8 )
  {
    v4 = -1073741675;
    MmDetachSession(v11, (int)v27, v15, v16);
    ObfDereferenceObject(v11);
    goto LABEL_29;
  }
  if ( v16 <= v26 && v23 )
  {
    v17 = v26 - v5;
    v18 = (_DWORD *)(v10 + v5);
  }
  else
  {
    v23 = 0;
    v4 = -1073741820;
    v17 = 0;
    v18 = 0;
  }
  v19 = ExGetBigPoolInfo(v18, v17, 0, (unsigned int *)&v22);
  if ( v19 >= 0 || (v4 = v19, v19 == -1073741820) )
  {
    if ( v23 == 1 && v19 >= 0 )
    {
      v7 = (_DWORD *)(v10 + v5);
      v12[1] = v24;
      *v12 = 12 * (v12[2] + 1);
    }
    v5 += v22;
    MmDetachSession(v11, (int)v27, v20, v22);
    goto LABEL_20;
  }
  MmDetachSession(v11, (int)v27, v20, -1073741820);
LABEL_24:
  ObfDereferenceObject(v11);
LABEL_25:
  if ( v4 < 0 )
  {
LABEL_29:
    v6 = v21;
    goto LABEL_30;
  }
  v6 = v21;
  if ( v7 )
    *v7 = 0;
LABEL_30:
  if ( v10 )
    ExUnlockUserBuffer(v9);
  *v6 = v5;
  return v4;
}
