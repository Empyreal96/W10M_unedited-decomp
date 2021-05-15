// SepGetLowBoxHandlesEntry 
 
int __fastcall SepGetLowBoxHandlesEntry(int a1, int a2, _DWORD *a3, int a4)
{
  _DWORD *v4; // r8
  int v7; // r0
  int result; // r0
  int v9; // r7
  int v10; // r0
  _DWORD *v11; // r4
  int v12; // r0
  int v13[6]; // [sp+0h] [bp-18h] BYREF

  v13[0] = a4;
  v4 = *(_DWORD **)(a1 + 4);
  v7 = SepFindMatchingLowBoxHandlesEntry(v4, (unsigned __int16 *)a2, v13, a4);
  if ( v13[0] )
    return sub_7D651C(v7);
  v9 = (4 * *(unsigned __int8 *)(a2 + 1) + 39) & 0xFFFFFFFC;
  v10 = ExAllocatePoolWithTag(1, v9, 1934386515);
  v11 = (_DWORD *)v10;
  if ( !v10 )
    return -1073741670;
  *(_DWORD *)(v10 + 16) = v10 + 28;
  RtlCopySid(v9 - 28, v10 + 28, a2);
  v11[3] = 1;
  v11[5] = 0;
  v11[6] = 0;
  v12 = SepComputeSidSignature(a2);
  if ( !RtlInsertEntryHashTable((int)v4, (int)v11, v12, 0) )
  {
    ExFreePoolWithTag((unsigned int)v11);
    return -1073741670;
  }
  result = 0;
  *a3 = v11;
  return result;
}
