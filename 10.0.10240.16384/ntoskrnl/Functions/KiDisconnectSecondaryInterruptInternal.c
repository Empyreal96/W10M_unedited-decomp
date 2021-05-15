// KiDisconnectSecondaryInterruptInternal 
 
int __fastcall KiDisconnectSecondaryInterruptInternal(int a1)
{
  int v2; // r3
  int result; // r0
  int v4; // r0
  int v5; // r3
  __int64 v6; // kr00_8

  v2 = *(unsigned __int8 *)(a1 + 51);
  result = -1073741585;
  if ( v2 )
  {
    v4 = KiGlobalSecondaryIDT + 28 * (*(_DWORD *)(a1 + 44) - 4096);
    v5 = *(_DWORD *)(v4 + 24);
    if ( v5 == a1 )
    {
      if ( *(_DWORD *)(v5 + 4) == v5 + 4 )
        *(_DWORD *)(v4 + 24) = 0;
      else
        *(_DWORD *)(v4 + 24) = *(_DWORD *)(a1 + 4) - 4;
    }
    v6 = *(_QWORD *)(a1 + 4);
    if ( *(_DWORD *)(v6 + 4) != a1 + 4 || *(_DWORD *)HIDWORD(v6) != a1 + 4 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v6) = v6;
    *(_DWORD *)(v6 + 4) = HIDWORD(v6);
    if ( *(_DWORD *)(v4 + 24) )
      result = 296;
    else
      result = 0;
    *(_BYTE *)(a1 + 51) = 0;
  }
  return result;
}
