// RtlCmDecodeMemIoResource 
 
int __fastcall RtlCmDecodeMemIoResource(int a1, _DWORD *a2)
{
  int v3; // r2

  if ( *(_BYTE *)a1 != 3 )
    return sub_54DF88();
  v3 = *(_DWORD *)(a1 + 12);
  if ( a2 )
  {
    *a2 = *(_DWORD *)(a1 + 4);
    a2[1] = *(_DWORD *)(a1 + 8);
  }
  return v3;
}
