// EtwpQueryProcessOtherInfo 
 
int __fastcall EtwpQueryProcessOtherInfo(int a1, _DWORD *a2)
{
  int result; // r0

  *a2 = 0;
  a2[1] = 0;
  result = PsGetProcessSectionBaseAddress(a1);
  if ( result )
  {
    result = RtlImageNtHeader(result);
    if ( result )
    {
      *a2 = *(_DWORD *)(result + 88);
      a2[1] = *(_DWORD *)(result + 8);
    }
  }
  return result;
}
