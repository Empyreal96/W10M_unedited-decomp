// PopBootLoaderTraceProcess 
 
void PopBootLoaderTraceProcess()
{
  int v0; // r4
  int v1; // r0

  v0 = dword_61EC98;
  if ( dword_61EC98 )
  {
    BapdRecordFirmwareBootStats();
    v1 = *(_DWORD *)(v0 + 136);
    if ( v1 )
      PopBootLoaderTraceEtwEvents(v1, *(_DWORD *)(v0 + 140));
  }
}
