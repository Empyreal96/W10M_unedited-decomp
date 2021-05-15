// PoGetSystemWake 
 
int __fastcall PoGetSystemWake(int a1)
{
  int v1; // r2
  int result; // r0

  v1 = *(_DWORD *)(a1 + 40 * *(char *)(a1 + 34) + 108);
  if ( *(_BYTE *)(v1 + 112) )
    result = 0;
  else
    result = *(unsigned __int8 *)(v1 + 148);
  return result;
}
