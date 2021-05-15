// sub_69410C 
 
void __fastcall sub_69410C(_BYTE *a1, int a2, int a3, int a4)
{
  int v4; // r10
  unsigned int v5; // r0

  do
  {
    if ( a4 == 32 || a4 >= 48 && a4 <= 57 )
      break;
    a4 = (char)*++a1;
  }
  while ( *a1 );
  v5 = atol((int)a1);
  *(_DWORD *)(v4 + 88) = v5;
  if ( !v5 || v5 > 0x20 || ((v5 - 1) & v5) != 0 )
    *(_DWORD *)(v4 + 88) = 32;
  JUMPOUT(0x691EFE);
}
