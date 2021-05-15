// PiCMDispatch 
 
int __fastcall PiCMDispatch(int a1, int a2)
{
  int v2; // r4
  int v3; // r3

  v2 = *(_DWORD *)(a2 + 24);
  if ( v2 >= 0 )
  {
    v3 = **(unsigned __int8 **)(a2 + 96);
    if ( !**(_BYTE **)(a2 + 96) || v3 == 2 )
      goto LABEL_6;
    if ( v3 == 14 )
    {
      v2 = -1073741637;
      goto LABEL_7;
    }
    if ( v3 == 18 )
LABEL_6:
      v2 = 0;
  }
LABEL_7:
  *(_DWORD *)(a2 + 24) = v2;
  IofCompleteRequest(a2, 0);
  return v2;
}
