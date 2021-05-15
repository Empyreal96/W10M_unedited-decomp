// SepValidLabelSubjectContext 
 
int __fastcall SepValidLabelSubjectContext(int **a1, unsigned __int16 *a2, unsigned __int16 *a3, unsigned __int16 *a4)
{
  unsigned __int16 *v4; // r6
  char v5; // r7
  int result; // r0
  int *v7; // r4
  unsigned int v8; // r2
  int v9; // r0
  unsigned int v10; // r1
  __int16 v11; // r3
  int v12; // r3
  _DWORD v13[2]; // [sp+0h] [bp-20h] BYREF
  unsigned __int16 *v14[6]; // [sp+8h] [bp-18h] BYREF

  v13[0] = a1;
  v13[1] = a2;
  v14[0] = a3;
  v14[1] = a4;
  v4 = a2;
  v5 = (char)a3;
  if ( !a2 )
    return sub_7F4D20();
  v7 = *a1;
  if ( !*a1 )
    v7 = a1[2];
  if ( v7[42] == 2 && v7[43] < 2 )
    return 0;
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v8 + 308);
  ExAcquireResourceSharedLite(v7[12], 1);
  SepCopyTokenIntegrity((int)v7, v14);
  v9 = ExReleaseResourceLite(v7[12]);
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = *(_WORD *)(v10 + 0x134) + 1;
  *(_WORD *)(v10 + 308) = v11;
  if ( !v11 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
    KiCheckForKernelApcDelivery(v9);
  if ( (v5 & 8) != 0 )
  {
    if ( RtlSidDominates(v4, *(unsigned __int16 **)(SeExports + 380), v13) < 0 )
      return 0;
    if ( !LOBYTE(v13[0]) )
      v4 = *(unsigned __int16 **)(SeExports + 380);
  }
  if ( RtlSidDominates(v14[0], v4, v13) < 0 )
    return 0;
  result = LOBYTE(v13[0]);
  if ( !LOBYTE(v13[0]) )
    result = SeSinglePrivilegeCheck(SeRelabelPrivilege, SHIDWORD(SeRelabelPrivilege), 1, v12);
  return result;
}
