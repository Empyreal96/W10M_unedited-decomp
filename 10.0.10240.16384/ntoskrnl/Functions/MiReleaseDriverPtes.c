// MiReleaseDriverPtes 
 
int __fastcall MiReleaseDriverPtes(int a1, unsigned int a2, int a3)
{
  int v3; // r4
  unsigned int v6; // r10
  int v7; // r7
  int *v8; // r8
  int *v9; // r3
  _DWORD *v10; // r4
  unsigned int v11; // r1
  unsigned int v12; // r9
  __int64 v14; // kr00_8
  int v15; // r5
  char *v16; // r6
  int v17; // r3
  int *v18; // [sp+8h] [bp-C0h]
  char v20[184]; // [sp+10h] [bp-B8h] BYREF

  v3 = a1;
  v6 = a3 + 15;
  v7 = __mrc(15, 0, 13, 0, 3);
  v8 = 0;
  MiLockDriverMappings(v7 & 0xFFFFFFC0);
  v9 = &MiState[v3];
  v10 = (_DWORD *)v9[305];
  v18 = v9;
  if ( !v10 )
    goto LABEL_18;
  do
  {
    v11 = v10[1];
    if ( a2 >= v11 && a2 < v11 + 4 * ((16 * v10[2]) & 0xFFFFF) )
      break;
    v8 = v10;
    v10 = (_DWORD *)*v10;
  }
  while ( v10 );
  if ( !v10 )
LABEL_18:
    KeBugCheckEx(26, 8450, a2 << 10, a3 << 12, 0);
  v12 = (int)(a2 - v10[1]) >> 2;
  if ( !RtlAreBitsSet(v10 + 2, v12 >> 4, v6 >> 4) )
    sub_7CEE78();
  RtlClearBits((_BYTE *)v10 + 8, v12 >> 4, v6 >> 4);
  if ( RtlNumberOfSetBits(v10 + 2) )
    return MiUnlockDriverMappings(v7 & 0xFFFFFFC0);
  v14 = *(_QWORD *)(v10 + 1);
  if ( a1 )
  {
    v15 = 11;
    v16 = 0;
  }
  else
  {
    v15 = 12;
    v16 = v20;
    MiInitializeTbFlushList((int)v20, 0, 33);
  }
  MiReturnSystemVa((_DWORD)v14 << 10, (HIDWORD(v14) << 16) + ((_DWORD)v14 << 10), v15, (unsigned int)v16);
  v17 = *v10;
  if ( v8 )
    *v8 = v17;
  else
    v18[305] = v17;
  MiUnlockDriverMappings(v7 & 0xFFFFFFC0);
  return ExFreePoolWithTag((unsigned int)v10);
}
