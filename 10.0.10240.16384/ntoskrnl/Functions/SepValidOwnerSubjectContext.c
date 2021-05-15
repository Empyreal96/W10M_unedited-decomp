// SepValidOwnerSubjectContext 
 
int __fastcall SepValidOwnerSubjectContext(int **a1, unsigned __int16 *a2, int a3)
{
  int *v4; // r4
  int v6; // r5
  unsigned int v7; // r2
  unsigned int v8; // r8
  unsigned __int16 **v9; // r6
  unsigned __int16 *v10; // t1
  bool v11; // zf
  int v12; // r0
  int v13; // r0
  unsigned int v14; // r1
  __int16 v15; // r3
  int v16; // r0
  unsigned int v17; // r1
  __int16 v18; // r3

  if ( !a2 )
    return 0;
  if ( a3 || (v4 = *a1) == 0 )
    v4 = a1[2];
  if ( v4[42] == 2 )
    return sub_7E829C();
  v6 = 0;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 308);
  ExAcquireResourceSharedLite(v4[12], 1);
  v8 = v4[31];
  if ( v8 )
  {
    v9 = (unsigned __int16 **)v4[37];
    while ( 1 )
    {
      v10 = *v9;
      v9 += 2;
      if ( RtlEqualSid(a2, v10) )
        break;
      if ( ++v6 >= v8 )
        goto LABEL_15;
    }
    v11 = SepIdAssignableAsOwner(v4, v6) == 0;
    v12 = v4[12];
    if ( !v11 )
    {
      v13 = ExReleaseResourceLite(v12);
      v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v15 = *(_WORD *)(v14 + 0x134) + 1;
      *(_WORD *)(v14 + 308) = v15;
      if ( !v15 && *(_DWORD *)(v14 + 100) != v14 + 100 && !*(_WORD *)(v14 + 310) )
        KiCheckForKernelApcDelivery(v13);
      return 1;
    }
  }
  else
  {
LABEL_15:
    v12 = v4[12];
  }
  v16 = ExReleaseResourceLite(v12);
  v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v18 = *(_WORD *)(v17 + 0x134) + 1;
  *(_WORD *)(v17 + 308) = v18;
  if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 && !*(_WORD *)(v17 + 310) )
    KiCheckForKernelApcDelivery(v16);
  return SeSinglePrivilegeCheck(SeRestorePrivilege, dword_922B9C, 1, (int)&SeRestorePrivilege);
}
