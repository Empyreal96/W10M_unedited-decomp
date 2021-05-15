// -StDmPageError@-$ST_STORE@USM_TRAITS@@@@SAXPAU_ST_DATA_MGR@1@PAD1PAU_ST_PAGE_LOCATION@1@J@Z 
 
_DWORD *__fastcall ST_STORE<SM_TRAITS>::StDmPageError(int a1, int a2, int a3, int a4, int a5)
{
  void *v9; // r0

  if ( *(_BYTE *)(a1 + 72) )
  {
    if ( (dword_636E9C & 0x10) != 0 )
    {
      v9 = &unk_636E90;
      goto LABEL_7;
    }
  }
  else if ( (dword_636E9C & 0x40) != 0 )
  {
    v9 = &unk_636E90;
    goto LABEL_7;
  }
  v9 = 0;
LABEL_7:
  if ( v9 )
    SmEtwLogStoreCorruption(v9, a2, a1);
  if ( ((*(_DWORD *)(a1 + 116) >> 5) & 3u) >= 2 && KdDebuggerEnabled )
    __debugbreak();
  if ( ((*(_DWORD *)(a1 + 116) >> 5) & 3) == 3 )
    KeBugCheckEx(299, a5, *(unsigned __int16 *)(a4 + 4), a2, a3);
  return ST_STORE<SM_TRAITS>::StDmDeviceError((_DWORD *)a1, 0, a5);
}
