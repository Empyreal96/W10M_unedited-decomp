// CmpAssignSecurityDescriptorWrapper 
 
int __fastcall CmpAssignSecurityDescriptorWrapper(int a1, _WORD *a2, int a3, int a4)
{
  int v5; // r5
  int v8; // r6
  int v9; // r4
  int v11[8]; // [sp+8h] [bp-20h] BYREF

  v11[0] = a3;
  v11[1] = a4;
  v5 = *(_DWORD *)(a1 + 4);
  v11[0] = -1;
  v8 = (*(int (__fastcall **)(_DWORD, _DWORD, int *))(*(_DWORD *)(v5 + 20) + 4))(
         *(_DWORD *)(v5 + 20),
         *(_DWORD *)(v5 + 24),
         v11);
  if ( !v8 )
    return -1073741670;
  *(_DWORD *)(a1 - 4) = 0;
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A)
    || (*(_DWORD *)(*(_DWORD *)(v5 + 20) + 3228) & 0x20) == 0 )
  {
    v9 = CmpAssignSecurityDescriptor(*(_DWORD *)(v5 + 20), *(_DWORD *)(v5 + 24), v8, a2, 0);
    if ( v9 >= 0 )
      CmpAssignSecurityToKcb(v5, *(_DWORD *)(v8 + 44), a3, 1);
    (*(void (__fastcall **)(_DWORD, int *))(*(_DWORD *)(v5 + 20) + 8))(*(_DWORD *)(v5 + 20), v11);
    return v9;
  }
  return sub_805968();
}
