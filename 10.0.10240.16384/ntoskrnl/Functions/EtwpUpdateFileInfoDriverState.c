// EtwpUpdateFileInfoDriverState 
 
int __fastcall EtwpUpdateFileInfoDriverState(_DWORD *a1, int a2, int a3, int a4)
{
  _DWORD v5[6]; // [sp+0h] [bp-18h] BYREF

  v5[0] = a2;
  v5[1] = a3;
  v5[2] = a4;
  if ( !a3 )
  {
    if ( !a1 || (*a1 & 0x6000200) == 0 )
    {
      if ( dword_64A56C )
        WmiTraceRundownNotify(a4);
      EtwpUpdateFileInfoDriverRegistration(0);
      if ( dword_64A56C )
      {
        RtlInitUnicodeString((unsigned int)v5, L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\FileInfo");
        ZwUnloadDriver();
        dword_64A56C = 0;
      }
    }
    JUMPOUT(0x78A6DE);
  }
  return sub_7D088C();
}
