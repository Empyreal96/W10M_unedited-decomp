// IoInitializeRemoveLockEx 
 
int __fastcall IoInitializeRemoveLockEx(int result, int a2, int a3, int a4, int a5)
{
  if ( result )
  {
    if ( a5 == 24 )
    {
      *(_DWORD *)(result + 4) = 1;
      *(_BYTE *)result = 0;
      *(_BYTE *)(result + 8) = 1;
      *(_BYTE *)(result + 10) = 4;
      *(_BYTE *)(result + 9) = 0;
      *(_DWORD *)(result + 12) = 0;
      *(_DWORD *)(result + 16) = result + 16;
      *(_DWORD *)(result + 20) = result + 16;
    }
    else
    {
      result = sub_528484();
    }
  }
  return result;
}
