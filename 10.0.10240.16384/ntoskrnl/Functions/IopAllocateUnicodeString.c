// IopAllocateUnicodeString 
 
int __fastcall IopAllocateUnicodeString(int a1, unsigned int a2)
{
  unsigned int v2; // r3
  int v4; // r4
  int v5; // r0

  v2 = (unsigned __int16)(a2 + 2);
  *(_WORD *)a1 = 0;
  if ( v2 < a2 )
  {
    v4 = -1073741675;
    *(_WORD *)(a1 + 2) = -1;
  }
  else
  {
    *(_WORD *)(a1 + 2) = v2;
    v4 = 0;
    v5 = ExAllocatePoolWithTag(1, (unsigned __int16)v2, 1970499664);
    *(_DWORD *)(a1 + 4) = v5;
    if ( !v5 )
      return sub_7C8AC0();
  }
  return v4;
}
