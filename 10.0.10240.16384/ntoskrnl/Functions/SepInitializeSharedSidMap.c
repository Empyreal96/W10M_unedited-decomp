// SepInitializeSharedSidMap 
 
int SepInitializeSharedSidMap()
{
  _DWORD *v0; // r3
  int v1; // r4

  v0 = g_SepSidMapping;
  v1 = 0;
  *(_DWORD *)g_SepSidMapping = 0;
  v0[1] = 0;
  if ( !RtlCreateHashTable((int)(v0 + 1), 0, 0) )
    v1 = -1073741801;
  return v1;
}
