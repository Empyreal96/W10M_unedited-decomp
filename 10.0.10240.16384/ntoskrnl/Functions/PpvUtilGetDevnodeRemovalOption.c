// PpvUtilGetDevnodeRemovalOption 
 
int __fastcall PpvUtilGetDevnodeRemovalOption(int a1)
{
  int v1; // r3
  int v2; // r3
  int result; // r0

  v1 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
  if ( !v1 )
    goto LABEL_6;
  v2 = *(_DWORD *)(v1 + 268);
  if ( (v2 & 0x10) != 0 )
    return 1;
  if ( (v2 & 0x10000) != 0 )
    result = 0;
  else
LABEL_6:
    result = 2;
  return result;
}
