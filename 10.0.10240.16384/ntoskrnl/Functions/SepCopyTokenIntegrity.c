// SepCopyTokenIntegrity 
 
int __fastcall SepCopyTokenIntegrity(int result, _DWORD *a2)
{
  int v2; // r2
  _DWORD *v3; // r2

  v2 = *(_DWORD *)(result + 184);
  if ( v2 == -1 )
    return sub_52C6CC();
  v3 = (_DWORD *)(*(_DWORD *)(result + 148) + 8 * v2);
  if ( !v3 )
    return sub_52C6CC();
  *a2 = *v3;
  a2[1] = v3[1];
  return result;
}
