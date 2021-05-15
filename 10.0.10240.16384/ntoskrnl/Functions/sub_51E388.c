// sub_51E388 
 
void __fastcall sub_51E388(_DWORD *a1)
{
  _DWORD *v1; // r4

  if ( a1[2] )
  {
    if ( a1[1] )
      a1 = RtlRealSuccessor(a1);
    a1[1] = v1;
  }
  else
  {
    a1[2] = v1;
  }
  *v1 = a1;
  JUMPOUT(0x44D086);
}
