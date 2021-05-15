// IopCreateVpb 
 
int __fastcall IopCreateVpb(int a1)
{
  _BYTE *v2; // r0
  _BYTE *v3; // r4

  v2 = (_BYTE *)ExAllocatePoolWithTag(512, 88, 543322198);
  v3 = v2;
  if ( !v2 )
    return -1073741670;
  memset(v2, 0, 88);
  *(_WORD *)v3 = 10;
  *((_WORD *)v3 + 1) = 88;
  *((_DWORD *)v3 + 3) = a1;
  *(_DWORD *)(a1 + 36) = v3;
  return 0;
}
