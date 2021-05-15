// PnpUnicodeStringToWstrFree 
 
unsigned int __fastcall PnpUnicodeStringToWstrFree(unsigned int a1, int a2)
{
  int v2; // r3

  if ( a1 )
  {
    if ( a2 )
    {
      if ( *(_WORD *)(a2 + 2) )
      {
        v2 = *(_DWORD *)(a2 + 4);
        if ( v2 != a1 )
        {
          if ( v2 )
            a1 = ExFreePoolWithTag(a1);
        }
      }
    }
  }
  return a1;
}
