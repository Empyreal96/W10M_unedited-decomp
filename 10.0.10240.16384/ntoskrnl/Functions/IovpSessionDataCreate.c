// IovpSessionDataCreate 
 
_BYTE *__fastcall IovpSessionDataCreate(int a1, int *a2, int a3)
{
  _BYTE *v4; // r4
  int v5; // r8
  int v6; // r2
  int v7; // r6
  int v8; // r7
  _BYTE *v9; // r0
  _BYTE *v10; // r2
  int v11; // r3
  __int64 v12; // r0

  if ( !a3 && !IovUtilIsVerifiedDeviceStack(a1) )
    return 0;
  v5 = *a2;
  v6 = *(char *)(*a2 + 34);
  v7 = 80 * v6;
  if ( v6 <= 20 && ViSessionDataInitialized )
  {
    v8 = 1;
    v9 = (_BYTE *)ExAllocateFromNPagedLookasideList((int)&ViSessionDataLookaside);
  }
  else
  {
    v8 = 0;
    v9 = (_BYTE *)ExAllocatePoolWithTag(512, v7 + 120, 1936749129);
  }
  v4 = v9;
  if ( !v9 )
    return 0;
  memset(v9, 0, v7 + 120);
  if ( v8 )
    *((_DWORD *)v4 + 4) |= 4u;
  HIDWORD(v12) = a2 + 11;
  v10 = v4 + 8;
  v11 = MmVerifierData;
  *(_DWORD *)v4 = a2;
  *((_DWORD *)v4 + 9) = v11;
  LODWORD(v12) = a2[11];
  *((_QWORD *)v4 + 1) = v12;
  if ( *(int **)(v12 + 4) != a2 + 11 )
    __fastfail(3u);
  *(_DWORD *)(v12 + 4) = v10;
  *(_DWORD *)HIDWORD(v12) = v10;
  a2[35] = (int)v4;
  *((_BYTE *)a2 + 108) = *(_BYTE *)(v5 + 35);
  a2[9] = a2[9] & 0xFFFFFE2F | 1;
  *((_DWORD *)v4 + 8) = v5;
  return v4;
}
