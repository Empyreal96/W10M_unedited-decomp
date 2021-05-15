// IoUpdateShareAccess 
 
int __fastcall IoUpdateShareAccess(int result, _DWORD *a2)
{
  if ( *(_DWORD *)(result + 124) )
    return sub_7E7804();
  if ( *(_BYTE *)(result + 38) || *(_BYTE *)(result + 39) || *(_BYTE *)(result + 40) )
  {
    ++*a2;
    a2[1] += *(unsigned __int8 *)(result + 38);
    a2[2] += *(unsigned __int8 *)(result + 39);
    a2[3] += *(unsigned __int8 *)(result + 40);
    a2[4] += *(unsigned __int8 *)(result + 41);
    a2[5] += *(unsigned __int8 *)(result + 42);
    a2[6] += *(unsigned __int8 *)(result + 43);
  }
  return result;
}
