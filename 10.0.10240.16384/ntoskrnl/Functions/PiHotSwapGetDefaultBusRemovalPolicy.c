// PiHotSwapGetDefaultBusRemovalPolicy 
 
int __fastcall PiHotSwapGetDefaultBusRemovalPolicy(int result, int *a2)
{
  int v2; // r4
  int v4; // r3

  v2 = result;
  if ( (*(unsigned __int16 *)(result + 20) <= 8u || (result = wcsnicmp(*(_DWORD *)(result + 24), L"USB\\", 4)) != 0)
    && (*(unsigned __int16 *)(v2 + 20) <= 0xAu || (result = wcsnicmp(*(_DWORD *)(v2 + 24), L"1394\\", 5)) != 0)
    && (*(unsigned __int16 *)(v2 + 20) <= 0xAu || (result = wcsnicmp(*(_DWORD *)(v2 + 24), L"SBP2\\", 5)) != 0)
    && (*(unsigned __int16 *)(v2 + 20) <= 0xEu || (result = wcsnicmp(*(_DWORD *)(v2 + 24), L"PCMCIA\\", 7)) != 0) )
  {
    if ( *(unsigned __int16 *)(v2 + 20) > 8u )
    {
      result = wcsnicmp(*(_DWORD *)(v2 + 24), L"PCI\\", 4);
      if ( !result )
        return sub_81A760();
    }
    v4 = 4;
  }
  else
  {
    v4 = 5;
  }
  *a2 = v4;
  return result;
}
