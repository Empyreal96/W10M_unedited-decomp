// VfZwReplaceKey 
 
int __fastcall VfZwReplaceKey(int a1, int a2, int a3)
{
  if ( ViZwShouldCheck(a1, a2) )
  {
    ViZwCheckObjectAttributes(a1);
    ViZwCheckObjectAttributes(a3);
  }
  return pXdvZwReplaceKey(a1, a2, a3);
}
