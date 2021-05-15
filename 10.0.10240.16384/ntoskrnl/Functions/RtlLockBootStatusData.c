// RtlLockBootStatusData 
 
int __fastcall RtlLockBootStatusData(_DWORD *a1)
{
  int result; // r0
  int v3; // [sp+8h] [bp-240h]
  char v4[8]; // [sp+28h] [bp-220h] BYREF
  unsigned __int16 v5[264]; // [sp+38h] [bp-210h] BYREF

  wcscpy_s((char *)v5, 257, (char *)L"\\SystemRoot\\bootstat.dat");
  RtlInitUnicodeString((unsigned int)v4, v5);
  result = ZwOpenFile();
  if ( result < 0 )
    *a1 = 0;
  else
    *a1 = v3;
  return result;
}
