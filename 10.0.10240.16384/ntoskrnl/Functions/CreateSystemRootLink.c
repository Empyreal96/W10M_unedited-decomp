// CreateSystemRootLink 
 
int __fastcall CreateSystemRootLink(int a1)
{
  int v2; // r0
  int v3; // r0
  int v4; // r0
  int v5; // r0
  int v6; // r0
  int v8; // [sp+8h] [bp-248h] BYREF
  int v9; // [sp+Ch] [bp-244h]
  char *v10; // [sp+10h] [bp-240h]
  int v11; // [sp+14h] [bp-23Ch]
  int v12; // [sp+18h] [bp-238h]
  int v13; // [sp+1Ch] [bp-234h]
  int v14; // [sp+20h] [bp-230h] BYREF
  int v15[2]; // [sp+28h] [bp-228h] BYREF
  char v16[8]; // [sp+30h] [bp-220h] BYREF
  char v17[8]; // [sp+38h] [bp-218h] BYREF
  unsigned __int16 v18[264]; // [sp+40h] [bp-210h] BYREF

  RtlInitUnicodeString((unsigned int)v16, L"\\ArcName");
  v8 = 24;
  v9 = 0;
  v11 = 80;
  v10 = v16;
  v12 = SePublicDefaultUnrestrictedSd;
  v13 = 0;
  if ( NtCreateDirectoryObject() < 0 )
    sub_96F29C();
  NtClose();
  RtlInitUnicodeString((unsigned int)v16, L"\\Device");
  v8 = 24;
  v9 = 0;
  v11 = 80;
  v10 = v16;
  v12 = SePublicDefaultUnrestrictedSd;
  v13 = 0;
  v2 = NtCreateDirectoryObject();
  if ( v2 < 0 )
    KeBugCheckEx(100, v2, 2, 0, 0);
  NtClose();
  RtlInitUnicodeString((unsigned int)v17, L"\\Device\\BootDevice");
  v8 = 24;
  v9 = 0;
  v11 = 80;
  v10 = v17;
  v12 = SePublicDefaultUnrestrictedSd;
  v13 = 0;
  v3 = RtlStringCbPrintfW(v18, 0x200u, (int)L"\\ArcName\\%S", *(_DWORD *)(a1 + 104));
  if ( v3 < 0 )
    KeBugCheckEx(100, v3, 3, 0, 0);
  RtlInitUnicodeString((unsigned int)v15, v18);
  v4 = NtCreateSymbolicLinkObject((unsigned int)&v14, 983041, (int)&v8, v15);
  if ( v4 < 0 )
    KeBugCheckEx(100, v4, 4, 0, 0);
  NtClose();
  RtlInitUnicodeString((unsigned int)v17, L"\\SystemRoot");
  v10 = v17;
  v8 = 24;
  v9 = 0;
  v12 = SePublicDefaultUnrestrictedSd;
  v11 = 80;
  v13 = 0;
  v5 = RtlStringCbPrintfW(v18, 0x200u, (int)L"%s%S", (int)L"\\Device\\BootDevice");
  if ( v5 < 0 )
    KeBugCheckEx(100, v5, 5, 0, 0);
  RtlInitUnicodeString((unsigned int)v15, v18);
  LOWORD(v15[0]) -= 2;
  v6 = NtCreateSymbolicLinkObject((unsigned int)&v14, 983041, (int)&v8, v15);
  if ( v6 < 0 )
    KeBugCheckEx(100, v6, 6, 0, 0);
  NtClose();
  return 0;
}
