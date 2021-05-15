// _fputwc_nolock 
 
int __fastcall fputwc_nolock(int result, int a2)
{
  int v2; // r3

  if ( a2 )
  {
    v2 = *(_DWORD *)(a2 + 4) - 2;
    *(_DWORD *)(a2 + 4) = v2;
    if ( v2 < 0 )
    {
      result = (unsigned __int16)flswbuf();
    }
    else
    {
      **(_WORD **)a2 = result;
      *(_DWORD *)a2 += 2;
    }
  }
  else
  {
    PopPoCoalescinCallback();
    result = 0xFFFF;
  }
  return result;
}
