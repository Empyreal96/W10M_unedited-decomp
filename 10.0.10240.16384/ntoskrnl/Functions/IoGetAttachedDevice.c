// IoGetAttachedDevice 
 
int __fastcall IoGetAttachedDevice(int result)
{
  int i; // r3

  for ( i = *(_DWORD *)(result + 16); i; i = *(_DWORD *)(i + 16) )
    result = i;
  return result;
}
