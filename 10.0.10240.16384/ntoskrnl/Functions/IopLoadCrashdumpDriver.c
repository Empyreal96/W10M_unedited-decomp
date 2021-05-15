// IopLoadCrashdumpDriver 
 
int IopLoadCrashdumpDriver()
{
  int result; // r0
  int v1; // r0
  int v2; // r1
  int (__fastcall *v3)(__int16 **); // r6
  int v4; // [sp+8h] [bp-38h]
  int v5; // [sp+Ch] [bp-34h]
  char v6[8]; // [sp+10h] [bp-30h] BYREF
  __int16 *v7; // [sp+18h] [bp-28h] BYREF
  int (*v9)(int, int); // [sp+20h] [bp-20h]
  int (*v10)(); // [sp+24h] [bp-1Ch]
  int v11; // [sp+28h] [bp-18h]
  int v12; // [sp+2Ch] [bp-14h]
  int v13; // [sp+30h] [bp-10h]

  if ( CrashdmpImageEntry )
    return 0;
  RtlInitUnicodeString((unsigned int)v6, L"\\SystemRoot\\System32\\Drivers\\crashdmp.sys");
  result = MmLoadSystemImage((int)v6, 0);
  if ( result >= 0 )
  {
    v1 = RtlImageNtHeader(v4);
    if ( !v1 )
      return -1073741823;
    v3 = (int (__fastcall *)(__int16 **))(*(_DWORD *)(v1 + 40) + v4);
    v7 = &IoArcBootDeviceName;
    if ( !IopGetPhysicalMemoryBlock(v1, v2) )
      return -1073741670;
    v9 = MmLoadSystemImage;
    v10 = MmUnloadSystemImage;
    v12 = IopReportBugCheckProgress;
    v11 = 0;
    v13 = 0;
    CrashdmpCallTable = 1;
    dword_637648 = 7;
    result = v3(&v7);
    if ( result >= 0 )
    {
      CrashdmpImageEntry = v5;
      CrashdmpImageBase = v4;
      return 0;
    }
  }
  return result;
}
