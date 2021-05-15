// IoRemoveShareAccess 
 
int __fastcall IoRemoveShareAccess(int result, _DWORD *a2)
{
  _DWORD *v2; // r3

  v2 = *(_DWORD **)(result + 124);
  if ( (!v2 || (*v2 & 1) == 0) && (*(_BYTE *)(result + 38) || *(_BYTE *)(result + 39) || *(_BYTE *)(result + 40)) )
  {
    --*a2;
    if ( *(_BYTE *)(result + 38) )
      --a2[1];
    if ( *(_BYTE *)(result + 39) )
      --a2[2];
    if ( *(_BYTE *)(result + 40) )
      --a2[3];
    if ( *(_BYTE *)(result + 41) )
      --a2[4];
    if ( *(_BYTE *)(result + 42) )
      --a2[5];
    if ( *(_BYTE *)(result + 43) )
      --a2[6];
  }
  return result;
}
