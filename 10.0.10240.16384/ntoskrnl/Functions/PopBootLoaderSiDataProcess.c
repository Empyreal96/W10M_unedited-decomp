// PopBootLoaderSiDataProcess 
 
void PopBootLoaderSiDataProcess()
{
  int v0; // r0

  if ( dword_61EC98 )
  {
    v0 = *(_DWORD *)(dword_61EC98 + 136);
    if ( v0 )
      PopBootLoaderSiData(v0, *(_DWORD *)(dword_61EC98 + 140));
  }
}
