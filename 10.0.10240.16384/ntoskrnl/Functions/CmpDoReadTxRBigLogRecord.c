// CmpDoReadTxRBigLogRecord 
 
int __fastcall CmpDoReadTxRBigLogRecord(int a1, int a2, unsigned int *a3)
{
  int v3; // r8
  int v6; // r4
  int v7; // r7
  int v8; // r6
  char v10[4]; // [sp+10h] [bp-48h] BYREF
  _DWORD *v11; // [sp+14h] [bp-44h] BYREF
  char v12[8]; // [sp+18h] [bp-40h] BYREF
  char v13[8]; // [sp+20h] [bp-38h] BYREF
  char v14[8]; // [sp+28h] [bp-30h] BYREF
  char v15[40]; // [sp+30h] [bp-28h] BYREF

  v3 = *(_DWORD *)(a2 + 40);
  v10[0] = 0;
  v11 = (_DWORD *)a2;
  v6 = 0;
  v7 = ExAllocatePoolWithTag(1, *(_DWORD *)(a2 + 4), 538987843);
  *a3 = v7;
  if ( !v7 )
    return -1073741670;
  v8 = 0;
  while ( (int)v11[3] < 0 && v11[11] == v8 )
  {
    memmove(v7, (int)(v11 + 13), v11[12]);
    ++v8;
    v7 += v11[12];
    if ( !--v3 )
      goto LABEL_10;
    v10[0] = 1;
    v6 = ((int (__fastcall *)(int, _DWORD **, char *, char *, _DWORD, char *, char *, char *))ClfsReadNextLogRecord)(
           a1,
           &v11,
           v12,
           v10,
           0,
           v15,
           v14,
           v13);
    if ( v6 < 0 )
      goto LABEL_11;
  }
  v6 = -1073741762;
LABEL_10:
  if ( v6 >= 0 )
    return v6;
LABEL_11:
  ExFreePoolWithTag(*a3);
  *a3 = 0;
  return v6;
}
