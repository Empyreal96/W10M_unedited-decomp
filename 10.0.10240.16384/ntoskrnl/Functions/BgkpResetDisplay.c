// BgkpResetDisplay 
 
int __fastcall BgkpResetDisplay(int a1, int a2, _DWORD *a3)
{
  int result; // r0

  *a3 = 0;
  if ( !a1 || dword_6416A8 == 2 )
    return -1073741637;
  if ( !dword_64B0A8 )
    return -1073741823;
  dword_64B0A8(80, 50);
  VidResetDisplay_0();
  memset((_BYTE *)a2, 0, 28);
  *(_DWORD *)(a2 + 4) = 480;
  *(_DWORD *)(a2 + 8) = 640;
  *(_DWORD *)(a2 + 12) = 640;
  *(_DWORD *)(a2 + 16) = 1;
  *(_BYTE *)a2 = 0;
  result = 0;
  *(_DWORD *)(a2 + 24) = BgkpVgaBltRoutine;
  return result;
}
