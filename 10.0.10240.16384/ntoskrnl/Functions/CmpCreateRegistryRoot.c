// CmpCreateRegistryRoot 
 
int __fastcall CmpCreateRegistryRoot(int a1, int a2)
{
  _BYTE *v2; // r0
  unsigned int v3; // r5
  int v4; // r4
  _DWORD *v5; // r0
  _DWORD *v6; // r5
  int v7; // r4
  int v8; // r0
  int result; // r0
  int v10; // [sp+18h] [bp-38h] BYREF
  unsigned int v11; // [sp+1Ch] [bp-34h] BYREF
  int v12[2]; // [sp+20h] [bp-30h] BYREF
  int v13[10]; // [sp+28h] [bp-28h] BYREF

  if ( !CmpCreateRootNode(CmpMasterHive, a2, &v11) )
    goto LABEL_8;
  v2 = CmpHiveRootSecurityDescriptor();
  v13[0] = 24;
  v13[1] = 0;
  v13[2] = (int)CmRegistryRootName;
  v13[3] = 64;
  v13[5] = 0;
  v3 = (unsigned int)v2;
  v13[4] = (int)v2;
  v4 = ObCreateObject(0, CmKeyObjectType, (int)v13, 1, 0, 44, 0, 0, v12);
  ExFreePoolWithTag(v3);
  if ( v4 < 0 )
    goto LABEL_8;
  v5 = (_DWORD *)CmpCreateKeyControlBlock(__SPAIR64__(v11, (unsigned int)CmpMasterHive), 0, 0, CmRegistryRootName);
  v6 = v5;
  if ( !v5 )
    goto LABEL_8;
  CmpUnlockKcb(v5);
  v7 = v12[0];
  *(_DWORD *)v12[0] = 1803104306;
  *(_DWORD *)(v7 + 4) = v6;
  *(_DWORD *)(v7 + 8) = 0;
  *(_DWORD *)(v7 + 12) = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x36C);
  *(_WORD *)(v7 + 24) = 0;
  *(_WORD *)(v7 + 26) = 0;
  *(_DWORD *)(v7 + 36) = v7 + 36;
  *(_DWORD *)(v7 + 40) = v7 + 36;
  EnlistKeyBodyWithKCB((_DWORD *)v7, 0);
  *(_DWORD *)(v7 + 28) = 0;
  *(_DWORD *)(v7 + 32) = 0;
  if ( ObInsertObject(v7, 0, 0, 0, 0, (int)&v10) < 0 )
LABEL_8:
    JUMPOUT(0x966C38);
  v8 = ObReferenceObjectByHandle(v10, 131097, 0, 0, (int)v12, 0);
  CmpRegistryRootObject = v12[0];
  if ( v8 >= 0 )
    result = 1;
  else
    result = sub_966C30();
  return result;
}
