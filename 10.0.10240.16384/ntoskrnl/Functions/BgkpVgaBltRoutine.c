// BgkpVgaBltRoutine 
 
int __fastcall BgkpVgaBltRoutine(int a1, int a2, int a3)
{
  int result; // r0

  if ( a3 )
  {
    memset(*(_BYTE **)(a1 + 16), 0, *(_DWORD *)(a1 + 12));
    result = -1073741823;
  }
  else
  {
    VidBitBltEx_0();
    result = 0;
  }
  return result;
}
