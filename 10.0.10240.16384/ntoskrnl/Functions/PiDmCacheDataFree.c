// PiDmCacheDataFree 
 
_BYTE *__fastcall PiDmCacheDataFree(int a1)
{
  if ( *(_DWORD *)a1 == 4 )
  {
    ExFreePoolWithTag(*(_DWORD *)(a1 + 12));
  }
  else if ( *(_DWORD *)a1 == 5 )
  {
    return (_BYTE *)sub_7EF678();
  }
  return memset((_BYTE *)a1, 0, 20);
}
