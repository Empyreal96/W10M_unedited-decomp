// WmipGetSMBiosFromLoaderBlock 
 
int __fastcall WmipGetSMBiosFromLoaderBlock(int result)
{
  _DWORD *v1; // r1
  int v2; // r1

  v1 = *(_DWORD **)(result + 132);
  if ( *v1 >= 0x908u )
  {
    v2 = v1[9];
    if ( v2 )
    {
      LOBYTE(WmipSMBiosVersionInfo) = 0;
      WmipSMBiosTablePhysicalAddress = *(_QWORD *)(v2 + 16);
      WmipSMBiosTableLength = *(_DWORD *)(v2 + 12);
      *(_WORD *)((char *)&WmipSMBiosVersionInfo + 1) = *(_WORD *)(v2 + 7);
      HIBYTE(WmipSMBiosVersionInfo) = 0;
    }
  }
  return result;
}
