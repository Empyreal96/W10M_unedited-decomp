// sub_8AA96C 
 
int __fastcall sub_8AA96C(int result)
{
  _WORD *v1; // r3

  v1 = *(_WORD **)(result + 8);
  if ( v1 )
  {
    *(_DWORD *)(result + 4) = 0;
    *(_WORD *)result = 0;
    *v1 = 0;
  }
  return result;
}
