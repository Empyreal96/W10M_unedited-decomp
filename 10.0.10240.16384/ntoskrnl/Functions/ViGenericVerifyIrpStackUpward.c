// ViGenericVerifyIrpStackUpward 
 
int __fastcall ViGenericVerifyIrpStackUpward(_DWORD *a1, int a2, _DWORD *a3, int a4)
{
  int v4; // r7
  int v5; // r6
  int v7; // r9
  int v9; // r2
  int v10; // r0
  int result; // r0

  v4 = *(_DWORD *)(a4 + 24);
  v5 = *a1;
  v7 = *(_DWORD *)(*a1 + 24);
  if ( (a1[9] & 0x20) != 0 )
  {
    v9 = a3[1];
    if ( (v9 & 0x1000000) == 0 )
    {
      if ( v7 != a3[16] )
      {
        a3[1] = v9 | 0x1000000;
        if ( *(unsigned __int8 *)(a2 + 1) == 255 )
          v10 = 571;
        else
          v10 = 531;
        VfErrorReport1(v10, v4, v5);
      }
      if ( *(_DWORD *)(v5 + 28) != a3[17] )
      {
        a3[1] |= 0x1000000u;
        VfErrorReport1(532, v4, v5);
      }
    }
  }
  result = VfMajorIsValidIrpStatus(a2, v7);
  if ( !result )
    result = VfErrorReport6(768, v4, v5, v7);
  return result;
}
