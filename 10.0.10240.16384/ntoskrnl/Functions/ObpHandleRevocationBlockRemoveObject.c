// ObpHandleRevocationBlockRemoveObject 
 
int __fastcall ObpHandleRevocationBlockRemoveObject(int result)
{
  if ( *(_DWORD *)(result + 8) > 2u )
    result = sub_80125C();
  return result;
}
