// BiGetPartitionVhdFilePath 
 
int __fastcall BiGetPartitionVhdFilePath(unsigned __int16 *a1, int a2, int a3, int a4)
{
  _DWORD v5[2]; // [sp+0h] [bp-8h] BYREF

  v5[0] = a3;
  v5[1] = a4;
  RtlInitUnicodeString((unsigned int)v5, a1);
  return BiGetPartitionVhdFilePathFromUnicodeString(v5);
}
