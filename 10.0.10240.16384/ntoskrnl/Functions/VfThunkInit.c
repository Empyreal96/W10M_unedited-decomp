// VfThunkInit 
 
int VfThunkInit()
{
  __int64 v0; // r3

  HIDWORD(v0) = &VfPoolThunksBitMap;
  VfRegularThunksBitMapHeader = 224;
  dword_90A0D4 = (int)&VfRegularThunksBitMap;
  RtlSetAllBits(&VfRegularThunksBitMapHeader);
  LODWORD(v0) = 32;
  *(_QWORD *)(HIDWORD(v0) + 108) = v0;
  RtlSetAllBits(VfPoolThunksBitMapHeader);
  VfOrderDependentThunksBitMapHeader = 64;
  dword_90A0A4 = (int)&VfOrderDependentThunksBitMap;
  RtlSetAllBits(&VfOrderDependentThunksBitMapHeader);
  VfXdvThunksBitMapHeader = 320;
  dword_90A074 = (int)&VfXdvThunksBitMap;
  return RtlSetAllBits(&VfXdvThunksBitMapHeader);
}
