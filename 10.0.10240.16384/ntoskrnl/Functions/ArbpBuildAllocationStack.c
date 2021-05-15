// ArbpBuildAllocationStack 
 
int __fastcall ArbpBuildAllocationStack(int a1, _DWORD *a2, int a3)
{
  __int64 v4; // r4
  _DWORD *i; // r2
  int v7; // r3
  int v8; // r8
  _DWORD *v9; // r5
  _DWORD *v10; // r4
  _DWORD *v11; // r9
  unsigned int v12; // r8
  int result; // r0

  v4 = (unsigned int)(a3 + 1);
  for ( i = (_DWORD *)*a2; a2 != i; i = (_DWORD *)*i )
  {
    v7 = i[2];
    if ( v7 )
      HIDWORD(v4) += 56 * v7;
    else
      LODWORD(v4) = v4 - 1;
  }
  v8 = 7 * v4;
  LODWORD(v4) = HIDWORD(v4) + 56 * v4;
  if ( *(_DWORD *)(a1 + 52) < (unsigned int)v4 )
  {
    HIDWORD(v4) = ExAllocatePoolWithTag(1, v4, 1096970817);
    if ( !HIDWORD(v4) )
      return -1073741670;
    ExFreePoolWithTag(*(_DWORD *)(a1 + 56));
    *(_QWORD *)(a1 + 52) = v4;
  }
  memset(*(_BYTE **)(a1 + 56), 0, v4);
  v9 = *(_DWORD **)(a1 + 56);
  v10 = (_DWORD *)*a2;
  v11 = &v9[2 * v8];
  if ( a2 == (_DWORD *)*a2 )
  {
LABEL_14:
    v9[8] = 0;
    return 0;
  }
  while ( !v10[2] )
  {
LABEL_13:
    v10 = (_DWORD *)*v10;
    if ( a2 == v10 )
      goto LABEL_14;
  }
  v9[8] = v10;
  v9[10] = v10[2];
  v9[11] = v11;
  *v9 = 1;
  v9[1] = 0;
  v12 = v10[3];
  if ( v12 >= v12 + 32 * v10[2] )
  {
LABEL_12:
    v9 += 14;
    goto LABEL_13;
  }
  while ( 1 )
  {
    result = ArbpBuildAlternative(a1, v12, v11);
    if ( result < 0 )
      return result;
    v11[8] = 0;
    v12 += 32;
    v11 += 14;
    if ( v12 >= v10[3] + 32 * v10[2] )
      goto LABEL_12;
  }
}
