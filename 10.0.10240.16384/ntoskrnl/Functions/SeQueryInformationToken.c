// SeQueryInformationToken 
 
// positive sp value has been detected, the output may be wrong!
int __fastcall SeQueryInformationToken(int a1, int a2, _DWORD *a3)
{
  int v6; // r4
  _BYTE v8[20]; // [sp-158h] [bp-1F0h] BYREF

  memset(v8, 0, sizeof(v8));
  if ( a2 == 24 )
  {
    *a3 = (*(_DWORD *)(a1 + 176) & 0x400) != 0;
    v6 = 0;
  }
  else
  {
    if ( (unsigned int)(a2 - 1) <= 0x29 )
      __asm { ADD             PC, R3 }
    v6 = -1073741821;
  }
  return v6;
}
