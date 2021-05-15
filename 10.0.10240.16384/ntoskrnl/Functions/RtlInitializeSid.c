// RtlInitializeSid 
 
int __fastcall RtlInitializeSid(int a1, int a2, unsigned int a3)
{
  if ( a3 > 0xF )
    return -1073741811;
  *(_BYTE *)a1 = 1;
  *(_BYTE *)(a1 + 1) = a3;
  *(_DWORD *)(a1 + 2) = *(_DWORD *)a2;
  *(_WORD *)(a1 + 6) = *(_WORD *)(a2 + 4);
  return 0;
}
