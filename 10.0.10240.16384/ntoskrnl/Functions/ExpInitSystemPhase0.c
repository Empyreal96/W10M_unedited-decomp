// ExpInitSystemPhase0 
 
int ExpInitSystemPhase0()
{
  char *v0; // r5
  int v1; // r4
  int v3; // r0

  ExpTimeout = -40000000;
  dword_61A0DC = -1;
  ExpSystemResourcesList = (int)&ExpSystemResourcesList;
  dword_61A0E4 = (int)&ExpSystemResourcesList;
  ExpEnvironmentLock = 1;
  dword_61A084 = 0;
  unk_61A088 = 0;
  byte_61A08C = 1;
  byte_61A08D = 0;
  byte_61A08E = 4;
  dword_61A090 = 0;
  dword_61A098 = (int)&dword_61A094;
  dword_61A094 = (int)&dword_61A094;
  ExNPagedLookasideListHead = (int)&ExNPagedLookasideListHead;
  dword_61A0A4 = (int)&ExNPagedLookasideListHead;
  ExNPagedLookasideLock = 0;
  ExPagedLookasideListHead = (int)&ExPagedLookasideListHead;
  dword_61A0AC = (int)&ExPagedLookasideListHead;
  ExPagedLookasideLock = 0;
  ExpFirmwareTableProviderListHead = (int)&ExpFirmwareTableProviderListHead;
  dword_61A1BC = (int)&ExpFirmwareTableProviderListHead;
  ExInitializeResourceLite((int)&ExpFirmwareTableResource);
  ExpConDrvLoadLock = 0;
  dword_922C40 = 0;
  dword_922C04 = 0;
  if ( CmSuiteBufferType == 7 )
  {
    v0 = (char *)&CmSuiteBuffer;
    if ( CmSuiteBuffer )
    {
      v1 = dword_6416B0;
      while ( 1 )
      {
        if ( !wcscmp(v0, (char *)L"Small Business") )
          return sub_96C518();
        if ( !wcscmp(v0, (char *)L"Small Business(Restricted)") )
        {
          v1 |= 0x20u;
          goto LABEL_22;
        }
        if ( !wcscmp(v0, (char *)L"Enterprise") )
          break;
        if ( !wcscmp(v0, (char *)L"CommunicationServer") )
        {
          v1 |= 8u;
          goto LABEL_22;
        }
        if ( !wcscmp(v0, (char *)L"BackOffice") )
        {
          v1 |= 4u;
          goto LABEL_22;
        }
        if ( !wcscmp(v0, (char *)L"Terminal Server") )
        {
          v1 |= 0x10u;
          goto LABEL_22;
        }
        if ( !wcscmp(v0, (char *)L"EmbeddedNT") )
        {
          v1 |= 0x40u;
          goto LABEL_22;
        }
        if ( !wcscmp(v0, (char *)L"DataCenter") )
        {
          v1 |= 0x80u;
          goto LABEL_22;
        }
        if ( !wcscmp(v0, (char *)L"Personal") )
        {
          v1 |= 0x200u;
          goto LABEL_22;
        }
        if ( !wcscmp(v0, (char *)L"Blade") )
        {
          v1 |= 0x400u;
          goto LABEL_22;
        }
        if ( !wcscmp(v0, (char *)L"Embedded(Restricted)") )
        {
          v1 |= 0x800u;
          goto LABEL_22;
        }
        if ( !wcscmp(v0, (char *)L"Security Appliance") )
        {
          v1 |= 0x1000u;
          goto LABEL_22;
        }
        if ( !wcscmp(v0, (char *)L"Storage Server") )
        {
          v1 |= 0x2000u;
          goto LABEL_22;
        }
        if ( !wcscmp(v0, (char *)L"Compute Server") )
        {
          v1 |= 0x4000u;
          goto LABEL_22;
        }
        if ( !wcscmp(v0, (char *)L"WH Server") )
        {
          v1 |= 0x8000u;
          goto LABEL_22;
        }
        if ( !wcscmp(v0, (char *)L"PhoneNT") )
        {
          v1 |= 0x10000u;
LABEL_22:
          dword_6416B0 = v1;
        }
        v0 += 2 * wcslen((unsigned __int16 *)v0) + 2;
        if ( !*(_WORD *)v0 )
          goto LABEL_24;
      }
      v1 |= 2u;
      goto LABEL_22;
    }
  }
LABEL_24:
  v3 = ExpUpdateProductSuiteType(0);
  ExpRngInitializeSystem(v3);
  RtlpHeapKey = ExGenRandom(1);
  return 1;
}
