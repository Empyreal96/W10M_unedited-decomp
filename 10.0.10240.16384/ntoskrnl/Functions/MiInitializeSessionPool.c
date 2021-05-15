// MiInitializeSessionPool 
 
int MiInitializeSessionPool()
{
  _DWORD *v0; // r4
  unsigned int v1; // r6
  int result; // r0

  v0 = *(_DWORD **)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324);
  v0[805] = 0;
  ExInitializePoolDescriptor(v0 + 864, 33, 0);
  v0[808] = ((v0[9] >> 10) & 0x3FFFFC) - 0x40000000;
  v1 = (unsigned int)(-4194304 - dword_63389C) >> 12;
  if ( !MiInitializeDynamicBitmap(v0 + 806, MmSessionSpace + 0x10000, v1, 0) )
    return -1073741670;
  v0[809] = v1;
  v0[806] = 0;
  result = 0;
  v0[1] |= 4u;
  return result;
}
