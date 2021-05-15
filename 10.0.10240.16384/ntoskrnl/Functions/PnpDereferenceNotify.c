// PnpDereferenceNotify 
 
int __fastcall PnpDereferenceNotify(int result)
{
  __int16 v1; // r2

  v1 = *(_WORD *)(result + 32);
  *(_WORD *)(result + 32) = v1 - 1;
  if ( v1 == 1 )
    result = sub_7EE9B4();
  return result;
}
