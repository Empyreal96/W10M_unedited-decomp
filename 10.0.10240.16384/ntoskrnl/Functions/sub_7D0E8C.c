// sub_7D0E8C 
 
void __fastcall sub_7D0E8C(_DWORD *a1)
{
  _DWORD *v1; // r4
  __int16 v2; // r2

  *v1 = 0;
  v1[1] = 0;
  v2 = -1;
  if ( *a1 )
    v2 = *a1;
  *(_WORD *)v1 = v2;
  EtwpReleaseLoggerContext(a1, 0);
  JUMPOUT(0x78B260);
}
