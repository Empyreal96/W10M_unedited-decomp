// IopCreateRootDirectories 
 
int IopCreateRootDirectories()
{
  int v1; // [sp+0h] [bp-30h]
  char v2[8]; // [sp+8h] [bp-28h] BYREF
  int v3; // [sp+10h] [bp-20h]
  int v4; // [sp+14h] [bp-1Ch]
  char *v5; // [sp+18h] [bp-18h]
  int v6; // [sp+1Ch] [bp-14h]
  int v7; // [sp+20h] [bp-10h]
  int v8; // [sp+24h] [bp-Ch]

  RtlInitUnicodeString((unsigned int)v2, L"\\Driver");
  v3 = 24;
  v4 = 0;
  v6 = 528;
  v5 = v2;
  v7 = 0;
  v8 = 0;
  if ( NtCreateDirectoryObject() < 0 )
    return 0;
  ObCloseHandle(v1);
  RtlInitUnicodeString((unsigned int)v2, L"\\FileSystem");
  if ( NtCreateDirectoryObject() < 0 )
    return 0;
  ObCloseHandle(v1);
  RtlInitUnicodeString((unsigned int)v2, L"\\FileSystem\\Filters");
  if ( NtCreateDirectoryObject() < 0 )
    return 0;
  ObCloseHandle(v1);
  return 1;
}
