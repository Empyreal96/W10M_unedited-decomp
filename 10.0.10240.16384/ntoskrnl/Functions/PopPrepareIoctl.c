// PopPrepareIoctl 
 
int __fastcall PopPrepareIoctl(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int result; // r0
  int v11; // r2
  char v12; // r3

  result = IoReuseIrp(a1, -1073741637);
  v11 = *(_DWORD *)(a1 + 96);
  if ( a3 )
    v12 = 15;
  else
    v12 = 14;
  *(_BYTE *)(v11 - 40) = v12;
  *(_DWORD *)(v11 - 28) = a5;
  *(_DWORD *)(v11 - 24) = a2;
  *(_DWORD *)(v11 - 32) = a6;
  *(_DWORD *)(a1 + 12) = a4;
  return result;
}
