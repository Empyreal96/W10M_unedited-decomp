// MiInitializeColorBaseSession 
 
int __fastcall MiInitializeColorBaseSession(int a1)
{
  return MI_INITIALIZE_COLOR_BASE(
           *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324) + 3248,
           0,
           a1);
}
