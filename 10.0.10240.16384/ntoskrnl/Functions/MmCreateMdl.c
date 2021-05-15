// MmCreateMdl 
 
int __fastcall MmCreateMdl(int result, unsigned int a2, unsigned int a3)
{
  unsigned __int64 v3; // r4
  int v4; // r2

  v3 = __PAIR64__(a3, a2);
  if ( !result )
  {
    result = ExAllocatePoolWithTag(512, 4 * ((((a2 & 0xFFF) + a3 + 4095) >> 12) + 7), 1818520909);
    if ( !result )
      return 0;
  }
  v4 = v3 & 0xFFF;
  LODWORD(v3) = v3 & 0xFFFFF000;
  *(_WORD *)(result + 4) = 4 * (((unsigned int)(v4 + HIDWORD(v3) + 4095) >> 12) + 7);
  *(_DWORD *)result = 0;
  *(_WORD *)(result + 6) = 0;
  *(_QWORD *)(result + 16) = v3;
  *(_DWORD *)(result + 24) = v4;
  return result;
}
