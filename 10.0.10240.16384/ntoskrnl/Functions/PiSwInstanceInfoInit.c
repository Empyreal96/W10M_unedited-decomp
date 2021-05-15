// PiSwInstanceInfoInit 
 
int __fastcall PiSwInstanceInfoInit(int a1, int a2)
{
  int v4; // r4

  v4 = PnpConcatPWSTR(0xC8u, 1466986064, (unsigned int *)a1, 2u, (int)L"SWD\\", *(_DWORD *)a2);
  if ( v4 < 0 || (v4 = PnpAllocatePWSTR(*(unsigned __int16 **)(a2 + 8), 0xC8u, 1466986064, (int *)(a1 + 4)), v4 < 0) )
    PiSwInstanceInfoFree(a1);
  return v4;
}
