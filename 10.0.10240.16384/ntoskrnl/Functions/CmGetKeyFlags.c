// CmGetKeyFlags 
 
int __fastcall CmGetKeyFlags(int a1, int a2, int a3, int a4)
{
  int v6; // r4
  int v7; // r0
  int v8; // r5
  int v10[6]; // [sp+0h] [bp-18h] BYREF

  v10[1] = a4;
  v10[0] = 0;
  v6 = *(_DWORD *)(a1 + 104) & 0xF;
  if ( a2 )
  {
    while ( 1 )
    {
      v7 = CmListGetPrevElement(a1 + 108, v10);
      v8 = v7;
      if ( !v7 )
        break;
      if ( CmEqualTrans(*(_DWORD *)(v7 + 28), a2) && *(_DWORD *)(v8 + 36) == 7 )
        return *(_DWORD *)(v8 + 48);
    }
  }
  return v6;
}
