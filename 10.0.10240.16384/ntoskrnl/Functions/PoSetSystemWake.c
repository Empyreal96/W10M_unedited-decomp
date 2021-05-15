// PoSetSystemWake 
 
int __fastcall PoSetSystemWake(int result)
{
  int v1; // r2

  v1 = *(_DWORD *)(result + 40 * *(char *)(result + 34) + 108);
  if ( !*(_BYTE *)(v1 + 112) )
    *(_BYTE *)(v1 + 148) = 1;
  return result;
}
