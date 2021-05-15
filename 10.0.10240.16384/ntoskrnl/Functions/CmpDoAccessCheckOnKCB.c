// CmpDoAccessCheckOnKCB 
 
void **__fastcall CmpDoAccessCheckOnKCB(int a1, int a2, int a3, char a4)
{
  void **v4; // r4
  int v9; // r5
  int v10; // r0
  int v12[2]; // [sp+18h] [bp-168h] BYREF
  char v13[28]; // [sp+20h] [bp-160h] BYREF
  char v14[92]; // [sp+3Ch] [bp-144h] BYREF
  char v15[232]; // [sp+98h] [bp-E8h] BYREF

  v4 = &CmKeyObjectType;
  if ( ObCreateObject(a4, CmKeyObjectType, 0, a4, 0, 44, 0, 0, v12) < 0 )
    return 0;
  v9 = v12[0];
  *(_DWORD *)(v12[0] + 28) = 0;
  *(_DWORD *)(v9 + 32) = 0;
  *(_DWORD *)v9 = 1803104306;
  *(_DWORD *)(v9 + 4) = 0;
  *(_WORD *)(v9 + 24) = 0;
  *(_WORD *)(v9 + 26) = 0;
  *(_DWORD *)(v9 + 36) = v9 + 36;
  *(_DWORD *)(v9 + 40) = v9 + 36;
  v10 = SeCreateAccessState((int)v13, (int)v15, a3, (_DWORD *)CmKeyObjectType + 13);
  if ( v10 < 0 )
    v4 = 0;
  v12[0] = v10;
  if ( v10 >= 0 )
  {
    *(_DWORD *)(v9 + 4) = a1;
    v4 = (void **)CmpCheckKeyBodyAccess(v9, a2, (int)v13, a4, v12);
    SepDeleteAccessState((int)v13);
    SeReleaseSubjectContext((int)v14);
    *(_DWORD *)(v9 + 4) = 0;
  }
  ObfDereferenceObject(v9);
  return v4;
}
