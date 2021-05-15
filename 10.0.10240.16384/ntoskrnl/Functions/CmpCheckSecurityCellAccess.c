// CmpCheckSecurityCellAccess 
 
int __fastcall CmpCheckSecurityCellAccess(int a1, int a2, char a3, int a4)
{
  int (__fastcall *v5)(int, int, int *); // r4
  int v8; // r0
  int v9; // r4
  int v10; // r5
  int v11; // r0
  int v12; // r4
  int v14; // [sp+18h] [bp-38h] BYREF
  int v15; // [sp+1Ch] [bp-34h] BYREF
  int v16; // [sp+20h] [bp-30h] BYREF
  int v17; // [sp+24h] [bp-2Ch] BYREF
  char v18[40]; // [sp+28h] [bp-28h] BYREF

  v5 = *(int (__fastcall **)(int, int, int *))(a1 + 4);
  v17 = -1;
  v8 = v5(a1, a2, &v17);
  v9 = v8;
  if ( !v8 )
    return -1073741670;
  v10 = ExAllocatePoolWithTag(1, *(_DWORD *)(v8 + 16), 538987843);
  if ( v10 )
  {
    v14 = *(_DWORD *)(v9 + 16);
    v16 = 31;
    v15 = v9 + 20;
    v11 = SeQuerySecurityDescriptorInfo(&v16, v10, &v14, &v15);
    v12 = v11;
    if ( v11 == -1073741789 )
      return sub_7EA6AC();
    if ( v11 >= 0 )
    {
      SeCaptureSubjectContext(v18);
      if ( SeAccessCheck(v10, (int)v18, 0, a4, 0, 0, (int)CmKeyObjectType + 52, a3, (int)&v15, (int)&v16) != 1 )
        v12 = -1073741790;
      SeReleaseSubjectContext((int)v18);
    }
    ExFreePoolWithTag(v10);
  }
  else
  {
    v12 = -1073741670;
  }
  (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v17);
  return v12;
}
