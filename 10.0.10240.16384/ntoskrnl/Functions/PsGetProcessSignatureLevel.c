// PsGetProcessSignatureLevel 
 
int __fastcall PsGetProcessSignatureLevel(int a1, _BYTE *a2)
{
  if ( a2 )
    *a2 = *(_BYTE *)(a1 + 733);
  return *(unsigned __int8 *)(a1 + 732);
}
