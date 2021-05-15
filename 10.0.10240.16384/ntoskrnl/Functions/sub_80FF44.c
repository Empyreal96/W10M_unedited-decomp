// sub_80FF44 
 
void __fastcall sub_80FF44(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, char a11, int a12, int a13, int a14, char *a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, unsigned __int16 a25)
{
  int v25; // r2
  int v26; // r3

  if ( CmpAccessBitForPhase == 2 )
  {
    RtlInitUnicodeString(
      (unsigned int)&a11,
      L"\\registry\\machine\\system\\CurrentControlSet\\Control\\Session Manager\\Configuration Manager\\Defrag");
    a13 = 24;
    a14 = 0;
    a16 = 704;
    a15 = &a11;
    a17 = 0;
    a18 = 0;
    if ( ZwCreateKey() >= 0 )
    {
      ExSystemTimeToLocalTime((__int64 *)&CmpReorganizeLastRun, &a19);
      RtlTimeToTimeFields((int)&a19, &a21, v25, v26);
      if ( swprintf_s((int)&a25, 16, (int)L"%02d:%02d:%04d", SHIWORD(a21)) != -1 )
      {
        RtlInitUnicodeString((unsigned int)&a11, L"LastRun");
        wcslen(&a25);
        if ( ZwSetValueKey() >= 0 )
        {
          RtlInitUnicodeString((unsigned int)&a11, L"TotalBytesSaved");
          ZwSetValueKey();
        }
      }
      ZwClose();
    }
  }
  JUMPOUT(0x79CC2E);
}
