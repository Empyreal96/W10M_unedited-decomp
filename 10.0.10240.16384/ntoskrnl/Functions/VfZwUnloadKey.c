// VfZwUnloadKey 
 
int __fastcall VfZwUnloadKey(int a1, int a2)
{
  if ( ViZwShouldCheck(a1, a2) )
    ViZwCheckObjectAttributes(a1);
  return pXdvZwUnloadKey(a1);
}
