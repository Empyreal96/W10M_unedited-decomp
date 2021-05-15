// IopAssignBootDriveLetter 
 
int IopAssignBootDriveLetter()
{
  int v1; // [sp+18h] [bp-30h] BYREF
  int v2; // [sp+1Ch] [bp-2Ch] BYREF
  char v3[20]; // [sp+20h] [bp-28h] BYREF
  int v4; // [sp+34h] [bp-14h]
  int v5[4]; // [sp+38h] [bp-10h] BYREF

  RtlInitUnicodeString((unsigned int)v3, L"\\Device\\MountPointManager");
  if ( IoGetDeviceObjectPointer((int)v3, 128, &v2, &v1) < 0 )
    JUMPOUT(0x96920A);
  v3[16] = 0;
  v3[17] = 0;
  v3[18] = 4;
  v4 = 0;
  v5[1] = (int)v5;
  v5[0] = (int)v5;
  if ( IoBuildDeviceIoControlRequest((int)&off_6DC044, v1, 0, 0, 0, 0) )
    JUMPOUT(0x9691E0);
  return sub_9691DC();
}
