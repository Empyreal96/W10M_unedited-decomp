// SeLocateProcessImageName 
 
int __fastcall SeLocateProcessImageName(int a1)
{
  int result; // r0

  if ( *(_DWORD *)(a1 + 380) )
    result = PsGetAllocatedFullProcessImageName();
  else
    result = -1073741275;
  return result;
}
