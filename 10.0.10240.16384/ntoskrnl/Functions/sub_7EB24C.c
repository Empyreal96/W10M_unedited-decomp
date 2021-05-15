// sub_7EB24C 
 
void __fastcall sub_7EB24C(int a1, int a2, int a3, __int16 a4)
{
  _DWORD *v4; // r4
  int v5; // r3
  int v6; // r3

  if ( (a4 & 0x8000) != 0 )
  {
    v5 = *(_DWORD *)(a2 + 12);
    if ( !v5 )
      goto LABEL_8;
    v6 = v5 + a2;
  }
  else
  {
    v6 = *(_DWORD *)(a2 + 12);
  }
  if ( v6 && *(_WORD *)(v6 + 4) )
  {
    if ( SepAdtAuditThisEventWithContext(0x74u, a1, a1 == 0, v4) )
      JUMPOUT(0x707E32);
  }
LABEL_8:
  JUMPOUT(0x707E30);
}
