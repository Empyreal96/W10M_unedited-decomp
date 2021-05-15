// IopReassignSystemRoot 
 
int __fastcall IopReassignSystemRoot(int a1, unsigned __int16 *a2)
{
  int v3; // r0
  int v4; // r3
  int v5; // r4
  int v7[2]; // [sp+0h] [bp-250h] BYREF
  int v8; // [sp+8h] [bp-248h] BYREF
  int v9; // [sp+Ch] [bp-244h]
  int *v10; // [sp+10h] [bp-240h]
  int v11; // [sp+14h] [bp-23Ch]
  int v12; // [sp+18h] [bp-238h]
  int v13; // [sp+1Ch] [bp-234h]
  int v14[2]; // [sp+20h] [bp-230h] BYREF
  char v15[8]; // [sp+28h] [bp-228h] BYREF
  unsigned __int16 v16[272]; // [sp+30h] [bp-220h] BYREF

  v7[0] = 0;
  if ( RtlStringCchPrintfW(v16, 0x100u, (int)L"\\ArcName\\%S", *(_DWORD *)(a1 + 104)) >= 0 )
  {
    RtlInitUnicodeString((unsigned int)v14, v16);
    HIWORD(v14[0]) = 512;
    v8 = 24;
    v9 = 0;
    v10 = v14;
    v12 = 0;
    v13 = 0;
    v11 = 576;
    v3 = NtOpenSymbolicLinkObject((unsigned int)v7, 983041, (int)&v8, 0);
    if ( v3 == -1073741788 )
    {
LABEL_6:
      if ( RtlUnicodeStringToAnsiString(a2, (unsigned __int16 *)v14, 0, v4) >= 0 )
      {
        RtlInitUnicodeString((unsigned int)v15, L"\\Device\\BootDevice");
        v8 = 24;
        v9 = 0;
        v10 = (int *)v15;
        v11 = 576;
        v12 = 0;
        v13 = 0;
        if ( NtOpenSymbolicLinkObject((unsigned int)v7, 983041, (int)&v8, 0) >= 0 )
        {
          NtMakeTemporaryObject(v7[0]);
          ObCloseHandle(v7[0]);
          v8 = 24;
          v9 = 0;
          v11 = 592;
          v10 = (int *)v15;
          v12 = 0;
          v13 = 0;
          NtCreateSymbolicLinkObject((unsigned int)v7, 983041, (int)&v8, v14);
          ObCloseHandle(v7[0]);
          return 1;
        }
      }
    }
    else
    {
      while ( v3 >= 0 )
      {
        LOWORD(v14[0]) = 0;
        v5 = NtQuerySymbolicLinkObject(v7[0], (unsigned int)v14, 0, v4);
        ObCloseHandle(v7[0]);
        if ( v5 < 0 )
          break;
        v8 = 24;
        v9 = 0;
        v10 = v14;
        v11 = 576;
        v12 = 0;
        v13 = 0;
        v3 = NtOpenSymbolicLinkObject((unsigned int)v7, 983041, (int)&v8, 0);
        if ( v3 == -1073741788 )
          goto LABEL_6;
      }
    }
  }
  return 0;
}
