// sub_554CA8 
 
void __fastcall sub_554CA8(_DWORD *a1, int a2, _DWORD *a3, _DWORD *a4, int a5, int a6)
{
  if ( a4 == a1 && (_DWORD *)*a3 == a1 )
  {
    *a3 = a2;
    *(_DWORD *)(a2 + 4) = a3;
    *a1 = a1;
    a1[1] = a1;
    KeSetEvent((int)&PopPowerSettingCallbackReturned, 0, 0);
    __asm { POP.W           {R11,PC} }
  }
  __fastfail(3u);
}
