// ObpParseSymbolicLink 
 
int __fastcall ObpParseSymbolicLink(int a1, int a2, int a3, char a4, int a5, int a6, unsigned __int16 *a7, int a8, int a9, int *a10)
{
  int result; // r0
  unsigned int v12; // r6
  unsigned int v13; // r2
  unsigned int v14; // r9
  unsigned int v15; // r10
  int v16; // r7
  unsigned int v17; // r0

  if ( (*(_DWORD *)(a1 + 20) & 2) != 0 )
    return sub_7D64DC();
  if ( *a7 )
  {
    if ( **((_WORD **)a7 + 1) != 92 )
      return -1073741788;
    goto LABEL_5;
  }
  if ( a2 != ObpSymbolicLinkObjectType )
    goto LABEL_5;
  result = ObReferenceObjectByPointer(a1, 0, a2, a4);
  if ( result >= 0 )
  {
    *a10 = a1;
    return result;
  }
  if ( result == -1073741788 )
  {
LABEL_5:
    v12 = *(unsigned __int16 *)(a1 + 8);
    if ( *(_WORD *)(a1 + 8)
      && *(_WORD *)(*(_DWORD *)(a1 + 12) + 2 * (v12 >> 1) - 2) == 92
      && *a7
      && **((_WORD **)a7 + 1) == 92 )
    {
      v12 -= 2;
    }
    v13 = *a7 + v12;
    if ( v13 > 0xFFF0 )
    {
      result = -1073741562;
    }
    else
    {
      v14 = (unsigned __int16)v13;
      v15 = *(unsigned __int16 *)(a6 + 2);
      if ( v15 <= (unsigned __int16)v13 )
      {
        LOWORD(v15) = v13 + 2;
        v16 = ExAllocatePoolWithTag(1, (unsigned __int16)(v13 + 2), 1833853519);
        if ( !v16 )
          return -1073741670;
      }
      else
      {
        v16 = *(_DWORD *)(a6 + 4);
      }
      if ( *a7 )
        memmove(v16 + v12, *((_DWORD *)a7 + 1), *a7);
      memmove(v16, *(_DWORD *)(a1 + 12), v12);
      *(_WORD *)(v16 + 2 * (v14 >> 1)) = 0;
      v17 = *(_DWORD *)(a6 + 4);
      if ( v16 != v17 )
      {
        if ( v17 )
          ExFreePoolWithTag(v17);
      }
      *(_DWORD *)(a6 + 4) = v16;
      *(_WORD *)a6 = v14;
      *(_WORD *)(a6 + 2) = v15;
      result = 260;
    }
  }
  return result;
}
