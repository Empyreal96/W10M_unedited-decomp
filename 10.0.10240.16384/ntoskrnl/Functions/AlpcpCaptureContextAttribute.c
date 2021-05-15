// AlpcpCaptureContextAttribute 
 
int __fastcall AlpcpCaptureContextAttribute(int a1, _DWORD *a2, int a3, _DWORD *a4)
{
  int v4; // r2

  a2[3] = *(_DWORD *)(a3 + 136);
  a2[4] = *(_DWORD *)(a3 + 140);
  a2[2] = 0;
  *a2 = *(_DWORD *)(a1 + 28);
  v4 = a2[1];
  if ( (*(_DWORD *)(a1 + 244) & 6) == 4 )
    *a4 = v4;
  else
    a4[1] = v4;
  return 0;
}
