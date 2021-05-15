// NtQueryDirectoryFile 
 
int __fastcall NtQueryDirectoryFile(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, unsigned __int8 a9, int a10, unsigned __int8 a11)
{
  int result; // r0
  unsigned __int8 v12; // [sp+38h] [bp-18h]
  char v13; // [sp+39h] [bp-17h]
  int v14; // [sp+3Ch] [bp-14h]
  int v15; // [sp+40h] [bp-10h]
  int v16; // [sp+44h] [bp-Ch]

  result = ((int (__fastcall *)(int, int, int, int, int, int, int, int, _DWORD, int, _DWORD))BuildQueryDirectoryIrp)(
             a1,
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11);
  if ( !result )
    result = IopSynchronousServiceTail(v16, v15, v14, 1, v13, v12, 2);
  return result;
}
