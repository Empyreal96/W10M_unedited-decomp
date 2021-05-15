// MiPfCompleteCoalescedIo 
 
int __fastcall MiPfCompleteCoalescedIo(int a1, int *a2)
{
  int v4; // r7
  int v5; // r2
  int v6; // r2
  int v7; // r3
  __int64 **v8; // r6
  __int64 *v9; // r5
  __int64 v10; // r2
  int v11; // r2
  int v12; // r3
  int v13; // r0

  v4 = 0;
  KeWaitForSingleObject(a1 + 16, 9, 0, 0, 0);
  if ( (*(_WORD *)(a1 + 158) & 0x200) != 0 )
  {
    MiRetardMdl(a1 + 152);
    *(_DWORD *)(a1 + 48) = -1073741670;
    *(_DWORD *)(a1 + 52) = 0;
  }
  if ( (*(_WORD *)(a1 + 158) & 1) != 0 )
    MmUnmapLockedPages(*(_DWORD *)(a1 + 164), a1 + 152, v5);
  if ( *(int *)(a1 + 48) < 0 )
  {
    v4 = *(_DWORD *)(a1 + 48);
  }
  else
  {
    v6 = *(_DWORD *)(a1 + 52);
    v7 = *(_DWORD *)(a1 + 172);
    if ( v6 != v7 )
      KeBugCheckEx(122, 5, v6, v7, a1);
  }
  v8 = (__int64 **)(a1 + 8);
  while ( *v8 != (__int64 *)v8 )
  {
    v9 = *v8;
    v10 = **v8;
    if ( (__int64 **)HIDWORD(v10) != v8 || *(__int64 **)(v10 + 4) != v9 )
      __fastfail(3u);
    *v8 = (__int64 *)v10;
    *(_DWORD *)(v10 + 4) = v8;
    *((_DWORD *)v9 + 12) = *(_DWORD *)(a1 + 48);
    if ( *(int *)(a1 + 48) < 0 )
      *((_DWORD *)v9 + 13) = 0;
    else
      *((_DWORD *)v9 + 13) = *((_DWORD *)v9 + 26);
    KeSetEvent((int)(v9 + 2), 0, 0);
    v13 = MiPfCompleteInPageSupport((int)v9, a2, v11, v12);
    if ( v13 < 0 && v13 != -1073740748 )
      v4 = v13;
  }
  ExFreePoolWithTag(a1);
  return v4;
}
