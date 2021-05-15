// PipIsDevNodeDNStarted 
 
BOOL __fastcall PipIsDevNodeDNStarted(int a1)
{
  int v1; // r2

  v1 = *(_DWORD *)(a1 + 172);
  return v1 > 772 && v1 <= 781;
}
