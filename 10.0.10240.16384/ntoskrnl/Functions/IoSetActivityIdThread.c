// IoSetActivityIdThread 
 
int __fastcall IoSetActivityIdThread(int a1)
{
  unsigned int v2; // r3
  int result; // r0

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  result = *(_DWORD *)(v2 + 1036);
  *(_DWORD *)(v2 + 1036) = a1;
  return result;
}
